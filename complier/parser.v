#############################################################################
#                     U N R E G I S T E R E D   C O P Y
# 
# You are on day 82 of your 30 day trial period.
# 
# This file was produced by an UNREGISTERED COPY of Parser Generator. It is
# for evaluation purposes only. If you continue to use Parser Generator 30
# days after installation then you are required to purchase a license. For
# more information see the online help or go to the Bumble-Bee Software
# homepage at:
# 
# http://www.bumblebeesoftware.com
# 
# This notice must remain present in the file. It cannot be removed.
#############################################################################

#############################################################################
# parser.v
# YACC verbose file generated from parser.y.
# 
# Date: 12/17/13
# Time: 23:46:18
# 
# AYACC Version: 2.07
#############################################################################


##############################################################################
# Rules
##############################################################################

    0  $accept : program $end

    1  program : MAIN LPAREN RPAREN compound_stmt

    2  var_declaration : type_specifier idlist SEMICOLON

    3  idlist : idlist COMMA id
    4         | id

    5  type_specifier : INT
    6                 | CHAR

    7  id : ID

    8  compound_stmt : LBRACE local_declarations statement_list RBRACE
    9                | LBRACE statement_list RBRACE

   10  local_declarations : local_declarations var_declaration
   11                     | var_declaration

   12  statement_list : statement_list statement
   13                 | statement

   14  statement : expression_stmt
   15            | compound_stmt
   16            | selection_stmt
   17            | while_stmt
   18            | for_stmt
   19            | input_stmt
   20            | print_stmt

   21  expression_stmt : expression SEMICOLON
   22                  | SEMICOLON

   23  selection_stmt : IF LPAREN expression RPAREN statement ELSE statement
   24                 | IF LPAREN expression RPAREN statement

   25  while_stmt : WHILE LPAREN expression RPAREN statement

   26  for_stmt : FOR LPAREN expression_stmt expression_stmt expression RPAREN statement

   27  input_stmt : INPUT LPAREN var RPAREN

   28  print_stmt : PRINT LPAREN var RPAREN

   29  expression : var ASSIGN expression
   30             | or_expression

   31  var : ID

   32  or_expression : or_expression OR and_expression
   33                | and_expression

   34  and_expression : and_expression AND bor_expression
   35                 | bor_expression

   36  bor_expression : bor_expression BOR bxor_expression
   37                 | bxor_expression

   38  bxor_expression : bxor_expression BXOR band_expression
   39                  | band_expression

   40  band_expression : band_expression BAND additive_expression
   41                  | additive_expression

   42  additive_expression : additive_expression EQ shift_expression
   43                      | additive_expression LT shift_expression
   44                      | additive_expression GT shift_expression
   45                      | additive_expression LE shift_expression
   46                      | additive_expression GE shift_expression
   47                      | additive_expression NE shift_expression
   48                      | shift_expression

   49  shift_expression : shift_expression SHR rel_expression
   50                   | shift_expression SHL rel_expression
   51                   | rel_expression

   52  rel_expression : rel_expression PLUS term
   53                 | rel_expression MINUS term
   54                 | term

   55  term : term TIMES factor
   56       | term OVER factor
   57       | term REM factor
   58       | short_term

   59  short_term : INC factor
   60             | factor INC
   61             | DEC factor
   62             | factor DEC
   63             | BNOT factor
   64             | factor

   65  factor : LPAREN expression RPAREN
   66         | var
   67         | NUM
   68         | CONSTCHAR
   69         | NOT factor


##############################################################################
# States
##############################################################################

state 0
	$accept : . program $end

	MAIN  shift 1

	program  goto 2


state 1
	program : MAIN . LPAREN RPAREN compound_stmt

	LPAREN  shift 3


state 2
	$accept : program . $end  (0)

	$end  accept


state 3
	program : MAIN LPAREN . RPAREN compound_stmt

	RPAREN  shift 4


state 4
	program : MAIN LPAREN RPAREN . compound_stmt

	LBRACE  shift 5

	compound_stmt  goto 6


state 5
	compound_stmt : LBRACE . local_declarations statement_list RBRACE
	compound_stmt : LBRACE . statement_list RBRACE

	INT  shift 7
	CHAR  shift 8
	IF  shift 9
	WHILE  shift 10
	FOR  shift 11
	INPUT  shift 12
	PRINT  shift 13
	ID  shift 14
	NUM  shift 15
	CONSTCHAR  shift 16
	NOT  shift 17
	INC  shift 18
	DEC  shift 19
	BNOT  shift 20
	SEMICOLON  shift 21
	LPAREN  shift 22
	LBRACE  shift 5

	compound_stmt  goto 23
	var_declaration  goto 24
	type_specifier  goto 25
	local_declarations  goto 26
	statement_list  goto 27
	statement  goto 28
	expression_stmt  goto 29
	selection_stmt  goto 30
	while_stmt  goto 31
	for_stmt  goto 32
	input_stmt  goto 33
	print_stmt  goto 34
	expression  goto 35
	var  goto 36
	or_expression  goto 37
	and_expression  goto 38
	bor_expression  goto 39
	bxor_expression  goto 40
	band_expression  goto 41
	additive_expression  goto 42
	shift_expression  goto 43
	rel_expression  goto 44
	term  goto 45
	factor  goto 46
	short_term  goto 47


