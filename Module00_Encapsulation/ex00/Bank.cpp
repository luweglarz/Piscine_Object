#include "Bank.hpp"

Bank::Bank() :
    liquidity(0)
{

}

Bank::Bank(const Bank& other) :
    liquidity(other.liquidity),
    clientAccounts(other.clientAccounts)
{

}

Bank& Bank::operator=(const Bank& other)
{
    if (this != &other)
    {
        this->liquidity = other.liquidity;
        clientAccounts = other.clientAccounts;
    }
    return *this;
}

Bank::Bank(Bank& other):
    liquidity(other.liquidity),
    clientAccounts(other.clientAccounts)
{

}

Bank& Bank::operator=(Bank& other)
{
    if (this != &other)
    {
        this->liquidity = other.liquidity;
        this->clientAccounts = other.clientAccounts;
    }
    return *this;
}

Bank::~Bank()
{
    this->clientAccounts.clear();
}

const int& Bank::getLiquidity() const {
    return this->liquidity;
}

void Bank::setLiquidity(int newLiquidity) {
    this->liquidity = newLiquidity;
}

const std::vector<Account *>& Bank::getClientAccounts() const {
    return this->clientAccounts;
}

void Bank::addClientAccount(Account* account) {
    for (std::vector<Account*>::iterator it = this->clientAccounts.begin(); it != this->clientAccounts.end(); it++)
    {
        if ((*it)->getId() == account->getId()){
            std::cerr << "Account with id " << account->getId() << " already exists in the bank" << std::endl;
        }
    }
    if (account != NULL)
        this->clientAccounts.push_back(account);
}

void Bank::addMoney(Account& account, int amount) {
    bool foundAccount = false;
    int commission = amount * 0.05;
    size_t i = 0;

    while (i < this->clientAccounts.size())
    {
        Account* checkAccount = this->clientAccounts[i];
        if (account.getId() == checkAccount->getId())
        {
            account.setValue(account.getValue() + (amount - commission));
            foundAccount = true;
            break;
        }
        i++;
    }
    if (!foundAccount)
    {
        std::cerr << "Account with id " << account.getId() << " not found in the bank" << std::endl;
    }
	this->liquidity += commission;
}

std::ostream& operator << (std::ostream& p_os, const Bank& p_bank)
{
    p_os << "Bank informations : " << std::endl;
    p_os << "Liquidity : " << p_bank.getLiquidity() << std::endl;
    const std::vector<Account*>& clientAccounts = p_bank.getClientAccounts();
    for (std::vector<Account*>::const_iterator it = clientAccounts.begin(); it != clientAccounts.end(); ++it)
        p_os << *(*it) << std::endl;
    return p_os;
}

void Bank::removeLiquidity(int amount) {
    this->liquidity -= amount;
}

void Bank::addLiquidity(int amount) {
    this->liquidity += amount;
}