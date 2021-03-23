//���ű����ͷ�ļ�

#define MAX_ID 1024   //���ű�����������

typedef struct TAG_SYMBOL_ENTRY   //���Ž��
{
	string name;   //������
	int token;     //�ս���ı�ţ�257��ʼ��
	int type;      //��������
} symbol_entry;

class symbol_table   //���ű���
{
private:
	symbol_entry table[MAX_ID];  //�������ű�����
	int size;      //��¼���ű������з��ŵ���Ŀ

public:
	int lookup(string name);   //��ѯ�Ƿ���ڷ��ű���       
	int insert(string name, int token);   //������ű�
	int gettoken(string name);	//��ȡ�ս�����
	string &getname(int pos);	//��ȡ������
	int set_type(int pos, int type);	//��������������
	int get_type(int pos);	//��ȡ���ŵ�����
};