state 6
	program : MAIN LPAREN RPAREN compound_stmt .  (1)

	.  reduce 1


state 7
	type_specifier : INT .  (5)

	.  reduce 5


state 8
	type_specifier : CHAR .  (6)

	.  reduce 6


state 9
	selection_stmt : IF . LPAREN expression RPAREN statement ELSE statement
	selection_stmt : IF . LPAREN expression RPAREN statement

	LPAREN  shift 48


state 10
	while_stmt : WHILE . LPAREN expression RPAREN statement

	LPAREN  shift 49


state 11
	for_stmt : FOR . LPAREN expression_stmt expression_stmt expression RPAREN statement

	LPAREN  shift 50


state 12
	input_stmt : INPUT . LPAREN var RPAREN

	LPAREN  shift 51


state 13
	print_stmt : PRINT . LPAREN var RPAREN

	LPAREN  shift 52


state 14
	var : ID .  (31)

	.  reduce 31


state 15
	factor : NUM .  (67)

	.  reduce 67


state 16
	factor : CONSTCHAR .  (68)

	.  reduce 68


state 17
	factor : NOT . factor

	ID  shift 14
	NUM  shift 15
	CONSTCHAR  shift 16
	NOT  shift 17
	LPAREN  shift 22

	var  goto 53
	factor  goto 54


state 18
	short_term : INC . factor

	ID  shift 14
	NUM  shift 15
	CONSTCHAR  shift 16
	NOT  shift 17
	LPAREN  shift 22

	var  goto 53
	factor  goto 55


state 19
	short_term : DEC . factor

	ID  shift 14
	NUM  shift 15
	CONSTCHAR  shift 16
	NOT  shift 17
	LPAREN  shift 22

	var  goto 53
	factor  goto 56


state 20
	short_term : BNOT . factor

	ID  shift 14
	NUM  shift 15
	CONSTCHAR  shift 16
	NOT  shift 17
	LPAREN  shift 22

	var  goto 53
	factor  goto 57


state 21
	expression_stmt : SEMICOLON .  (22)

	.  reduce 22


state 22
	factor : LPAREN . expression RPAREN

	ID  shift 14
	NUM  shift 15
	CONSTCHAR  shift 16
	NOT  shift 17
	INC  shift 18
	DEC  shift 19
	BNOT  shift 20
	LPAREN  shift 22

	expression  goto 58
	var  goto 36
	or_expression  goto 37
	and_expression  goto 38
	bor_expression  goto 39
	bxor_expression  goto 40
	band_expression  goto 41
	additive_expression  goto 42
	shift_expression  goto 43
	rel_expression  goto 44
	term  goto 45
	factor  goto 46
	short_term  goto 47


state 23
	statement : compound_stmt .  (15)

	.  reduce 15


state 24
	local_declarations : var_declaration .  (11)

	.  reduce 11


state 25
	var_declaration : type_specifier . idlist SEMICOLON

	ID  shift 59

	idlist  goto 60
	id  goto 61


state 26
	compound_stmt : LBRACE local_declarations . statement_list RBRACE
	local_declarations : local_declarations . var_declaration

	INT  shift 7
	CHAR  shift 8
	IF  shift 9
	WHILE  shift 10
	FOR  shift 11
	INPUT  shift 12
	PRINT  shift 13
	ID  shift 14
	NUM  shift 15
	CONSTCHAR  shift 16
	NOT  shift 17
	INC  shift 18
	DEC  shift 19
	BNOT  shift 20
	SEMICOLON  shift 21
	LPAREN  shift 22
	LBRACE  shift 5

	compound_stmt  goto 23
	var_declaration  goto 62
	type_specifier  goto 25
	statement_list  goto 63
	statement  goto 28
	expression_stmt  goto 29
	selection_stmt  goto 30
	while_stmt  goto 31
	for_stmt  goto 32
	input_stmt  goto 33
	print_stmt  goto 34
	expression  goto 35
	var  goto 36
	or_expression  goto 37
	and_expression  goto 38
	bor_expression  goto 39
	bxor_expression  goto 40
	band_expression  goto 41
	additive_expression  goto 42
	shift_expression  goto 43
	rel_expression  goto 44
	term  goto 45
	factor  goto 46
	short_term  goto 47


