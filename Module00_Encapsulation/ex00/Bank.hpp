#pragma once

#include <vector>
#include <iostream> // Include any other necessary headers here
#include "Account.hpp"
class Account; // Forward declaration of the Account class

class Bank
{
public:
	Bank();

	Bank(const Bank& other);

	Bank& operator=(const Bank& other);

	Bank(Bank& other) ;

	Bank& operator=(Bank& other);

	~Bank();

	const int& getLiquidity() const;

	void setLiquidity(int newLiquidity);

	const std::vector<Account *>& getClientAccounts() const;

	void addClientAccount(Account* account);

	friend std::ostream& operator << (std::ostream& p_os, const Bank& p_bank);

	void removeLiquidity(int amount);

	void addLiquidity(int amount);

	void addMoney(Account& account, int amount);

private:
	int liquidity;
	std::vector<Account *> clientAccounts;
};