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
* parser.cpp
* C++ source file generated from parser.y.
* 
* Date: 12/17/13
* Time: 23:46:18
* 
* AYACC Version: 2.07
****************************************************************************/

#include <yycpars.h>

// namespaces
#ifdef YYSTDCPPLIB
using namespace std;
#endif
#ifdef YYNAMESPACE
using namespace yl;
#endif

#line 1 ".\\parser.y"


#include <fstream>
#include <string>
#include "common.h"
#include "lexer.h"
#include "symbol.h"
#include "tree.h"

using namespace std;

extern symbol_table symtbl;
extern tree parse_tree;


#line 54 "parser.cpp"
// repeated because of possible precompiled header
#include <yycpars.h>

// namespaces
#ifdef YYSTDCPPLIB
using namespace std;
#endif
#ifdef YYNAMESPACE
using namespace yl;
#endif

#include ".\parser.h"

/////////////////////////////////////////////////////////////////////////////
// constructor

YYPARSERNAME::YYPARSERNAME()
{
	yytables();
}

/////////////////////////////////////////////////////////////////////////////
// destructor

YYPARSERNAME::~YYPARSERNAME()
{
	// allows virtual functions to be called properly for correct cleanup
	yydestroy();
}

#ifndef YYSTYPE
#define YYSTYPE int
#endif
#ifndef YYSTACK_SIZE
#define YYSTACK_SIZE 100
#endif
#ifndef YYSTACK_MAX
#define YYSTACK_MAX 0
#endif

/****************************************************************************
* N O T E
* 
* If the compiler generates a YYPARSERNAME error then you have not declared
* the name of the parser. The easiest way to do this is to use a name
* declaration. This is placed in the declarations section of your YACC
* source file and is introduced with the %name keyword. For instance, the
* following name declaration declares the parser myparser:
* 
* %name myparser
* 
* For more information see help.
****************************************************************************/

// yyattribute
#ifdef YYDEBUG
void YYFAR* YYPARSERNAME::yyattribute1(int index) const
{
	YYSTYPE YYFAR* p = &((YYSTYPE YYFAR*)yyattributestackptr)[yytop + index];
	return p;
}
#define yyattribute(index) (*(YYSTYPE YYFAR*)yyattribute1(index))
#else
#define yyattribute(index) (((YYSTYPE YYFAR*)yyattributestackptr)[yytop + (index)])
#endif

void YYPARSERNAME::yystacktoval(int index)
{
	yyassert(index >= 0);
	*(YYSTYPE YYFAR*)yyvalptr = ((YYSTYPE YYFAR*)yyattributestackptr)[index];
}

void YYPARSERNAME::yyvaltostack(int index)
{
	yyassert(index >= 0);
	((YYSTYPE YYFAR*)yyattributestackptr)[index] = *(YYSTYPE YYFAR*)yyvalptr;
}

void YYPARSERNAME::yylvaltoval()
{
	*(YYSTYPE YYFAR*)yyvalptr = *(YYSTYPE YYFAR*)yylvalptr;
}

void YYPARSERNAME::yyvaltolval()
{
	*(YYSTYPE YYFAR*)yylvalptr = *(YYSTYPE YYFAR*)yyvalptr;
}

void YYPARSERNAME::yylvaltostack(int index)
{
	yyassert(index >= 0);
	((YYSTYPE YYFAR*)yyattributestackptr)[index] = *(YYSTYPE YYFAR*)yylvalptr;
}

void YYFAR* YYPARSERNAME::yynewattribute(int count)
{
	yyassert(count >= 0);
	return new YYFAR YYSTYPE[count];
}

void YYPARSERNAME::yydeleteattribute(void YYFAR* attribute)
{
	delete[] (YYSTYPE YYFAR*)attribute;
}

void YYPARSERNAME::yycopyattribute(void YYFAR* dest, const void YYFAR* src, int count)
{
	for (int i = 0; i < count; i++) {
		((YYSTYPE YYFAR*)dest)[i] = ((YYSTYPE YYFAR*)src)[i];
	}
}

#ifdef YYDEBUG
void YYPARSERNAME::yyinitdebug(void YYFAR** p, int count) const
{
	yyassert(p != NULL);
	yyassert(count >= 1);

	YYSTYPE YYFAR** p1 = (YYSTYPE YYFAR**)p;
	for (int i = 0; i < count; i++) {
		p1[i] = &((YYSTYPE YYFAR*)yyattributestackptr)[yytop + i - (count - 1)];
	}
}
#endif

void YYPARSERNAME::yyaction(int action)
{
	switch (action) {
	case 0:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[5];
			yyinitdebug((void YYFAR**)yya, 5);
#endif
			{
#line 36 ".\\parser.y"

						(*(YYSTYPE YYFAR*)yyvalptr) = yyattribute(4 - 4);
					
#line 194 "parser.cpp"
			}
		}
		break;
	case 1:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 41 ".\\parser.y"

						Node *p;
						(*(YYSTYPE YYFAR*)yyvalptr) = parse_tree.NewRoot(DECL_NODE, VAR_DECL, 0, Notype, yyattribute(1 - 3), yyattribute(2 - 3));
						for(p = yyattribute(2 - 3); p; p = p->sibling)
						{
							p->type = yyattribute(1 - 3)->type;
							symtbl.set_type(p->attr.symtbl_seq, p->type);
						}
					
#line 215 "parser.cpp"
			}
		}
		break;
	case 2:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 52 ".\\parser.y"

						YYSTYPE t = yyattribute(1 - 3);
						if(t != NULL)
						{
							while(t->sibling != NULL)
							{
								t = t->sibling;
							}
							t->sibling = yyattribute(3 - 3);
							(*(YYSTYPE YYFAR*)yyvalptr) = yyattribute(1 - 3);
						}
						else
						{
							(*(YYSTYPE YYFAR*)yyvalptr) = yyattribute(3 - 3);
						}
					
#line 243 "parser.cpp"
			}
		}
		break;
	case 3:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 69 ".\\parser.y"

						(*(YYSTYPE YYFAR*)yyvalptr) = yyattribute(1 - 1);
					
#line 258 "parser.cpp"
			}
		}
		break;
	case 4:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 74 ".\\parser.y"

						(*(YYSTYPE YYFAR*)yyvalptr) = parse_tree.NewRoot(EXPR_NODE, TYPE_EXPR, 0, Integer);
					
#line 273 "parser.cpp"
			}
		}
		break;
	case 5:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 78 ".\\parser.y"

						(*(YYSTYPE YYFAR*)yyvalptr) = parse_tree.NewRoot(EXPR_NODE, TYPE_EXPR, 0, Char);
					
