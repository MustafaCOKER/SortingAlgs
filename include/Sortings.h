#pragma once

#include "Tools.h"

void bubbleSort(void *arr, size_t size, t_greaterThan greaterThan, t_sswap sswap);

void selectionSort(void *arr, size_t size, t_greaterThan greaterThan, t_sswap sswap);

void recursiveBubbleSort(void *arr, size_t size, t_greaterThan greaterThan, t_sswap sswap);

void insertionSort(void *arr, size_t size, t_greaterThan greaterThan, t_sswap sswap);

void recursiveInsertionSort(void *arr, size_t size, t_greaterThan greaterThan, t_sswap sswap);

void gnomeSort(void *arr, size_t size, t_greaterThan greaterThan, t_sswap sswap);