#include "BankAccount.h"

using namespace std;

BankAccount::BankAccount() : balance(0) {
    transactionLog = new std::vector<Transaction>();
}

BankAccount::~BankAccount() {
    delete transactionLog;
}

BankAccount BankAccount::operator+(const Transaction& t) const {
    // Create new account object, copy the values of the current account into it
    BankAccount acc = BankAccount();
    acc = *this;
    // Add the transaction using the overloaded += operator
    acc += t;
    // Return the new object
    return acc;
}

BankAccount& BankAccount::operator+=(const Transaction& t) {
    balance += t.getAmount();
    transactionLog->push_back(t);
    return *this;
}

BankAccount& BankAccount::operator=(const BankAccount& rhs) {
    if (this != &rhs) {
        balance = rhs.balance;
        // Deep-copy the transaction list to the other object
        transactionLog->assign(rhs.transactionLog->begin(), rhs.transactionLog->end());
    }
    return *this;
}

std::ostream& operator<<(std::ostream& os, BankAccount& acc) {
    os << "Total balance: " << acc.balance << endl;
    os << "- - - - - - - - - - - - - - " << endl;
    for (auto& trans : *acc.transactionLog) {
        os << trans << endl;
    }
    os << "- - - - - - - - - - - - - - " << endl;
    return os;
}


