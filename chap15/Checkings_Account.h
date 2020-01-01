#ifndef _CHECKINGS_ACCOUNT_H_
#define _CHECKINGS_ACCOUNT_H_
#include "Account.h"

class Checkings_Account: public Account{
	friend std::ostream &operator<<(std::ostream &os, const Checkings_Account &account);
private:
	static constexpr const char *def_name = "Unnamed Chechings Account";
	static constexpr double def_balance = 0.0;
	static constexpr float per_check_fee = 1.5;
public:
	Checkings_Account(std::string name = def_name, double balance = def_balance);
	bool withdraw(double amount);
};

#endif
