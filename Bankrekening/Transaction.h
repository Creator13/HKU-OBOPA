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
    float amt; //@edwin ik wil deze const maken, maar dan klaagt hij dat hij de default assingment operator niet meer kan gebruiken. Fix?
    std::tm* time;
};


#endif
