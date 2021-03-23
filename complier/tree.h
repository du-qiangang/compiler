/*
	�﷨����صĶ��塣������
	1����������͡�������͡����ʽ���͡�����������͡��������͵ȵ�ö�ٶ��壻
	2��������ԡ���ŵ����ϣ�
	3��������������Ķ��塣
*/

//������͵�ö�ٶ��壨����������͡����ʽ���͡��������ͣ�
enum  
{
	STMT_NODE = 0,
	EXPR_NODE,
	DECL_NODE
};

//������͵�ö�ٶ��壨����if��䡢while��䡢for��䡢���������䡢�Ƚ���䣩
enum	
{
	IF_STMT = 0,
	WHILE_STMT,
	FOR_STMT,					
	INPUT_STMT,
	PRINT_STMT,
	COMP_STMT
};

//���ʽ��ö�ٶ��壨�����߼����ʽ���������ʽ����ϵ���ʽ�����泣���������ȣ�
enum
{
	TYPE_EXPR = 0,
	OP_EXPR,
	NOT_EXPR,
	ARRAY_EXPR,
	CONST_EXPR,
	ID_EXPR
};

//��������ö�����ͣ������������塢���鶨�壩
enum    
{
	VAR_DECL = 0,
	ARRAY_DECL
};

//�������͵�ö�ٶ��壨�������͡������͡��ַ��ͺ������ͣ�
enum
{
	Notype = 0,
	Integer,
	Boolean,
	Char
};

//���������Ե�����
union NodeAttr {
	int op; //���Ϊ���ʽ������Ϊ���ʽ����
	int vali;  //���Ϊ���ͻ��ַ��ͳ���������Ϊ������ֵ
	char valc;
	int symtbl_seq;   //���ΪID��������Ϊ��ID�ڷ��ű��е�λ��
	
	NodeAttr(void) { op = 0; }
	NodeAttr(int i)	{ op = i; }
	NodeAttr(char c) { valc = c; }
};

//�����ŵ�
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

#define MAX_CHILDREN 4  //��������ӽ����

//����㶨��
struct Node
{
	struct Node *children[MAX_CHILDREN];  //���ӽ������
	struct Node *sibling;  //���ֵܽ��
	int lineno;   //��¼Դ���к�
	int kind;     //�������
	int kind_kind;   //������͵������ͣ������ֻ���������͵Ľ�һ�����ࣩ
	NodeAttr attr;   //�������
	int type;     //ID�����泣������
	int seq;    //�����
	int temp_var;  //��ʱ����
	Label label;  //���
	
	void output(void);  //����ӡ
};

//�����ඨ��
class tree
{
private:
	Node *root;  //���ĸ����
	static int node_seq;  //�����
	static int temp_var_seq; //��ʱ�������
	static int label_seq;  //��ű��

private:
	void type_check(Node *t); //���������
	void get_temp_var(Node *t);  //������ʱ�������
	string new_label(void);  //�����µı��
	void recursive_get_label(Node *t);  //�ݹ�������ɱ��
	void stmt_get_label(Node *t);  //��������ɱ��
	void expr_get_label(Node *t);  //�������������ʽ���ɱ��
	void gen_header(ostream &out);  //��ӡͷ�ļ�
	void gen_decl(ostream &out, Node *t); //�������ݶΣ����Ŷ�����䣩
	void recursive_gen_code(ostream &out, Node *t); //�ݹ鴦������
	void stmt_gen_code(ostream &out, Node *t); //�������
	void expr_gen_code(ostream &out, Node *t); //������ʽ
	

public:
	Node *NewRoot(int kind, int kind_kind, NodeAttr attr, int type,  //�����µĽ�㣬�����г�ʼ���ʹ�ӡ
		Node *child1 = NULL, Node *child2 = NULL, Node *child3 = NULL, Node *child4 = NULL);
	void get_label(void);  //������ñ�ŵ��ú���
	void gen_code(ostream &out); //Ŀ��������������ú���
	//~tree();
};