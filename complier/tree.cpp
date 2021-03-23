#include <iostream>
#include <string>

using namespace std;

#include "common.h"
#include "tree.h"
#include "symbol.h"
#include "lexer.h"
#include "parser.h"

extern int lineno;
extern symbol_table symtbl;

tree parse_tree;

int tree::node_seq = 0;
int tree::temp_var_seq = 0;
int tree::label_seq = 0;

void Node::output(void)//由NewRoot()调用打印各个节点
{
	cout.setf(ios_base::left);//设置输出的格式
	cout.width(2);
	cout << seq << ": ";
	switch(kind)//根据kind来确定STMT_NODE还是EXPR_NODE
	{
	case STMT_NODE:
		{
			string names[] = {"if", "while","for", "input", "print", "compound"};
			cout.width(40);
			cout << names[kind_kind] + " statement,";//根据kind_kind来确定STMT_NODE是IF WHILE FOR INPUT PRINT COMPOUND....
			break;
		}
	case EXPR_NODE:
		{
			string names[] = { "Type Specifier", "Expr", "Not Expr", "Array", "Const Declaration", "ID Declaration" };
			string types[] = { "Notype", "integer", "boolean", "char" };
			string opnames[] = { "==", "!=", ">=", "<=", "||", "&&", "!", "=", "++", "--", ">>", "<<", "+", "-", "*", "/", "%", "&", "|", "^", "~", "<", ">"};
			cout.width(20);
			cout << names[kind_kind] + ',';
			cout.width(10);
			cout << types[type] + ',';//根据EXPR_NODE的type来确定表达式的类型
			cout.width(10);
			switch (kind_kind)//根据表达式的各种类型来输出父节点的各种信息，包括父节点的名称和父节点的值（通过表达式计算出来的，主要体现在temp_var上）
			{
			case TYPE_EXPR:
				cout << "";
				break;
			case NOT_EXPR:
			case OP_EXPR:
				{
					char tmp[100];
					if (attr.op >= INC && attr.op <= BNOT)								
						sprintf_s(tmp, "op: %s, t%d", opnames[attr.op - EQ].c_str(), temp_var);
					else
						sprintf_s(tmp, "op: %s", opnames[attr.op - EQ].c_str());
					cout << tmp;
				}
				break;
			case CONST_EXPR:
				if (type == Integer)
				{
					char tmp[100];
					sprintf_s(tmp, "value:%d, ", attr.vali);
					cout << tmp;
				}
				else
					cout << string("value: '") + attr.valc + "',";
				break;
			case ID_EXPR:
				cout << "symbol: " + symtbl.getname(attr.symtbl_seq);
				break;
			}
			break;
		}
	case DECL_NODE:
		{
			string names[] = { "Var Declaration, ", "Array Declaration, " };
			cout.width(40);
			cout << names[kind_kind];
			break;
		}
	}
//以上的代码是用来输出父节点的信息，之后的代码是用来输出父节点的兄弟节点和孩子结点的信息的，包括孩子结点的标号和兄弟节点的标号
	cout << "Children: ";
	int i = 0;
	for (; i < MAX_CHILDREN; i++)
		if (NULL == children[i])
			break;
		else
		{
			cout << children[i]->seq << " ";
		}
	if (i)
	{
		i--;
		for (Node *child = children[i]->sibling; child; child = child->sibling)
			cout << child->seq << " ";
	}

	cout << endl;
}


void tree::type_check(Node *t)
{
	if (t->type != Notype)
		return;

	if (t->kind == STMT_NODE)
	{
		if (t->kind_kind == IF_STMT || t->kind_kind == WHILE_STMT)//对于IF和WHILE来说，他们的第一个（也是唯一一个）孩子类型必须是BOOL型，否则就要报错
			if (t->children[0]->type != Boolean)
			{
				cerr << "Bad boolean type at line: " << t->lineno << endl;
				exit(1);
			}
			else
				return;
		if (t->kind_kind == FOR_STMT)//对于FOR语句来说，他的第二个孩子必须是BOOL型，（判断语句），否则报错											
			if (t->children[1]->type != Boolean)
			{
				cerr << "Bad boolean type at line: " << t->lineno << endl;
				exit(1);
			}
			else
				return;
		
	}
	if (t->kind != EXPR_NODE)
		return;

	if (t->kind_kind != OP_EXPR && t->kind_kind != NOT_EXPR)
		return;
//对于不是EXPR_NODE类型的结点和虽然是EXPR_NODE但其结点类型的子类型不是操作符表达式和符号表达式的表达式均不需要用类型检查
	Node *arg1 = t->children[0];
	Node *arg2 = t->children[1];
	if (t->attr.op == NOT)//对于操作符表达式来说，如果是OP属性为NOT的，必须为BOOL
	{
		if (arg1->type != Boolean)
		{
			cerr << "Bad type at line: " << t->lineno << endl;
			exit(1);
		}
		t->type = arg1->type;
	}
	else if (t->attr.op == AND || t->attr.op == OR)//对于操作符表达式来说，如果是OP属性为AND和OR的，必须为BOOL
	{
		if (arg1->type != Boolean || arg2->type != Boolean)
		{
			cerr << "Bad type at line: " << t->lineno << endl;
			exit(1);
		}
		t->type = arg1->type;
	}
	else if (t->attr.op >= EQ && t->attr.op <= LE || t->attr.op == LT || t->attr.op == GT)//对于OP属性为EQ LE LT GT来说，两个孩子的类型必须为整形
	{
		if (arg1->type != Integer || arg2->type != Integer)
		{
			cerr << "Bad type at line: " << t->lineno << endl;
			exit(1);
		}
		t->type = Boolean;
	}
	else if (t->attr.op >= SHR && t->attr.op <= BXOR || t->attr.op == ASSIGN)//左移右移的两个操作符都必须是整形	
	{
		
		if (arg1->type != Integer || arg2->type != Integer)
		{
			cerr << "Bad type at line: " << t->lineno << endl;
			exit(1);
		}
		t->type = arg1->type;
	}
	else if (t->attr.op == INC || t->attr.op == DEC || t->attr.op == BNOT)//自增自减和按位异或的孩子必须是整形，同时要注意只有一个操作符，所以要使用temp	
	{
		Node *temp;
		if (arg1 == NULL)
			temp = arg2;
		else
			temp = arg1;
		if (temp->type != Integer)
		{
			cerr << "Bad type at line: " << t->lineno << endl;
			exit(1);
		}
		t->type = temp->type;
	}


	return;
}

