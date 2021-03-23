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
# lexer.v
# Lex verbose file generated from lexer.l.
# 
# Date: 12/17/13
# Time: 23:46:19
# 
# ALex Version: 2.07
#############################################################################


#############################################################################
# Expressions
#############################################################################

    1  "int"

    2  "char"

    3  "if"

    4  "else"

    5  "while"

    6  "for"

    7  "input"

    8  "print"

    9  "main"

   10  "=="

   11  "!="

   12  ">="

   13  "<="

   14  "||"

   15  "&&"

   16  "!"

   17  "="

   18  "++"

   19  "--"

   20  ">>"

   21  "<<"

   22  "+"

   23  "-"

   24  "*"

   25  "/"

   26  "%"

   27  "&"

   28  "|"

   29  "^"

   30  "~"

   31  "<"

   32  ">"

   33  ";"

   34  ","

   35  "("

   36  ")"

   37  "{"

   38  "}"

   39  "/*"

   40  "//"

   41  [a-zA-Z_]+[a-zA-Z0-9_]*

   42  (-?[1-9]+[0-9]*)|(-?[1-9])|0

   43  '.'

   44  \n

   45  [ \t]+

   46  .


#############################################################################
# States
#############################################################################

state 1
	INITIAL

	0x00 - 0x08 (9)    goto 3
	0x09               goto 4
	0x0a               goto 5
	0x0b - 0x1f (21)   goto 3
	0x20               goto 4
	0x21               goto 6
	0x22 - 0x24 (3)    goto 3
	0x25               goto 7
	0x26               goto 8
	0x27               goto 9
	0x28               goto 10
	0x29               goto 11
	0x2a               goto 12
	0x2b               goto 13
	0x2c               goto 14
	0x2d               goto 15
	0x2e               goto 3
	0x2f               goto 16
	0x30               goto 17
	0x31 - 0x39 (9)    goto 18
	0x3a               goto 3
	0x3b               goto 19
	0x3c               goto 20
	0x3d               goto 21
	0x3e               goto 22
	0x3f - 0x40 (2)    goto 3
	0x41 - 0x5a (26)   goto 23
	0x5b - 0x5d (3)    goto 3
	0x5e               goto 24
	0x5f               goto 23
	0x60               goto 3
	0x61 - 0x62 (2)    goto 23
	0x63               goto 25
	0x64               goto 23
	0x65               goto 26
	0x66               goto 27
	0x67 - 0x68 (2)    goto 23
	0x69               goto 28
	0x6a - 0x6c (3)    goto 23
	0x6d               goto 29
	0x6e - 0x6f (2)    goto 23
	0x70               goto 30
	0x71 - 0x76 (6)    goto 23
	0x77               goto 31
	0x78 - 0x7a (3)    goto 23
	0x7b               goto 32
	0x7c               goto 33
	0x7d               goto 34
	0x7e               goto 35
	0x7f - 0xff (129)  goto 3


state 2
	^INITIAL

	0x00 - 0x08 (9)    goto 3
	0x09               goto 4
	0x0a               goto 5
	0x0b - 0x1f (21)   goto 3
	0x20               goto 4
	0x21               goto 6
	0x22 - 0x24 (3)    goto 3
	0x25               goto 7
	0x26               goto 8
	0x27               goto 9
	0x28               goto 10
	0x29               goto 11
	0x2a               goto 12
	0x2b               goto 13
	0x2c               goto 14
	0x2d               goto 15
	0x2e               goto 3
	0x2f               goto 16
	0x30               goto 17
	0x31 - 0x39 (9)    goto 18
	0x3a               goto 3
	0x3b               goto 19
	0x3c               goto 20
	0x3d               goto 21
	0x3e               goto 22
	0x3f - 0x40 (2)    goto 3
	0x41 - 0x5a (26)   goto 23
	0x5b - 0x5d (3)    goto 3
	0x5e               goto 24
	0x5f               goto 23
	0x60               goto 3
	0x61 - 0x62 (2)    goto 23
	0x63               goto 25
	0x64               goto 23
	0x65               goto 26
	0x66               goto 27
	0x67 - 0x68 (2)    goto 23
	0x69               goto 28
	0x6a - 0x6c (3)    goto 23
	0x6d               goto 29
	0x6e - 0x6f (2)    goto 23
	0x70               goto 30
	0x71 - 0x76 (6)    goto 23
	0x77               goto 31
	0x78 - 0x7a (3)    goto 23
	0x7b               goto 32
	0x7c               goto 33
	0x7d               goto 34
	0x7e               goto 35
	0x7f - 0xff (129)  goto 3


state 3
	match 46


state 4
	0x09               goto 4
	0x20               goto 4

	match 45


state 5
	match 44


state 6
	0x3d               goto 36

	match 16


state 7
	match 26


state 8
	0x26               goto 37

	match 27


state 9
	0x00 - 0x09 (10)   goto 38
	0x0b - 0xff (245)  goto 38

	match 46


