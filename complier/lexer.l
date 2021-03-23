%{
#include <string>

using namespace std;

#include "common.h"
#include "parser.h"
#include "symbol.h"
#include "tree.h"

extern symbol_table symtbl;

Node dummy;//虚设的结点，用来赋值给yylval，作为lex和yacc的交互，以便设置结点的属性

int lineno = 1;//行号

%}

%name lexer

id 			[a-zA-Z_]+[a-zA-Z0-9_]*
num 		(-?[1-9]+[0-9]*)|(-?[1-9])|0
constchar 	'.'
newline 	\n
whitespace 	[ \t]+

%%

%{

	YYSTYPE YYFAR& yylval = *(YYSTYPE YYFAR*)yyparserptr->yylvalptr;

%}

"int"		{return INT;}
"char"		{return CHAR;}

"if"		{return IF;}
"else"		{return ELSE;}
"while"		{return WHILE;}
"for"		{return FOR;}

"input"		{return INPUT;}
"print"		{return PRINT;}

"main"		{return MAIN;}

"=="		{return EQ;}
"!="		{return NE;}
">="		{return GE;}
"<="		{return LE;}

"||"		{return OR;}
"&&"		{return AND;}
"!"			{return NOT;}
"="			{return ASSIGN;}

"++"		{return INC;}
"--"		{return DEC;}
">>"		{return SHR;}
"<<"		{return SHL;}

"+"			{return PLUS;}
"-"			{return MINUS;}
"*"			{return TIMES;}
"/"			{return OVER;}
"%"			{return REM;}
"&"			{return BAND;}
"|"			{return BOR;}
"^"			{return BXOR;}
"~"			{return BNOT;}
"<"			{return LT;}
">"			{return GT;}

";"			{return SEMICOLON;}
","			{return COMMA;}
"("			{return LPAREN;}
")"			{return RPAREN;}
"{"			{return LBRACE;}
"}"			{return RBRACE;}
"/*"		{
				char c;
				LABEL:
				do
				{
					c = input();
					if(c == '\n')
						lineno++;
				}while(c != '*');//用来检测注释后面的'*',当检测到'*'时跳出循环

				do
				{
					c = input();
					if(c == '/')
						break;
					if(c == '\n')
						lineno++;
					if(c != '*')
						goto LABEL;
				}while(c == '*');//用来检测注释后面的'/',当紧接着'*'的字符不是'/'是，采用goto语句返回到上一个循环，重新检测'*'
			}//假定"/*"的后面一定会出现"*/"
"//"		{
				char c;
				do
				{
					c = input();
					if(c == '\n')
						break;
				}while(c != '\n');
			}//跳过"//"后面的所有的字符,直到遇到换行符'\n'

{id}		{
				int p;
				p = symtbl.lookup(yytext);//在符号表中查找当前识别出来的id，如果id已经存在在符号表中，则返回该id在符号表中的位置，如果id不在符号表中，则返回-1
				if(p == -1)
				{
					p = symtbl.insert(yytext, ID);//如果该id不在符号表中，即p = -1，则将该id+"/n"插入到符号表中(string类型)
				}
				else
				{
					dummy.type = symtbl.get_type(p);//如果该id在符号表中，则根据该id在符号表中的位置来获得该id的类型
				}
				yylval = &dummy;
				yylval->attr.symtbl_seq = p;//yylval结点在符号表中的位置就是该id在符号表中的位置，事实上是为了传递给yacc在创建新的结点的时候使用，以便将此属性赋值给父节点，作为综合属性
				return ID;
			}
{num}		{
				yylval = &dummy;
				yylval->attr.vali = atoi(yytext);//atoi()用来将yytext转换成整数，从而将num真正的值赋予dummy(yylval)结点的vali属性
				return NUM;
			}
{constchar}	{
				yylval = &dummy;
				yylval->attr.valc = yytext[0];//取yytext中的第一个字符，赋值给yylval中的valc属性
				return CONSTCHAR;
			}
{newline}	{
				lineno++;
				#ifdef LEX_DEBUG
					cout<<"lineno:"<<lineno<<endl;
				#endif
			}
{whitespace}	{}//直接跳过
.			{
				#ifdef LEX_DEBUG
					cout<<"error!"<<endl;
				#endif
				return ERROR;
			}//除上面能识别出来的字符串之外，所有未能识别出来的字符串全部以"error!"输出

%%
