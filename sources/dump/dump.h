#include "../includes/standarts.h"
#include "../lexer/lexer.h"
#include "../parcer/parcer.h"

typedef enum {OPEN = 15, JUST} dump_modes;

//===*===*===*===*===*===*===*===*===*===*===*===*===*===*===*===*===*===*===*//
//===*===*===*===*===*===*===*===*===*===*===*===*===*===*===*===*===*===*===*//
int NodeGraphInit (node_t *tree, FILE * file);
int NodeGraphLink (node_t *tree, FILE * file);
int GraphDump (node_t *tree, dump_modes mode);
//===*===*===*===*===*===*===*===*===*===*===*===*===*===*===*===*===*===*===*//
//===*===*===*===*===*===*===*===*===*===*===*===*===*===*===*===*===*===*===*//
