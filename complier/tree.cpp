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

void Node::output(void)//��NewRoot()���ô�ӡ�����ڵ�
{
	cout.setf(ios_base::left);//��������ĸ�ʽ
	cout.width(2);
	cout << seq << ": ";
	switch(kind)//����kind��ȷ��STMT_NODE����EXPR_NODE
	{
	case STMT_NODE:
		{
			string names[] = {"if", "while","for", "input", "print", "compound"};
			cout.width(40);
			cout << names[kind_kind] + " statement,";//����kind_kind��ȷ��STMT_NODE��IF WHILE FOR INPUT PRINT COMPOUND....
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
			cout << types[type] + ',';//����EXPR_NODE��type��ȷ�����ʽ������
			cout.width(10);
			switch (kind_kind)//���ݱ��ʽ�ĸ���������������ڵ�ĸ�����Ϣ���������ڵ�����ƺ͸��ڵ��ֵ��ͨ�����ʽ��������ģ���Ҫ������temp_var�ϣ�
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
//���ϵĴ���������������ڵ����Ϣ��֮��Ĵ���������������ڵ���ֵܽڵ�ͺ��ӽ�����Ϣ�ģ��������ӽ��ı�ź��ֵܽڵ�ı��
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
		if (t->kind_kind == IF_STMT || t->kind_kind == WHILE_STMT)//����IF��WHILE��˵�����ǵĵ�һ����Ҳ��Ψһһ�����������ͱ�����BOOL�ͣ������Ҫ����
			if (t->children[0]->type != Boolean)
			{
				cerr << "Bad boolean type at line: " << t->lineno << endl;
				exit(1);
			}
			else
				return;
		if (t->kind_kind == FOR_STMT)//����FOR�����˵�����ĵڶ������ӱ�����BOOL�ͣ����ж���䣩�����򱨴�											
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
//���ڲ���EXPR_NODE���͵Ľ�����Ȼ��EXPR_NODE���������͵������Ͳ��ǲ��������ʽ�ͷ��ű��ʽ�ı��ʽ������Ҫ�����ͼ��
	Node *arg1 = t->children[0];
	Node *arg2 = t->children[1];
	if (t->attr.op == NOT)//���ڲ��������ʽ��˵�������OP����ΪNOT�ģ�����ΪBOOL
	{
		if (arg1->type != Boolean)
		{
			cerr << "Bad type at line: " << t->lineno << endl;
			exit(1);
		}
		t->type = arg1->type;
	}
	else if (t->attr.op == AND || t->attr.op == OR)//���ڲ��������ʽ��˵�������OP����ΪAND��OR�ģ�����ΪBOOL
	{
		if (arg1->type != Boolean || arg2->type != Boolean)
		{
			cerr << "Bad type at line: " << t->lineno << endl;
			exit(1);
		}
		t->type = arg1->type;
	}
	else if (t->attr.op >= EQ && t->attr.op <= LE || t->attr.op == LT || t->attr.op == GT)//����OP����ΪEQ LE LT GT��˵���������ӵ����ͱ���Ϊ����
	{
		if (arg1->type != Integer || arg2->type != Integer)
		{
			cerr << "Bad type at line: " << t->lineno << endl;
			exit(1);
		}
		t->type = Boolean;
	}
	else if (t->attr.op >= SHR && t->attr.op <= BXOR || t->attr.op == ASSIGN)//�������Ƶ�����������������������	
	{
		
		if (arg1->type != Integer || arg2->type != Integer)
		{
			cerr << "Bad type at line: " << t->lineno << endl;
			exit(1);
		}
		t->type = arg1->type;
	}
	else if (t->attr.op == INC || t->attr.op == DEC || t->attr.op == BNOT)//�����Լ��Ͱ�λ���ĺ��ӱ��������Σ�ͬʱҪע��ֻ��һ��������������Ҫʹ��temp	
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

void tree::get_temp_var(Node *t)//ֻ�в��������ʽ������˫Ŀ�з���ֵ�Ĳ��������ʽ�����Ǹ��ڵ���temp_var������û���������Եı��ʽ����䶼�Թ�
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
		t->seq = tree::node_seq++;//ȫ�ֽ����
		t->sibling = NULL;
		t->label.begin_label = "";
		t->label.next_label = "";
		t->label.true_label = "";
		t->label.false_label = "";
		root = t;
		type_check(t);
		get_temp_var(t);

#ifdef PARSE_DEBUG
		t->output();//����output()ֱ���ڿ���̨��������ǽ���һ���µĽ��ʹ�ӡ����
#endif
	}
	return t;
}
//=============================================
/************�����µı��**************/
//=============================================
string tree::new_label(void)
{
	char tmp[20];
//���������@i����ֵ��tmp����������
	sprintf_s(tmp, "@%d", tree::label_seq);//�ִ���ʽ������Ѹ�ʽ��������д��ĳ�ַ����У�tmp��
	tree::label_seq++;
	return tmp;
}
//=========================================
/***********����������ñ��**************/
//=========================================
void tree::stmt_get_label(Node *t)
{
	switch (t->kind_kind)//���ݲ�ͬ�������д���
	{
	case COMP_STMT:
		{
			Node *last;
			Node *p;
			for (p = t->children[0]; p->kind == DECL_NODE; p = p->sibling) ;//����Ǳ����������
			//��һ���Ǳ����������ĺ��ӽ���begin_label��Ϊ������begin_label
			p->label.begin_label = t->label.begin_label;
			for (; p; p = p->sibling)//�������ֵܽ��
			{
				last = p;
				recursive_get_label(p);
			}

			t->label.next_label = last->label.next_label;//���һ�����ֵܽ�㼴Ϊ������next_label
			//�������������ֵܽ�㣬��ô�ý���begin_label��Ϊ������next_label
			if (t->sibling)
				t->sibling->label.begin_label = t->label.next_label;
		}
		break;
//if������������ӽ�㣬�ֱ�Ϊ�ж���䡢��ִֵ����䡢��ִֵ�����
	case IF_STMT:
		{
			Node *e = t->children[0];
			Node *s1 = t->children[1];
			Node *s2 = t->children[2];

			e->label.true_label = new_label();//����ֵ�ж�������ɱ��

			if (t->label.next_label == "")//���������next_labelΪ�գ������µı��
				t->label.next_label = new_label();
			s1->label.next_label = t->label.next_label; //��һ�����ӽ���next_labelΪ������next_label
			if (t->sibling)//�����������ֵܽ�㣨������ڣ�
				t->sibling->label.begin_label = t->label.next_label;
//�������else��䣬��ֵ�ж�������ɱ�ţ�next_label �͸������ͬ
			if (s2)
			{
				e->label.false_label = new_label();
				s2->label.next_label = t->label.next_label;
			}
			else //���������else��䣬��ֵ�ж����false_label��Ϊ������next_label
			{
				e->label.false_label = t->label.next_label;
			}
			//�ݹ鴦���ӽ��
			recursive_get_label(e);
			recursive_get_label(s1);
			if (s2)
				recursive_get_label(s2);
		}
		break;
//while������������ӽ�㣬�ֱ�Ϊ�ж�����ѭ�������
	case WHILE_STMT:
		{
			Node *e = t->children[0];
			Node *s = t->children[1];

			if (t->label.begin_label == "")	//��������begin_label�����µı��
				t->label.begin_label = new_label();
			s->label.next_label = t->label.begin_label;//ѭ��������next_label��Ϊ������begin_label

			s->label.begin_label = new_label();//��ѭ��������begin_label�����µı��
			e->label.true_label = s->label.begin_label; //�ж�����true_label��Ϊѭ��������begin_label

			if (t->label.next_label == "")//��������next_label���ɱ��
				t->label.next_label = new_label();
			e->label.false_label = t->label.next_label;//�ж�����false_label��Ϊ������next_label
			if (t->sibling)//�������������ֵ�һ��㣬����begin_label��Ϊ������next_label
				t->sibling->label.begin_label = t->label.next_label;
//�ݹ鴦���ӽ��
			recursive_get_label(e);
			recursive_get_label(s);
			
		}
		break;
//for������ĸ����ӽ�㣬�ֱ�Ϊ��ֵ��䡢�ж���䡢ѭ����������ѭ�������
	case FOR_STMT:												
		{
			Node *e0 = t->children[0];
			Node *e1 = t->children[1];
			Node *e2 = t->children[2];
			Node *s = t->children[3];
			//Ϊ��ֵ����next_label��ѭ����������begin_label��ѭ�����begin_label���ɱ��
	
			e0->label.next_label = new_label();					//@0
				
			e2->label.begin_label = new_label();				//@1
			s->label.begin_label = new_label();					//@2
			//���������next_labelΪ�գ����ɱ��
			if(t->label.next_label == "")
				t->label.next_label = new_label();				//@3
			//�������������ֵܽ�㣬����begin_labelΪ������next_label
			if(t->sibling)
				t->sibling->label.begin_label = t->label.next_label;

			e1->label.true_label = s->label.begin_label;//�ж�����true_label��ѭ�����begin_label			
			e1->label.false_label = t->label.next_label;//�ж�����false_label�Ǹ�����next_label

			//�ݹ鴦���ӽ��
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
/***********���������ʽ���ñ��**************/
//=============================================

void tree::expr_get_label(Node *t)
{
	if (t->type != Boolean) //������ʽ���Ͳ�Ϊ�����ͣ�ֱ���˳�
		return;
//����������ı�ź�true_label��false_label
#ifdef PARSE_DEBUG
	cout << "node " << t->seq << ": "<< t->label.true_label << ", " << t->label.false_label << endl;
#endif
	Node *e1 = t->children[0];
	Node *e2 = t->children[1];
	switch (t->attr.op)
	{
	case AND://������
		e1->label.true_label = new_label();	//����һ�����ӽ���true_label�����µı�ţ����Ϊȫ�ֱ���tree::label_seq��
		e2->label.true_label = t->label.true_label;//�ڶ������ӽ���true_label��ֵΪ������true_label
		//�������������ӽ���false_label��ͬ
		e1->label.false_label = e2->label.false_label = t->label.false_label;
		break;

	case OR://������
		e1->label.false_label = new_label(); //��һ�����ӽ���false_label�����µı��
		e2->label.false_label = t->label.false_label;//�ڶ������ӵ�false_label�븸�����ͬ
		//�������������ӽ���true_label��ͬ
		e1->label.true_label = e2->label.true_label = t->label.true_label;
		break;

	case NOT://������
	//���ӽ�������븸������������෴�����Զ��ߵ�true_label��false_labelҲ�෴
		e1->label.true_label = t->label.false_label;
		e1->label.false_label = t->label.true_label;
		break;
	}
	//e1��e2Ҳ�ǲ������ʽ�����Լ����ݹ鴦��
	if (e1)
		recursive_get_label(e1);
	if (e2)
		recursive_get_label(e2);
}
//=====================================================
/***********�����ͱ��ʽ���������ñ��**************/
//=====================================================
void tree::recursive_get_label(Node *t)
{
	if (t->kind == STMT_NODE)
		stmt_get_label(t);
	else if (t->kind == EXPR_NODE)
		expr_get_label(t);
}
//=========================================
/***********���û�������**************/
//=========================================
void tree::get_label(void)
{
	Node *p = root;

	p->label.begin_label = "_start";
	recursive_get_label(p);
}
//=========================================
/***********��ӡ��Ҫ��ͷ�ļ�**************/
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
/***********���ݶΣ�����������䣩�Ĵ���**************/
//=====================================================
void tree::gen_decl(ostream &out, Node *t)
{
	out << endl << endl << "\t.data" << endl; //������ݶα��
	
	for (; t->kind == DECL_NODE; t = t->sibling) //��ӡ����ID����
	{
		for (Node *p = t->children[1]; p; p = p->sibling)
			if (p->type == Integer)
				out << "\t\t_" << symtbl.getname(p->attr.symtbl_seq) << " DWORD 0" << endl;
			else if (p->type == Char)
				out << "\t\t_" << symtbl.getname(p->attr.symtbl_seq) << " BYTE 0" << endl;
	}
	
	for (int i = 0; i < temp_var_seq; i++) //������ʱ����
	{
		out << "\t\tt" <<  i << " DWORD 0" << endl;
	}

	out << "\t\tbuffer BYTE 128 dup(0)" << endl;
	out << "\t\tLF BYTE 13, 10, 0" << endl;
}
//=======================================
/***********��䲿�ֵķ���**************/
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
	if�����2�����ӽ�㣺��һ�����ӽ��Ϊ�ж���䣬�ڶ������ӽ��Ϊ�������ִ����䣨��true_label��
	������е��������ӽ�㣬��Ϊ�����ж�Ϊ�ٵ�ִ����䣨��Ϊfalse_label��
*/

	else if (t->kind_kind == IF_STMT)														
	{
		if (t->label.begin_label != "")//����п�ʼ��ţ����ȴ�ӡ����
			out << t->label.begin_label << ":" << endl;
		//�ݹ����recursive_gen_code()�����ӽ��
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
		out << t->label.next_label << ": " <<endl;//����if���������
	}
/****************while-statement**************/
/*
	while������������ӽ�㣬�ֱ�Ϊ�жϱ��ʽ��ѭ���塣�ݹ����recursive_gen_code()�������������
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
	for������ĸ����ӽ�㣬����ִ�е�һ�����ӽ�㣨��ֵ��䣩��Ȼ�������һ�����ӽ���next_label��
	�ݹ鴦��ڶ������ӽ�㣨�ж���䣩����ӡ���������ӽ�㣨�ж����仯��䣩�Ŀ�ʼ��ţ��ݹ鴦����������ӽ�㣻
	��ת����һ�����ӽ���next_label(�ж����)��ִ��ѭ���壬��ת�����������ӽ��Ŀ�ʼ��ţ��ж����仯��䣩��
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

void tree::expr_gen_code(ostream &out, Node *t)//�����˵�Ŀ��˫Ŀ����������һ��EXPR_NODE����������
{
	Node *e1 = t->children[0];//��������ߵı���var
	Node *e2 = t->children[1];//�������ұߵı��ʽOR����var
	switch (t->attr.op)//����EXPR_NODE��������attr.op�������������Ĳ���
	{
	case ASSIGN://��ֵ���ʽASSIGN
		if (t->label.begin_label != "")
			out << t->label.begin_label << ":" << endl;//�����EXPR_NODE�����begin_labelʱ��ӡ�����򲻴�ӡ
		recursive_gen_code(out, e1);//�ݹ���ã�����EXPR_NODE�ĵ�һ�����ӽ�㣨�п�����Ϊ����stmt��expr����ִ���κ���䣩
		recursive_gen_code(out, e2);//�ݹ���ã�����EXPR_NODE�ĵڶ������ӽ�㣨�п�����Ϊ����stmt��expr����ִ���κ���䣩
		out << "\tMOV eax, ";
		if (e2->kind_kind == ID_EXPR)
			out << "_" << symtbl.getname(e2->attr.symtbl_seq);//����ڶ���������ID�Ļ�����ô���ݵڶ������ӵķ��ű�λ�����Դӷ��ű��л�ȡ�ú��ӵ����֣��������MOV eax, _�ĺ��棬�γ�MOV eax, _�ڶ������ӵ�����;
		else if (e2->kind_kind == CONST_EXPR)
			out << e2->attr.vali;//����ڶ��������ǳ����Ļ����͸��ݵڶ������ӵ�����ֱֵ�������MOV eax,�ĺ���
		else out << "t" << e2->temp_var;//��������ʱ������Ϊ��ʱ��ֵ���γ�MOV eax, t123.....
		out << endl;
		out << "\tMOV ";
		if (e1->kind_kind == ID_EXPR)
			out << "_" << symtbl.getname(e1->attr.symtbl_seq);
		else out << "t" << e1->temp_var;
		out << ", eax" << endl;//������������ǽ��ӵڶ��������еõ���ֵ��ֵ����һ�������У�ͬ��Ҳ���жϵ�һ��������ID/������������
		break;
//+ - * / %���ʽ
/*
�Ӽ��˳���ȡ��Ĳ�����ʽ�������ƣ�ֻ���ڳ�����ȡ���ʱ�����ڳ�����ȡ��ָ��������ԣ�����Ҫ������Ĵ�������EAX�У�������EDX��
*/
	case PLUS:
		out << "\tMOV eax, ";
		if (e1->kind_kind == ID_EXPR)
			out << "_" << symtbl.getname(e1->attr.symtbl_seq);
		else if (e1->kind_kind == CONST_EXPR)
			out << e1->attr.vali;
		else out << "t" << e1->temp_var;//ͬ��ֵ���ʽһ��MOV eax, _/t/ +��һ�����ӵ�����
		out << endl;
		out << "\tADD eax, ";//ADD�ӷ�������Բ�����
		if (e2->kind_kind == ID_EXPR)
			out << "_" << symtbl.getname(e2->attr.symtbl_seq);
		else if (e2->kind_kind == CONST_EXPR)
			out << e2->attr.vali;
		else out << "t" << e2->temp_var;//ADD eax,  _/t/ +�ڶ������ӵ�����,�Ӷ�ADD�Ľ��������eax��
		out << endl;
		out << "\tMOV t" << t->temp_var << ", eax" << endl;//MOV t+EXPR_NODE��temp_var����, eax����EXPR_NODE������eax�е�ֵ���ӷ������
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
		else out << "t" << e1->temp_var;//��һ�����Ӵ�ֵ��eax
		out << endl;

		out << "\tcdq" << endl;//��EDX������λ�����EAX���λ��ֵ
		
		out << "\tMOV ecx, ";
		if (e2->kind_kind == ID_EXPR)
			out << "_" << symtbl.getname(e2->attr.symtbl_seq);
		else if (e2->kind_kind == CONST_EXPR)
			out << e2->attr.vali;
		else out << "t" << e2->temp_var;//�ڶ������Ӵ�ֵ��ecx
		out << endl; 

		out << "\tIDIV ecx" << endl;//IDIV ecx,EAX����ECX,�̷���EAX,������EDX �����ŵĶ�����������
		
		out << "\tMOV t" << t->temp_var << ", eax" << endl;//�̷���EXPR_NODE����temp_var��
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
		
		out << "\tMOV t" << t->temp_var << ", edx" << endl;//ͬ�������ƣ�ֻ�������Ľ����edx���뵽EXPR_NODE��temp_var��
		break;
//< > <= >= == != 
/*
��Щ���������˾���Ĳ���ָ�ͬ�����Ķ���ͬ�����綼�ǽ���һ�����Ӵ�ֵ��EAX��ִ�в���ָ�� eax, �ڶ������ӵ�ֵ����������������ţ�Ϊ��ı�ź�Ϊ�ٵı�ţ��Ӷ�������еĲ���
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

//˫Ŀ�� �� ��
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

//�����Լ���
/*
	�����Լ�����ֻ��һ�������룬���Բ���Ҫ���������ӣ�ֻ����һ����ʱ��NODE��㣬��++a����a++�е�aֱ�Ӹ��������ʱ����ٴ�����
	�������ֵ����eax��->���в���->eax�е�ֵ���ظ��ڵ��temp_var��t0��
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
//��λ�� ��� �� �� 
/*
ͬ�Ӽ���һ���ģ�ֻ�����ǻ�����Ӧ��ָ�����
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
ͬ�Ӽ��ķ������ƣ�����һ�����ӵ�ֵ����eax�У�SHR eax �ڶ������ӵ�ֵ, �������Ľ���ͻ���EXPR_NODE��temp_var(��t0)��ʵ�ּ���������ɡ�
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

		out << "\tMOV t" << t->temp_var << ", eax" << endl;//eax�еĽ���ͻ������ڵ��е�temp_var�У�ʵ������t0
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

		out << "\tMOV t" << t->temp_var << ", eax" << endl;//eax�еĽ���ͻ������ڵ��е�temp_var�У�ʵ������t0
		break;
	}
}
//�ݹ���ô�������
//����εĴ�������󲿷ִ������ͱ��ʽ
void tree::recursive_gen_code(ostream &out, Node *t)
{
	if (t->kind == STMT_NODE)
	{
		stmt_gen_code(out, t);//�������ķ��벿��
	}
	else if (t->kind == EXPR_NODE && (t->kind_kind == OP_EXPR || t->kind_kind == NOT_EXPR))
	{
		expr_gen_code(out, t);
	}
}
//�Ӹ���������Ϊͷ�ļ������ݶΡ�����εķ������
void tree::gen_code(ostream &out)
{
	gen_header(out);//�����Ҫ�Ļ��ͷ�ļ�
	Node *p = root->children[0];
	if (p->kind == DECL_NODE)//���ֱ���������䣬�������ݶ�
		gen_decl(out, p);
	out << endl << endl << "\t.code" << endl;
	recursive_gen_code(out, root);	//�ݹ���ô�������
	if (root->label.next_label != "")
		out << root->label.next_label << ":" << endl;
	out << "\tinvoke ExitProcess, 0" << endl;//��ӡ�����˳����
	out << "end " << root->label.begin_label << endl;//��ӡ������־
}