#include <iostream>
using namespace std;
using namespace RespondError;
using namespace Tools;

namespace RespondError
{
	template <typename T>
	static bool LowCheck(T value, const char* variableName)
	{
		if (value <= 0)
		{
			cout << "\nError : " << variableName << " Is Too Low" << endl;
			return true;
		}

		return false;
	}

	static bool NormalizedInput()
	{
		if (cin.fail())
		{
			cin.clear();
			cin.ignore();
			system("cls");
			return false;
		}
		return true;
	}
};

namespace Tools
{
	template <typename T>
	static void InputQuestionResult(const char* question, T* storage)
	{
		while (true)
		{
			cout << question;

			cin >> *storage;

			if (NormalizedInput()) break;
		}
	}

	template <typename T>
	static void InputQuestionResultRange(const char* question, T* storage, T max, T min)
	{
		while (true)
		{
			cout << question;

			cin >> *storage;

			if (NormalizedInput())
			{
				if (storage >= min && storage <= max)
				{
					break;
				}
			}
		}
	}
};

class BankingAccount
{
public:
	BankingAccount() = default;

	BankingAccount(string* name, int id, double money, int month, double interest, double tax)
		: name(name), id(id), money(money), month(month), interest(interest), tax(tax) {}

	~BankingAccount()
	{
		delete(name);
	}

	bool SetID(int value)
	{
		if (LowCheck(value, "ID")) return false;

		id = value;

		return true;
	}
	bool SetName(string value)
	{

		name = new string();
		*name = value;

		return true;
	}
	bool SetMoney(double value)
	{
		if (LowCheck(value, "Money")) return false;

		money = value;

		return true;
	}
	bool SetMonth(int value)
	{
		if (LowCheck(value, "Month")) return false;

		month = value;

		return true;
	}
	bool SetInterest(double value)
	{
		if (LowCheck(value, "Interest")) return false;

		interest = value;

		return true;
	}
	bool SetTax(double value)
	{
		if (LowCheck(value, "Tax")) return false;

		tax = value;

		return true;
	}
	
	unsigned int GetID() const
	{
		if (LowCheck(id, "id")) return -1;

		return id;
	}
	double GetMoney() const
	{
		if (LowCheck(money, "Money")) return -1;

		return money;
	}
	int GetMonth() const
	{
		if (LowCheck(month, "Month")) return -1;

		return month;
	}
	double GetInterest() const
	{
		if (LowCheck(interest, "Interest")) return -1;

		return interest;
	}
	double GetTax() const
	{
		if (LowCheck(tax, "Tax")) return -1;

		return tax;
	}
	string GetName() const
	{
		return *name;
	}

protected:
	string* name = nullptr;
	unsigned int id = -1;
	double money = 0;

	int month = 0;
	double interest = 0;
	double tax = 15.4;

	const int percentage = 100;
	const int monthCount = 12;
};

class Savings : public BankingAccount // ����
{
public:
	Savings() = delete;

	Savings(string* name, int id, double money, int month, double interest, double tax)
		: BankingAccount(name, id, money, month, interest, tax) {}
	
	Savings(const BankingAccount& classObject)
	{
		name = new string();
		*name = classObject.GetName();
	}

	Savings& operator=(const Savings& classObject)
	{
		name = new string();
		*name = *classObject.name;

		return *this;
	}

	double Calcurate()
	{
		if (LowCheck(money, "Money")) return -1;
		if (LowCheck(month, "Month")) return -1;
		if (LowCheck(interest, "Interest")) return -1;
		if (LowCheck(tax, "Tax")) return -1;

		double totalMoney = money * month;

		double interestAddTax = (interest * (month + formulaConstant1) / formulaConstant2) * (formulaConstant3 - tax / percentage);

		double result = totalMoney * (formulaConstant4 + (interestAddTax / percentage));

		return result;
	}

private:
	const int formulaConstant1 = 1;
	const int formulaConstant2 = 24;
	const int formulaConstant3 = 1;
	const int formulaConstant4 = 1;
};

class Deposit : public BankingAccount // ���� ����
{
public:
	Deposit() = delete;

	Deposit(string* name, int id, double money, int month, double interest, double tax)
		: BankingAccount(name, id, money, month, interest, tax) {}

	Deposit(const BankingAccount& classObject)
	{
		name = new string();
		*name = classObject.GetName();
	}

	Deposit& operator=(const Deposit& classObject)
	{
		name = new string();
		*name = *classObject.name;

		return *this;
	}

	double Calcurate()
	{
		if (LowCheck(money, "Money")) return -1;
		if (LowCheck(interest, "Interest")) return -1;
		if (LowCheck(month, "Month")) return -1;

		double result = money * pow((formulaConstant + interest / percentage / monthCount), month);

		return result;
	}

private:
	const int formulaConstant = 1;
};

int main()
{
	BankingAccount bankingAccount = BankingAccount();

	int id;
	while (true)
	{
		cout << "���̵� �Է����ּ��� : ";

		cin >> id;

		NormalizedInput();

		if (bankingAccount.SetID(id)) break;
	}

	string name;
	while (true)
	{
		cout << "�̸��� �Է����ּ��� : ";

		cin >> name;

		NormalizedInput();

		if (bankingAccount.SetName(name)) break;
	}

	//---����-------------------------------------------------------------------------------
	Deposit deposit(bankingAccount);

	deposit.SetInterest(3);

	double depositMoney;
	InputQuestionResult("[����] �󸶳� �Ա��Ͻðڽ��ϱ�? : ", &depositMoney);
	deposit.SetMoney(depositMoney);

	int depositMonth;
	InputQuestionResult("[����] ���� ������ �󸶷� �Ͻðڽ��ϱ�? : ", &depositMonth);
	deposit.SetMonth(depositMonth);
	//--------------------------------------------------------------------------------------

	//---����-------------------------------------------------------------------------------
	Savings savings(bankingAccount);

	savings.SetInterest(4);

	double savingsMoney;
	InputQuestionResult("[����] �� �� �󸶳� �Ա��Ͻðڽ��ϱ�? : ", &savingsMoney);
	savings.SetMoney(savingsMoney);

	int savingsMonth;
	InputQuestionResult("[����] �Ա��� �� ���� ���� �Ͻðڽ��ϱ�? : ", &savingsMonth);
	savings.SetMonth(savingsMonth);
	//--------------------------------------------------------------------------------------

	cout << bankingAccount.GetID() << " / " << bankingAccount.GetName() << endl;
	cout << "���� : �� �� " << savings.GetMoney() << "�� �� " << savings.GetMonth() << "���� �Ա��ϸ� " << savings.Calcurate() << "��" << endl;
	cout << "���� : " << deposit.GetMoney() << "�� �� " << deposit.GetMonth() << "���� ��ġ�ϸ� " << deposit.Calcurate() << "��" << endl;
}