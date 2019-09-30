#ifndef GAMEOFLIFE_BANKACCOUNT_H
#define GAMEOFLIFE_BANKACCOUNT_H


#include <vector>
#include <ostream>
#include "Transaction.h"

class BankAccount {
public:
    BankAccount();
    virtual ~BankAccount();

    BankAccount operator+(const Transaction& t) const;
    BankAccount& operator+=(const Transaction& t);
    BankAccount& operator=(const BankAccount& rhs);

    friend std::ostream& operator<<(std::ostream& os, BankAccount& acc);
private:
    float balance;
    std::vector<Transaction>* transactionLog;
};


#endif
