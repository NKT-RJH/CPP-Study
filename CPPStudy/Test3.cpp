#include <iostream>
using namespace std;

const int monthCount = 12;

class RespondError
{
public:
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

	static void NormalizedInput()
	{
		if (cin.fail())
		{
			cin.clear();
			cin.ignore();
			system("cls");
		}
	}
};

class IAccount
{
public:
	// ����� �� �̵��ϰ� �̸��� ���� savings�� deposit����
	

protected:
	char* name;
	int id;
};

class Savings
{
private:
	double annualInterestRate = 3.55;
	double interestIncomeTax = 15.4;
	const int percentage = 100;
	const int formulaConstant1 = 1;
	const int formulaConstant2 = 24;
	const int formulaConstant3 = 1;
	int month = 0;

public:
	Savings() = default;

	Savings(int month)
	{
		if (RespondError::LowCheck<int>(month, "Month")) return;

		this->month = month;
	}

	Savings(double annualInterestRate)
	{
		if (RespondError::LowCheck<double>(annualInterestRate, "AnnualInterestRate")) return;

		this->annualInterestRate = annualInterestRate;
	}

	Savings(double annualInterestRate, double interestIncomeTax, int month)
	{
		if (RespondError::LowCheck<int>(month, "Month")) return;
		if (RespondError::LowCheck<double>(annualInterestRate, "AnnualInterestRate")) return;
		if (RespondError::LowCheck<double>(interestIncomeTax, "InterestIncomeTax")) return;

		this->annualInterestRate = annualInterestRate;
		this->interestIncomeTax = interestIncomeTax;
		this->month = month;
	}

	int GetMonth()
	{
		return month;
	}

	bool SetMonth(int value)
	{
		if (RespondError::LowCheck<int>(value, "Month")) return false;

		month = value;

		return true;
	}

	bool SetAnnualInterestRate(double value)
	{
		if (RespondError::LowCheck<double>(value, "AnnualInterestRate")) return false;

		annualInterestRate = value;

		return true;
	}

	bool SetInterestIncomeTax(double value)
	{
		if (RespondError::LowCheck<double>(value, "InterestIncomeTax")) return false;

		interestIncomeTax = value;

		return true;
	}

	/*double CalcurateInterestRate() const
	{
		if (RespondError::LowCheck<int>(month, "Month")) return -1;


		return result;
	}*/

	double GetInterestRate() const
	{
		if (RespondError::LowCheck<int>(month, "Month")) return -1;

		double result1 = annualInterestRate * (double)(month + formulaConstant1) / formulaConstant2;
		double result2 = result1 * (formulaConstant3 - (interestIncomeTax / percentage));

		return result2;
	}
};

class InstallmentSavingsCalcurator
{
private:
	const int constNumber = 1;
	const int percentage = 100;
	int payMonthly = 0;
	double interestRate = 0;

public:
	InstallmentSavingsCalcurator() = default;

	InstallmentSavingsCalcurator(int payMonthly)
	{
		if (RespondError::LowCheck<int>(payMonthly, "PayMonthly")) return;

		this->payMonthly = payMonthly;
		interestRate = 0;
	}

	InstallmentSavingsCalcurator(int payMonthly, double interestRate)
	{
		if (RespondError::LowCheck<int>(payMonthly, "PayMonthly")) return;
		if (RespondError::LowCheck<double>(payMonthly, "InterestRate")) return;

		this->payMonthly = payMonthly;
		this->interestRate = interestRate;
	}

	bool SetPayMonthly(int value)
	{
		if (RespondError::LowCheck<int>(value, "PayMonthly")) return false;

		payMonthly = value;

		return true;
	}

	bool SetInterestRate(double value)
	{
		if (RespondError::LowCheck<double>(value, "InterestRate"))return false;

		interestRate = value;

		return true;
	}

	double Calcuration(int month)
	{
		if (RespondError::LowCheck<int>(month, "Month")) return -1;

		int depositMoney = payMonthly * month;

		double totalMoney = depositMoney * (constNumber + (interestRate / percentage));

		return totalMoney;
	}
};

int main()
{
	/*InstallmentSavings installmentSavings = InstallmentSavings();
	InstallmentSavingsCalcurator installmentSavingsCalcurator = InstallmentSavingsCalcurator();

	while (true)
	{
		cout << "1�� : Ư������ ��(12����) ���� 4%\n"
			<< "2�� : �Ϲ����� ��(12����) ���� 3%\n"
			<< "������ �����Ͻðڽ��ϱ�? (���� 1 Ȥ�� 2 �Է�) : ";

		int choose;

		cin >> choose;

		RespondError::NormalizedInput();

		if (choose == 1)
		{
			installmentSavings.SetAnnualInterestRate(4);
			break;
		}
		else if (choose == 2)
		{
			installmentSavings.SetAnnualInterestRate(3);
			break;
		}

		cout << "\n�ٽ� �Է����ּ���\n" << endl;
	}

	cout << endl;

	while (true)
	{
		cout << "�� �� �󸶸� �Ա��Ͻðڽ��ϱ�? : ";

		int payMonthly;

		cin >> payMonthly;

		RespondError::NormalizedInput();

		if (installmentSavingsCalcurator.SetPayMonthly(payMonthly)) break;
	}

	cout << endl;

	while (true)
	{
		cout << "�� ���� ���� �����Ͻðڽ��ϱ�? : ";

		int month;

		cin >> month;

		RespondError::NormalizedInput();

		if (installmentSavings.SetMonth(month)) break;
	}

	cout << endl;

	double interestRate = installmentSavings.CalcurateInterestRate();
	double interestRateAddTax = installmentSavings.CalcurateInterestRateAddTax();

	installmentSavingsCalcurator.SetInterestRate(interestRate);

	cout << fixed << "�� �� �� �ݾ��� " << (int)installmentSavingsCalcurator.Calcuration(installmentSavings.GetMonth()) << "��(�Ҽ��� ����) �Դϴ�" << endl;

	installmentSavingsCalcurator.SetInterestRate(interestRateAddTax);

	cout << fixed << "�� �� �� �ݾ��� " << (int)installmentSavingsCalcurator.Calcuration(installmentSavings.GetMonth()) << "��(�Ҽ��� ����) �Դϴ�" << endl;

	return 0;*/
}