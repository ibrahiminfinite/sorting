
#include "InsertionSort.h"

void insertionSort(std::vector<int>& keys)
{
    int i;
    for(int j = 1; j < keys.size() ; j = j + 1)
    {
        auto key = keys[j];
        i = j - 1;
        while(i >= 0 && keys[i] > key)
        {
            keys[i + 1] = keys[i];
            i -= 1;
        }
        keys[i + 1] = key;
    }
}

