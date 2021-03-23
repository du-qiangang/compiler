/****************************************************************************
*                     U N R E G I S T E R E D   C O P Y
* 
* You are on day 82 of your 30 day trial period.
* 
* This file was produced by an UNREGISTERED COPY of Parser Generator. It is
* for evaluation purposes only. If you continue to use Parser Generator 30
* days after installation then you are required to purchase a license. For
* more information see the online help or go to the Bumble-Bee Software
* homepage at:
* 
* http://www.bumblebeesoftware.com
* 
* This notice must remain present in the file. It cannot be removed.
****************************************************************************/

/****************************************************************************
* lexer.cpp
* C++ source file generated from lexer.l.
* 
* Date: 12/17/13
* Time: 23:46:19
* 
* ALex Version: 2.07
****************************************************************************/

#include <yyclex.h>

// namespaces
#ifdef YYSTDCPPLIB
using namespace std;
#endif
#ifdef YYNAMESPACE
using namespace yl;
#endif

#line 1 ".\\lexer.l"

#include <string>

using namespace std;

#include "common.h"
#include "parser.h"
#include "symbol.h"
#include "tree.h"

extern symbol_table symtbl;

Node dummy;//虚设的结点，用来赋值给yylval，作为lex和yacc的交互，以便设置结点的属性

int lineno = 1;//行号


#line 56 "lexer.cpp"
// repeated because of possible precompiled header
#include <yyclex.h>

// namespaces
#ifdef YYSTDCPPLIB
using namespace std;
#endif
#ifdef YYNAMESPACE
using namespace yl;
#endif

#include ".\lexer.h"

/////////////////////////////////////////////////////////////////////////////
// constructor

YYLEXERNAME::YYLEXERNAME()
{
	yytables();
}

/////////////////////////////////////////////////////////////////////////////
// destructor

YYLEXERNAME::~YYLEXERNAME()
{
}

#ifndef YYTEXT_SIZE
#define YYTEXT_SIZE 100
#endif
#ifndef YYUNPUT_SIZE
#define YYUNPUT_SIZE YYTEXT_SIZE
#endif
#ifndef YYTEXT_MAX
#define YYTEXT_MAX 0
#endif
#ifndef YYUNPUT_MAX
#define YYUNPUT_MAX YYTEXT_MAX
#endif

/****************************************************************************
* N O T E
* 
* If the compiler generates a YYLEXERNAME error then you have not declared
* the name of the lexical analyser. The easiest way to do this is to use a
* name declaration. This is placed in the declarations section of your Lex
* source file and is introduced with the %name keyword. For instance, the
* following name declaration declares the lexer mylexer:
* 
* %name mylexer
* 
* For more information see help.
****************************************************************************/

// backwards compatability with lex
#ifdef input
int YYLEXERNAME::yyinput()
{
	return input();
}
#else
#define input yyinput
#endif

#ifdef output
void YYLEXERNAME::yyoutput(int ch)
{
	output(ch);
}
#else
#define output yyoutput
#endif

#ifdef unput
void YYLEXERNAME::yyunput(int ch)
{
	unput(ch);
}
#else
#define unput yyunput
#endif

#ifndef YYNBORLANDWARN
#ifdef __BORLANDC__
#pragma warn -rch		// <warning: unreachable code> off
#endif
#endif