#line 288 "parser.cpp"
			}
		}
		break;
	case 6:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 83 ".\\parser.y"

						(*(YYSTYPE YYFAR*)yyvalptr) = parse_tree.NewRoot(EXPR_NODE, ID_EXPR, yyattribute(1 - 1)->attr.symtbl_seq, yyattribute(1 - 1)->type);
					
#line 303 "parser.cpp"
			}
		}
		break;
	case 7:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[5];
			yyinitdebug((void YYFAR**)yya, 5);
#endif
			{
#line 88 ".\\parser.y"

						YYSTYPE t = yyattribute(2 - 4);
						if(t != NULL)
						{
							while(t->sibling != NULL)
							{
								t = t->sibling;
							}
							t->sibling = yyattribute(3 - 4);
							(*(YYSTYPE YYFAR*)yyvalptr) = parse_tree.NewRoot(STMT_NODE, COMP_STMT, 0, Notype, yyattribute(2 - 4));
						}
						else
						{
							(*(YYSTYPE YYFAR*)yyvalptr) = parse_tree.NewRoot(STMT_NODE, COMP_STMT, 0, Notype, yyattribute(3 - 4));
						}
					
#line 331 "parser.cpp"
			}
		}
		break;
	case 8:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 105 ".\\parser.y"

						(*(YYSTYPE YYFAR*)yyvalptr) = parse_tree.NewRoot(STMT_NODE, COMP_STMT, 0, Notype, yyattribute(2 - 3));
					
#line 346 "parser.cpp"
			}
		}
		break;
	case 9:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[3];
			yyinitdebug((void YYFAR**)yya, 3);
#endif
			{
#line 110 ".\\parser.y"

						YYSTYPE t = yyattribute(1 - 2);
						if(t != NULL)
						{
							while(t->sibling != NULL)
							{
								t=t->sibling;
							}
							t->sibling = yyattribute(2 - 2);
							(*(YYSTYPE YYFAR*)yyvalptr) = yyattribute(1 - 2);
						}
						else
						{
							(*(YYSTYPE YYFAR*)yyvalptr) = yyattribute(2 - 2);
						}
					
#line 374 "parser.cpp"
			}
		}
		break;
	case 10:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 127 ".\\parser.y"

						(*(YYSTYPE YYFAR*)yyvalptr) = yyattribute(1 - 1);
					
#line 389 "parser.cpp"
			}
		}
		break;
	case 11:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[3];
			yyinitdebug((void YYFAR**)yya, 3);
#endif
			{
#line 132 ".\\parser.y"

						YYSTYPE t = yyattribute(1 - 2);
						if(t != NULL)
						{
							while(t->sibling != NULL)
							{
								t=t->sibling;
							}
							t->sibling = yyattribute(2 - 2);
							(*(YYSTYPE YYFAR*)yyvalptr) = yyattribute(1 - 2);
						}
						else
						{
							(*(YYSTYPE YYFAR*)yyvalptr) = yyattribute(2 - 2);
						}
					
#line 417 "parser.cpp"
			}
		}
		break;
	case 12:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 149 ".\\parser.y"

						(*(YYSTYPE YYFAR*)yyvalptr) = yyattribute(1 - 1);
					
#line 432 "parser.cpp"
			}
		}
		break;
	case 13:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 154 ".\\parser.y"

						(*(YYSTYPE YYFAR*)yyvalptr) = yyattribute(1 - 1);
					
#line 447 "parser.cpp"
			}
		}
		break;
	case 14:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 158 ".\\parser.y"

						(*(YYSTYPE YYFAR*)yyvalptr) = yyattribute(1 - 1);
					
#line 462 "parser.cpp"
			}
		}
		break;
	case 15:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 162 ".\\parser.y"

						(*(YYSTYPE YYFAR*)yyvalptr) =yyattribute(1 - 1);
					
#line 477 "parser.cpp"
			}
		}
		break;
	case 16:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 166 ".\\parser.y"

						(*(YYSTYPE YYFAR*)yyvalptr) = yyattribute(1 - 1);
					
#line 492 "parser.cpp"
			}
		}
		break;
	case 17:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 170 ".\\parser.y"

						(*(YYSTYPE YYFAR*)yyvalptr) = yyattribute(1 - 1);
					
#line 507 "parser.cpp"
			}
		}
		break;
	case 18:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 174 ".\\parser.y"

						(*(YYSTYPE YYFAR*)yyvalptr) = yyattribute(1 - 1);
					
#line 522 "parser.cpp"
			}
		}
		break;
	case 19:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 178 ".\\parser.y"

						(*(YYSTYPE YYFAR*)yyvalptr) =yyattribute(1 - 1);
					
#line 537 "parser.cpp"
			}
		}
		break;
	case 20:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[3];
			yyinitdebug((void YYFAR**)yya, 3);
#endif
			{
#line 183 ".\\parser.y"

						(*(YYSTYPE YYFAR*)yyvalptr) = yyattribute(1 - 2);
					
#line 552 "parser.cpp"
			}
		}
		break;
	case 21:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 187 ".\\parser.y"

						(*(YYSTYPE YYFAR*)yyvalptr) = NULL;
					
#line 567 "parser.cpp"
			}
		}
		break;
	case 22:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[8];
			yyinitdebug((void YYFAR**)yya, 8);
#endif
			{
#line 192 ".\\parser.y"

						(*(YYSTYPE YYFAR*)yyvalptr) = parse_tree.NewRoot(STMT_NODE, IF_STMT, 0, Notype, yyattribute(3 - 7), yyattribute(5 - 7), yyattribute(7 - 7));
					
#line 582 "parser.cpp"
			}
		}
		break;
	case 23:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[6];
			yyinitdebug((void YYFAR**)yya, 6);
#endif
			{
#line 196 ".\\parser.y"

						(*(YYSTYPE YYFAR*)yyvalptr) = parse_tree.NewRoot(STMT_NODE, IF_STMT, 0, Notype, yyattribute(3 - 5), yyattribute(5 - 5));
					
#line 597 "parser.cpp"
			}
		}
		break;
	case 24:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[6];
			yyinitdebug((void YYFAR**)yya, 6);
#endif
			{
#line 201 ".\\parser.y"

						(*(YYSTYPE YYFAR*)yyvalptr) = parse_tree.NewRoot(STMT_NODE, WHILE_STMT, 0, Notype, yyattribute(3 - 5), yyattribute(5 - 5));
					
#line 612 "parser.cpp"
			}
		}
		break;
	case 25:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[8];
			yyinitdebug((void YYFAR**)yya, 8);
