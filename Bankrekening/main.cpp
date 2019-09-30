#include <iostream>
#include "Transaction.h"
#include "BankAccount.h"

using namespace std;

int main() {
    Transaction t = Transaction(90);
    Transaction t2(-30);
    BankAccount account = BankAccount();

    account += t;
    auto acc2 = account + t2;
    account += t2;
    account += Transaction{40};

    cout << "acc1" << endl;
    cout << account << endl;
    cout << "acc2" << endl;
    cout << acc2 << endl;
}