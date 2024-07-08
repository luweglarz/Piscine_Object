#pragma once

#include <vector>
#include "Account.hpp"

class Bank
{
public:
	Bank();

	Bank(const Bank& other);

	Bank& operator=(const Bank& other);

	Bank(Bank&& other) noexcept;

	Bank& operator=(Bank&& other) noexcept;

	~Bank();

	const int& getLiquidity() const;

	void setLiquidity(int newLiquidity);

	const std::vector<Account *>& getClientAccounts() const;

	void addClientAccount(Account* account);

    void removeLiquidity(int amount);

    friend std::ostream& operator << (std::ostream& p_os, const Bank& p_bank);

    void Bank::removeLiquidity(int amount);

    void addLiquidity(int amount);

private:
	int liquidity;
	std::vector<Account *> clientAccounts;
};