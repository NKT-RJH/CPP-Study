#include <iostream>
using namespace std;

const int monthCount = 12;

template <typename T> class RespondError
{
public:
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

class InstallmentSavings
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
	InstallmentSavings() = default;

	InstallmentSavings(int month)
	{
		if (RespondError<int>::LowCheck(month, "Month")) return;

		this->month = month;
	}

	InstallmentSavings(double annualInterestRate)
	{
		if (RespondError<double>::LowCheck(annualInterestRate, "AnnualInterestRate")) return;

		this->annualInterestRate = annualInterestRate;
	}

	InstallmentSavings(double annualInterestRate, double interestIncomeTax, int month)
	{
		if (RespondError<int>::LowCheck(month, "Month")) return;
		if (RespondError<double>::LowCheck(annualInterestRate, "AnnualInterestRate")) return;
		if (RespondError<double>::LowCheck(interestIncomeTax, "InterestIncomeTax")) return;

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
		if (RespondError<int>::LowCheck(value, "Month")) return false;

		month = value;

		return true;
	}

	bool SetAnnualInterestRate(double value)
	{
		if (RespondError<double>::LowCheck(value, "AnnualInterestRate")) return false;

		annualInterestRate = value;

		return true;
	}

	bool SetInterestIncomeTax(double value)
	{
		if (RespondError<double>::LowCheck(value, "InterestIncomeTax")) return false;

		interestIncomeTax = value;

		return true;
	}

	double CalcurateInterestRate() const
	{
		if (RespondError<int>::LowCheck(month, "Month")) return -1;

		double result = annualInterestRate * (double)(month + formulaConstant1) / formulaConstant2;

		return result;
	}

	double CalcurateInterestRateAddTax() const
	{
		if (RespondError<int>::LowCheck(month, "Month")) return -1;

		double result = CalcurateInterestRate() * (formulaConstant3 - (interestIncomeTax / percentage));

		return result;
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
		if (RespondError<int>::LowCheck(payMonthly, "PayMonthly")) return;

		this->payMonthly = payMonthly;
		interestRate = 0;
	}

	InstallmentSavingsCalcurator(int payMonthly, double interestRate)
	{
		if (RespondError<int>::LowCheck(payMonthly, "PayMonthly")) return;
		if (RespondError<double>::LowCheck(payMonthly, "InterestRate")) return;

		this->payMonthly = payMonthly;
		this->interestRate = interestRate;
	}

	bool SetPayMonthly(int value)
	{
		if (RespondError<int>::LowCheck(value, "PayMonthly")) return false;

		payMonthly = value;

		return true;
	}

	bool SetInterestRate(double value)
	{
		if (RespondError<double>::LowCheck(value, "InterestRate"))return false;

		interestRate = value;

		return true;
	}

	double Calcuration(int month)
	{
		if (RespondError<int>::LowCheck(month, "Month")) return -1;

		int depositMoney = payMonthly * month;

		double totalMoney = depositMoney * (constNumber + (interestRate / percentage));

		return totalMoney;
	}
};

int main()
{
	InstallmentSavings installmentSavings = InstallmentSavings();
	InstallmentSavingsCalcurator installmentSavingsCalcurator = InstallmentSavingsCalcurator();

	while (true)
	{
		cout << "1�� : Ư������ ��(12����) ���� 4%\n"
			<< "2�� : �Ϲ����� ��(12����) ���� 3%\n"
			<< "������ �����Ͻðڽ��ϱ�? (���� 1 Ȥ�� 2 �Է�) : ";

		int choose;

		cin >> choose;

		RespondError<int>::NormalizedInput();

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

		RespondError<int>::NormalizedInput();

		if (installmentSavingsCalcurator.SetPayMonthly(payMonthly)) break;
	}

	cout << endl;

	while (true)
	{
		cout << "�� ���� ���� �����Ͻðڽ��ϱ�? : ";

		int month;

		cin >> month;

		RespondError<int>::NormalizedInput();

		if (installmentSavings.SetMonth(month)) break;
	}

	cout << endl;

	double interestRate = installmentSavings.CalcurateInterestRate();
	double interestRateAddTax = installmentSavings.CalcurateInterestRateAddTax();

	installmentSavingsCalcurator.SetInterestRate(interestRate);

	cout << fixed << "�� �� �� �ݾ��� " << (int)installmentSavingsCalcurator.Calcuration(installmentSavings.GetMonth()) << "��(�Ҽ��� ����) �Դϴ�" << endl;

	installmentSavingsCalcurator.SetInterestRate(interestRateAddTax);

	cout << fixed << "�� �� �� �ݾ��� " << (int)installmentSavingsCalcurator.Calcuration(installmentSavings.GetMonth()) << "��(�Ҽ��� ����) �Դϴ�" << endl;

	return 0;
}