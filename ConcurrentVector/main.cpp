#include <thread>
#include <iostream>
#include "concurrent_vector.h"

int main() {
    // Create two vectors
    std::vector<std::string> v{};
    concurrent_vector<std::string> cv{};

    // Add items to the normal vector from three different threads
    std::thread v_t1([&v](){
        for (int i = 0; i < 150; i++) {
            v.push_back("func1");
        }
    });

    std::thread v_t2([&v](){
        for (int i = 0; i < 150; i++) {
            v.push_back("func2");
        }
    });

    std::thread v_t3([&v](){
        for (int i = 0; i < 150; i++) {
            v.push_back("func3");
        }
    });

    // Wait for threads
    v_t1.join();
    v_t2.join();
    v_t3.join();

    // Print items in normal vector
    std::cout << "standard vector: " << v.size() << std::endl;
    for (auto& num : v) {
        std::cout << num << std::endl;
    }

    // Add items to concurrent vector from three threads
    std::thread cv_t1([&cv](){
        for (int i = 0; i < 150; i++) {
            cv.push_back("func1");
        }
    });

    std::thread cv_t2([&cv](){
        for (int i = 0; i < 150; i++) {
            cv.push_back("func2");
        }
    });

    std::thread cv_t3([&cv](){
        for (int i = 0; i < 150; i++) {
            cv.push_back("func3");
        }
    });

    // Wait for threads
    cv_t1.join();
    cv_t2.join();
    cv_t3.join();

    // Print items in concurrent vectors
    std::cout << "concurrent vector: " << cv.vector.size() << std::endl;
    for (auto& num : cv.vector) {
        std::cout << num << std::endl;
    }
}