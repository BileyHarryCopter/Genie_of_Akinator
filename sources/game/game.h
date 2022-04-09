#include "../includes/standarts.h"
#include "../includes/errors.h"
#include "../includes/inout.h"
#include "../lexer/lexer.h"
#include "../parcer/parcer.h"
#include "../dump/dump.h"
//===*===*===*===*===*===*===*===*===*===*===*===*===*===*===*===*===*===*===*//
//===*===*===*===*===*===*===*===*===*===*===*===*===*===*===*===*===*===*===*//
char * StrCtorStd (int mode);
int AnsDetect (const char *answer);
int istrcmp (const char * str1, const char * str2);
int RunAkinator (const char * input_name, const char * output_name);
int NodeAdd (char *question, char *answer, node_t *node, node_t *nodeans);
//===*===*===*===*===*===*===*===*===*===*===*===*===*===*===*===*===*===*===*//
//===*===*===*===*===*===*===*===*===*===*===*===*===*===*===*===*===*===*===*//
