#pragma once

// Type Definitions

typedef unsigned char boolean;

typedef void (*t_sswap)(void *, int, int);
typedef boolean (*t_greaterThan)(void *, int, int);


// Macro Definitions

#define GOTO_INDEX(ttype, startPos, index)                                  \
    ( * ((ttype*) (startPos + index * sizeof(ttype))) )

#define DEF_GREATER_THAN( type, fooName )                                   \
    boolean fooName(void* p1, int index1, int index2)                          \
    {                                                                       \
        return GOTO_INDEX( type, p1, index1 )                               \
             > GOTO_INDEX( type, p1, index2 );                              \
    }

#define DEF_SWAP( type, fooName )                                           \
    void fooName(void* p1, int index1, int index2)                          \
    {                                                                       \
        type temp = GOTO_INDEX( type, p1, index2 );                         \
        GOTO_INDEX( type, p1, index2 ) = GOTO_INDEX( type, p1, index1 );    \
        GOTO_INDEX( type, p1, index1 ) = temp;                              \
    }

#define DEF_PRINT( type, fooName, printfFrmt )                              \
    void fooName(void* p, int index)                                        \
    {                                                                       \
        printf(printfFrmt, GOTO_INDEX( type, p, index ) );                  \
    }



// Function Declarations.

void printArr(void *p, int size, void (*print)(void *p1, int index));