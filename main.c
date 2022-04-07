#include "sources/includes/standarts.h"
#include "sources/includes/errors.h"
#include "sources/lexer/lexer.h"
#include "sources/parcer/parcer.h"
//===*===*===*===*===*===*===*===*===*===*===*===*===*===*===*===*===*===*===*//
//===*===*===*===*===*===*===*===*===*===*===*===*===*===*===*===*===*===*===*//
int main (void)
{
    FILE *outfile = fopen ("input.txt", "w");
    lex_array_t * lexus = LexsInit (CAP_INIT);
    node_t *tree = NULL;

    if (LexsFill (lexus, "output.txt") == NO_ERROR)
    {
        // LexsPrint (lexus);
        tree = ParceTree (lexus);
        TreePrint (tree, 0, outfile);
    }
    else
        printf ("LOH\n");

    TreeDel (tree);
    LexsDelete (lexus);
    fclose (outfile);
    return 0;
}
//===*===*===*===*===*===*===*===*===*===*===*===*===*===*===*===*===*===*===*//
            // Listen to "Who Wants to Live Forever" by Queen!!!    //
//===*===*===*===*===*===*===*===*===*===*===*===*===*===*===*===*===*===*===*//
