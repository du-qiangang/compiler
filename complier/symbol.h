//符号表相关头文件

#define MAX_ID 1024   //符号表中最大符号数

typedef struct TAG_SYMBOL_ENTRY   //符号结点
{
	string name;   //符号名
	int token;     //终结符的编号（257开始）
	int type;      //符号类型
} symbol_entry;

class symbol_table   //符号表类
{
private:
	symbol_entry table[MAX_ID];  //声明符号表数组
	int size;      //记录符号表中已有符号的数目

public:
	int lookup(string name);   //查询是否存在符号表中       
	int insert(string name, int token);   //插入符号表
	int gettoken(string name);	//获取终结符标号
	string &getname(int pos);	//获取符号名
	int set_type(int pos, int type);	//给符号设置类型
	int get_type(int pos);	//获取符号的类型
};
