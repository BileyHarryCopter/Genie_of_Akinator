#ifndef INITTREE
#define INITTREE
//===*===*===*===*===*===*===*===*===*===*===*===*===*===*===*===*===*===*===*//
        //  Incapsulation of initialization the structure of tree //
//===*===*===*===*===*===*===*===*===*===*===*===*===*===*===*===*===*===*===*//
typedef struct node_t
{
    struct node_t  *left, *right;
    unsigned       depth;
    data_t         data;
} node_t;

typedef struct tree_t
{
    node_t        *top;
    unsigned      size;
} tree_t;
//===*===*===*===*===*===*===*===*===*===*===*===*===*===*===*===*===*===*===*//
//===*===*===*===*===*===*===*===*===*===*===*===*===*===*===*===*===*===*===*//
#endif
