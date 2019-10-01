#include "Transaction.h"

Transaction::Transaction(float amt) : amt(amt) {
    // Create new transaction with the current timestamp
    time_t now = std::time(nullptr);
    time = gmtime(&now);
}

Transaction::~Transaction() {
    // This line of code causes the program to Segfault and I don't understand why
//    delete time;
}

float Transaction::getAmount() const {
    return amt;
}

std::ostream& operator<<(std::ostream& os, Transaction& t) {
    // Print the transaction in the following format:
    // {amt}EUR @ {yr}-{mt}-{dy} {hr}:{min} (UTC)

    os << t.amt << "EUR @ " <<
       (1900 + t.time->tm_year) << "-" <<
       (1 + t.time->tm_mon) << "-" <<
       t.time->tm_mday << " " <<
       t.time->tm_hour << ":" <<
       t.time->tm_min << " (UTC)";

    return os;
}