state 27
	compound_stmt : LBRACE statement_list . RBRACE
	statement_list : statement_list . statement

	IF  shift 9
	WHILE  shift 10
	FOR  shift 11
	INPUT  shift 12
	PRINT  shift 13
	ID  shift 14
	NUM  shift 15
	CONSTCHAR  shift 16
	NOT  shift 17
	INC  shift 18
	DEC  shift 19
	BNOT  shift 20
	SEMICOLON  shift 21
	LPAREN  shift 22
	LBRACE  shift 5
	RBRACE  shift 64

	compound_stmt  goto 23
	statement  goto 65
	expression_stmt  goto 29
	selection_stmt  goto 30
	while_stmt  goto 31
	for_stmt  goto 32
	input_stmt  goto 33
	print_stmt  goto 34
	expression  goto 35
	var  goto 36
	or_expression  goto 37
	and_expression  goto 38
	bor_expression  goto 39
	bxor_expression  goto 40
	band_expression  goto 41
	additive_expression  goto 42
	shift_expression  goto 43
	rel_expression  goto 44
	term  goto 45
	factor  goto 46
	short_term  goto 47


state 28
	statement_list : statement .  (13)

	.  reduce 13


state 29
	statement : expression_stmt .  (14)

	.  reduce 14


state 30
	statement : selection_stmt .  (16)

	.  reduce 16


state 31
	statement : while_stmt .  (17)

	.  reduce 17


state 32
	statement : for_stmt .  (18)

	.  reduce 18


state 33
	statement : input_stmt .  (19)

	.  reduce 19


state 34
	statement : print_stmt .  (20)

	.  reduce 20


state 35
	expression_stmt : expression . SEMICOLON

	SEMICOLON  shift 66


state 36
	expression : var . ASSIGN expression
	factor : var .  (66)

	ASSIGN  shift 67
	.  reduce 66


state 37
	expression : or_expression .  (30)
	or_expression : or_expression . OR and_expression

	OR  shift 68
	.  reduce 30


state 38
	or_expression : and_expression .  (33)
	and_expression : and_expression . AND bor_expression

	AND  shift 69
	.  reduce 33


state 39
	and_expression : bor_expression .  (35)
	bor_expression : bor_expression . BOR bxor_expression

	BOR  shift 70
	.  reduce 35


state 40
	bor_expression : bxor_expression .  (37)
	bxor_expression : bxor_expression . BXOR band_expression

	BXOR  shift 71
	.  reduce 37


state 41
	bxor_expression : band_expression .  (39)
	band_expression : band_expression . BAND additive_expression

	BAND  shift 72
	.  reduce 39


state 42
	band_expression : additive_expression .  (41)
	additive_expression : additive_expression . EQ shift_expression
	additive_expression : additive_expression . LT shift_expression
	additive_expression : additive_expression . GT shift_expression
	additive_expression : additive_expression . LE shift_expression
	additive_expression : additive_expression . GE shift_expression
	additive_expression : additive_expression . NE shift_expression

	EQ  shift 73
	NE  shift 74
	GE  shift 75
	LE  shift 76
	LT  shift 77
	GT  shift 78
	.  reduce 41


state 43
	additive_expression : shift_expression .  (48)
	shift_expression : shift_expression . SHR rel_expression
	shift_expression : shift_expression . SHL rel_expression

	SHR  shift 79
	SHL  shift 80
	.  reduce 48


state 44
	shift_expression : rel_expression .  (51)
	rel_expression : rel_expression . PLUS term
	rel_expression : rel_expression . MINUS term

	PLUS  shift 81
	MINUS  shift 82
	.  reduce 51


state 45
	rel_expression : term .  (54)
	term : term . TIMES factor
	term : term . OVER factor
	term : term . REM factor

	TIMES  shift 83
	OVER  shift 84
	REM  shift 85
	.  reduce 54


state 46
	short_term : factor . INC
	short_term : factor . DEC
	short_term : factor .  (64)

	INC  shift 86
	DEC  shift 87
	.  reduce 64


state 47
	term : short_term .  (58)

	.  reduce 58


state 48
	selection_stmt : IF LPAREN . expression RPAREN statement ELSE statement
	selection_stmt : IF LPAREN . expression RPAREN statement

	ID  shift 14
	NUM  shift 15
	CONSTCHAR  shift 16
	NOT  shift 17
	INC  shift 18
	DEC  shift 19
	BNOT  shift 20
	LPAREN  shift 22

	expression  goto 88
	var  goto 36
	or_expression  goto 37
	and_expression  goto 38
	bor_expression  goto 39
	bxor_expression  goto 40
	band_expression  goto 41
	additive_expression  goto 42
	shift_expression  goto 43
	rel_expression  goto 44
	term  goto 45
	factor  goto 46
	short_term  goto 47


