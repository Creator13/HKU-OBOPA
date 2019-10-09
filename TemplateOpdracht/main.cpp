#include "SortArray.h"
#include "Queue.h"

template <typename T>
void printArray(T array[], int n) {
    for (int i = 0; i < n; i++) {
        std::cout << array[i] << ((i == n-1) ? " " : " | ");
    }
    std::cout << std::endl;
}

int main() {
    std::cout << "FLOATS" << std::endl;
    std::cout << "-------------------------" << std::endl;

    const int flt_len = 10;
    float floats[flt_len] {
        10, 23, 2, 23, 1, 6, 7.6, 3, 2.3, 15.21
    };
    printArray(floats, flt_len);
    sortArray(floats, flt_len);
    printArray(floats, flt_len);

    //##############################################//
    std::cout << "-------------------------" << std::endl;
    std::cout << "STRINGS" << std::endl;
    std::cout << "-------------------------" << std::endl;

    const int str_len = 5;
    std::string strings[str_len] {
        "AAABBB",
        "BBBAAA",
        "CCCCCC",
        "(Iam text)",
        "Balabal"
    };
    printArray(strings, str_len);
    sortArray(strings, str_len);
    printArray(strings, str_len);

    /********************************************/
    // QUEUE
    /********************************************/
    std::cout << "-------------------------" << std::endl;
    std::cout << "QUEUE" << std::endl;
    std::cout << "-------------------------" << std::endl;

    Queue<int> q {};
    q.enqueue(4);
    std::cout << q << std::endl;
    q.enqueue(3);
    std::cout << q << std::endl;
    q.enqueue(2);
    std::cout << q << std::endl;
    q.enqueue(1);
    std::cout << q << std::endl;
    q.dequeue();
    std::cout << q << std::endl;
    q.dequeue();
    std::cout << q << std::endl;
    q.dequeue();
    std::cout << q << std::endl;
    q.dequeue();
    std::cout << q << std::endl;

}