#include "../includes/standarts.h"

#ifndef LEXER
#define LEXER


#define KRIT_KF 0.6
#define ENCR_KF 2
#define CAP_INIT 20
#define STR_INIT 150

typedef char* data_t;

typedef enum braces       {LBRACE   = 10, RBRACE} braces;

typedef enum lexem_kind_t {BRACKET  = 20, QUESTION, ANSWER} lexem_kind_t;

typedef union lexem lexem;

typedef struct lexem_t lexem_t;

typedef struct lex_array_t lex_array_t;

#endif
//===*===*===*===*===*===*===*===*===*===*===*===*===*===*===*===*===*===*===*//
                    //  lexer's function prototypes   //
//===*===*===*===*===*===*===*===*===*===*===*===*===*===*===*===*===*===*===*//
int StrDelete (char *str);
int IsQuest (char *str);
int LexsResz (lex_array_t *lexus);
int LexsPrint (lex_array_t *lexus);
int LexsDelete (lex_array_t *lexus);
char * StrCtor (char first, FILE *file);
lex_array_t *LexsInit (unsigned capacity);
int LexsFill (lex_array_t *lexus, const char *file_name);
FILE * FileOpen (const char *file_name, const char *mode);
int LexsInsert (lex_array_t *lexus, lexem_kind_t kind, ...);
//===*===*===*===*===*===*===*===*===*===*===*===*===*===*===*===*===*===*===*//
//===*===*===*===*===*===*===*===*===*===*===*===*===*===*===*===*===*===*===*//
