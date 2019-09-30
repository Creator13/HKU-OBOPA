#include "Transaction.h"

std::ostream& operator<<(std::ostream& os, Transaction& t) {
    os << t.amt << "EUR @ " <<
       (1900 + t.time->tm_year) << "-" <<
       (1 + t.time->tm_mon) << "-" <<
       t.time->tm_mday << " " <<
       t.time->tm_hour << ":" <<
       t.time->tm_min << " (UTC)";

    return os;
}

Transaction::Transaction(float amt) : amt(amt) {
    time_t now = std::time(nullptr);
    time = gmtime(&now);
}

Transaction::~Transaction() {
//    delete time;
}

float Transaction::getAmount() const {
    return amt;
}

