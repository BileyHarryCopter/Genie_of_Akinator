#include "game.h"
#include "../includes/initlex.h"
#include "../includes/inittree.h"

#define PLAY_AGAIN                                                             \
{                                                                              \
    printf ("Do you wanna play again?\n");                                     \
    result = scanf ("%s", answer);                                             \
    if (AnsDetect (answer) == POSITIVE)                                        \
    {                                                                          \
        node = tree;                                                           \
        printf ("%s\n", node->data);                                           \
        result = scanf ("%s", answer);                                         \
        continue;                                                              \
    }                                                                          \
    else                                                                       \
    {                                                                          \
        printf ("Understandable, have a good day!\n");                         \
        break;                                                                 \
    }                                                                          \
}

#define GREETING                                                               \
{                                                                              \
    printf ("Hi!\n");                                                          \
    printf ("My name is Ginie of the Akinator and I can guess everything"      \
    "that you can imagine\n");                                                 \
    printf ("Do you wanna check my abilities?\n");                             \
    result = scanf ("%s", answer);                                             \
    if (result != 0 && AnsDetect (answer) == POSITIVE)                         \
        printf ("Okey, let's start! Loading the data...\n");                   \
    else                                                                       \
    {                                                                          \
        printf ("Understandable, have a good day!\n");                         \
        free (answer);                                                         \
        return NO_ERROR;                                                       \
    }                                                                          \
}

//===*===*===*===*===*===*===*===*===*===*===*===*===*===*===*===*===*===*===*//
//    this function should be placed in some standart file of main service    //
//===*===*===*===*===*===*===*===*===*===*===*===*===*===*===*===*===*===*===*//
int istrcmp (const char * str1, const char * str2)
{
    while (isalpha (*str1) != 0)
    {
        if (tolower (*str1) != tolower (*str2))
        {
            return (*str1 - *str2);
        }
        str1++;
        str2++;
    }
    return (*str1 == ' ' || *str1 == '\t' || *str1 == '\n' || *str1 == '\0') ? 0 : -1;
}
//===*===*===*===*===*===*===*===*===*===*===*===*===*===*===*===*===*===*===*//
                  //  Realization of launching a game   //
//===*===*===*===*===*===*===*===*===*===*===*===*===*===*===*===*===*===*===*//
char * StrCtorStd (int mode)
{
    char *str  = (char *) calloc (STR_INIT, sizeof (char));
    char symb  = getc (stdin);
    int i;

    while (isspace (symb))
    {
        symb = getc (stdin);
    }
    for (i = 0; i < STR_INIT && symb != '\n'; i++)
    {
        str[i] = symb;
        symb   = getc(stdin);
    }

    if (mode == QUESTION)
        str[i] = '?';

    return str;
}

int AnsDetect (const char *answer)
{
    for (int i = N; i < NUMB_OF_ANSW; i++)
    {
        if (istrcmp (answer, name_answ[i]) == 0)
        {
            switch (i)
            {
                case N:
                case NO:
                case NOPE:
                    return NEGATIVE;
                case Y:
                case YES:
                case YEAH:
                    return POSITIVE;
                case Q:
                case QUIT:
                    return END;
                default:
                    printf ("Check this shit on %d", __LINE__);
                    return ERROR;
            }
        }
    }

    return -1;
}

int NodeAdd (char *question, char *answer, node_t *node, node_t *nodeans)
{
    assert (question);
    assert (answer);
    assert (node);
    assert (nodeans);

    node_t *newanswr = (node_t *) calloc (1, sizeof (node_t));
    node_t *newquest = (node_t *) calloc (1, sizeof (node_t));

    newquest->data   = (char *) calloc (STR_INIT, sizeof (char));
    newquest->data   = memmove (newquest->data, question, strlen (question));
    newquest->kind   = QUESTION;
    newanswr->data   = (char *) calloc (STR_INIT, sizeof (char));
    newanswr->data   = memmove (newanswr->data, answer, strlen (answer));
    newanswr->kind   = ANSWER;

    newquest->left   = newanswr;
    newquest->right  = nodeans;

    if (strcmp (node->left->data, nodeans->data) == 0)
    {
        node->left   = newquest;
    }
    else if (strcmp (node->right->data, nodeans->data) == 0)
    {
        node->right  = newquest;
    }
    return NO_ERROR;
}

