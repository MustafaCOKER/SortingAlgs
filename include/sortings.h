#pragma once

#include "tools.h"

void bubbleSort(void* arr, size_t size, t_greaterThan greaterThan, t_sswap sswap);

void selectionSort(void* arr, size_t size, t_greaterThan greaterThan, t_sswap sswap);

void recursiveBubbleSort(void* arr, size_t size, t_greaterThan greaterThan, t_sswap sswap);