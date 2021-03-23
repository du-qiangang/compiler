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
* parser.h
* C++ header file generated from parser.y.
* 
* Date: 12/17/13
* Time: 23:46:18
* 
* AYACC Version: 2.07
****************************************************************************/

#ifndef _PARSER_H
#define _PARSER_H

#include <yycpars.h>

/////////////////////////////////////////////////////////////////////////////
// parser

#ifndef YYEXPPARSER
#define YYEXPPARSER
#endif

class YYEXPPARSER YYFAR parser : public _YL yyfparser {
public:
	parser();
	virtual ~parser();

protected:
	void yytables();
	virtual void yyaction(int action);
#ifdef YYDEBUG
	void YYFAR* yyattribute1(int index) const;
	void yyinitdebug(void YYFAR** p, int count) const;
#endif

	// attribute functions
	virtual void yystacktoval(int index);
	virtual void yyvaltostack(int index);
	virtual void yylvaltoval();
	virtual void yyvaltolval();
	virtual void yylvaltostack(int index);

	virtual void YYFAR* yynewattribute(int count);
	virtual void yydeleteattribute(void YYFAR* attribute);
	virtual void yycopyattribute(void YYFAR* dest, const void YYFAR* src, int count);

public:
};

#ifndef YYPARSERNAME
#define YYPARSERNAME parser
#endif

#line 20 ".\\parser.y"

	#ifndef YYSTYPE
	#define YYSTYPE Node *
	#endif

#line 77 "parser.h"
#define INT 257
#define CHAR 258
#define IF 259
#define ELSE 260
#define WHILE 261
#define FOR 262
#define INPUT 263
#define PRINT 264
#define ID 265
#define NUM 266
#define CONSTCHAR 267
#define MAIN 268
#define EQ 269
#define NE 270
#define GE 271
#define LE 272
#define OR 273
#define AND 274
#define NOT 275
#define ASSIGN 276
#define INC 277
#define DEC 278
#define SHR 279
#define SHL 280
#define PLUS 281
#define MINUS 282
#define TIMES 283
#define OVER 284
#define REM 285
#define BAND 286
#define BOR 287
#define BXOR 288
#define BNOT 289
#define LT 290
#define GT 291
#define SEMICOLON 292
#define COMMA 293
#define LPAREN 294
#define RPAREN 295
#define LBRACE 296
#define RBRACE 297
#define ERROR 298
#endif