state 49
	while_stmt : WHILE LPAREN . expression RPAREN statement

	ID  shift 14
	NUM  shift 15
	CONSTCHAR  shift 16
	NOT  shift 17
	INC  shift 18
	DEC  shift 19
	BNOT  shift 20
	LPAREN  shift 22

	expression  goto 89
	var  goto 36
	or_expression  goto 37
	and_expression  goto 38
	bor_expression  goto 39
	bxor_expression  goto 40
	band_expression  goto 41
	additive_expression  goto 42
	shift_expression  goto 43
	rel_expression  goto 44
	term  goto 45
	factor  goto 46
	short_term  goto 47


state 50
	for_stmt : FOR LPAREN . expression_stmt expression_stmt expression RPAREN statement

	ID  shift 14
	NUM  shift 15
	CONSTCHAR  shift 16
	NOT  shift 17
	INC  shift 18
	DEC  shift 19
	BNOT  shift 20
	SEMICOLON  shift 21
	LPAREN  shift 22

	expression_stmt  goto 90
	expression  goto 35
	var  goto 36
	or_expression  goto 37
	and_expression  goto 38
	bor_expression  goto 39
	bxor_expression  goto 40
	band_expression  goto 41
	additive_expression  goto 42
	shift_expression  goto 43
	rel_expression  goto 44
	term  goto 45
	factor  goto 46
	short_term  goto 47


state 51
	input_stmt : INPUT LPAREN . var RPAREN

	ID  shift 14

	var  goto 91


state 52
	print_stmt : PRINT LPAREN . var RPAREN

	ID  shift 14

	var  goto 92


state 53
	factor : var .  (66)

	.  reduce 66


state 54
	factor : NOT factor .  (69)

	.  reduce 69


state 55
	short_term : INC factor .  (59)

	.  reduce 59


state 56
	short_term : DEC factor .  (61)

	.  reduce 61


state 57
	short_term : BNOT factor .  (63)

	.  reduce 63


state 58
	factor : LPAREN expression . RPAREN

	RPAREN  shift 93


state 59
	id : ID .  (7)

	.  reduce 7


state 60
	var_declaration : type_specifier idlist . SEMICOLON
	idlist : idlist . COMMA id

	SEMICOLON  shift 94
	COMMA  shift 95


state 61
	idlist : id .  (4)

	.  reduce 4


state 62
	local_declarations : local_declarations var_declaration .  (10)

	.  reduce 10


state 63
	compound_stmt : LBRACE local_declarations statement_list . RBRACE
	statement_list : statement_list . statement

	IF  shift 9
	WHILE  shift 10
	FOR  shift 11
	INPUT  shift 12
	PRINT  shift 13
	ID  shift 14
	NUM  shift 15
	CONSTCHAR  shift 16
	NOT  shift 17
	INC  shift 18
	DEC  shift 19
	BNOT  shift 20
	SEMICOLON  shift 21
	LPAREN  shift 22
	LBRACE  shift 5
	RBRACE  shift 96

	compound_stmt  goto 23
	statement  goto 65
	expression_stmt  goto 29
	selection_stmt  goto 30
	while_stmt  goto 31
	for_stmt  goto 32
	input_stmt  goto 33
	print_stmt  goto 34
	expression  goto 35
	var  goto 36
	or_expression  goto 37
	and_expression  goto 38
	bor_expression  goto 39
	bxor_expression  goto 40
	band_expression  goto 41
	additive_expression  goto 42
	shift_expression  goto 43
	rel_expression  goto 44
	term  goto 45
	factor  goto 46
	short_term  goto 47


state 64
	compound_stmt : LBRACE statement_list RBRACE .  (9)

	.  reduce 9


state 65
	statement_list : statement_list statement .  (12)

	.  reduce 12


state 66
	expression_stmt : expression SEMICOLON .  (21)

	.  reduce 21


state 67
	expression : var ASSIGN . expression

	ID  shift 14
	NUM  shift 15
	CONSTCHAR  shift 16
	NOT  shift 17
	INC  shift 18
	DEC  shift 19
	BNOT  shift 20
	LPAREN  shift 22

	expression  goto 97
	var  goto 36
	or_expression  goto 37
	and_expression  goto 38
	bor_expression  goto 39
	bxor_expression  goto 40
	band_expression  goto 41
	additive_expression  goto 42
	shift_expression  goto 43
	rel_expression  goto 44
	term  goto 45
	factor  goto 46
	short_term  goto 47


state 68
	or_expression : or_expression OR . and_expression

	ID  shift 14
	NUM  shift 15
	CONSTCHAR  shift 16
	NOT  shift 17
	INC  shift 18
	DEC  shift 19
	BNOT  shift 20
	LPAREN  shift 22

	var  goto 53
	and_expression  goto 98
	bor_expression  goto 39
	bxor_expression  goto 40
	band_expression  goto 41
	additive_expression  goto 42
	shift_expression  goto 43
	rel_expression  goto 44
	term  goto 45
	factor  goto 46
	short_term  goto 47