#endif
			{
#line 206 ".\\parser.y"

						(*(YYSTYPE YYFAR*)yyvalptr) = parse_tree.NewRoot(STMT_NODE, FOR_STMT, 0, Notype, yyattribute(3 - 7), yyattribute(4 - 7), yyattribute(5 - 7), yyattribute(7 - 7));
					
#line 627 "parser.cpp"
			}
		}
		break;
	case 26:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[5];
			yyinitdebug((void YYFAR**)yya, 5);
#endif
			{
#line 211 ".\\parser.y"

						(*(YYSTYPE YYFAR*)yyvalptr) = parse_tree.NewRoot(STMT_NODE, INPUT_STMT, 0, Notype, yyattribute(3 - 4));
					
#line 642 "parser.cpp"
			}
		}
		break;
	case 27:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[5];
			yyinitdebug((void YYFAR**)yya, 5);
#endif
			{
#line 216 ".\\parser.y"

						(*(YYSTYPE YYFAR*)yyvalptr) = parse_tree.NewRoot(STMT_NODE, PRINT_STMT, 0, Notype, yyattribute(3 - 4));
					
#line 657 "parser.cpp"
			}
		}
		break;
	case 28:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 221 ".\\parser.y"

						(*(YYSTYPE YYFAR*)yyvalptr) = parse_tree.NewRoot(EXPR_NODE, OP_EXPR, ASSIGN, Notype, yyattribute(1 - 3), yyattribute(3 - 3));
					
#line 672 "parser.cpp"
			}
		}
		break;
	case 29:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 225 ".\\parser.y"

						(*(YYSTYPE YYFAR*)yyvalptr) = yyattribute(1 - 1);
					
#line 687 "parser.cpp"
			}
		}
		break;
	case 30:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 230 ".\\parser.y"

						(*(YYSTYPE YYFAR*)yyvalptr) = parse_tree.NewRoot(EXPR_NODE, ID_EXPR, yyattribute(1 - 1)->attr.symtbl_seq, yyattribute(1 - 1)->type);
					
#line 702 "parser.cpp"
			}
		}
		break;
	case 31:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 235 ".\\parser.y"

						(*(YYSTYPE YYFAR*)yyvalptr) = parse_tree.NewRoot(EXPR_NODE, OP_EXPR, OR, Notype, yyattribute(1 - 3), yyattribute(3 - 3));
                    
#line 717 "parser.cpp"
			}
		}
		break;
	case 32:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 239 ".\\parser.y"

                    	(*(YYSTYPE YYFAR*)yyvalptr) = yyattribute(1 - 1);
                    
#line 732 "parser.cpp"
			}
		}
		break;
	case 33:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 244 ".\\parser.y"

						(*(YYSTYPE YYFAR*)yyvalptr) = parse_tree.NewRoot(EXPR_NODE, OP_EXPR, AND, Notype, yyattribute(1 - 3), yyattribute(3 - 3));
                    
#line 747 "parser.cpp"
			}
		}
		break;
	case 34:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 248 ".\\parser.y"

                    	(*(YYSTYPE YYFAR*)yyvalptr) = yyattribute(1 - 1);
                    
#line 762 "parser.cpp"
			}
		}
		break;
	case 35:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 253 ".\\parser.y"

						(*(YYSTYPE YYFAR*)yyvalptr) = parse_tree.NewRoot(EXPR_NODE, OP_EXPR, BOR, Notype, yyattribute(1 - 3), yyattribute(3 - 3));
					
#line 777 "parser.cpp"
			}
		}
		break;
	case 36:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 257 ".\\parser.y"

						(*(YYSTYPE YYFAR*)yyvalptr) = yyattribute(1 - 1);
					
#line 792 "parser.cpp"
			}
		}
		break;
	case 37:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 262 ".\\parser.y"

						(*(YYSTYPE YYFAR*)yyvalptr) = parse_tree.NewRoot(EXPR_NODE, OP_EXPR, BXOR, Notype, yyattribute(1 - 3), yyattribute(3 - 3));	
					
#line 807 "parser.cpp"
			}
		}
		break;
	case 38:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 266 ".\\parser.y"

						(*(YYSTYPE YYFAR*)yyvalptr) = yyattribute(1 - 1);
					
#line 822 "parser.cpp"
			}
		}
		break;
	case 39:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 271 ".\\parser.y"

						(*(YYSTYPE YYFAR*)yyvalptr) = parse_tree.NewRoot(EXPR_NODE, OP_EXPR, BAND, Notype, yyattribute(1 - 3), yyattribute(3 - 3));
					
#line 837 "parser.cpp"
			}
		}
		break;
	case 40:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 275 ".\\parser.y"

						(*(YYSTYPE YYFAR*)yyvalptr) = yyattribute(1 - 1);
					
#line 852 "parser.cpp"
			}
		}
		break;
	case 41:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 280 ".\\parser.y"

						(*(YYSTYPE YYFAR*)yyvalptr) = parse_tree.NewRoot(EXPR_NODE, OP_EXPR, EQ, Notype, yyattribute(1 - 3), yyattribute(3 - 3));
					
#line 867 "parser.cpp"
			}
		}
		break;
	case 42:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 284 ".\\parser.y"

						(*(YYSTYPE YYFAR*)yyvalptr) = parse_tree.NewRoot(EXPR_NODE, OP_EXPR, LT, Notype, yyattribute(1 - 3), yyattribute(3 - 3));
					
#line 882 "parser.cpp"
			}
		}
		break;
	case 43:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 288 ".\\parser.y"

						(*(YYSTYPE YYFAR*)yyvalptr) = parse_tree.NewRoot(EXPR_NODE, OP_EXPR, GT, Notype, yyattribute(1 - 3), yyattribute(3 - 3));
					
#line 897 "parser.cpp"
			}
		}
		break;
	case 44:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 292 ".\\parser.y"

						(*(YYSTYPE YYFAR*)yyvalptr) = parse_tree.NewRoot(EXPR_NODE, OP_EXPR, LE, Notype, yyattribute(1 - 3), yyattribute(3 - 3));
					
#line 912 "parser.cpp"
			}
		}
		break;
	case 45:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 296 ".\\parser.y"

						(*(YYSTYPE YYFAR*)yyvalptr) = parse_tree.NewRoot(EXPR_NODE, OP_EXPR, GE, Notype, yyattribute(1 - 3), yyattribute(3 - 3));
					
