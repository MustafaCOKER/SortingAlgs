#pragma once

#include <stdio.h>

// Type Definitions
typedef unsigned char boolean;

typedef void (*t_sswap)(void *, size_t, size_t);
typedef boolean (*t_greaterThan)(void *, size_t, size_t);
typedef boolean (*t_compareNthItemsOf2Array)(const void *, const void *, size_t);

// Macro Definitions

#define TRUE    1
#define FALSE   0

#define GOTO_INDEX(ttype, startPos, index)                                  \
    ( * ((ttype*) (startPos + index * sizeof(ttype))) )

#define DEF_GREATER_THAN( type, fooName )                                   \
    boolean fooName(void* p1, size_t index1, size_t index2)                 \
    {                                                                       \
        return GOTO_INDEX( type, p1, index1 )                               \
             > GOTO_INDEX( type, p1, index2 );                              \
    }

#define DEF_SWAP( type, fooName )                                           \
    void fooName(void* p1, size_t index1, size_t index2)                    \
    {                                                                       \
        type temp = GOTO_INDEX( type, p1, index2 );                         \
        GOTO_INDEX( type, p1, index2 ) = GOTO_INDEX( type, p1, index1 );    \
        GOTO_INDEX( type, p1, index1 ) = temp;                              \
    }

#define DEF_PRINT( type, fooName, printfFrmt)                               \
    void fooName(void* p, size_t index)                                     \
    {                                                                       \
        printf(printfFrmt, GOTO_INDEX( type, p, index ) );                  \
    }

#define DEF_COMPARE_Nth_ITEMs_Of_2ARRAY(type, fooName )                     \
    boolean fooName(const void * arr1, const void * arr2, size_t index)     \
    {                                                                       \
        if (    GOTO_INDEX( type, arr1, index ) ==                          \
                GOTO_INDEX( type, arr2, index ) )                           \
            return TRUE;                                                    \
        return FALSE;                                                       \
    }


// Function Declarations.

void printArr(void *p, size_t size, void (*print)(void *p1, size_t index));

boolean isEqualArr(const void *arr1, const void *arr2, size_t size, t_compareNthItemsOf2Array compare);