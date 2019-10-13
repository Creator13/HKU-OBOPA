#ifndef GAMEOFLIFE_TRANSACTION_H
#define GAMEOFLIFE_TRANSACTION_H


#include <ctime>
#include <ostream>

class Transaction {
public:
    explicit Transaction(float amt);
    virtual ~Transaction();

    float getAmount() const;

    friend std::ostream& operator<<(std::ostream& os, Transaction& t);
private:
    float amt;
    std::tm* time;
};


#endif
