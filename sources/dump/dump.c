#include "dump.h"
#include "../includes/errors.h"
#include "../includes/inittree.h"
#include "../includes/initlex.h"
//===*===*===*===*===*===*===*===*===*===*===*===*===*===*===*===*===*===*===*//
                    //  Realisation of graphic dump   //
//===*===*===*===*===*===*===*===*===*===*===*===*===*===*===*===*===*===*===*//
//  it should work with INorder bypass
int NodeGraphInit (node_t *tree, FILE * file)
{
    assert (file);
    assert (tree);

    fprintf (file, "\t\tnode_%p [label = \"%s\"", tree, tree->data);
    if (tree->kind == QUESTION)
        fprintf (file, ", fillcolor = \"powderblue\"");
    fprintf (file, "];\n");

    if (tree->left && tree->right)
    {
        NodeGraphInit (tree->left,  file);
        NodeGraphInit (tree->right, file);
    }
    return NO_ERROR;
}

int NodeGraphLink (node_t *tree, FILE * file)
{
    assert (tree);
    assert (file);

    if (tree->kind == QUESTION)
    {
        fprintf (file, "\t\tnode_%p -> node_%p [label = \"YES\"];\n", tree, tree->left);
        fprintf (file, "\t\tnode_%p -> node_%p [label = \"NO\"];\n", tree, tree->right);
        NodeGraphLink (tree->left, file);
        NodeGraphLink (tree->right, file);
    }

    return NO_ERROR;
}

int GraphDump (node_t *tree, dump_modes mode)
{
    assert (tree);
    FILE * file = fopen ("sources/dump/dump_tree.dot", "w");
    fseek (file, 0L, SEEK_SET);

    fprintf (file,
            "digraph AKINATOR\n"
            "{\n"
            "\tgraph [dpi = 200];\n"
            "\trankdir = HR;\n"
            "\n"
            "\tsubgraph TREE\n"
            "\t{\n"
            "\t\tnode [shape = egg, style = \"filled\", fillcolor = \"bisque\", fontcolor = \"black\", fontsize = 12];\n"
            "\t\tedge [color = \"black\", fontcolor = \"teal\", fontsize = 10, fontname = \"Impact\"];\n"
            "\n");

    NodeGraphInit (tree, file);
    fprintf (file, "\n");
    NodeGraphLink (tree, file);

    fprintf (file,
            "\t}\n"
            "}\n");

    fclose (file);

    system ("dot sources/dump/dump_tree.dot -T png -o sources/dump/dump_tree.png");

    if (mode == OPEN)
    {
        system ("open sources/dump/dump_tree.png");
    }

    return NO_ERROR;
}
