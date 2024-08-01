#pragma once

#include <iostream>
#include "Bank.hpp"

class Bank;

class Account {
public:
	Account();

	Account(const Account& other);

	Account& operator=(const Account& other);

	~Account();

	int getId() const;

	void setId(const int newId);

	int getValue() const;

	void setValue(const int newValue);

	friend std::ostream& operator << (std::ostream& p_os, const Account& p_account);

private:
	int id;
	int value;
};