int YYLEXERNAME::yyaction(int action)
{
#line 29 ".\\lexer.l"


	YYSTYPE YYFAR& yylval = *(YYSTYPE YYFAR*)yyparserptr->yylvalptr;


#line 154 "lexer.cpp"
	yyreturnflg = yytrue;
	switch (action) {
	case 1:
		{
#line 35 ".\\lexer.l"
return INT;
#line 161 "lexer.cpp"
		}
		break;
	case 2:
		{
#line 36 ".\\lexer.l"
return CHAR;
#line 168 "lexer.cpp"
		}
		break;
	case 3:
		{
#line 38 ".\\lexer.l"
return IF;
#line 175 "lexer.cpp"
		}
		break;
	case 4:
		{
#line 39 ".\\lexer.l"
return ELSE;
#line 182 "lexer.cpp"
		}
		break;
	case 5:
		{
#line 40 ".\\lexer.l"
return WHILE;
#line 189 "lexer.cpp"
		}
		break;
	case 6:
		{
#line 41 ".\\lexer.l"
return FOR;
#line 196 "lexer.cpp"
		}
		break;
	case 7:
		{
#line 43 ".\\lexer.l"
return INPUT;
#line 203 "lexer.cpp"
		}
		break;
	case 8:
		{
#line 44 ".\\lexer.l"
return PRINT;
#line 210 "lexer.cpp"
		}
		break;
	case 9:
		{
#line 46 ".\\lexer.l"
return MAIN;
#line 217 "lexer.cpp"
		}
		break;
	case 10:
		{
#line 48 ".\\lexer.l"
return EQ;
#line 224 "lexer.cpp"
		}
		break;
	case 11:
		{
#line 49 ".\\lexer.l"
return NE;
#line 231 "lexer.cpp"
		}
		break;
	case 12:
		{
#line 50 ".\\lexer.l"
return GE;
#line 238 "lexer.cpp"
		}
		break;
	case 13:
		{
#line 51 ".\\lexer.l"
return LE;
#line 245 "lexer.cpp"
		}
		break;
	case 14:
		{
#line 53 ".\\lexer.l"
return OR;
#line 252 "lexer.cpp"
		}
		break;
	case 15:
		{
#line 54 ".\\lexer.l"
return AND;
#line 259 "lexer.cpp"
		}
		break;
	case 16:
		{
#line 55 ".\\lexer.l"
return NOT;
#line 266 "lexer.cpp"
		}
		break;
	case 17:
		{
#line 56 ".\\lexer.l"
return ASSIGN;
#line 273 "lexer.cpp"
		}
		break;
	case 18:
		{
#line 58 ".\\lexer.l"
return INC;
#line 280 "lexer.cpp"
		}
		break;
	case 19:
		{
#line 59 ".\\lexer.l"
return DEC;
#line 287 "lexer.cpp"
		}
		break;
	case 20:
		{
#line 60 ".\\lexer.l"
return SHR;
#line 294 "lexer.cpp"
		}
		break;
	case 21:
		{
#line 61 ".\\lexer.l"
return SHL;
#line 301 "lexer.cpp"
		}
		break;
	case 22:
		{
#line 63 ".\\lexer.l"
return PLUS;
#line 308 "lexer.cpp"
		}
		break;
	case 23:
		{
#line 64 ".\\lexer.l"
return MINUS;
#line 315 "lexer.cpp"
		}
		break;
	case 24:
		{
#line 65 ".\\lexer.l"
return TIMES;
#line 322 "lexer.cpp"
		}
		break;
	case 25:
		{
#line 66 ".\\lexer.l"
return OVER;
#line 329 "lexer.cpp"
		}
		break;
	case 26:
		{
#line 67 ".\\lexer.l"
return REM;
#line 336 "lexer.cpp"
		}
		break;
	case 27:
		{
#line 68 ".\\lexer.l"
return BAND;
#line 343 "lexer.cpp"
		}
		break;
	case 28:
		{
#line 69 ".\\lexer.l"
return BOR;
#line 350 "lexer.cpp"
		}
		break;
	case 29:
		{
#line 70 ".\\lexer.l"
return BXOR;
#line 357 "lexer.cpp"
		}
		break;
	case 30:
		{
#line 71 ".\\lexer.l"
return BNOT;
#line 364 "lexer.cpp"
		}
		break;
	case 31:
		{
#line 72 ".\\lexer.l"
return LT;
#line 371 "lexer.cpp"
		}
		break;
	case 32:
		{
#line 73 ".\\lexer.l"
return GT;
#line 378 "lexer.cpp"
		}
		break;
	case 33:
		{
#line 75 ".\\lexer.l"
return SEMICOLON;
#line 385 "lexer.cpp"
		}
		break;
	case 34:
		{
#line 76 ".\\lexer.l"
return COMMA;
#line 392 "lexer.cpp"
		}
		break;
	case 35:
		{
#line 77 ".\\lexer.l"
return LPAREN;
#line 399 "lexer.cpp"
		}
		break;
	case 36:
		{
#line 78 ".\\lexer.l"
return RPAREN;
#line 406 "lexer.cpp"
		}
		break;
	case 37:
		{
#line 79 ".\\lexer.l"
return LBRACE;
#line 413 "lexer.cpp"
		}
		break;
	case 38:
		{
#line 80 ".\\lexer.l"
return RBRACE;
#line 420 "lexer.cpp"
		}
		break;
	case 39:
		{
#line 81 ".\\lexer.l"

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
			
#line 447 "lexer.cpp"
		}
		break;
	case 40:
		{
#line 102 ".\\lexer.l"

				char c;
				do
				{
					c = input();
					if(c == '\n')
						break;
				}while(c != '\n');
			
#line 462 "lexer.cpp"
		}
		break;
	case 41:
		{
#line 112 ".\\lexer.l"

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
			
#line 483 "lexer.cpp"
		}
		break;
	case 42:
		{
#line 127 ".\\lexer.l"

				yylval = &dummy;
				yylval->attr.vali = atoi(yytext);//atoi()用来将yytext转换成整数，从而将num真正的值赋予dummy(yylval)结点的vali属性
				return NUM;
			
#line 494 "lexer.cpp"
		}
		break;
	case 43:
		{
#line 132 ".\\lexer.l"

				yylval = &dummy;
				yylval->attr.valc = yytext[0];//取yytext中的第一个字符，赋值给yylval中的valc属性
				return CONSTCHAR;
			
#line 505 "lexer.cpp"
		}
		break;
	case 44:
		{
#line 137 ".\\lexer.l"

				lineno++;
				#ifdef LEX_DEBUG
					cout<<"lineno:"<<lineno<<endl;
				#endif
			
#line 517 "lexer.cpp"
		}
		break;
	case 45:
		{
#line 143 ".\\lexer.l"

#line 524 "lexer.cpp"
		}
		break;
	case 46:
		{
#line 144 ".\\lexer.l"

				#ifdef LEX_DEBUG
					cout<<"error!"<<endl;
				#endif
				return ERROR;
			
#line 536 "lexer.cpp"
		}
		break;
	default:
		yyassert(0);
		break;
	}
	yyreturnflg = yyfalse;
	return 0;
}