state 69
	and_expression : and_expression AND . bor_expression

	ID  shift 14
	NUM  shift 15
	CONSTCHAR  shift 16
	NOT  shift 17
	INC  shift 18
	DEC  shift 19
	BNOT  shift 20
	LPAREN  shift 22

	var  goto 53
	bor_expression  goto 99
	bxor_expression  goto 40
	band_expression  goto 41
	additive_expression  goto 42
	shift_expression  goto 43
	rel_expression  goto 44
	term  goto 45
	factor  goto 46
	short_term  goto 47


state 70
	bor_expression : bor_expression BOR . bxor_expression

	ID  shift 14
	NUM  shift 15
	CONSTCHAR  shift 16
	NOT  shift 17
	INC  shift 18
	DEC  shift 19
	BNOT  shift 20
	LPAREN  shift 22

	var  goto 53
	bxor_expression  goto 100
	band_expression  goto 41
	additive_expression  goto 42
	shift_expression  goto 43
	rel_expression  goto 44
	term  goto 45
	factor  goto 46
	short_term  goto 47


state 71
	bxor_expression : bxor_expression BXOR . band_expression

	ID  shift 14
	NUM  shift 15
	CONSTCHAR  shift 16
	NOT  shift 17
	INC  shift 18
	DEC  shift 19
	BNOT  shift 20
	LPAREN  shift 22

	var  goto 53
	band_expression  goto 101
	additive_expression  goto 42
	shift_expression  goto 43
	rel_expression  goto 44
	term  goto 45
	factor  goto 46
	short_term  goto 47


state 72
	band_expression : band_expression BAND . additive_expression

	ID  shift 14
	NUM  shift 15
	CONSTCHAR  shift 16
	NOT  shift 17
	INC  shift 18
	DEC  shift 19
	BNOT  shift 20
	LPAREN  shift 22

	var  goto 53
	additive_expression  goto 102
	shift_expression  goto 43
	rel_expression  goto 44
	term  goto 45
	factor  goto 46
	short_term  goto 47


state 73
	additive_expression : additive_expression EQ . shift_expression

	ID  shift 14
	NUM  shift 15
	CONSTCHAR  shift 16
	NOT  shift 17
	INC  shift 18
	DEC  shift 19
	BNOT  shift 20
	LPAREN  shift 22

	var  goto 53
	shift_expression  goto 103
	rel_expression  goto 44
	term  goto 45
	factor  goto 46
	short_term  goto 47


state 74
	additive_expression : additive_expression NE . shift_expression

	ID  shift 14
	NUM  shift 15
	CONSTCHAR  shift 16
	NOT  shift 17
	INC  shift 18
	DEC  shift 19
	BNOT  shift 20
	LPAREN  shift 22

	var  goto 53
	shift_expression  goto 104
	rel_expression  goto 44
	term  goto 45
	factor  goto 46
	short_term  goto 47


state 75
	additive_expression : additive_expression GE . shift_expression

	ID  shift 14
	NUM  shift 15
	CONSTCHAR  shift 16
	NOT  shift 17
	INC  shift 18
	DEC  shift 19
	BNOT  shift 20
	LPAREN  shift 22

	var  goto 53
	shift_expression  goto 105
	rel_expression  goto 44
	term  goto 45
	factor  goto 46
	short_term  goto 47


state 76
	additive_expression : additive_expression LE . shift_expression

	ID  shift 14
	NUM  shift 15
	CONSTCHAR  shift 16
	NOT  shift 17
	INC  shift 18
	DEC  shift 19
	BNOT  shift 20
	LPAREN  shift 22

	var  goto 53
	shift_expression  goto 106
	rel_expression  goto 44
	term  goto 45
	factor  goto 46
	short_term  goto 47


state 77
	additive_expression : additive_expression LT . shift_expression

	ID  shift 14
	NUM  shift 15
	CONSTCHAR  shift 16
	NOT  shift 17
	INC  shift 18
	DEC  shift 19
	BNOT  shift 20
	LPAREN  shift 22

	var  goto 53
	shift_expression  goto 107
	rel_expression  goto 44
	term  goto 45
	factor  goto 46
	short_term  goto 47


state 78
	additive_expression : additive_expression GT . shift_expression

	ID  shift 14
	NUM  shift 15
	CONSTCHAR  shift 16
	NOT  shift 17
	INC  shift 18
	DEC  shift 19
	BNOT  shift 20
	LPAREN  shift 22

	var  goto 53
	shift_expression  goto 108
	rel_expression  goto 44
	term  goto 45
	factor  goto 46
	short_term  goto 47


