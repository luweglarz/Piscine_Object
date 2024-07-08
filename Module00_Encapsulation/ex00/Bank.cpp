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

Bank::Bank(Bank&& other) noexcept :
    liquidity(std::move(other.liquidity)),
    clientAccounts(std::move(other.clientAccounts))
{

}

Bank& Bank::operator=(Bank&& other) noexcept
{
    if (this != &other)
    {
        this->liquidity = std::move(other.liquidity);
        this->clientAccounts = std::move(other.clientAccounts);
    }
    return *this;
}

Bank::~Bank()
{
    for (auto& account : clientAccounts)
        delete account;
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
    this->clientAccounts.push_back(account);
}

std::ostream& operator << (std::ostream& p_os, const Bank& p_bank)
{
    p_os << "Bank informations : " << std::endl;
    p_os << "Liquidity : " << p_bank.liquidity << std::endl;
    for (auto &clientAccount : p_bank.clientAccounts)
        p_os << *clientAccount << std::endl;
    return (p_os);
}

void Bank::removeLiquidity(int amount) {
    this->liquidity -= amount;
}

void Bank::addLiquidity(int amount) {
    this->liquidity += amount;
}