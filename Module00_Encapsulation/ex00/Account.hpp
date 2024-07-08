#include <iostream>

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

    void addValue(const int addiValue, Bank& bank);

private:
	int id;
	int value;
};