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

node_t *NodeCtor (data_t datanode, lexem_kind_t kind)
{
    assert (datanode);
    node_t *node = (node_t *) calloc (1, sizeof (node_t));
    node->data   = (data_t) calloc (STR_INIT, sizeof (char));
    node->data   = memmove (node->data, datanode, strlen (datanode));
    node->kind   = kind;
    // printf ("ADDRESS of node = %p\n", node);
    // printf ("ADDRESS of node data = %p\n", node->data);
    return node;
}

int TreePrint (node_t *top, const char * output_name)
{
    assert (top);
    assert (output_name);
    FILE * output = fopen (output_name, WRITING);
    assert (output);
    TreePrintIn (top, 0, output);
    fclose (output);

    return NO_ERROR;
}

//  realization by DED
int TreePrintIn (node_t *top, unsigned count, FILE * file)
{
    //  just c flex
    assert (file);
    fprintf (file, "%*s%s", 5*count, "{", top->data);
    if (!top->left && !top->right)
    {
        fprintf (file, "}\n");
        return NO_ERROR;
    }
    fprintf (file, "\n");
    if (top->left && !top->right)
    {
        TreePrintIn (top->left, ++count, file);
        --count;
    }
    if (!top->left && top->right)
    {
        TreePrintIn (top->right, ++count, file);
        --count;
    }
    if (top->left && top->right && TreePrintIn (top->left, ++count, file) == NO_ERROR)
    {
        --count;
        TreePrintIn (top->right, ++count, file);
        --count;
    }
    fprintf (file, "%*s\n", 5*count, "}");
    return NO_ERROR;
}

int NodeDelete (node_t *node)
{
    assert (node);
    assert (node->data);
    // printf ("from %s: pointer %p was been freed\n\n", __PRETTY_FUNCTION__, node);
    free (node->data);
    free (node);
    return NO_ERROR;
}

int TreeDelete (node_t *top)
{
    // printf ("pointer = %p\n", top);
    // printf ("data    = %s\n", top->data);
    // printf ("pointer data = %p\n", top->data);
    if (!top->left && !top->right)
    {
        NodeDelete (top);
        return NO_ERROR;
    }
    if (top->left && !top->right)
        TreeDelete (top->left);
    if (!top->left && top->right)
        TreeDelete (top->right);
    if (top->left && top->right && TreeDelete (top->left) == NO_ERROR)
        TreeDelete (top->right);
    NodeDelete (top);
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
            return NodeCtor (lexus->lexems[lexus->size - 2].lexm.data, lexus->lexems[lexus->size - 2].kind);
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
            node_t *top = NodeCtor (lexus->lexems[lexus->size].lexm.data, lexus->lexems[lexus->size].kind);
            lexus->size++;

            top->left   = TreeFill (lexus);

            //  unnecessary check for opening left bracket
            if (lexus->lexems[lexus->size].lexm.brac == LBRACE)
                top->right  = TreeFill (lexus);
            if (lexus->lexems[lexus->size].lexm.brac == RBRACE)
            {
                lexus->size++;
                return top;
            }
            else
            {
                printf ("MISHA all of this on %d is fucking bullshit, let's a new attempt!\n", __LINE__);
                return NULL;
            }
        }
        else
        {
            //  вопрос, не имеющий ответа - бан нахуй
            printf ("MISHA all of this on %d is fucking bullshit, let's a new attempt!\n", __LINE__);
            return NULL;
        }
    }

    printf ("Oh shit, I am sorry!\n");
    return NULL;
}
