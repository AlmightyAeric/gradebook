#ifndef BANKACCOUNT_HPP
#define BANKACCOUNT_HPP

#include <string>

class BankAccount{
   
 private:
 std::string name;
 int account_num;
 double balance;


 public:
 BankAccount(const std::string& accName, int accNum, double initialBal);
   void deposit(double amount);
   void withdraw(double amount);
   void display() const;


};

#endif