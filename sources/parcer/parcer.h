#include "../includes/standarts.h"
#include "../lexer/lexer.h"

typedef struct node_t node_t;
typedef struct tree_t tree_t;
//===*===*===*===*===*===*===*===*===*===*===*===*===*===*===*===*===*===*===*//
                    //  parser's function prototypes   //
//===*===*===*===*===*===*===*===*===*===*===*===*===*===*===*===*===*===*===*//
int TreeDelete (node_t *top);
int NodeDelete (node_t *node);
tree_t *TreeCtor (data_t datatop);
node_t *NodeCtor (data_t datanode, lexem_kind_t kind);
int TreePrint   (node_t *top, const char * output_name);
int TreePrintIn (node_t *top, unsigned count, FILE *file);
node_t *ParceTree (lex_array_t *lexus);
node_t *TreeFill (lex_array_t * lexus);
//===*===*===*===*===*===*===*===*===*===*===*===*===*===*===*===*===*===*===*//
//===*===*===*===*===*===*===*===*===*===*===*===*===*===*===*===*===*===*===*//