#line 927 "parser.cpp"
			}
		}
		break;
	case 46:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 300 ".\\parser.y"

						(*(YYSTYPE YYFAR*)yyvalptr) = parse_tree.NewRoot(EXPR_NODE, OP_EXPR, NE, Notype, yyattribute(1 - 3), yyattribute(3 - 3));
					
#line 942 "parser.cpp"
			}
		}
		break;
	case 47:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 304 ".\\parser.y"

						(*(YYSTYPE YYFAR*)yyvalptr) = yyattribute(1 - 1);
					
#line 957 "parser.cpp"
			}
		}
		break;
	case 48:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 309 ".\\parser.y"
 
						(*(YYSTYPE YYFAR*)yyvalptr) = parse_tree.NewRoot(EXPR_NODE, OP_EXPR, SHR, Notype, yyattribute(1 - 3), yyattribute(3 - 3));
					
#line 972 "parser.cpp"
			}
		}
		break;
	case 49:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 313 ".\\parser.y"
 
						(*(YYSTYPE YYFAR*)yyvalptr) = parse_tree.NewRoot(EXPR_NODE, OP_EXPR, SHL, Notype, yyattribute(1 - 3), yyattribute(3 - 3));
					
#line 987 "parser.cpp"
			}
		}
		break;
	case 50:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 317 ".\\parser.y"

						(*(YYSTYPE YYFAR*)yyvalptr) = yyattribute(1 - 1);
					
#line 1002 "parser.cpp"
			}
		}
		break;
	case 51:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 322 ".\\parser.y"

						(*(YYSTYPE YYFAR*)yyvalptr) = parse_tree.NewRoot(EXPR_NODE, OP_EXPR, PLUS, Notype, yyattribute(1 - 3), yyattribute(3 - 3));
                    
#line 1017 "parser.cpp"
			}
		}
		break;
	case 52:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 326 ".\\parser.y"

						(*(YYSTYPE YYFAR*)yyvalptr) = parse_tree.NewRoot(EXPR_NODE, OP_EXPR, MINUS, Notype, yyattribute(1 - 3), yyattribute(3 - 3));
                    
#line 1032 "parser.cpp"
			}
		}
		break;
	case 53:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 330 ".\\parser.y"

                    	(*(YYSTYPE YYFAR*)yyvalptr) = yyattribute(1 - 1);
                    
#line 1047 "parser.cpp"
			}
		}
		break;
	case 54:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 335 ".\\parser.y"

						(*(YYSTYPE YYFAR*)yyvalptr) = parse_tree.NewRoot(EXPR_NODE, OP_EXPR, TIMES, Notype, yyattribute(1 - 3), yyattribute(3 - 3));
                    
#line 1062 "parser.cpp"
			}
		}
		break;
	case 55:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 339 ".\\parser.y"

						(*(YYSTYPE YYFAR*)yyvalptr) = parse_tree.NewRoot(EXPR_NODE, OP_EXPR, OVER, Notype, yyattribute(1 - 3), yyattribute(3 - 3));
                    
#line 1077 "parser.cpp"
			}
		}
		break;
	case 56:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 343 ".\\parser.y"

						(*(YYSTYPE YYFAR*)yyvalptr) = parse_tree.NewRoot(EXPR_NODE, OP_EXPR, REM, Notype, yyattribute(1 - 3), yyattribute(3 - 3));
					
#line 1092 "parser.cpp"
			}
		}
		break;
	case 57:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 347 ".\\parser.y"

                    	(*(YYSTYPE YYFAR*)yyvalptr) = yyattribute(1 - 1);
                    
#line 1107 "parser.cpp"
			}
		}
		break;
	case 58:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[3];
			yyinitdebug((void YYFAR**)yya, 3);
#endif
			{
#line 352 ".\\parser.y"

						(*(YYSTYPE YYFAR*)yyvalptr) = parse_tree.NewRoot(EXPR_NODE, OP_EXPR, INC, Notype, NULL, yyattribute(2 - 2));
					
#line 1122 "parser.cpp"
			}
		}
		break;
	case 59:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[3];
			yyinitdebug((void YYFAR**)yya, 3);
#endif
			{
#line 356 ".\\parser.y"

						(*(YYSTYPE YYFAR*)yyvalptr) = parse_tree.NewRoot(EXPR_NODE, OP_EXPR, INC, Notype, yyattribute(1 - 2), NULL);
					
#line 1137 "parser.cpp"
			}
		}
		break;
	case 60:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[3];
			yyinitdebug((void YYFAR**)yya, 3);
#endif
			{
#line 360 ".\\parser.y"

						(*(YYSTYPE YYFAR*)yyvalptr) = parse_tree.NewRoot(EXPR_NODE, OP_EXPR, DEC, Notype, NULL, yyattribute(2 - 2));
					
#line 1152 "parser.cpp"
			}
		}
		break;
	case 61:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[3];
			yyinitdebug((void YYFAR**)yya, 3);
#endif
			{
#line 364 ".\\parser.y"

						(*(YYSTYPE YYFAR*)yyvalptr) = parse_tree.NewRoot(EXPR_NODE, OP_EXPR, DEC, Notype, yyattribute(1 - 2), NULL);		
					
#line 1167 "parser.cpp"
			}
		}
		break;
	case 62:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[3];
			yyinitdebug((void YYFAR**)yya, 3);
#endif
			{
#line 368 ".\\parser.y"
	
						(*(YYSTYPE YYFAR*)yyvalptr) = parse_tree.NewRoot(EXPR_NODE, OP_EXPR, BNOT, Notype, yyattribute(2 - 2));
					
#line 1182 "parser.cpp"
			}
		}
		break;
	case 63:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 372 ".\\parser.y"

						(*(YYSTYPE YYFAR*)yyvalptr) = yyattribute(1 - 1);
					
#line 1197 "parser.cpp"
			}
		}
		break;
	case 64:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 377 ".\\parser.y"

                    	(*(YYSTYPE YYFAR*)yyvalptr) = yyattribute(2 - 3);
                    
#line 1212 "parser.cpp"
			}
		}
		break;
	case 65:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 381 ".\\parser.y"

                    	(*(YYSTYPE YYFAR*)yyvalptr) = yyattribute(1 - 1);
                    
#line 1227 "parser.cpp"
			}
		}
		break;
	case 66:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 385 ".\\parser.y"
 
						(*(YYSTYPE YYFAR*)yyvalptr) = parse_tree.NewRoot(EXPR_NODE, CONST_EXPR, yyattribute(1 - 1)->attr.vali, Integer);
                    
