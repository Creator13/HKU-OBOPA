#ifndef GAMEOFLIFE_SORTARRAY_H
#define GAMEOFLIFE_SORTARRAY_H

#include <string>
#include <iostream>

template<typename T>
void sortArray(T array[], int n) {
    // Simple bubble sort
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1 - i; j++) {
            if (array[j] > array[j+1]) {
                T temp = array[j];
                array[j] = array[j+1];
                array[j+1] = temp;
            }
        }
    }
}

#endif //GAMEOFLIFE_SORTARRAY_H