state 79
	shift_expression : shift_expression SHR . rel_expression

	ID  shift 14
	NUM  shift 15
	CONSTCHAR  shift 16
	NOT  shift 17
	INC  shift 18
	DEC  shift 19
	BNOT  shift 20
	LPAREN  shift 22

	var  goto 53
	rel_expression  goto 109
	term  goto 45
	factor  goto 46
	short_term  goto 47


state 80
	shift_expression : shift_expression SHL . rel_expression

	ID  shift 14
	NUM  shift 15
	CONSTCHAR  shift 16
	NOT  shift 17
	INC  shift 18
	DEC  shift 19
	BNOT  shift 20
	LPAREN  shift 22

	var  goto 53
	rel_expression  goto 110
	term  goto 45
	factor  goto 46
	short_term  goto 47


state 81
	rel_expression : rel_expression PLUS . term

	ID  shift 14
	NUM  shift 15
	CONSTCHAR  shift 16
	NOT  shift 17
	INC  shift 18
	DEC  shift 19
	BNOT  shift 20
	LPAREN  shift 22

	var  goto 53
	term  goto 111
	factor  goto 46
	short_term  goto 47


state 82
	rel_expression : rel_expression MINUS . term

	ID  shift 14
	NUM  shift 15
	CONSTCHAR  shift 16
	NOT  shift 17
	INC  shift 18
	DEC  shift 19
	BNOT  shift 20
	LPAREN  shift 22

	var  goto 53
	term  goto 112
	factor  goto 46
	short_term  goto 47


state 83
	term : term TIMES . factor

	ID  shift 14
	NUM  shift 15
	CONSTCHAR  shift 16
	NOT  shift 17
	LPAREN  shift 22

	var  goto 53
	factor  goto 113


state 84
	term : term OVER . factor

	ID  shift 14
	NUM  shift 15
	CONSTCHAR  shift 16
	NOT  shift 17
	LPAREN  shift 22

	var  goto 53
	factor  goto 114


state 85
	term : term REM . factor

	ID  shift 14
	NUM  shift 15
	CONSTCHAR  shift 16
	NOT  shift 17
	LPAREN  shift 22

	var  goto 53
	factor  goto 115


state 86
	short_term : factor INC .  (60)

	.  reduce 60


state 87
	short_term : factor DEC .  (62)

	.  reduce 62


state 88
	selection_stmt : IF LPAREN expression . RPAREN statement ELSE statement
	selection_stmt : IF LPAREN expression . RPAREN statement

	RPAREN  shift 116


state 89
	while_stmt : WHILE LPAREN expression . RPAREN statement

	RPAREN  shift 117


state 90
	for_stmt : FOR LPAREN expression_stmt . expression_stmt expression RPAREN statement

	ID  shift 14
	NUM  shift 15
	CONSTCHAR  shift 16
	NOT  shift 17
	INC  shift 18
	DEC  shift 19
	BNOT  shift 20
	SEMICOLON  shift 21
	LPAREN  shift 22

	expression_stmt  goto 118
	expression  goto 35
	var  goto 36
	or_expression  goto 37
	and_expression  goto 38
	bor_expression  goto 39
	bxor_expression  goto 40
	band_expression  goto 41
	additive_expression  goto 42
	shift_expression  goto 43
	rel_expression  goto 44
	term  goto 45
	factor  goto 46
	short_term  goto 47


state 91
	input_stmt : INPUT LPAREN var . RPAREN

	RPAREN  shift 119


state 92
	print_stmt : PRINT LPAREN var . RPAREN

	RPAREN  shift 120


state 93
	factor : LPAREN expression RPAREN .  (65)

	.  reduce 65


state 94
	var_declaration : type_specifier idlist SEMICOLON .  (2)

	.  reduce 2


state 95
	idlist : idlist COMMA . id

	ID  shift 59

	id  goto 121


state 96
	compound_stmt : LBRACE local_declarations statement_list RBRACE .  (8)

	.  reduce 8


state 97
	expression : var ASSIGN expression .  (29)

	.  reduce 29


state 98
	or_expression : or_expression OR and_expression .  (32)
	and_expression : and_expression . AND bor_expression

	AND  shift 69
	.  reduce 32


state 99
	and_expression : and_expression AND bor_expression .  (34)
	bor_expression : bor_expression . BOR bxor_expression

	BOR  shift 70
	.  reduce 34


state 100
	bor_expression : bor_expression BOR bxor_expression .  (36)
	bxor_expression : bxor_expression . BXOR band_expression

	BXOR  shift 71
	.  reduce 36


state 101
	bxor_expression : bxor_expression BXOR band_expression .  (38)
	band_expression : band_expression . BAND additive_expression

	BAND  shift 72
	.  reduce 38