void tree::get_temp_var(Node *t)//只有操作符表达式并且是双目有返回值的操作符表达式才能是父节点有temp_var，所以没有上述属性的表达式和语句都略过
{
	if (t->kind != EXPR_NODE)
		return;
	if (t->attr.op < INC || t->attr.op > BNOT)							
		return;

	Node *arg1 = t->children[0];
	Node *arg2 = t->children[1];

	if (arg1->kind_kind == OP_EXPR)
		temp_var_seq--;
	if (arg2 && arg2->kind_kind == OP_EXPR)
		tree::temp_var_seq--;
	t->temp_var = tree::temp_var_seq;
	tree::temp_var_seq++;
}

Node* tree::NewRoot(int kind, int kind_kind, NodeAttr attr, int type,
				   Node *child1, Node *child2, Node *child3, Node *child4)
{
	Label label0;
	Node *t = new Node;
	
	if (NULL == t)
		cerr << "Out of memory at line %d\n" << lineno;
	else
	{
		t->kind = kind;
		t->kind_kind = kind_kind;
		t->attr = attr;
		t->type = type;
		t->children[0] = child1;
		t->children[1] = child2;
		t->children[2] = child3;
		t->children[3] = child4;
		t->lineno = lineno;
		t->seq = tree::node_seq++;//全局结点标号
		t->sibling = NULL;
		t->label.begin_label = "";
		t->label.next_label = "";
		t->label.true_label = "";
		t->label.false_label = "";
		root = t;
		type_check(t);
		get_temp_var(t);

#ifdef PARSE_DEBUG
		t->output();//调用output()直接在控制台输出，就是建立一个新的结点就打印出来
#endif
	}
	return t;
}
//=============================================
/************生成新的标号**************/
//=============================================
string tree::new_label(void)
{
	char tmp[20];
//将标号名“@i”赋值给tmp变量并返回
	sprintf_s(tmp, "@%d", tree::label_seq);//字串格式化命令：把格式化的数据写入某字符串中（tmp）
	tree::label_seq++;
	return tmp;
}
//=========================================
/***********给各语句设置标号**************/
//=========================================
void tree::stmt_get_label(Node *t)
{
	switch (t->kind_kind)//根据不同的语句进行处理
	{
	case COMP_STMT:
		{
			Node *last;
			Node *p;
			for (p = t->children[0]; p->kind == DECL_NODE; p = p->sibling) ;//处理非变量定义语句
			//第一个非变量定义语句的孩子结点的begin_label即为父结点的begin_label
			p->label.begin_label = t->label.begin_label;
			for (; p; p = p->sibling)//处理右兄弟结点
			{
				last = p;
				recursive_get_label(p);
			}

			t->label.next_label = last->label.next_label;//最后一个右兄弟结点即为父结点的next_label
			//如果父结点有右兄弟结点，那么该结点的begin_label即为父结点的next_label
			if (t->sibling)
				t->sibling->label.begin_label = t->label.next_label;
		}
		break;
//if语句有三个孩子结点，分别为判断语句、真值执行语句、假值执行语句
	case IF_STMT:
		{
			Node *e = t->children[0];
			Node *s1 = t->children[1];
			Node *s2 = t->children[2];

			e->label.true_label = new_label();//给真值判断语句生成标号

			if (t->label.next_label == "")//如果父结点的next_label为空，生成新的标号
				t->label.next_label = new_label();
			s1->label.next_label = t->label.next_label; //第一个孩子结点的next_label为父结点的next_label
			if (t->sibling)//处理父结点的右兄弟结点（如果存在）
				t->sibling->label.begin_label = t->label.next_label;
//如果存在else语句，假值判断语句生成标号，next_label 和父结点相同
			if (s2)
			{
				e->label.false_label = new_label();
				s2->label.next_label = t->label.next_label;
			}
			else //如果不存在else语句，假值判断语句false_label即为父结点的next_label
			{
				e->label.false_label = t->label.next_label;
			}
			//递归处理孩子结点
			recursive_get_label(e);
			recursive_get_label(s1);
			if (s2)
				recursive_get_label(s2);
		}
		break;
//while语句有两个孩子结点，分别为判断语句和循环体语句
	case WHILE_STMT:
		{
			Node *e = t->children[0];
			Node *s = t->children[1];

			if (t->label.begin_label == "")	//给父结点的begin_label生成新的标号
				t->label.begin_label = new_label();
			s->label.next_label = t->label.begin_label;//循环体语句的next_label即为父结点的begin_label

			s->label.begin_label = new_label();//给循环体语句的begin_label生成新的标号
			e->label.true_label = s->label.begin_label; //判断语句的true_label即为循环体语句的begin_label

			if (t->label.next_label == "")//给父结点的next_label生成标号
				t->label.next_label = new_label();
			e->label.false_label = t->label.next_label;//判断语句的false_label即为父结点的next_label
			if (t->sibling)//如果父结点有有兄弟一结点，则其begin_label即为父结点的next_label
				t->sibling->label.begin_label = t->label.next_label;
//递归处理孩子结点
			recursive_get_label(e);
			recursive_get_label(s);
			
		}
		break;
//for语句有四个孩子结点，分别为初值语句、判断语句、循环变量语句和循环体语句
	case FOR_STMT:												
		{
			Node *e0 = t->children[0];
			Node *e1 = t->children[1];
			Node *e2 = t->children[2];
			Node *s = t->children[3];
			//为初值语句的next_label、循环变量语句的begin_label和循环体的begin_label生成标号
	
			e0->label.next_label = new_label();					//@0
				
			e2->label.begin_label = new_label();				//@1
			s->label.begin_label = new_label();					//@2
			//如果父结点的next_label为空，生成标号
			if(t->label.next_label == "")
				t->label.next_label = new_label();				//@3
			//如果父结点有右兄弟结点，则其begin_label为父结点的next_label
			if(t->sibling)
				t->sibling->label.begin_label = t->label.next_label;

			e1->label.true_label = s->label.begin_label;//判断语句的true_label是循环体的begin_label			
			e1->label.false_label = t->label.next_label;//判断语句的false_label是父结点的next_label

			//递归处理孩子结点
			recursive_get_label(e0);
			recursive_get_label(e1);
			recursive_get_label(e2);
			recursive_get_label(s);
				
		}	
		break;

	}
#ifdef PARSE_DEBUG
	cout << "node " << t->seq << ":" << t->label.begin_label << ", " << t->label.next_label << endl;
#endif
}
//=============================================
/***********给布尔表达式设置标号**************/
//=============================================