state 10
	match 35


state 11
	match 36


state 12
	match 24


state 13
	0x2b               goto 39

	match 22


state 14
	match 34


state 15
	0x2d               goto 40
	0x31 - 0x39 (9)    goto 18

	match 23


state 16
	0x2a               goto 41
	0x2f               goto 42

	match 25


state 17
	match 42


state 18
	0x30               goto 43
	0x31 - 0x39 (9)    goto 18

	match 42


state 19
	match 33


state 20
	0x3c               goto 44
	0x3d               goto 45

	match 31


state 21
	0x3d               goto 46

	match 17


state 22
	0x3d               goto 47
	0x3e               goto 48

	match 32


state 23
	0x30 - 0x39 (10)   goto 23
	0x41 - 0x5a (26)   goto 23
	0x5f               goto 23
	0x61 - 0x7a (26)   goto 23

	match 41


state 24
	match 29


state 25
	0x30 - 0x39 (10)   goto 23
	0x41 - 0x5a (26)   goto 23
	0x5f               goto 23
	0x61 - 0x67 (7)    goto 23
	0x68               goto 49
	0x69 - 0x7a (18)   goto 23

	match 41


state 26
	0x30 - 0x39 (10)   goto 23
	0x41 - 0x5a (26)   goto 23
	0x5f               goto 23
	0x61 - 0x6b (11)   goto 23
	0x6c               goto 50
	0x6d - 0x7a (14)   goto 23

	match 41


state 27
	0x30 - 0x39 (10)   goto 23
	0x41 - 0x5a (26)   goto 23
	0x5f               goto 23
	0x61 - 0x6e (14)   goto 23
	0x6f               goto 51
	0x70 - 0x7a (11)   goto 23

	match 41


state 28
	0x30 - 0x39 (10)   goto 23
	0x41 - 0x5a (26)   goto 23
	0x5f               goto 23
	0x61 - 0x65 (5)    goto 23
	0x66               goto 52
	0x67 - 0x6d (7)    goto 23
	0x6e               goto 53
	0x6f - 0x7a (12)   goto 23

	match 41


state 29
	0x30 - 0x39 (10)   goto 23
	0x41 - 0x5a (26)   goto 23
	0x5f               goto 23
	0x61               goto 54
	0x62 - 0x7a (25)   goto 23

	match 41


state 30
	0x30 - 0x39 (10)   goto 23
	0x41 - 0x5a (26)   goto 23
	0x5f               goto 23
	0x61 - 0x71 (17)   goto 23
	0x72               goto 55
	0x73 - 0x7a (8)    goto 23

	match 41


state 31
	0x30 - 0x39 (10)   goto 23
	0x41 - 0x5a (26)   goto 23
	0x5f               goto 23
	0x61 - 0x67 (7)    goto 23
	0x68               goto 56
	0x69 - 0x7a (18)   goto 23

	match 41


state 32
	match 37


state 33
	0x7c               goto 57

	match 28


state 34
	match 38


state 35
	match 30


state 36
	match 11


state 37
	match 15


state 38
	0x27               goto 58


state 39
	match 18


state 40
	match 19


state 41
	match 39


state 42
	match 40


state 43
	0x30 - 0x39 (10)   goto 43

	match 42


state 44
	match 21


state 45
	match 13


state 46
	match 10


state 47
	match 12


state 48
	match 20


state 49
	0x30 - 0x39 (10)   goto 23
	0x41 - 0x5a (26)   goto 23
	0x5f               goto 23
	0x61               goto 59
	0x62 - 0x7a (25)   goto 23

	match 41


state 50
	0x30 - 0x39 (10)   goto 23
	0x41 - 0x5a (26)   goto 23
	0x5f               goto 23
	0x61 - 0x72 (18)   goto 23
	0x73               goto 60
	0x74 - 0x7a (7)    goto 23

	match 41


state 51
	0x30 - 0x39 (10)   goto 23
	0x41 - 0x5a (26)   goto 23
	0x5f               goto 23
	0x61 - 0x71 (17)   goto 23
	0x72               goto 61
	0x73 - 0x7a (8)    goto 23

	match 41


state 52
	0x30 - 0x39 (10)   goto 23
	0x41 - 0x5a (26)   goto 23
	0x5f               goto 23
	0x61 - 0x7a (26)   goto 23

	match 3


state 53
	0x30 - 0x39 (10)   goto 23
	0x41 - 0x5a (26)   goto 23
	0x5f               goto 23
	0x61 - 0x6f (15)   goto 23
	0x70               goto 62
	0x71 - 0x73 (3)    goto 23
	0x74               goto 63
	0x75 - 0x7a (6)    goto 23

	match 41


state 54
	0x30 - 0x39 (10)   goto 23
	0x41 - 0x5a (26)   goto 23
	0x5f               goto 23
	0x61 - 0x68 (8)    goto 23
	0x69               goto 64
	0x6a - 0x7a (17)   goto 23

	match 41


