#include "Account.hpp"
#include "Bank.hpp"

Account::Account() :
		id(-1),
		value(0)
	{
		
	}

Account::Account(const Account& other) :
	id(other.id),
		value(other.value)
{
		
}

Account& Account::operator=(const Account& other)
{
	if (this != &other)
	{
		this->id = other.id;
		this->value = other.value;
	}
	return *this;
}

Account::~Account()
{
		
}

int Account::getId() const {
	return this->id;
}

void Account::setId(const int newId) {
    this->id = newId;
}

int Account::getValue() const {
    return value;
}

void Account::setValue(const int newValue) {
    this->value = newValue;
}

std::ostream& operator << (std::ostream& p_os, const Account& p_account)
{
    p_os << "[" << p_account.id << "] - [" << p_account.value << "]";
    return p_os;
}

void Account::addValue(const int addiValue, Bank& bank)
{
    bool foundAccount = false;
    std::vector<Account *> accounts = bank.getClientAccounts();

    int i = 0;
    while (i < bank.getClientAccounts().size())
    {
        Account* account = bank.getClientAccounts()[i];
        if (account->getId() == this->id)
        {
            account->setValue(account->getValue() + addiValue);
            foundAccount = true;
            break;
        }
        i++;
    }
    if (!foundAccount)
    {
        throw std::runtime_error("Account not found");
    }
    this->value += addiValue;
	bank.addLiquidity(addiValue * 0.05);
}