#include "sources/includes/standarts.h"
#include "sources/includes/errors.h"
#include "sources/lexer/lexer.h"
//===*===*===*===*===*===*===*===*===*===*===*===*===*===*===*===*===*===*===*//
//===*===*===*===*===*===*===*===*===*===*===*===*===*===*===*===*===*===*===*//
int main (void)
{
    lex_array_t * lexus = LexsInit (CAP_INIT);

    if (LexsFill (lexus, "data.txt") == NO_ERROR)
        // LexsPrint (lexus);
        printf ("LOL\n");
    else
        printf ("LOH\n");

    LexsDelete (lexus);
    return 0;
}
//===*===*===*===*===*===*===*===*===*===*===*===*===*===*===*===*===*===*===*//
//===*===*===*===*===*===*===*===*===*===*===*===*===*===*===*===*===*===*===*//

// Listen to "Who Wants to Live Forever" by Queen!!!
