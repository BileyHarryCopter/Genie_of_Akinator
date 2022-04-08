#include "sources/includes/standarts.h"
#include "sources/includes/errors.h"
#include "sources/lexer/lexer.h"
#include "sources/parcer/parcer.h"
#include "sources/dump/dump.h"
//===*===*===*===*===*===*===*===*===*===*===*===*===*===*===*===*===*===*===*//
//===*===*===*===*===*===*===*===*===*===*===*===*===*===*===*===*===*===*===*//
int main (void)
{
    FILE *outfile = fopen ("sources/data/output.txt", "w");
    lex_array_t * lexus = LexsInit (CAP_INIT);
    node_t *tree = NULL;


    if (LexsFill (lexus, "sources/data/input.txt") == NO_ERROR)
    {
        // LexsPrint (lexus);
        tree = ParceTree (lexus);
        TreePrint (tree, 0, outfile);
        GraphDump (tree);
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
