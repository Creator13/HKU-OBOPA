#ifndef GAMEOFLIFE_CONCURRENT_VECTOR_H
#define GAMEOFLIFE_CONCURRENT_VECTOR_H

#include <vector>
#include <mutex>

template <typename T>
class concurrent_vector {
public:
    concurrent_vector() : vector(), mutex() {};
    virtual ~concurrent_vector() = default;

    std::vector<T> vector;

    void push_back(T elem) {
        mutex.lock();
        vector.push_back(elem);
        mutex.unlock();
    }
private:
    std::mutex mutex;
};


#endif //GAMEOFLIFE_CONCURRENT_VECTOR_H
