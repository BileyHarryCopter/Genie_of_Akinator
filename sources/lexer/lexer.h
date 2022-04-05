#include "../includes/standarts.h"

#define KRIT_KF 0.6
#define ENCR_KF 2
#define CAP_INIT 20
#define STR_INIT 150

//  in init.h
typedef char* data_t;

typedef enum braces       {LBRACE   = 10, RBRACE} braces;

typedef enum lexem_kind_t {BRACKET  = 20, QUESTION, ANSWER} lexem_kind_t;

typedef union lexem
{
    braces        brac;
    data_t        data;
} lexem;

typedef struct lexem_t
{
    lexem_kind_t  kind;
    lexem         lexm;
} lexem_t;

typedef struct lex_array_t
{
    lexem_t*      lexems;
    unsigned      capacity, size;
} lex_array_t;
//===*===*===*===*===*===*===*===*===*===*===*===*===*===*===*===*===*===*===*//
//===*===*===*===*===*===*===*===*===*===*===*===*===*===*===*===*===*===*===*//
int StrDel (char *str);
int IsQuest (char *str);
int LexsResz (lex_array_t *lexus);
int LexsPrint (lex_array_t *lexus);
int LexsDelete (lex_array_t *lexus);
char * StrCtor (char first, FILE *file);
lex_array_t *LexsInit (unsigned capacity);
int LexsFill (lex_array_t *lexus, const char *file_name);
FILE * FileOpen (const char *file_name, const char *mode);
int LexsInsert (lex_array_t *lexus, lexem_kind_t kind, ...);
