#include "lexer.h"
#include "../includes/errors.h"
#include "../includes/initlex.h"

//===*===*===*===*===*===*===*===*===*===*===*===*===*===*===*===*===*===*===*//
                     //    Realisation of Lexer    //
//===*===*===*===*===*===*===*===*===*===*===*===*===*===*===*===*===*===*===*//
lex_array_t *LexsInit (unsigned capacity)
{
    lex_array_t *lexus = (lex_array_t *) calloc (1, sizeof (lex_array_t));
    lexus->lexems   = (lexem_t *) calloc (capacity, sizeof (lexem_t));
    lexus->capacity = capacity;
    lexus->size     = 0;
    return lexus;
}

int LexsResz (lex_array_t *lexus)
{
    assert (lexus);
    assert (lexus->lexems);
    lexus->capacity = ENCR_KF * lexus->capacity;
    lexus->lexems   = (lexem_t *) realloc (lexus->lexems, lexus->capacity * sizeof (lexem_t));
    return NO_ERROR;
}

int LexsDelete (lex_array_t *lexus)
{
    assert (lexus);
    assert (lexus->lexems);

    for (int i = 0; i < lexus->size; i++)
    {
        if (lexus->lexems[i].kind != BRACKET)
            free (lexus->lexems[i].lexm.data);
    }
    free   (lexus->lexems);
    free   (lexus);
    return NO_ERROR;
}

int LexsInsert (lex_array_t *lexus, lexem_kind_t kind, ...)
{
    va_list args;
    data_t data = NULL;
    braces brac = 0;

    if (kind != BRACKET)
    {
        va_start (args, kind);
        data = va_arg (args, data_t);
        assert (data);
    }
    else
    {
        va_start (args, kind);
        brac = va_arg (args, braces);
    }


    assert (lexus);
    if (lexus->size > KRIT_KF * lexus->capacity)
        LexsResz (lexus);
    assert (lexus->lexems);

    lexus->lexems[lexus->size].kind = kind;
    switch (kind)
    {
        case QUESTION:
        case ANSWER:
            lexus->lexems[lexus->size].lexm.data = (char *) calloc (strlen(data), sizeof (char));
            lexus->lexems[lexus->size].lexm.data = memmove (lexus->lexems[lexus->size].lexm.data, data, strlen(data));
            break;
        case BRACKET:
            lexus->lexems[lexus->size].lexm.brac = brac;
            break;
        default:
            return ERROR;
    }
    lexus->size++;

    va_end (args);

    return NO_ERROR;
}

int LexsPrint (lex_array_t *lexus)
{
    assert (lexus);
    int kind = 0;
    int brac = 0;

    for (unsigned pos = 0; pos < lexus->size - 1; pos++)
    {
        kind = lexus->lexems[pos].kind;
        switch (kind)
        {
            case BRACKET:
                brac = lexus->lexems[pos].lexm.brac;
                if (brac == LBRACE)
                    printf ("LBRACE ");
                else if (brac == RBRACE)
                    printf ("RBRACE ");
                break;
            case QUESTION:
                printf ("QUESTION: %s ", lexus->lexems[pos].lexm.data);
                break;
            case ANSWER:
                printf ("ANSWER: %s ", lexus->lexems[pos].lexm.data);
                break;
            default:
                return ERROR;
        }
    }
    printf ("\n");

    return NO_ERROR;
}
//===*===*===*===*===*===*===*===*===*===*===*===*===*===*===*===*===*===*===*//
//  reading of file with data and filling lexem_array   //
//===*===*===*===*===*===*===*===*===*===*===*===*===*===*===*===*===*===*===*//
FILE * FileOpen (const char *file_name, const char *mode)
{
    assert (file_name && mode);
    FILE *file = fopen (file_name, mode);
    assert (file);
    return file;
}

char * StrCtor (char first, FILE *file)
{
    assert (file);
    int length = 0;
    char *str = (char *) calloc (STR_INIT, sizeof (char));
    ungetc (first, file);

    while (first != EOF && first != '\n')
    {
        first = getc (file);
        if (first == '(' || first == '[' || first == '{' || first == ')' || first == ']' || first == '}')
        {
            ungetc (first, file);
            return str;
        }
        str[length] = first;
        length++;
    }
    //  delete an indent
    if (length > 1)
        str[length - 1] = 0;

    assert (str);
    return str;
}

int StrDel (char *str)
{
    assert (str);
    free (str);
    return NO_ERROR;
}

int IsQuest (char *str)
{
    assert (str);
    char symb = *str;

    while (symb != 0 && symb != '?')
    {
        symb = *str;
        str++;
    }

    return (symb == '?') ? 1 : 0;

    printf ("ERROR IN %s\n", __PRETTY_FUNCTION__);
    return ERROR;
}

int LexsFill (lex_array_t *lexus, const char *file_name)
{
    char symb = 0;
    unsigned pos = 0;
    char *str = NULL;
    FILE *file = NULL;

    file = FileOpen (file_name, READING);
    fseek (file, 0L, SEEK_SET);

    while (symb != EOF)
    {
        symb = getc (file);

        if (isspace(symb))
            continue;

        if (symb == '(' || symb == '[' || symb == '{')
        {
            LexsInsert (lexus, BRACKET, LBRACE);
        }
        else if (symb == ')'  || symb == ']' || symb == '}')
        {
            LexsInsert (lexus, BRACKET, RBRACE);
        }
        else
        {
            str = StrCtor (symb, file);
            if (IsQuest (str))
                LexsInsert (lexus, QUESTION, str);
            else
                LexsInsert (lexus, ANSWER, str);
            StrDel (str);
        }
    }

    fclose (file);
    return NO_ERROR;
}
