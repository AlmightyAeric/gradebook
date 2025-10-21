#include <iostream>
#include "bankaccount.hpp"

BankAccount::BankAccount(const std::string& accName, int accNum, double initialBal)
 :name(accName),account_num(accNum), balance(initialBal) {}

void BankAccount::deposit(double amount) {
    if(amount > 0) {
        balance+= amount;
        std::cout << "Deposit $" << amount << "\n";
    } else {
      std::cout << "Invalid deposit amount\n";
    }
  
  }

  void BankAccount::withdraw(double amount) {
    if(amount > 0 && amount <= balance) {
      balance -= amount;
      std::cout << "Withdraw $" << amount << "\n";
      std::cout << "New balance: $" << balance << "\n";
    } else {
      std::cout << "Invalid withdrawal amount.\n";
    }
  }

  void BankAccount::display() const {
    std::cout << "Account Holder " << name << "\n";
    std::cout << "Account Number " << account_num << "\n";
    std::cout << "Balance " << balance << "\n";

  
  }