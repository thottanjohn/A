#define NUM 257
#define VAR 258
#define RELOP 259
#define MAIN 260
#define IF 261
#define ELSE 262
#define WHILE 263
#define TYPE 264
#ifdef YYSTYPE
#undef  YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
#endif
#ifndef YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
typedef union
{
char var[10];
} YYSTYPE;
#endif /* !YYSTYPE_IS_DECLARED */
extern YYSTYPE yylval;
