//���ű���ش�����

#include <iostream>
#include <string>

using namespace ::std;

#include "symbol.h"
#include "tree.h"

symbol_table symtbl;	//����������������

//��ѯ���ű����Ƿ���ڸ÷���
int symbol_table::lookup(string name)   
{
	for (int i = 0; i < size; i++)  //��ͷ������ֱ����ǰ���һ������
		if (table[i].name == name)  //�����ҵ���Ҫ��ѯ�ķ���
			return i;               //�������ڷ��ű��з�����λ��
	return -1;                      //���򷵻�-1
}

//������ű�
int symbol_table::insert(string name, int token)
{
	if (size >= MAX_ID)
		return -1;
	table[size].name = name;
	table[size].token = token;
	table[size].type = Notype;
	size++;   //���ű��з�����Ŀ��1
	return size - 1;   //���ص�ǰ���һ�����ŵ�λ��
}

//��ȡ�ս�����
int symbol_table::gettoken(string name)
{
	for (int i = 0; i < size; i++)
		if (table[i].name == name)
			return table[i].token;
	return -1;
}

//��ȡ������
string& symbol_table::getname(int pos)
{
	return table[pos].name;
}

//��������������
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

//��ȡ��������
int symbol_table::get_type(int pos)
{
	if (pos < 0 || pos >= size)
	{
		cerr << "Bad identifier" << endl;
		return -1;
	}

	return table[pos].type;
}