int RunAkinator (const char * input_name, const char * output_name)
{
    assert (input_name);
    assert (output_name);

    int  result        = 0;
    char *question     = NULL;
    char *answer       = (char *) calloc (STR_INIT, sizeof (char));
    node_t      *tree  = NULL;
    node_t      *node  = NULL;
    node_t   *nodeans  = NULL;
    lex_array_t *lexus = NULL;

//                                         greeting                                             //
                                           GREETING
//                                         greeting                                             //


//                                     loading data                                             //
    lexus = LexsInit (CAP_INIT);
    if (LexsFill (lexus, input_name) == NO_ERROR)
    {
        tree = ParceTree (lexus);
    }
//                                     loading data                                             //


//                                                  play process                                                            //
    node = tree;
    printf ("%s\n", node->data);
    result = scanf ("%s", answer);


    while (result != 0)
    {
        if (AnsDetect (answer) == END)
        {
            printf ("Understandable, have a good day!\n");
            break;
        }
        else
        {
            if (AnsDetect (answer) == POSITIVE)
                nodeans = node->left;
            else if (AnsDetect (answer) == NEGATIVE)
                nodeans = node->right;
            else
            {
                printf ("We have some troubles on %d line...\n", __LINE__);
                break;
            }
            //  analysis of situation //
            if (nodeans->kind == ANSWER)
            {
                printf ("It is %s\n", nodeans->data);
                printf ("Have I guessed right?\n");
                result = scanf ("%s", answer);

                //  processing with main answer  //
                if (result != 0 && AnsDetect (answer) == POSITIVE)
                {
                    printf ("Yeah! I haven't any doubts about my abilities. Thanks for playing\n");
                    //  suggestion to play again  //
                    PLAY_AGAIN
                    //  suggestion to play again  //
                }
                else if (result != 0 && AnsDetect (answer) == NEGATIVE)
                {
                    printf ("Oh may! It seems I am not perfect enough. Who did you really think about?\n");
                    answer   = StrCtorStd (ANSWER);

                    if (AnsDetect (answer) == END)
                    {
                        printf ("Understandable, have a good day!\n");
                        break;
                    }

                    printf ("And now please tell how is this different from %s\n", nodeans->data);
                    printf ("%s is different from %s in that in\n", answer, nodeans->data);
                    question = StrCtorStd (QUESTION);

                    if (AnsDetect (question) == END)
                    {
                        free (question);
                        printf ("Understandable, have a good day!\n");
                        break;
                    }
                    if (NodeAdd (question, answer, node, nodeans) != NO_ERROR)
                    {
                        printf ("Oh my! Here is some shit on %d!\n", __LINE__);
                    }
                    //  suggestion to play again  //
                    PLAY_AGAIN
                    //  suggestion to play again  //
                }
                else if (result != 0 && AnsDetect (answer) == END)
                {
                    printf ("An underplayed game is like an uneaten last piece of cake - StatHam\n");
                    printf ("https://s0.tchkcdn.com/g-d4Z9uynSWx-K4OLsyLIlPw/11/193864/800x600/r/0/03_160373110.jpg\n");
                    break;
                }
                else
                {
                    //  suggestion to play again  //
                    PLAY_AGAIN
                    //  suggestion to play again  //
                }
            }
            if (nodeans->kind == QUESTION)
            {
                node = nodeans;
            }
            printf ("%s\n", node->data);
            result = scanf ("%s", answer);
        }
    }
//                                                  play process                                                            //


    printf ("Do you wanna see a new tree?\n");
    result = scanf ("%s", answer);
    if (result != 0 && AnsDetect (answer) == POSITIVE)
        GraphDump (tree, OPEN);
    else if (result != 0 && AnsDetect (answer) == NEGATIVE)
        GraphDump (tree, JUST);
    printf ("Thanks for using. Goodbye, bro!\n");


    //  TreePrint (tree, input_name);
    TreePrint (tree, "sources/data/input.txt");

    /*
    //       keep saving a new tree        //
    TreePrint (tree, "sources/data/input.txt");
    //       keep saving a new tree        //
    */

    free (answer);
    LexsDelete (lexus);
    TreeDelete (tree);
    return NO_ERROR;
}
