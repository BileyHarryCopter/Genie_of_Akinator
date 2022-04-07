#include "parcer.h"
#include "../includes/errors.h"
#include "../includes/initlex.h"
#include "../includes/inittree.h"
//===*===*===*===*===*===*===*===*===*===*===*===*===*===*===*===*===*===*===*//
                       //    Realisation of Parcer    //
//===*===*===*===*===*===*===*===*===*===*===*===*===*===*===*===*===*===*===*//
tree_t *TreeCtor (data_t datatop)
{
    assert (datatop);
    tree_t *tree    = (tree_t *) calloc (1, sizeof (tree_t));
    tree->top       = (node_t *) calloc (1, sizeof (node_t));
    tree->top->data = (data_t)   calloc (STR_INIT ,sizeof (char));
    tree->top->data = memmove (tree->top->data, datatop, strlen (datatop));
    tree->size = 0;

    return tree;
}

node_t *NodeCtor (data_t datanode)
{
    assert (datanode);
    node_t *node = (node_t *) calloc (1, sizeof (node_t));
    node->data   = (data_t) calloc (STR_INIT, sizeof (char));
    node->data   = memmove (node->data, datanode, strlen (datanode));

    // printf ("ADDRESS of node = %p\n", node);
    // printf ("ADDRESS of node data = %p\n", node->data);
    return node;
}

//  realization by DED
int TreePrint (node_t *top, unsigned count, FILE * file)
{
    //  just c flex
    assert (file);
    fprintf (file, "%*s%s", 4*count, "{", top->data);
    if (!top->left && !top->right)
    {
        fprintf (file, "}\n");
        return NO_ERROR;
    }
    fprintf (file, "\n");
    if (top->left && !top->right)
    {
        TreePrint (top->left, ++count, file);
        --count;
    }
    if (!top->left && top->right)
    {
        TreePrint (top->right, ++count, file);
        --count;
    }
    if (top->left && top->right && TreePrint (top->left, ++count, file) == NO_ERROR)
    {
        --count;
        TreePrint (top->right, ++count, file);
        --count;
    }
    fprintf (file, "%*s\n", 4*count, "}");
    return NO_ERROR;
}

int NodeDel (node_t *node)
{
    assert (node);
    assert (node->data);
    // printf ("from %s: pointer %p was been freed\n\n", __PRETTY_FUNCTION__, node);
    free (node->data);
    free (node);
    return NO_ERROR;
}

int TreeDel (node_t *top)
{
    // printf ("pointer = %p\n", top);
    // printf ("data    = %s\n", top->data);
    // printf ("pointer data = %p\n", top->data);
    if (!top->left && !top->right)
    {
        NodeDel (top);
        return NO_ERROR;
    }
    if (top->left && !top->right)
        TreeDel (top->left);
    if (!top->left && top->right)
        TreeDel (top->right);
    if (top->left && top->right && TreeDel (top->left) == NO_ERROR)
        TreeDel (top->right);
    NodeDel (top);
    return NO_ERROR;
}

node_t *ParceTree (lex_array_t *lexus)
{
    assert (lexus);
    //  is needed for right indexation on the lexems array
    lexus->size = 0;
    return TreeFill (lexus);
}

node_t *TreeFill (lex_array_t * lexus)
{
    // read opening of a node
    if (lexus->lexems[lexus->size].lexm.brac == LBRACE)
        lexus->size++;
    else
    {
        printf ("MISHA all of this on %d is fucking bullshit, let's a new attempt!\n", __LINE__);
        return NULL;
    }

    if (lexus->lexems[lexus->size].kind == ANSWER)
    {
        //  выставление на выход из этой лексемы
        lexus->size += 2;
        if (lexus->lexems[lexus->size - 1].lexm.brac == RBRACE)
            return NodeCtor (lexus->lexems[lexus->size - 2].lexm.data);
        else
        {
            printf ("MISHA all of this on %d is fucking bullshit, let's a new attempt!\n", __LINE__);
            return NULL;
        }
    }

    if (lexus->lexems[lexus->size].kind == QUESTION)
    {
        //  checking for opening a new node
        if (lexus->lexems[lexus->size + 1].lexm.brac == LBRACE)
        {
            node_t *top = NodeCtor (lexus->lexems[lexus->size].lexm.data);
            lexus->size++;

            top->left   = TreeFill (lexus);

            if (lexus->lexems[lexus->size].lexm.brac == LBRACE)
                top->right  = TreeFill (lexus);
            else
            {
                printf ("MISHA all of this on %d is fucking bullshit, let's a new attempt!\n", __LINE__);
                return NULL;
            }

            if (lexus->lexems[lexus->size].lexm.brac == RBRACE)
                return top;
            else
            {
                printf ("MISHA all of this on %d is fucking bullshit, let's a new attempt!\n", __LINE__);
                return NULL;
            }
        }
    }

    printf ("Oh shit, I am sorry!\n");
    return NULL;
}
