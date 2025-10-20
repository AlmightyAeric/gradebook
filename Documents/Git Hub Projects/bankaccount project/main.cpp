#include <iostream>
#include "bankaccount.hpp"

int main() {

    BankAccount myAccount("Joe", 12345, 8500.0);

    myAccount.display();
    myAccount.deposit(200);
    myAccount.withdraw(250);
    myAccount.display();




    return 0;

}