state 55
	0x30 - 0x39 (10)   goto 23
	0x41 - 0x5a (26)   goto 23
	0x5f               goto 23
	0x61 - 0x68 (8)    goto 23
	0x69               goto 65
	0x6a - 0x7a (17)   goto 23

	match 41


state 56
	0x30 - 0x39 (10)   goto 23
	0x41 - 0x5a (26)   goto 23
	0x5f               goto 23
	0x61 - 0x68 (8)    goto 23
	0x69               goto 66
	0x6a - 0x7a (17)   goto 23

	match 41


state 57
	match 14


state 58
	match 43


state 59
	0x30 - 0x39 (10)   goto 23
	0x41 - 0x5a (26)   goto 23
	0x5f               goto 23
	0x61 - 0x71 (17)   goto 23
	0x72               goto 67
	0x73 - 0x7a (8)    goto 23

	match 41


state 60
	0x30 - 0x39 (10)   goto 23
	0x41 - 0x5a (26)   goto 23
	0x5f               goto 23
	0x61 - 0x64 (4)    goto 23
	0x65               goto 68
	0x66 - 0x7a (21)   goto 23

	match 41


state 61
	0x30 - 0x39 (10)   goto 23
	0x41 - 0x5a (26)   goto 23
	0x5f               goto 23
	0x61 - 0x7a (26)   goto 23

	match 6


state 62
	0x30 - 0x39 (10)   goto 23
	0x41 - 0x5a (26)   goto 23
	0x5f               goto 23
	0x61 - 0x74 (20)   goto 23
	0x75               goto 69
	0x76 - 0x7a (5)    goto 23

	match 41


state 63
	0x30 - 0x39 (10)   goto 23
	0x41 - 0x5a (26)   goto 23
	0x5f               goto 23
	0x61 - 0x7a (26)   goto 23

	match 1


state 64
	0x30 - 0x39 (10)   goto 23
	0x41 - 0x5a (26)   goto 23
	0x5f               goto 23
	0x61 - 0x6d (13)   goto 23
	0x6e               goto 70
	0x6f - 0x7a (12)   goto 23

	match 41


state 65
	0x30 - 0x39 (10)   goto 23
	0x41 - 0x5a (26)   goto 23
	0x5f               goto 23
	0x61 - 0x6d (13)   goto 23
	0x6e               goto 71
	0x6f - 0x7a (12)   goto 23

	match 41


state 66
	0x30 - 0x39 (10)   goto 23
	0x41 - 0x5a (26)   goto 23
	0x5f               goto 23
	0x61 - 0x6b (11)   goto 23
	0x6c               goto 72
	0x6d - 0x7a (14)   goto 23

	match 41


state 67
	0x30 - 0x39 (10)   goto 23
	0x41 - 0x5a (26)   goto 23
	0x5f               goto 23
	0x61 - 0x7a (26)   goto 23

	match 2


state 68
	0x30 - 0x39 (10)   goto 23
	0x41 - 0x5a (26)   goto 23
	0x5f               goto 23
	0x61 - 0x7a (26)   goto 23

	match 4


state 69
	0x30 - 0x39 (10)   goto 23
	0x41 - 0x5a (26)   goto 23
	0x5f               goto 23
	0x61 - 0x73 (19)   goto 23
	0x74               goto 73
	0x75 - 0x7a (6)    goto 23

	match 41


state 70
	0x30 - 0x39 (10)   goto 23
	0x41 - 0x5a (26)   goto 23
	0x5f               goto 23
	0x61 - 0x7a (26)   goto 23

	match 9


state 71
	0x30 - 0x39 (10)   goto 23
	0x41 - 0x5a (26)   goto 23
	0x5f               goto 23
	0x61 - 0x73 (19)   goto 23
	0x74               goto 74
	0x75 - 0x7a (6)    goto 23

	match 41


state 72
	0x30 - 0x39 (10)   goto 23
	0x41 - 0x5a (26)   goto 23
	0x5f               goto 23
	0x61 - 0x64 (4)    goto 23
	0x65               goto 75
	0x66 - 0x7a (21)   goto 23

	match 41


state 73
	0x30 - 0x39 (10)   goto 23
	0x41 - 0x5a (26)   goto 23
	0x5f               goto 23
	0x61 - 0x7a (26)   goto 23

	match 7


state 74
	0x30 - 0x39 (10)   goto 23
	0x41 - 0x5a (26)   goto 23
	0x5f               goto 23
	0x61 - 0x7a (26)   goto 23

	match 8


state 75
	0x30 - 0x39 (10)   goto 23
	0x41 - 0x5a (26)   goto 23
	0x5f               goto 23
	0x61 - 0x7a (26)   goto 23

	match 5


#############################################################################
# Summary
#############################################################################

1 start state(s)
46 expression(s), 75 state(s)


#############################################################################
# End of File
#############################################################################