#line 1242 "parser.cpp"
			}
		}
		break;
	case 67:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 389 ".\\parser.y"

						(*(YYSTYPE YYFAR*)yyvalptr) = parse_tree.NewRoot(EXPR_NODE, CONST_EXPR, yyattribute(1 - 1)->attr.valc, Char);
                   	
#line 1257 "parser.cpp"
			}
		}
		break;
	case 68:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[3];
			yyinitdebug((void YYFAR**)yya, 3);
#endif
			{
#line 393 ".\\parser.y"
 
						(*(YYSTYPE YYFAR*)yyvalptr) = parse_tree.NewRoot(EXPR_NODE, NOT_EXPR, NOT, Notype, yyattribute(2 - 2));
                    
#line 1272 "parser.cpp"
			}
		}
		break;
	default:
		yyassert(0);
		break;
	}
}

void YYPARSERNAME::yytables()
{
	yyattribute_size = sizeof(YYSTYPE);
	yysstack_size = YYSTACK_SIZE;
	yystack_max = YYSTACK_MAX;

#ifdef YYDEBUG
	static const yysymbol_t YYNEARFAR YYBASED_CODE symbol[] = {
		{ "$end", 0 },
		{ "error", 256 },
		{ "INT", 257 },
		{ "CHAR", 258 },
		{ "IF", 259 },
		{ "ELSE", 260 },
		{ "WHILE", 261 },
		{ "FOR", 262 },
		{ "INPUT", 263 },
		{ "PRINT", 264 },
		{ "ID", 265 },
		{ "NUM", 266 },
		{ "CONSTCHAR", 267 },
		{ "MAIN", 268 },
		{ "EQ", 269 },
		{ "NE", 270 },
		{ "GE", 271 },
		{ "LE", 272 },
		{ "OR", 273 },
		{ "AND", 274 },
		{ "NOT", 275 },
		{ "ASSIGN", 276 },
		{ "INC", 277 },
		{ "DEC", 278 },
		{ "SHR", 279 },
		{ "SHL", 280 },
		{ "PLUS", 281 },
		{ "MINUS", 282 },
		{ "TIMES", 283 },
		{ "OVER", 284 },
		{ "REM", 285 },
		{ "BAND", 286 },
		{ "BOR", 287 },
		{ "BXOR", 288 },
		{ "BNOT", 289 },
		{ "LT", 290 },
		{ "GT", 291 },
		{ "SEMICOLON", 292 },
		{ "COMMA", 293 },
		{ "LPAREN", 294 },
		{ "RPAREN", 295 },
		{ "LBRACE", 296 },
		{ "RBRACE", 297 },
		{ NULL, 0 }
	};
	yysymbol = symbol;

	static const char* const YYNEARFAR YYBASED_CODE rule[] = {
		"$accept: program",
		"program: MAIN LPAREN RPAREN compound_stmt",
		"var_declaration: type_specifier idlist SEMICOLON",
		"idlist: idlist COMMA id",
		"idlist: id",
		"type_specifier: INT",
		"type_specifier: CHAR",
		"id: ID",
		"compound_stmt: LBRACE local_declarations statement_list RBRACE",
		"compound_stmt: LBRACE statement_list RBRACE",
		"local_declarations: local_declarations var_declaration",
		"local_declarations: var_declaration",
		"statement_list: statement_list statement",
		"statement_list: statement",
		"statement: expression_stmt",
		"statement: compound_stmt",
		"statement: selection_stmt",
		"statement: while_stmt",
		"statement: for_stmt",
		"statement: input_stmt",
		"statement: print_stmt",
		"expression_stmt: expression SEMICOLON",
		"expression_stmt: SEMICOLON",
		"selection_stmt: IF LPAREN expression RPAREN statement ELSE statement",
		"selection_stmt: IF LPAREN expression RPAREN statement",
		"while_stmt: WHILE LPAREN expression RPAREN statement",
		"for_stmt: FOR LPAREN expression_stmt expression_stmt expression RPAREN statement",
		"input_stmt: INPUT LPAREN var RPAREN",
		"print_stmt: PRINT LPAREN var RPAREN",
		"expression: var ASSIGN expression",
		"expression: or_expression",
		"var: ID",
		"or_expression: or_expression OR and_expression",
		"or_expression: and_expression",
		"and_expression: and_expression AND bor_expression",
		"and_expression: bor_expression",
		"bor_expression: bor_expression BOR bxor_expression",
		"bor_expression: bxor_expression",
		"bxor_expression: bxor_expression BXOR band_expression",
		"bxor_expression: band_expression",
		"band_expression: band_expression BAND additive_expression",
		"band_expression: additive_expression",
		"additive_expression: additive_expression EQ shift_expression",
		"additive_expression: additive_expression LT shift_expression",
		"additive_expression: additive_expression GT shift_expression",
		"additive_expression: additive_expression LE shift_expression",
		"additive_expression: additive_expression GE shift_expression",
		"additive_expression: additive_expression NE shift_expression",
		"additive_expression: shift_expression",
		"shift_expression: shift_expression SHR rel_expression",
		"shift_expression: shift_expression SHL rel_expression",
		"shift_expression: rel_expression",
		"rel_expression: rel_expression PLUS term",
		"rel_expression: rel_expression MINUS term",
		"rel_expression: term",
		"term: term TIMES factor",
		"term: term OVER factor",
		"term: term REM factor",
		"term: short_term",
		"short_term: INC factor",
		"short_term: factor INC",
		"short_term: DEC factor",
		"short_term: factor DEC",
		"short_term: BNOT factor",
		"short_term: factor",
		"factor: LPAREN expression RPAREN",
		"factor: var",
		"factor: NUM",
		"factor: CONSTCHAR",
		"factor: NOT factor"
	};
	yyrule = rule;
#endif

	static const yyreduction_t YYNEARFAR YYBASED_CODE reduction[] = {
		{ 0, 1, -1 },
		{ 1, 4, 0 },
		{ 2, 3, 1 },
		{ 3, 3, 2 },
		{ 3, 1, 3 },
		{ 4, 1, 4 },
		{ 4, 1, 5 },
		{ 5, 1, 6 },
		{ 6, 4, 7 },
		{ 6, 3, 8 },
		{ 7, 2, 9 },
		{ 7, 1, 10 },
		{ 8, 2, 11 },
		{ 8, 1, 12 },
		{ 9, 1, 13 },
		{ 9, 1, 14 },
		{ 9, 1, 15 },
		{ 9, 1, 16 },
		{ 9, 1, 17 },
		{ 9, 1, 18 },
		{ 9, 1, 19 },
		{ 10, 2, 20 },
		{ 10, 1, 21 },
		{ 11, 7, 22 },
		{ 11, 5, 23 },
		{ 12, 5, 24 },
		{ 13, 7, 25 },
		{ 14, 4, 26 },
		{ 15, 4, 27 },
		{ 16, 3, 28 },
		{ 16, 1, 29 },
		{ 17, 1, 30 },
		{ 18, 3, 31 },
		{ 18, 1, 32 },
		{ 19, 3, 33 },
		{ 19, 1, 34 },
		{ 20, 3, 35 },
		{ 20, 1, 36 },
		{ 21, 3, 37 },
		{ 21, 1, 38 },
		{ 22, 3, 39 },
		{ 22, 1, 40 },
		{ 23, 3, 41 },
		{ 23, 3, 42 },
		{ 23, 3, 43 },
		{ 23, 3, 44 },
		{ 23, 3, 45 },
		{ 23, 3, 46 },
		{ 23, 1, 47 },
		{ 24, 3, 48 },
		{ 24, 3, 49 },
		{ 24, 1, 50 },
		{ 25, 3, 51 },
		{ 25, 3, 52 },
		{ 25, 1, 53 },
		{ 26, 3, 54 },
		{ 26, 3, 55 },
		{ 26, 3, 56 },
		{ 26, 1, 57 },
		{ 27, 2, 58 },
		{ 27, 2, 59 },
		{ 27, 2, 60 },
		{ 27, 2, 61 },
		{ 27, 2, 62 },
		{ 27, 1, 63 },
		{ 28, 3, 64 },
		{ 28, 1, 65 },
		{ 28, 1, 66 },
		{ 28, 1, 67 },
		{ 28, 2, 68 }
	};
	yyreduction = reduction;

	yytokenaction_size = 104;

	static const yytokenaction_t YYNEARFAR YYBASED_CODE tokenaction[] = {
		{ 126, YYAT_SHIFT, 9 },
		{ 124, YYAT_SHIFT, 126 },
		{ 126, YYAT_SHIFT, 10 },
		{ 126, YYAT_SHIFT, 11 },
		{ 126, YYAT_SHIFT, 12 },
		{ 126, YYAT_SHIFT, 13 },
		{ 122, YYAT_SHIFT, 125 },
		{ 126, YYAT_SHIFT, 15 },
		{ 126, YYAT_SHIFT, 16 },
		{ 118, YYAT_ERROR, 0 },
		{ 101, YYAT_SHIFT, 72 },
		{ 118, YYAT_ERROR, 0 },
		{ 118, YYAT_ERROR, 0 },
		{ 118, YYAT_ERROR, 0 },
		{ 118, YYAT_ERROR, 0 },
		{ 100, YYAT_SHIFT, 71 },
		{ 126, YYAT_SHIFT, 17 },
		{ 99, YYAT_SHIFT, 70 },
		{ 126, YYAT_SHIFT, 18 },
		{ 126, YYAT_SHIFT, 19 },
		{ 85, YYAT_ERROR, 0 },
		{ 85, YYAT_ERROR, 0 },
		{ 102, YYAT_SHIFT, 73 },
		{ 102, YYAT_SHIFT, 74 },
		{ 102, YYAT_SHIFT, 75 },
		{ 102, YYAT_SHIFT, 76 },
		{ 42, YYAT_SHIFT, 73 },
		{ 42, YYAT_SHIFT, 74 },
		{ 42, YYAT_SHIFT, 75 },
		{ 42, YYAT_SHIFT, 76 },
		{ 126, YYAT_SHIFT, 20 },
		{ 98, YYAT_SHIFT, 69 },
		{ 85, YYAT_ERROR, 0 },
		{ 126, YYAT_SHIFT, 21 },
		{ 95, YYAT_SHIFT, 59 },
		{ 126, YYAT_SHIFT, 22 },
		{ 92, YYAT_SHIFT, 120 },
		{ 126, YYAT_SHIFT, 5 },
		{ 112, YYAT_SHIFT, 83 },
		{ 112, YYAT_SHIFT, 84 },
		{ 112, YYAT_SHIFT, 85 },
		{ 91, YYAT_SHIFT, 119 },
		{ 118, YYAT_ERROR, 0 },
		{ 102, YYAT_SHIFT, 77 },
		{ 102, YYAT_SHIFT, 78 },
		{ 90, YYAT_SHIFT, 21 },
		{ 118, YYAT_ERROR, 0 },
		{ 42, YYAT_SHIFT, 77 },
		{ 42, YYAT_SHIFT, 78 },
		{ 111, YYAT_SHIFT, 83 },
		{ 111, YYAT_SHIFT, 84 },
		{ 111, YYAT_SHIFT, 85 },
		{ 45, YYAT_SHIFT, 83 },
		{ 45, YYAT_SHIFT, 84 },
		{ 45, YYAT_SHIFT, 85 },
		{ 110, YYAT_SHIFT, 81 },
		{ 110, YYAT_SHIFT, 82 },
		{ 109, YYAT_SHIFT, 81 },
		{ 109, YYAT_SHIFT, 82 },
		{ 108, YYAT_SHIFT, 79 },
		{ 108, YYAT_SHIFT, 80 },
		{ 107, YYAT_SHIFT, 79 },
		{ 107, YYAT_SHIFT, 80 },
		{ 106, YYAT_SHIFT, 79 },
		{ 106, YYAT_SHIFT, 80 },
		{ 105, YYAT_SHIFT, 79 },
		{ 105, YYAT_SHIFT, 80 },
		{ 104, YYAT_SHIFT, 79 },
		{ 104, YYAT_SHIFT, 80 },
		{ 103, YYAT_SHIFT, 79 },
		{ 103, YYAT_SHIFT, 80 },
		{ 60, YYAT_SHIFT, 94 },
		{ 60, YYAT_SHIFT, 95 },
		{ 46, YYAT_SHIFT, 86 },
		{ 46, YYAT_SHIFT, 87 },
		{ 44, YYAT_SHIFT, 81 },
		{ 44, YYAT_SHIFT, 82 },
		{ 43, YYAT_SHIFT, 79 },
		{ 43, YYAT_SHIFT, 80 },
		{ 26, YYAT_SHIFT, 7 },
		{ 26, YYAT_SHIFT, 8 },
		{ 89, YYAT_SHIFT, 117 },
		{ 88, YYAT_SHIFT, 116 },
		{ 63, YYAT_SHIFT, 96 },
		{ 58, YYAT_SHIFT, 93 },
		{ 52, YYAT_SHIFT, 14 },
		{ 41, YYAT_SHIFT, 72 },
		{ 40, YYAT_SHIFT, 71 },
		{ 39, YYAT_SHIFT, 70 },
		{ 38, YYAT_SHIFT, 69 },
		{ 37, YYAT_SHIFT, 68 },
		{ 36, YYAT_SHIFT, 67 },
		{ 35, YYAT_SHIFT, 66 },
		{ 27, YYAT_SHIFT, 64 },
		{ 13, YYAT_SHIFT, 52 },
		{ 12, YYAT_SHIFT, 51 },
		{ 11, YYAT_SHIFT, 50 },
		{ 10, YYAT_SHIFT, 49 },
		{ 9, YYAT_SHIFT, 48 },
		{ 4, YYAT_SHIFT, 5 },
		{ 3, YYAT_SHIFT, 4 },
		{ 2, YYAT_ACCEPT, 0 },
		{ 1, YYAT_SHIFT, 3 },
		{ 0, YYAT_SHIFT, 1 }
	};
	yytokenaction = tokenaction;

	static const yystateaction_t YYNEARFAR YYBASED_CODE stateaction[] = {
		{ -165, 1, YYAT_ERROR, 0 },
		{ -192, 1, YYAT_ERROR, 0 },
		{ 101, 1, YYAT_ERROR, 0 },
		{ -195, 1, YYAT_ERROR, 0 },
		{ -197, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_DEFAULT, 26 },
		{ 0, 0, YYAT_REDUCE, 1 },
		{ 0, 0, YYAT_REDUCE, 5 },
		{ 0, 0, YYAT_REDUCE, 6 },
		{ -196, 1, YYAT_ERROR, 0 },
		{ -197, 1, YYAT_ERROR, 0 },
		{ -198, 1, YYAT_ERROR, 0 },
		{ -199, 1, YYAT_ERROR, 0 },
		{ -200, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_REDUCE, 31 },
		{ 0, 0, YYAT_REDUCE, 67 },
		{ 0, 0, YYAT_REDUCE, 68 },
		{ 0, 0, YYAT_DEFAULT, 85 },
		{ 0, 0, YYAT_DEFAULT, 85 },
		{ 0, 0, YYAT_DEFAULT, 85 },
		{ 0, 0, YYAT_DEFAULT, 85 },
		{ 0, 0, YYAT_REDUCE, 22 },
		{ 0, 0, YYAT_DEFAULT, 118 },
		{ 0, 0, YYAT_REDUCE, 15 },
		{ 0, 0, YYAT_REDUCE, 11 },
		{ 0, 0, YYAT_DEFAULT, 95 },
		{ -178, 1, YYAT_DEFAULT, 126 },
		{ -204, 1, YYAT_DEFAULT, 126 },
		{ 0, 0, YYAT_REDUCE, 13 },
		{ 0, 0, YYAT_REDUCE, 14 },
		{ 0, 0, YYAT_REDUCE, 16 },
		{ 0, 0, YYAT_REDUCE, 17 },
		{ 0, 0, YYAT_REDUCE, 18 },
		{ 0, 0, YYAT_REDUCE, 19 },
		{ 0, 0, YYAT_REDUCE, 20 },
		{ -200, 1, YYAT_ERROR, 0 },
		{ -185, 1, YYAT_REDUCE, 66 },
		{ -183, 1, YYAT_REDUCE, 30 },
		{ -185, 1, YYAT_REDUCE, 33 },
		{ -199, 1, YYAT_REDUCE, 35 },
		{ -201, 1, YYAT_REDUCE, 37 },
		{ -200, 1, YYAT_REDUCE, 39 },
		{ -243, 1, YYAT_REDUCE, 41 },
		{ -202, 1, YYAT_REDUCE, 48 },
		{ -206, 1, YYAT_REDUCE, 51 },
		{ -231, 1, YYAT_REDUCE, 54 },
		{ -204, 1, YYAT_REDUCE, 64 },
		{ 0, 0, YYAT_REDUCE, 58 },
		{ 0, 0, YYAT_DEFAULT, 118 },
		{ 0, 0, YYAT_DEFAULT, 118 },
		{ 0, 0, YYAT_DEFAULT, 90 },
		{ 0, 0, YYAT_DEFAULT, 52 },
		{ -180, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_REDUCE, 66 },
		{ 0, 0, YYAT_REDUCE, 69 },
		{ 0, 0, YYAT_REDUCE, 59 },
		{ 0, 0, YYAT_REDUCE, 61 },
		{ 0, 0, YYAT_REDUCE, 63 },
		{ -211, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_REDUCE, 7 },
		{ -221, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_REDUCE, 4 },
		{ 0, 0, YYAT_REDUCE, 10 },
		{ -214, 1, YYAT_DEFAULT, 126 },
		{ 0, 0, YYAT_REDUCE, 9 },
		{ 0, 0, YYAT_REDUCE, 12 },
		{ 0, 0, YYAT_REDUCE, 21 },
		{ 0, 0, YYAT_DEFAULT, 118 },
		{ 0, 0, YYAT_DEFAULT, 118 },
		{ 0, 0, YYAT_DEFAULT, 118 },
		{ 0, 0, YYAT_DEFAULT, 118 },
		{ 0, 0, YYAT_DEFAULT, 118 },
		{ 0, 0, YYAT_DEFAULT, 118 },
		{ 0, 0, YYAT_DEFAULT, 118 },
		{ 0, 0, YYAT_DEFAULT, 118 },
		{ 0, 0, YYAT_DEFAULT, 118 },
		{ 0, 0, YYAT_DEFAULT, 118 },
		{ 0, 0, YYAT_DEFAULT, 118 },
		{ 0, 0, YYAT_DEFAULT, 118 },
		{ 0, 0, YYAT_DEFAULT, 118 },
		{ 0, 0, YYAT_DEFAULT, 118 },
		{ 0, 0, YYAT_DEFAULT, 118 },
		{ 0, 0, YYAT_DEFAULT, 118 },
		{ 0, 0, YYAT_DEFAULT, 85 },
		{ 0, 0, YYAT_DEFAULT, 85 },
		{ -257, 1, YYAT_DEFAULT, 118 },
		{ 0, 0, YYAT_REDUCE, 60 },
		{ 0, 0, YYAT_REDUCE, 62 },
		{ -213, 1, YYAT_ERROR, 0 },
		{ -214, 1, YYAT_ERROR, 0 },
		{ -247, 1, YYAT_DEFAULT, 118 },
		{ -254, 1, YYAT_ERROR, 0 },
		{ -259, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_REDUCE, 65 },
		{ 0, 0, YYAT_REDUCE, 2 },
		{ -231, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_REDUCE, 8 },
		{ 0, 0, YYAT_REDUCE, 29 },
		{ -243, 1, YYAT_REDUCE, 32 },
		{ -270, 1, YYAT_REDUCE, 34 },
		{ -273, 1, YYAT_REDUCE, 36 },
		{ -276, 1, YYAT_REDUCE, 38 },
		{ -247, 1, YYAT_REDUCE, 40 },
		{ -210, 1, YYAT_REDUCE, 42 },
		{ -212, 1, YYAT_REDUCE, 47 },
		{ -214, 1, YYAT_REDUCE, 46 },
		{ -216, 1, YYAT_REDUCE, 45 },
		{ -218, 1, YYAT_REDUCE, 43 },
		{ -220, 1, YYAT_REDUCE, 44 },
		{ -224, 1, YYAT_REDUCE, 49 },
		{ -226, 1, YYAT_REDUCE, 50 },
		{ -234, 1, YYAT_REDUCE, 52 },
		{ -245, 1, YYAT_REDUCE, 53 },
		{ 0, 0, YYAT_REDUCE, 55 },
		{ 0, 0, YYAT_REDUCE, 56 },
		{ 0, 0, YYAT_REDUCE, 57 },
		{ 0, 0, YYAT_DEFAULT, 126 },
		{ 0, 0, YYAT_DEFAULT, 126 },
		{ -250, 1, YYAT_DEFAULT, 126 },
		{ 0, 0, YYAT_REDUCE, 27 },
		{ 0, 0, YYAT_REDUCE, 28 },
		{ 0, 0, YYAT_REDUCE, 3 },
		{ -254, 1, YYAT_REDUCE, 24 },
		{ 0, 0, YYAT_REDUCE, 25 },
		{ -294, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_DEFAULT, 126 },
		{ -259, 1, YYAT_DEFAULT, 52 },
		{ 0, 0, YYAT_REDUCE, 23 },
		{ 0, 0, YYAT_REDUCE, 26 }
	};
	yystateaction = stateaction;

	yynontermgoto_size = 69;

	static const yynontermgoto_t YYNEARFAR YYBASED_CODE nontermgoto[] = {
		{ 126, 23 },
		{ 125, 127 },
		{ 85, 53 },
		{ 126, 128 },
		{ 126, 29 },
		{ 126, 30 },
		{ 126, 31 },
		{ 126, 32 },
		{ 126, 33 },
		{ 126, 34 },
		{ 26, 62 },
		{ 117, 123 },
		{ 26, 25 },
		{ 85, 115 },
		{ 80, 110 },
		{ 80, 45 },
		{ 26, 63 },
		{ 26, 28 },
		{ 118, 124 },
		{ 118, 36 },
		{ 118, 37 },
		{ 118, 38 },
		{ 5, 24 },
		{ 90, 118 },
		{ 82, 112 },
		{ 82, 47 },
		{ 82, 46 },
		{ 5, 26 },
		{ 5, 27 },
		{ 90, 35 },
		{ 25, 60 },
		{ 116, 122 },
		{ 25, 61 },
		{ 78, 108 },
		{ 78, 44 },
		{ 72, 102 },
		{ 72, 43 },
		{ 71, 101 },
		{ 71, 42 },
		{ 70, 100 },
		{ 70, 41 },
		{ 69, 99 },
		{ 69, 40 },
		{ 68, 98 },
		{ 68, 39 },
		{ 95, 121 },
		{ 84, 114 },
		{ 83, 113 },
		{ 81, 111 },
		{ 79, 109 },
		{ 77, 107 },
		{ 76, 106 },
		{ 75, 105 },
		{ 74, 104 },
		{ 73, 103 },
		{ 67, 97 },
		{ 63, 65 },
		{ 52, 92 },
		{ 51, 91 },
		{ 50, 90 },
		{ 49, 89 },
		{ 48, 88 },
		{ 22, 58 },
		{ 20, 57 },
		{ 19, 56 },
		{ 18, 55 },
		{ 17, 54 },
		{ 4, 6 },
		{ 0, 2 }
	};
	yynontermgoto = nontermgoto;

	static const yystategoto_t YYNEARFAR YYBASED_CODE stategoto[] = {
		{ 67, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 61, -1 },
		{ 20, 26 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 38, 85 },
		{ 37, 85 },
		{ 36, 85 },
		{ 35, 85 },
		{ 0, -1 },
		{ 46, 118 },
		{ 0, -1 },
		{ 0, -1 },
		{ 27, -1 },
		{ 8, 126 },
		{ 0, 63 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 45, 118 },
		{ 44, 118 },
		{ 49, 90 },
		{ 41, -1 },
		{ 40, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 47, 126 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 39, 118 },
		{ 24, 69 },
		{ 21, 70 },
		{ 18, 71 },
		{ 15, 72 },
		{ 12, 78 },
		{ 30, 78 },
		{ 29, 78 },
		{ 28, 78 },
		{ 27, 78 },
		{ 26, 78 },
		{ 9, 80 },
		{ 24, 80 },
		{ -11, 82 },
		{ 22, 82 },
		{ -2, 85 },
		{ 19, 85 },
		{ 18, 85 },
		{ -15, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 13, 118 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 40, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 22, 126 },
		{ 2, 126 },
		{ 2, 68 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ -8, 126 },
		{ -6, 90 },
		{ 0, -1 },
		{ 0, -1 }
	};
	yystategoto = stategoto;

	yydestructorptr = NULL;

	yytokendestptr = NULL;
	yytokendest_size = 0;

	yytokendestbaseptr = NULL;
	yytokendestbase_size = 0;
}
#line 398 ".\\parser.y"


int main(int argc, char *argv[])
{
	int n = 1;
	lexer lexer;
	parser parser;
	if(parser.yycreate(&lexer))
	{
		if(lexer.yycreate(&parser))
		{
			lexer.yyin = new ifstream(argv[1]);
			lexer.yyout = new ofstream(argv[2]);
			n = parser.yyparse();
			parse_tree.get_label();
			parse_tree.gen_code(*lexer.yyout);
		}
	}
	getchar();
	return n;
}
