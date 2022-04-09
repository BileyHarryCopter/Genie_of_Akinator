#ifndef INOUT
#define INOUT

typedef enum {POSITIVE = 20, NEGATIVE, END} answer_t;

typedef enum
{
    N = 0,
    NO,
    NOPE,
    Y,
    YES,
    YEAH,
    Q,
    QUIT,
    NUMB_OF_ANSW
} answers;

static char * name_answ [NUMB_OF_ANSW] =
{
    "N",
    "NO",
    "NOPE",
    "Y",
    "YES",
    "YEAH",
    "Q",
    "QUIT"
};

#endif