#ifndef YYNBORLANDWARN
#ifdef __BORLANDC__
#pragma warn .rch		// <warning: unreachable code> to the old state
#endif
#endif

void YYLEXERNAME::yytables()
{
	yystext_size = YYTEXT_SIZE;
	yysunput_size = YYUNPUT_SIZE;
	yytext_max = YYTEXT_MAX;
	yyunput_max = YYUNPUT_MAX;

	static const yymatch_t YYNEARFAR YYBASED_CODE match[] = {
		0
	};
	yymatch = match;

	yytransitionmax = 211;
	static const yytransition_t YYNEARFAR YYBASED_CODE transition[] = {
		{ 0, 0 },
		{ 4, 1 },
		{ 5, 1 },
		{ 4, 4 },
		{ 43, 43 },
		{ 43, 43 },
		{ 43, 43 },
		{ 43, 43 },
		{ 43, 43 },
		{ 43, 43 },
		{ 43, 43 },
		{ 43, 43 },
		{ 43, 43 },
		{ 43, 43 },
		{ 18, 18 },
		{ 18, 18 },
		{ 18, 18 },
		{ 18, 18 },
		{ 18, 18 },
		{ 18, 18 },
		{ 18, 18 },
		{ 18, 18 },
		{ 18, 18 },
		{ 41, 16 },
		{ 4, 1 },
		{ 6, 1 },
		{ 4, 4 },
		{ 36, 6 },
		{ 42, 16 },
		{ 7, 1 },
		{ 8, 1 },
		{ 9, 1 },
		{ 10, 1 },
		{ 11, 1 },
		{ 12, 1 },
		{ 13, 1 },
		{ 14, 1 },
		{ 15, 1 },
		{ 49, 25 },
		{ 16, 1 },
		{ 17, 1 },
		{ 18, 1 },
		{ 18, 1 },
		{ 18, 1 },
		{ 18, 1 },
		{ 18, 1 },
		{ 18, 1 },
		{ 18, 1 },
		{ 18, 1 },
		{ 18, 1 },
		{ 50, 26 },
		{ 19, 1 },
		{ 20, 1 },
		{ 21, 1 },
		{ 22, 1 },
		{ 44, 20 },
		{ 45, 20 },
		{ 23, 1 },
		{ 23, 1 },
		{ 23, 1 },
		{ 23, 1 },
		{ 23, 1 },
		{ 23, 1 },
		{ 23, 1 },
		{ 23, 1 },
		{ 23, 1 },
		{ 23, 1 },
		{ 23, 1 },
		{ 23, 1 },
		{ 23, 1 },
		{ 23, 1 },
		{ 23, 1 },
		{ 23, 1 },
		{ 23, 1 },
		{ 23, 1 },
		{ 23, 1 },
		{ 23, 1 },
		{ 23, 1 },
		{ 23, 1 },
		{ 23, 1 },
		{ 23, 1 },
		{ 23, 1 },
		{ 23, 1 },
		{ 51, 27 },
		{ 62, 53 },
		{ 37, 8 },
		{ 24, 1 },
		{ 23, 1 },
		{ 63, 53 },
		{ 23, 1 },
		{ 23, 1 },
		{ 25, 1 },
		{ 23, 1 },
		{ 26, 1 },
		{ 27, 1 },
		{ 23, 1 },
		{ 23, 1 },
		{ 28, 1 },
		{ 23, 1 },
		{ 23, 1 },
		{ 23, 1 },
		{ 29, 1 },
		{ 23, 1 },
		{ 23, 1 },
		{ 30, 1 },
		{ 23, 1 },
		{ 23, 1 },
		{ 23, 1 },
		{ 23, 1 },
		{ 23, 1 },
		{ 23, 1 },
		{ 31, 1 },
		{ 23, 1 },
		{ 23, 1 },
		{ 23, 1 },
		{ 32, 1 },
		{ 33, 1 },
		{ 34, 1 },
		{ 35, 1 },
		{ 23, 75 },
		{ 23, 75 },
		{ 23, 75 },
		{ 23, 75 },
		{ 23, 75 },
		{ 23, 75 },
		{ 23, 75 },
		{ 23, 75 },
		{ 23, 75 },
		{ 23, 75 },
		{ 40, 15 },
		{ 47, 22 },
		{ 48, 22 },
		{ 0, 15 },
		{ 54, 29 },
		{ 55, 30 },
		{ 56, 31 },
		{ 23, 75 },
		{ 23, 75 },
		{ 23, 75 },
		{ 23, 75 },
		{ 23, 75 },
		{ 23, 75 },
		{ 23, 75 },
		{ 23, 75 },
		{ 23, 75 },
		{ 23, 75 },
		{ 23, 75 },
		{ 23, 75 },
		{ 23, 75 },
		{ 23, 75 },
		{ 23, 75 },
		{ 23, 75 },
		{ 23, 75 },
		{ 23, 75 },
		{ 23, 75 },
		{ 23, 75 },
		{ 23, 75 },
		{ 23, 75 },
		{ 23, 75 },
		{ 23, 75 },
		{ 23, 75 },
		{ 23, 75 },
		{ 57, 33 },
		{ 58, 38 },
		{ 0, 9 },
		{ 59, 49 },
		{ 23, 75 },
		{ 60, 50 },
		{ 23, 75 },
		{ 23, 75 },
		{ 23, 75 },
		{ 23, 75 },
		{ 23, 75 },
		{ 23, 75 },
		{ 23, 75 },
		{ 23, 75 },
		{ 23, 75 },
		{ 23, 75 },
		{ 23, 75 },
		{ 23, 75 },
		{ 23, 75 },
		{ 23, 75 },
		{ 23, 75 },
		{ 23, 75 },
		{ 23, 75 },
		{ 23, 75 },
		{ 23, 75 },
		{ 23, 75 },
		{ 23, 75 },
		{ 23, 75 },
		{ 23, 75 },
		{ 23, 75 },
		{ 23, 75 },
		{ 23, 75 },
		{ 52, 28 },
		{ 61, 51 },
		{ 39, 13 },
		{ 64, 54 },
		{ 65, 55 },
		{ 66, 56 },
		{ 67, 59 },
		{ 68, 60 },
		{ 53, 28 },
		{ 69, 62 },
		{ 70, 64 },
		{ 71, 65 },
		{ 72, 66 },
		{ 73, 69 },
		{ 74, 71 },
		{ 75, 72 },
		{ 46, 21 }
	};
	yytransition = transition;

	static const yystate_t YYNEARFAR YYBASED_CODE state[] = {
		{ 0, 0, 0 },
		{ -3, -8, 0 },
		{ 1, 0, 0 },
		{ 0, 0, 46 },
		{ 0, -6, 45 },
		{ 0, 0, 44 },
		{ 0, -34, 16 },
		{ 0, 0, 26 },
		{ 0, 47, 27 },
		{ -38, 154, 46 },
		{ 0, 0, 35 },
		{ 0, 0, 36 },
		{ 0, 0, 24 },
		{ 0, 153, 22 },
		{ 0, 0, 34 },
		{ 18, 84, 23 },
		{ 0, -19, 25 },
		{ 0, 0, 42 },
		{ 43, -35, 42 },
		{ 0, 0, 33 },
		{ 0, -5, 31 },
		{ 0, 149, 17 },
		{ 0, 69, 32 },
		{ 75, 0, 41 },
		{ 0, 0, 29 },
		{ 75, -66, 41 },
		{ 75, -58, 41 },
		{ 75, -28, 41 },
		{ 75, 92, 41 },
		{ 75, 36, 41 },
		{ 75, 20, 41 },
		{ 75, 31, 41 },
		{ 0, 0, 37 },
		{ 0, 38, 28 },
		{ 0, 0, 38 },
		{ 0, 0, 30 },
		{ 0, 0, 11 },
		{ 0, 0, 15 },
		{ 0, 124, 0 },
		{ 0, 0, 18 },
		{ 0, 0, 19 },
		{ 0, 0, 39 },
		{ 0, 0, 40 },
		{ 0, -44, 42 },
		{ 0, 0, 21 },
		{ 0, 0, 13 },
		{ 0, 0, 10 },
		{ 0, 0, 12 },
		{ 0, 0, 20 },
		{ 75, 68, 41 },
		{ 75, 52, 41 },
		{ 75, 81, 41 },
		{ 75, 0, 3 },
		{ 75, -28, 41 },
		{ 75, 92, 41 },
		{ 75, 93, 41 },
		{ 75, 94, 41 },
		{ 0, 0, 14 },
		{ 0, 0, 43 },
		{ 75, 86, 41 },
		{ 75, 100, 41 },
		{ 75, 0, 6 },
		{ 75, 86, 41 },
		{ 75, 0, 1 },
		{ 75, 94, 41 },
		{ 75, 95, 41 },
		{ 75, 98, 41 },
		{ 75, 0, 2 },
		{ 75, 0, 4 },
		{ 75, 91, 41 },
		{ 75, 0, 9 },
		{ 75, 92, 41 },
		{ 75, 108, 41 },
		{ 75, 0, 7 },
		{ 75, 0, 8 },
		{ 0, 71, 5 }
	};
	yystate = state;

	static const yybackup_t YYNEARFAR YYBASED_CODE backup[] = {
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0
	};
	yybackup = backup;
}
#line 151 ".\\lexer.l"