void tree::expr_get_label(Node *t)
{
	if (t->type != Boolean) //如果表达式类型不为布尔型，直接退出
		return;
//否则，输出结点的编号和true_label和false_label
#ifdef PARSE_DEBUG
	cout << "node " << t->seq << ": "<< t->label.true_label << ", " << t->label.false_label << endl;
#endif
	Node *e1 = t->children[0];
	Node *e2 = t->children[1];
	switch (t->attr.op)
	{
	case AND://与运算
		e1->label.true_label = new_label();	//给第一个孩子结点的true_label生成新的标号（标号为全局变量tree::label_seq）
		e2->label.true_label = t->label.true_label;//第二个孩子结点的true_label赋值为父结点的true_label
		//父结点和两个孩子结点的false_label相同
		e1->label.false_label = e2->label.false_label = t->label.false_label;
		break;

	case OR://或运算
		e1->label.false_label = new_label(); //第一个孩子结点的false_label生成新的标号
		e2->label.false_label = t->label.false_label;//第二个孩子的false_label与父结点相同
		//父结点和两个孩子结点的true_label相同
		e1->label.true_label = e2->label.true_label = t->label.true_label;
		break;

	case NOT://非运算
	//孩子结点的真假与父结点的真假正好相反，所以二者的true_label和false_label也相反
		e1->label.true_label = t->label.false_label;
		e1->label.false_label = t->label.true_label;
		break;
	}
	//e1、e2也是布尔表达式，所以继续递归处理
	if (e1)
		recursive_get_label(e1);
	if (e2)
		recursive_get_label(e2);
}
//=====================================================
/***********分语句和表达式两部分设置标号**************/
//=====================================================
void tree::recursive_get_label(Node *t)
{
	if (t->kind == STMT_NODE)
		stmt_get_label(t);
	else if (t->kind == EXPR_NODE)
		expr_get_label(t);
}
//=========================================
/***********设置汇编代码标号**************/
//=========================================
void tree::get_label(void)
{
	Node *p = root;

	p->label.begin_label = "_start";
	recursive_get_label(p);
}
//=========================================
/***********打印必要的头文件**************/
//=========================================
void tree::gen_header(ostream &out)
{
	out << "\t.386" << endl;
    out << "\t.model flat, stdcall" << endl;
	out << "\toption casemap :none" << endl;
	out << endl;
	out << "\tinclude D:\\masm32\\include\\windows.inc" << endl;
	out << "\tinclude D:\\masm32\\include\\user32.inc" << endl;
	out << "\tinclude D:\\masm32\\include\\kernel32.inc" << endl;
	out << "\tinclude D:\\masm32\\include\\masm32.inc" << endl;
	out << endl;
	out << "\tincludelib D:\\masm32\\lib\\user32.lib" << endl;
	out << "\tincludelib D:\\masm32\\lib\\kernel32.lib" << endl;
	out << "\tincludelib D:\\masm32\\lib\\masm32.lib" << endl;
}
//=====================================================
/***********数据段（变量声明语句）的处理**************/
//=====================================================
void tree::gen_decl(ostream &out, Node *t)
{
	out << endl << endl << "\t.data" << endl; //输出数据段标号
	
	for (; t->kind == DECL_NODE; t = t->sibling) //打印所有ID变量
	{
		for (Node *p = t->children[1]; p; p = p->sibling)
			if (p->type == Integer)
				out << "\t\t_" << symtbl.getname(p->attr.symtbl_seq) << " DWORD 0" << endl;
			else if (p->type == Char)
				out << "\t\t_" << symtbl.getname(p->attr.symtbl_seq) << " BYTE 0" << endl;
	}
	
	for (int i = 0; i < temp_var_seq; i++) //处理临时变量
	{
		out << "\t\tt" <<  i << " DWORD 0" << endl;
	}

	out << "\t\tbuffer BYTE 128 dup(0)" << endl;
	out << "\t\tLF BYTE 13, 10, 0" << endl;
}
//=======================================
/***********语句部分的翻译**************/
//=======================================
void tree::stmt_gen_code(ostream &out, Node *t)
{
	if (t->kind_kind == COMP_STMT)
	{
		for (int i = 0; t->children[i]; i++)
		{
			recursive_gen_code(out, t->children[i]);
			for (Node *p = t->children[i]->sibling; p; p = p->sibling)
				recursive_gen_code(out, p);
		}
	}
/****************if-statement**************/
/*
	if语句有2个孩子结点：第一个孩子结点为判断语句，第二个孩子结点为条件真的执行语句（即true_label）
	如果还有第三个孩子结点，则为条件判断为假的执行语句（即为false_label）
*/

	else if (t->kind_kind == IF_STMT)														
	{
		if (t->label.begin_label != "")//如果有开始标号，首先打印出来
			out << t->label.begin_label << ":" << endl;
		//递归调用recursive_gen_code()处理孩子结点
		recursive_gen_code(out, t->children[0]);
		out <<  t->children[0]->label.true_label << ": " <<endl;
		
		recursive_gen_code(out, t->children[1]);
		out << "\tjmp " << t->label.next_label << endl;
		
		if(t->children[2])
		{
			out <<  t->children[0]->label.false_label << ": " <<endl;
			recursive_gen_code(out, t->children[2]);
			out << "\tjmp " << t->label.next_label << endl;
		}
		out << t->label.next_label << ": " <<endl;//整个if语句结束标号
	}
/****************while-statement**************/
/*
	while语句有两个孩子结点，分别为判断表达式和循环体。递归调用recursive_gen_code()处理，最后跳出。
*/
	else if (t->kind_kind == WHILE_STMT)
	{
		if (t->label.begin_label != "")
			out << t->label.begin_label << ": " << endl;
		recursive_gen_code(out, t->children[0]);
		recursive_gen_code(out, t->children[1]);
		out << "\tjmp " << t->label.begin_label << endl;
	}

/****************for-statement**************/
/*
	for语句有四个孩子结点，首先执行第一个孩子结点（初值语句），然后输出第一个孩子结点的next_label；
	递归处理第二个孩子结点（判断语句），打印第三个孩子结点（判断量变化语句）的开始标号，递归处理第三个孩子结点；
	跳转到第一个孩子结点的next_label(判断语句)，执行循环体，跳转到第三个孩子结点的开始标号（判断量变化语句）。
*/
	else if (t->kind_kind == FOR_STMT)															
	{
		if (t->label.begin_label != "")
			out << t->label.begin_label << ":" << endl;
		recursive_gen_code(out, t->children[0]);
		out << t->children[0]->label.next_label << ":" << endl;
		recursive_gen_code(out, t->children[1]);
		out << t->children[2]->label.begin_label << ":" <<endl;
		recursive_gen_code(out, t->children[2]);
		out << "\tjmp " << t->children[0]->label.next_label <<endl;
		recursive_gen_code(out, t->children[3]);
		out << "\tjmp " << t->children[2]->label.begin_label <<endl;

	}
/****************input-statement**************/
	else if (t->kind_kind == INPUT_STMT)
	{
		Node *v = t->children[0];
		out << "\tinvoke StdIn, ADDR buffer, 127" << endl;
		out << "\tinvoke StripLF, ADDR buffer" << endl;
		out << "\tinvoke atodw, ADDR buffer" << endl;
		out << "\tMOV ";
		if (v->kind_kind == ID_EXPR)
			out << "_" << symtbl.getname(v->attr.symtbl_seq);
		out << ", eax" << endl;	
	}
	/****************print-statement**************/
	else if (t->kind_kind == PRINT_STMT)
	{
		Node *v = t->children[0];
		out << "\tinvoke dwtoa, ";
		if (v->kind_kind == ID_EXPR)
			out << "_" << symtbl.getname(v->attr.symtbl_seq);
		out << ", ADDR buffer" << endl;
		out << "\tinvoke StdOut, ADDR buffer" << endl;
		out << "\tinvoke StdOut, ADDR LF" << endl;
	}
}

