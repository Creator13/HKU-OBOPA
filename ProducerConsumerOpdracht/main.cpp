#include <queue>
#include <thread>
#include <iostream>
#include <condition_variable>

int counter = 0;
bool done = false;
std::queue<int> goods;

std::condition_variable flag;
std::mutex mutex;

void producer() {
    for (int i = 0; i < 500; ++i) {
        goods.push(i);
        counter++;
    }

    done = true;
    flag.notify_one();
}

void consumer() {
    // Skip waiting altogether if the producer is already done when this thread starts (solves lost notification)
    // @Edwin: ik kreeg telkens het probleem dat de producer al klaar was voordat deze thread uberhaupt begon en daarom
    // heb ik dit geimplementeerd. Alleen dit gebruikt nog steeds een globale variabele waar beide threads bij moeten
    // kunnen, en volgens mij breekt dit het observer pattern een beetje. Stel nou dat beide threads volledig
    // onafhankelijk van elkaar moeten werken en niet bij dezelfde data kunnen, dan is dit geen goede oplossing.
    // Is er een betere oplossing hiervoor?
    while (!done) {
        std::unique_lock<std::mutex> lock(mutex);
        flag.wait(lock);
    }

    // C O N S U M E
    while (!goods.empty()) {
        goods.pop();
        counter--;
    }
}

int main() {
    std::thread producerThread(producer);
    std::thread consumerThread(consumer);

    producerThread.join();
    consumerThread.join();

    std::cout << "Net: " << counter << " " << goods.size() << " " << std::endl;
}
