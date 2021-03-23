//符号表相关处理函数

#include <iostream>
#include <string>

using namespace ::std;

#include "symbol.h"
#include "tree.h"

symbol_table symtbl;	//给符号类声明对象

//查询符号表中是否存在该符号
int symbol_table::lookup(string name)   
{
	for (int i = 0; i < size; i++)  //从头遍历，直到当前最后一个符号
		if (table[i].name == name)  //或者找到需要查询的符号
			return i;               //若符号在符号表中返回其位置
	return -1;                      //否则返回-1
}

//插入符号表
int symbol_table::insert(string name, int token)
{
	if (size >= MAX_ID)
		return -1;
	table[size].name = name;
	table[size].token = token;
	table[size].type = Notype;
	size++;   //符号表中符号数目加1
	return size - 1;   //返回当前最后一个符号的位置
}

//获取终结符编号
int symbol_table::gettoken(string name)
{
	for (int i = 0; i < size; i++)
		if (table[i].name == name)
			return table[i].token;
	return -1;
}

//获取符号名
string& symbol_table::getname(int pos)
{
	return table[pos].name;
}

//给符号设置类型
int symbol_table::set_type(int pos, int type)
{
	if (pos < 0 || pos >= size)
	{
		cerr << "Bad identifier" << endl;
		return -1;
	}

	table[pos].type = type;
	return 0;
}

//获取符号类型
int symbol_table::get_type(int pos)
{
	if (pos < 0 || pos >= size)
	{
		cerr << "Bad identifier" << endl;
		return -1;
	}

	return table[pos].type;
}