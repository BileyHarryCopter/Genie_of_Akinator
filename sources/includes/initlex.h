#ifndef INITLEX
#define INITLEX
//===*===*===*===*===*===*===*===*===*===*===*===*===*===*===*===*===*===*===*//
        //  Incapsulation of initialization the structure of lexems //
//===*===*===*===*===*===*===*===*===*===*===*===*===*===*===*===*===*===*===*//
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
#endif
