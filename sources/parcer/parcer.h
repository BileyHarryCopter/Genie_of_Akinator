#include "../includes/standarts.h"
#include "../lexer/lexer.h"

typedef struct node_t node_t;
typedef struct tree_t tree_t;
//===*===*===*===*===*===*===*===*===*===*===*===*===*===*===*===*===*===*===*//
                    //  parser's function prototypes   //
//===*===*===*===*===*===*===*===*===*===*===*===*===*===*===*===*===*===*===*//
int TreeDel (node_t *top);
int NodeDel (node_t *node);
tree_t *TreeCtor (data_t datatop);
node_t *NodeCtor (data_t datanode);
int TreePrint (node_t *top, unsigned count, FILE *file);
node_t *ParceTree (lex_array_t *lexus);
node_t *TreeFill (lex_array_t * lexus);
//===*===*===*===*===*===*===*===*===*===*===*===*===*===*===*===*===*===*===*//
//===*===*===*===*===*===*===*===*===*===*===*===*===*===*===*===*===*===*===*//
