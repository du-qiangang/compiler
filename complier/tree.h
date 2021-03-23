/*
	语法树相关的定义。包括：
	1、树结点类型、语句类型、表达式类型、定义语句类型、变量类型等的枚举定义；
	2、结点属性、标号的联合；
	3、树结点和树的类的定义。
*/

//结点类型的枚举定义（包括语句类型、表达式类型、定义类型）
enum  
{
	STMT_NODE = 0,
	EXPR_NODE,
	DECL_NODE
};

//语句类型的枚举定义（包括if语句、while语句、for语句、输入输出语句、比较语句）
enum	
{
	IF_STMT = 0,
	WHILE_STMT,
	FOR_STMT,					
	INPUT_STMT,
	PRINT_STMT,
	COMP_STMT
};

//表达式的枚举定义（包括逻辑表达式、算术表达式、关系表达式、字面常量、变量等）
enum
{
	TYPE_EXPR = 0,
	OP_EXPR,
	NOT_EXPR,
	ARRAY_EXPR,
	CONST_EXPR,
	ID_EXPR
};

//定义语句的枚举类型（包括变量定义、数组定义）
enum    
{
	VAR_DECL = 0,
	ARRAY_DECL
};

//基本类型的枚举定义（包括整型、布尔型、字符型和无类型）
enum
{
	Notype = 0,
	Integer,
	Boolean,
	Char
};

//定义结点属性的联合
union NodeAttr {
	int op; //结点为表达式则属性为表达式类型
	int vali;  //结点为整型或字符型常量则属性为本身常量值
	char valc;
	int symtbl_seq;   //结点为ID，属性则为该ID在符号表中的位置
	
	NodeAttr(void) { op = 0; }
	NodeAttr(int i)	{ op = i; }
	NodeAttr(char c) { valc = c; }
};

//定义标号的
union Label {
	struct {
		string true_label;
		string false_label;
	};
	struct {
		string begin_label;
		string next_label;
	};
	Label(void) {
		
	};
	~Label() {};
};

#define MAX_CHILDREN 4  //定义最大孩子结点树

//树结点定义
struct Node
{
	struct Node *children[MAX_CHILDREN];  //孩子结点数组
	struct Node *sibling;  //右兄弟结点
	int lineno;   //记录源码行号
	int kind;     //结点类型
	int kind_kind;   //结点类型的子类型（对三种基本结点类型的进一步分类）
	NodeAttr attr;   //结点属性
	int type;     //ID和字面常量类型
	int seq;    //结点编号
	int temp_var;  //临时变量
	Label label;  //标号
	
	void output(void);  //结点打印
};

//树的类定义
class tree
{
private:
	Node *root;  //树的根结点
	static int node_seq;  //结点编号
	static int temp_var_seq; //临时变量编号
	static int label_seq;  //标号编号

private:
	void type_check(Node *t); //检查结点类型
	void get_temp_var(Node *t);  //设置临时变量编号
	string new_label(void);  //生成新的标号
	void recursive_get_label(Node *t);  //递归调用生成标号
	void stmt_get_label(Node *t);  //给语句生成标号
	void expr_get_label(Node *t);  //给（布尔）表达式生成标号
	void gen_header(ostream &out);  //打印头文件
	void gen_decl(ostream &out, Node *t); //处理数据段（符号定义语句）
	void recursive_gen_code(ostream &out, Node *t); //递归处理代码段
	void stmt_gen_code(ostream &out, Node *t); //翻译语句
	void expr_gen_code(ostream &out, Node *t); //翻译表达式
	

public:
	Node *NewRoot(int kind, int kind_kind, NodeAttr attr, int type,  //生成新的结点，并进行初始化和打印
		Node *child1 = NULL, Node *child2 = NULL, Node *child3 = NULL, Node *child4 = NULL);
	void get_label(void);  //外层设置标号调用函数
	void gen_code(ostream &out); //目标代码生成外层调用函数
	//~tree();
};