void tree::expr_gen_code(ostream &out, Node *t)//考虑了单目和双目操作符，即一个EXPR_NODE最多两个结点
{
	Node *e1 = t->children[0];//操作符左边的变量var
	Node *e2 = t->children[1];//操作符右边的表达式OR变量var
	switch (t->attr.op)//根据EXPR_NODE结点的属性attr.op来决定接下来的操作
	{
	case ASSIGN://赋值表达式ASSIGN
		if (t->label.begin_label != "")
			out << t->label.begin_label << ":" << endl;//如果在EXPR_NODE结点有begin_label时打印，否则不打印
		recursive_gen_code(out, e1);//递归调用，遍历EXPR_NODE的第一个孩子结点（有可能因为不是stmt和expr而不执行任何语句）
		recursive_gen_code(out, e2);//递归调用，遍历EXPR_NODE的第二个孩子结点（有可能因为不是stmt和expr而不执行任何语句）
		out << "\tMOV eax, ";
		if (e2->kind_kind == ID_EXPR)
			out << "_" << symtbl.getname(e2->attr.symtbl_seq);//如果第二个孩子是ID的话，那么根据第二个孩子的符号表位置属性从符号表中获取该孩子的名字，并输出到MOV eax, _的后面，形成MOV eax, _第二个孩子的名字;
		else if (e2->kind_kind == CONST_EXPR)
			out << e2->attr.vali;//如果第二个孩子是常量的话，就根据第二个孩子的属性值直接输出到MOV eax,的后面
		else out << "t" << e2->temp_var;//否则以临时变量作为临时的值，形成MOV eax, t123.....
		out << endl;
		out << "\tMOV ";
		if (e1->kind_kind == ID_EXPR)
			out << "_" << symtbl.getname(e1->attr.symtbl_seq);
		else out << "t" << e1->temp_var;
		out << ", eax" << endl;//上述三条语句是将从第二个孩子中得到的值赋值到第一个孩子中，同样也是判断第一个孩子是ID/常量还是其他
		break;
//+ - * / %表达式
/*
加减乘除和取余的操作方式大体相似，只是在除法和取余的时候，由于除法和取余指令的特殊性，所以要做特殊的处理，商在EAX中，余数在EDX中
*/
	case PLUS:
		out << "\tMOV eax, ";
		if (e1->kind_kind == ID_EXPR)
			out << "_" << symtbl.getname(e1->attr.symtbl_seq);
		else if (e1->kind_kind == CONST_EXPR)
			out << e1->attr.vali;
		else out << "t" << e1->temp_var;//同赋值表达式一样MOV eax, _/t/ +第一个孩子的名字
		out << endl;
		out << "\tADD eax, ";//ADD加法汇编语言操作符
		if (e2->kind_kind == ID_EXPR)
			out << "_" << symtbl.getname(e2->attr.symtbl_seq);
		else if (e2->kind_kind == CONST_EXPR)
			out << e2->attr.vali;
		else out << "t" << e2->temp_var;//ADD eax,  _/t/ +第二个孩子的名字,从而ADD的结果生成在eax中
		out << endl;
		out << "\tMOV t" << t->temp_var << ", eax" << endl;//MOV t+EXPR_NODE的temp_var属性, eax这样EXPR_NODE就有了eax中的值（加法结果）
		break;

	case MINUS:
		out << "\tMOV eax, ";
		if (e1->kind_kind == ID_EXPR)
			out << "_" << symtbl.getname(e1->attr.symtbl_seq);
		else if (e1->kind_kind == CONST_EXPR)
			out << e1->attr.vali;
		else out << "t" << e1->temp_var;
		out << endl;
		out << "\tSUB eax, ";
		if (e2->kind_kind == ID_EXPR)
			out << "_" << symtbl.getname(e2->attr.symtbl_seq);
		else if (e2->kind_kind == CONST_EXPR)
			out << e2->attr.vali;
		else out << "t" << e2->temp_var;
		out << endl;
		out << "\tMOV t" << t->temp_var << ", eax" << endl;
		break;

	case TIMES:
		out << "\tMOV eax, ";
		if (e1->kind_kind == ID_EXPR)
			out << "_" << symtbl.getname(e1->attr.symtbl_seq);
		else if (e1->kind_kind == CONST_EXPR)
			out << e1->attr.vali;
		else out << "t" << e1->temp_var;
		out << endl;
		out << "\tIMUL eax, ";
		if (e2->kind_kind == ID_EXPR)
			out << "_" << symtbl.getname(e2->attr.symtbl_seq);
		else if (e2->kind_kind == CONST_EXPR)
			out << e2->attr.vali;
		else out << "t" << e2->temp_var;
		out << endl;
		out << "\tMOV t" << t->temp_var << ", eax" << endl;
		break;

	case OVER:	
		out << "\tMOV eax, ";
		if (e1->kind_kind == ID_EXPR)
			out << "_" << symtbl.getname(e1->attr.symtbl_seq);
		else if (e1->kind_kind == CONST_EXPR)
			out << e1->attr.vali;
		else out << "t" << e1->temp_var;//第一个孩子传值到eax
		out << endl;

		out << "\tcdq" << endl;//把EDX的所有位都设成EAX最高位的值
		
		out << "\tMOV ecx, ";
		if (e2->kind_kind == ID_EXPR)
			out << "_" << symtbl.getname(e2->attr.symtbl_seq);
		else if (e2->kind_kind == CONST_EXPR)
			out << e2->attr.vali;
		else out << "t" << e2->temp_var;//第二个孩子传值到ecx
		out << endl; 

		out << "\tIDIV ecx" << endl;//IDIV ecx,EAX除以ECX,商放在EAX,余数在EDX 带符号的二进制数除法
		
		out << "\tMOV t" << t->temp_var << ", eax" << endl;//商放在EXPR_NODE结点的temp_var中
		break;
	

	case REM:
		out << "\tMOV eax, ";
		if (e1->kind_kind == ID_EXPR)
			out << "_" << symtbl.getname(e1->attr.symtbl_seq);
		else if (e1->kind_kind == CONST_EXPR)
			out << e1->attr.vali;
		else out << "t" << e1->temp_var;
		out << endl;

		out << "\tcdq" << endl;
		
		out << "\tMOV ecx, ";
		if (e2->kind_kind == ID_EXPR)
			out << "_" << symtbl.getname(e2->attr.symtbl_seq);
		else if (e2->kind_kind == CONST_EXPR)
			out << e2->attr.vali;
		else out << "t" << e2->temp_var;
		out << endl;

			out << "\tIDIV ecx" << endl;
		
		out << "\tMOV t" << t->temp_var << ", edx" << endl;//同除法相似，只不过最后的结果是edx放入到EXPR_NODE的temp_var中
		break;
//< > <= >= == != 
/*
这些操作符除了具体的操作指令不同其他的都相同，例如都是将第一个孩子传值到EAX，执行操作指令 eax, 第二个孩子的值，定义如下两个标号，为真的标号和为假的标号，从而完成所有的操作
*/
	case LT:
		out << "\tMOV eax, ";
		if (e1->kind_kind == ID_EXPR)
			out << "_" << symtbl.getname(e1->attr.symtbl_seq);
		else if (e1->kind_kind == CONST_EXPR)
			out << e1->attr.vali;
		else out << "t" << e1->temp_var;
		out << endl;
		out << "\tCMP eax, ";
		if (e2->kind_kind == ID_EXPR)
			out << "_" << symtbl.getname(e2->attr.symtbl_seq);
		else if (e2->kind_kind == CONST_EXPR)
			out << e2->attr.vali;
		else out << "t" << e2->temp_var;
		out << endl;
		out << "\tjl " << t->label.true_label << endl;
		out << "\tjmp " << t->label.false_label << endl;
		break;

	case LE:
		out << "\tMOV eax, ";
		if (e1->kind_kind == ID_EXPR)
			out << "_" << symtbl.getname(e1->attr.symtbl_seq);
		else if (e1->kind_kind == CONST_EXPR)
			out << e1->attr.vali;
		else out << "t" << e1->temp_var;
		out << endl;
		out << "\tCMP eax, ";
		if (e2->kind_kind == ID_EXPR)
			out << "_" << symtbl.getname(e2->attr.symtbl_seq);
		else if (e2->kind_kind == CONST_EXPR)
			out << e2->attr.vali;
		else out << "t" << e2->temp_var;
		out << endl;
		out << "\tjle " << t->label.true_label << endl;
		out << "\tjmp " << t->label.false_label << endl;
		break;

	case GT:
		out << "\tMOV eax, ";
		if (e1->kind_kind == ID_EXPR)
			out << "_" << symtbl.getname(e1->attr.symtbl_seq);
		else if (e1->kind_kind == CONST_EXPR)
			out << e1->attr.vali;
		else out << "t" << e1->temp_var;
		out << endl;
		out << "\tCMP eax, ";
		if (e2->kind_kind == ID_EXPR)
			out << "_" << symtbl.getname(e2->attr.symtbl_seq);
		else if (e2->kind_kind == CONST_EXPR)
			out << e2->attr.vali;
		else out << "t" << e2->temp_var;
		out << endl;
		out << "\tjg " << t->label.true_label << endl;
		out << "\tjmp " << t->label.false_label << endl;
		break;

	case GE:
		out << "\tMOV eax, ";
		if (e1->kind_kind == ID_EXPR)
			out << "_" << symtbl.getname(e1->attr.symtbl_seq);
		else if (e1->kind_kind == CONST_EXPR)
			out << e1->attr.vali;
		else out << "t" << e1->temp_var;
		out << endl;
		out << "\tCMP eax, ";
		if (e2->kind_kind == ID_EXPR)
			out << "_" << symtbl.getname(e2->attr.symtbl_seq);
		else if (e2->kind_kind == CONST_EXPR)
			out << e2->attr.vali;
		else out << "t" << e2->temp_var;
		out << endl;
		out << "\tjge " << t->label.true_label << endl;
		out << "\tjmp " << t->label.false_label << endl;
		break;

	case EQ:
		out << "\tMOV eax, ";
		if (e1->kind_kind == ID_EXPR)
			out << "_" << symtbl.getname(e1->attr.symtbl_seq);
		else if (e1->kind_kind == CONST_EXPR)
			out << e1->attr.vali;
		else out << "t" << e1->temp_var;
		out << endl;
		out << "\tCMP eax, ";
		if (e2->kind_kind == ID_EXPR)
			out << "_" << symtbl.getname(e2->attr.symtbl_seq);
		else if (e2->kind_kind == CONST_EXPR)
			out << e2->attr.vali;
		else out << "t" << e2->temp_var;
		out << endl;
		out << "\tje " << t->label.true_label << endl;
		out << "\tjmp " << t->label.false_label << endl;
		break;

	case NE:
		out << "\tMOV eax, ";
		if (e1->kind_kind == ID_EXPR)
			out << "_" << symtbl.getname(e1->attr.symtbl_seq);
		else if (e1->kind_kind == CONST_EXPR)
			out << e1->attr.vali;
		else out << "t" << e1->temp_var;
		out << endl;
		out << "\tCMP eax, ";
		if (e2->kind_kind == ID_EXPR)
			out << "_" << symtbl.getname(e2->attr.symtbl_seq);
		else if (e2->kind_kind == CONST_EXPR)
			out << e2->attr.vali;
		else out << "t" << e2->temp_var;
		out << endl;
		out << "\tjne " << t->label.true_label << endl;
		out << "\tjmp " << t->label.false_label << endl;
		break;

//双目与 或 非
/*

*/
	case AND:
		recursive_gen_code(out, e1);
		out << e1->label.true_label << ": " << endl;
		recursive_gen_code(out, e2);
		break;
	case OR:
		recursive_gen_code(out, e1);
		out << e1->label.false_label << ": " << endl;
		recursive_gen_code(out, e2);
		break;
	case NOT:
		e1->label.true_label = t->label.false_label;
		e1->label.false_label = t->label.true_label;
		recursive_gen_code(out, e1);
		break;

//自增自减符
/*
	自增自减由于只有一个操作码，所以不需要用两个孩子，只需用一个临时的NODE结点，将++a或者a++中的a直接赋予这个临时结点再处理即可
	操作码的值传到eax中->进行操作->eax中的值传回父节点的temp_var（t0）
*/
    case INC:
	{
		Node *temp = new Node;
		if (e1 != NULL)
			temp = e1;
		else
			temp = e2;
		
		out << "\tMOV eax, ";										
		if (temp->kind_kind == ID_EXPR)
			out << "_" << symtbl.getname(temp->attr.symtbl_seq);
		else if (temp->kind_kind == CONST_EXPR)
			out << temp->attr.vali;
		else out << "t" << temp->temp_var;
		out << endl;

		out << "\tINC eax" << endl;

	//	out << "\tMOV t" << t->temp_var << ", eax" << endl;
		out << "\tMOV " ;
		if (temp->kind_kind == ID_EXPR)
			out << "_" << symtbl.getname(temp->attr.symtbl_seq);
		else 
			out << "t" << temp->temp_var;
		out << ", eax " << endl;
		break;
	}
	
	case DEC:
	{
		Node *temp = new Node;
		if (e1 != NULL)
			temp = e1;
		else
			temp = e2;
		
		out << "\tMOV eax, ";										
		if (temp->kind_kind == ID_EXPR)
			out << "_" << symtbl.getname(temp->attr.symtbl_seq);
		else if (temp->kind_kind == CONST_EXPR)
			out << temp->attr.vali;
		else out << "t" << temp->temp_var;
		out << endl;

		out << "\tDEC eax" << endl;

	//	out << "\tMOV t" << t->temp_var << ", eax" << endl;
		out << "\tMOV " ;
		if (temp->kind_kind == ID_EXPR)
			out << "_" << symtbl.getname(temp->attr.symtbl_seq);
		else 
			out << "t" << temp->temp_var;
		out << ", eax " << endl;
		break;
	}
//按位求反 异或 与 或 
/*
同加减是一样的，只不过是换了相应的指令而已
*/		
	
	case BNOT:
		out << "\tMOV eax, ";
		if (e1->kind_kind == ID_EXPR)
			out << "_" << symtbl.getname(e1->attr.symtbl_seq);
		else if (e1->kind_kind == CONST_EXPR)
			out << e1->attr.vali;
		else out << "t" << e1->temp_var;
		out << endl;

		out << "\tNOT eax" <<endl;
	
		out << "\tMOV t" << t->temp_var << ", eax" << endl;
		break;

	case BXOR:
		out << "\tMOV eax, ";
		if (e1->kind_kind == ID_EXPR)
			out << "_" << symtbl.getname(e1->attr.symtbl_seq);
		else if (e1->kind_kind == CONST_EXPR)
			out << e1->attr.vali;
		else out << "t" << e1->temp_var;
		out << endl;

		out << "\tXOR eax, ";
		if (e2->kind_kind == ID_EXPR)
			out << "_" << symtbl.getname(e2->attr.symtbl_seq);
		else if (e2->kind_kind == CONST_EXPR)
			out << e2->attr.vali;
		else out << "t" << e2->temp_var;
		out << endl;

		out << "\tMOV t" << t->temp_var << ", eax" << endl;
		break;

	case BAND:
		out << "\tMOV eax, ";
		if (e1->kind_kind == ID_EXPR)
			out << "_" << symtbl.getname(e1->attr.symtbl_seq);
		else if (e1->kind_kind == CONST_EXPR)
			out << e1->attr.vali;
		else out << "t" << e1->temp_var;
		out << endl;
		
		out << "\tAND eax, ";

		if (e2->kind_kind == ID_EXPR)
			out << "_" << symtbl.getname(e2->attr.symtbl_seq);
		else if (e2->kind_kind == CONST_EXPR)
			out << e2->attr.vali;
		else out << "t" << e2->temp_var;
		out << endl;
	
		out << "\tMOV t" << t->temp_var << ", eax" << endl;
		break;

	case BOR:
		out << "\tMOV eax, ";
		if (e1->kind_kind == ID_EXPR)
			out << "_" << symtbl.getname(e1->attr.symtbl_seq);
		else if (e1->kind_kind == CONST_EXPR)
			out << e1->attr.vali;
		else out << "t" << e1->temp_var;
		out << endl;

		out << "\tOR eax, ";
		if (e2->kind_kind == ID_EXPR)
			out << "_" << symtbl.getname(e2->attr.symtbl_seq);
		else if (e2->kind_kind == CONST_EXPR)
			out << e2->attr.vali;
		else out << "t" << e2->temp_var;
		out << endl;

		out << "\tMOV t" << t->temp_var << ", eax" << endl;
		break;
	
//<< >>
/*
同加减的方法相似，将第一个孩子的值传入eax中，SHR eax 第二个孩子的值, 将产生的结果送还给EXPR_NODE的temp_var(即t0)中实现计算结果的完成。
*/
	case SHR:
		out << "\tMOV eax, ";
		if (e1->kind_kind == ID_EXPR)
			out << "_" << symtbl.getname(e1->attr.symtbl_seq);
		else if (e1->kind_kind == CONST_EXPR)
			out << e1->attr.vali;
		else out << "t" << e1->temp_var;
		out << endl;

		out << "\tSHR eax, ";
		if (e2->kind_kind == ID_EXPR)
			out << "_" << symtbl.getname(e2->attr.symtbl_seq);
		else if (e2->kind_kind == CONST_EXPR)
			out << e2->attr.vali;
		else out << "t" << e2->temp_var;
		out << endl;

		out << "\tMOV t" << t->temp_var << ", eax" << endl;//eax中的结果送还到父节点中的temp_var中，实际上是t0
		break;

	case SHL:
		out << "\tMOV eax, ";
		if (e1->kind_kind == ID_EXPR)
			out << "_" << symtbl.getname(e1->attr.symtbl_seq);
		else if (e1->kind_kind == CONST_EXPR)
			out << e1->attr.vali;
		else out << "t" << e1->temp_var;
		out << endl;

		out << "\tSHL eax, ";
		if (e2->kind_kind == ID_EXPR)
			out << "_" << symtbl.getname(e2->attr.symtbl_seq);
		else if (e2->kind_kind == CONST_EXPR)
			out << e2->attr.vali;
		else out << "t" << e2->temp_var;
		out << endl;

		out << "\tMOV t" << t->temp_var << ", eax" << endl;//eax中的结果送还到父节点中的temp_var中，实际上是t0
		break;
	}
}
//递归调用处理代码段
//代码段的处理分两大部分处理：语句和表达式
void tree::recursive_gen_code(ostream &out, Node *t)
{
	if (t->kind == STMT_NODE)
	{
		stmt_gen_code(out, t);//进入语句的翻译部分
	}
	else if (t->kind == EXPR_NODE && (t->kind_kind == OP_EXPR || t->kind_kind == NOT_EXPR))
	{
		expr_gen_code(out, t);
	}
}
//从根结点出发，为头文件、数据段、代码段的翻译搭建框架
void tree::gen_code(ostream &out)
{
	gen_header(out);//输出必要的汇编头文件
	Node *p = root->children[0];
	if (p->kind == DECL_NODE)//出现变量定义语句，处理数据段
		gen_decl(out, p);
	out << endl << endl << "\t.code" << endl;
	recursive_gen_code(out, root);	//递归调用处理代码段
	if (root->label.next_label != "")
		out << root->label.next_label << ":" << endl;
	out << "\tinvoke ExitProcess, 0" << endl;//打印程序退出语句
	out << "end " << root->label.begin_label << endl;//打印结束标志
}