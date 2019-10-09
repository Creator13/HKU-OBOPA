#ifndef GAMEOFLIFE_QUEUE_H
#define GAMEOFLIFE_QUEUE_H


#include <list>
#include <ostream>

template <typename T>
class Queue {
public:
    Queue() = default;
    virtual ~Queue() = default;

    void enqueue(T elem) {
        list.push_back(elem);
    }

    T dequeue() {
        T elem = list.front();
        list.pop_front();
        return elem;
    }

    int size() {
        return list.size();
    }

    friend std::ostream& operator<<(std::ostream& os, const Queue& q) {
        for(auto elem : q.list) {
            os << elem << (elem == q.list.back() ? " " : " | ");
        }
        os << "\n";
        os.flush();
        return os;
    }
private:
    std::list<T> list;
};


#endif //GAMEOFLIFE_QUEUE_H