state 102
	band_expression : band_expression BAND additive_expression .  (40)
	additive_expression : additive_expression . EQ shift_expression
	additive_expression : additive_expression . LT shift_expression
	additive_expression : additive_expression . GT shift_expression
	additive_expression : additive_expression . LE shift_expression
	additive_expression : additive_expression . GE shift_expression
	additive_expression : additive_expression . NE shift_expression

	EQ  shift 73
	NE  shift 74
	GE  shift 75
	LE  shift 76
	LT  shift 77
	GT  shift 78
	.  reduce 40


state 103
	additive_expression : additive_expression EQ shift_expression .  (42)
	shift_expression : shift_expression . SHR rel_expression
	shift_expression : shift_expression . SHL rel_expression

	SHR  shift 79
	SHL  shift 80
	.  reduce 42


state 104
	additive_expression : additive_expression NE shift_expression .  (47)
	shift_expression : shift_expression . SHR rel_expression
	shift_expression : shift_expression . SHL rel_expression

	SHR  shift 79
	SHL  shift 80
	.  reduce 47


state 105
	additive_expression : additive_expression GE shift_expression .  (46)
	shift_expression : shift_expression . SHR rel_expression
	shift_expression : shift_expression . SHL rel_expression

	SHR  shift 79
	SHL  shift 80
	.  reduce 46


state 106
	additive_expression : additive_expression LE shift_expression .  (45)
	shift_expression : shift_expression . SHR rel_expression
	shift_expression : shift_expression . SHL rel_expression

	SHR  shift 79
	SHL  shift 80
	.  reduce 45


state 107
	additive_expression : additive_expression LT shift_expression .  (43)
	shift_expression : shift_expression . SHR rel_expression
	shift_expression : shift_expression . SHL rel_expression

	SHR  shift 79
	SHL  shift 80
	.  reduce 43


state 108
	additive_expression : additive_expression GT shift_expression .  (44)
	shift_expression : shift_expression . SHR rel_expression
	shift_expression : shift_expression . SHL rel_expression

	SHR  shift 79
	SHL  shift 80
	.  reduce 44


state 109
	shift_expression : shift_expression SHR rel_expression .  (49)
	rel_expression : rel_expression . PLUS term
	rel_expression : rel_expression . MINUS term

	PLUS  shift 81
	MINUS  shift 82
	.  reduce 49


state 110
	shift_expression : shift_expression SHL rel_expression .  (50)
	rel_expression : rel_expression . PLUS term
	rel_expression : rel_expression . MINUS term

	PLUS  shift 81
	MINUS  shift 82
	.  reduce 50


state 111
	rel_expression : rel_expression PLUS term .  (52)
	term : term . TIMES factor
	term : term . OVER factor
	term : term . REM factor

	TIMES  shift 83
	OVER  shift 84
	REM  shift 85
	.  reduce 52


state 112
	rel_expression : rel_expression MINUS term .  (53)
	term : term . TIMES factor
	term : term . OVER factor
	term : term . REM factor

	TIMES  shift 83
	OVER  shift 84
	REM  shift 85
	.  reduce 53


state 113
	term : term TIMES factor .  (55)

	.  reduce 55


state 114
	term : term OVER factor .  (56)

	.  reduce 56


state 115
	term : term REM factor .  (57)

	.  reduce 57


state 116
	selection_stmt : IF LPAREN expression RPAREN . statement ELSE statement
	selection_stmt : IF LPAREN expression RPAREN . statement

	IF  shift 9
	WHILE  shift 10
	FOR  shift 11
	INPUT  shift 12
	PRINT  shift 13
	ID  shift 14
	NUM  shift 15
	CONSTCHAR  shift 16
	NOT  shift 17
	INC  shift 18
	DEC  shift 19
	BNOT  shift 20
	SEMICOLON  shift 21
	LPAREN  shift 22
	LBRACE  shift 5

	compound_stmt  goto 23
	statement  goto 122
	expression_stmt  goto 29
	selection_stmt  goto 30
	while_stmt  goto 31
	for_stmt  goto 32
	input_stmt  goto 33
	print_stmt  goto 34
	expression  goto 35
	var  goto 36
	or_expression  goto 37
	and_expression  goto 38
	bor_expression  goto 39
	bxor_expression  goto 40
	band_expression  goto 41
	additive_expression  goto 42
	shift_expression  goto 43
	rel_expression  goto 44
	term  goto 45
	factor  goto 46
	short_term  goto 47


