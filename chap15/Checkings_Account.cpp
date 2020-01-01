#include "Checkings_Account.h"

Checkings_Account::Checkings_Account(std::string name, double balance): Account{name, balance}{
}

bool Checkings_Account::withdraw(double amount){
	amount += per_check_fee;
	return Account::withdraw(amount);
}

std::ostream &operator<<(std::ostream& os, const Checkings_Account & account){
	os<<"[Checking Account: "<<account.name <<": "<< account.balance << "]";
	return os;
}
