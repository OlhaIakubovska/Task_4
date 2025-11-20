#ifndef SORT
#define SORT
#include "stringProcessor.h"
void swap(char** a, char** b)
{
    char* temp = *a;
    *a = *b;
    *b = temp;
}
void quick_sort(char** arr, size_t length)
{
    if (!arr || length == 0)
        return;

    for (size_t i = 0; i < length - 1; i++)
    {
        for (size_t j = 0; j < length - i - 1; j++)
        {
            if (strcmpp(arr[j], arr[j + 1]) > 0)
            {
                swap(&arr[j], &arr[j + 1]);
            }
        }
    }
}
#endif // !SORT