state 117
	while_stmt : WHILE LPAREN expression RPAREN . statement

	IF  shift 9
	WHILE  shift 10
	FOR  shift 11
	INPUT  shift 12
	PRINT  shift 13
	ID  shift 14
	NUM  shift 15
	CONSTCHAR  shift 16
	NOT  shift 17
	INC  shift 18
	DEC  shift 19
	BNOT  shift 20
	SEMICOLON  shift 21
	LPAREN  shift 22
	LBRACE  shift 5

	compound_stmt  goto 23
	statement  goto 123
	expression_stmt  goto 29
	selection_stmt  goto 30
	while_stmt  goto 31
	for_stmt  goto 32
	input_stmt  goto 33
	print_stmt  goto 34
	expression  goto 35
	var  goto 36
	or_expression  goto 37
	and_expression  goto 38
	bor_expression  goto 39
	bxor_expression  goto 40
	band_expression  goto 41
	additive_expression  goto 42
	shift_expression  goto 43
	rel_expression  goto 44
	term  goto 45
	factor  goto 46
	short_term  goto 47


state 118
	for_stmt : FOR LPAREN expression_stmt expression_stmt . expression RPAREN statement

	ID  shift 14
	NUM  shift 15
	CONSTCHAR  shift 16
	NOT  shift 17
	INC  shift 18
	DEC  shift 19
	BNOT  shift 20
	LPAREN  shift 22

	expression  goto 124
	var  goto 36
	or_expression  goto 37
	and_expression  goto 38
	bor_expression  goto 39
	bxor_expression  goto 40
	band_expression  goto 41
	additive_expression  goto 42
	shift_expression  goto 43
	rel_expression  goto 44
	term  goto 45
	factor  goto 46
	short_term  goto 47


state 119
	input_stmt : INPUT LPAREN var RPAREN .  (27)

	.  reduce 27


state 120
	print_stmt : PRINT LPAREN var RPAREN .  (28)

	.  reduce 28


state 121
	idlist : idlist COMMA id .  (3)

	.  reduce 3


122: shift-reduce conflict (shift 125, reduce 24) on ELSE
state 122
	selection_stmt : IF LPAREN expression RPAREN statement . ELSE statement
	selection_stmt : IF LPAREN expression RPAREN statement .  (24)

	ELSE  shift 125
	.  reduce 24


state 123
	while_stmt : WHILE LPAREN expression RPAREN statement .  (25)

	.  reduce 25


state 124
	for_stmt : FOR LPAREN expression_stmt expression_stmt expression . RPAREN statement

	RPAREN  shift 126


state 125
	selection_stmt : IF LPAREN expression RPAREN statement ELSE . statement

	IF  shift 9
	WHILE  shift 10
	FOR  shift 11
	INPUT  shift 12
	PRINT  shift 13
	ID  shift 14
	NUM  shift 15
	CONSTCHAR  shift 16
	NOT  shift 17
	INC  shift 18
	DEC  shift 19
	BNOT  shift 20
	SEMICOLON  shift 21
	LPAREN  shift 22
	LBRACE  shift 5

	compound_stmt  goto 23
	statement  goto 127
	expression_stmt  goto 29
	selection_stmt  goto 30
	while_stmt  goto 31
	for_stmt  goto 32
	input_stmt  goto 33
	print_stmt  goto 34
	expression  goto 35
	var  goto 36
	or_expression  goto 37
	and_expression  goto 38
	bor_expression  goto 39
	bxor_expression  goto 40
	band_expression  goto 41
	additive_expression  goto 42
	shift_expression  goto 43
	rel_expression  goto 44
	term  goto 45
	factor  goto 46
	short_term  goto 47


state 126
	for_stmt : FOR LPAREN expression_stmt expression_stmt expression RPAREN . statement

	IF  shift 9
	WHILE  shift 10
	FOR  shift 11
	INPUT  shift 12
	PRINT  shift 13
	ID  shift 14
	NUM  shift 15
	CONSTCHAR  shift 16
	NOT  shift 17
	INC  shift 18
	DEC  shift 19
	BNOT  shift 20
	SEMICOLON  shift 21
	LPAREN  shift 22
	LBRACE  shift 5

	compound_stmt  goto 23
	statement  goto 128
	expression_stmt  goto 29
	selection_stmt  goto 30
	while_stmt  goto 31
	for_stmt  goto 32
	input_stmt  goto 33
	print_stmt  goto 34
	expression  goto 35
	var  goto 36
	or_expression  goto 37
	and_expression  goto 38
	bor_expression  goto 39
	bxor_expression  goto 40
	band_expression  goto 41
	additive_expression  goto 42
	shift_expression  goto 43
	rel_expression  goto 44
	term  goto 45
	factor  goto 46
	short_term  goto 47


state 127
	selection_stmt : IF LPAREN expression RPAREN statement ELSE statement .  (23)

	.  reduce 23


state 128
	for_stmt : FOR LPAREN expression_stmt expression_stmt expression RPAREN statement .  (26)

	.  reduce 26


##############################################################################
# Summary
##############################################################################

State 122 contains 1 shift-reduce conflict(s)


43 token(s), 29 nonterminal(s)
70 grammar rule(s), 129 state(s)


##############################################################################
# End of File
##############################################################################
