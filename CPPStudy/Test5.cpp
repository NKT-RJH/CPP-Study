#include <iostream>
using namespace std;

#define YearCount 12

//���ο��� : �� �ҵ�� 4.5%
//�ǰ����� : ���������� 3.495%
//����纸�� : �ǰ�������� 12.27%
//��뺸�� : �� �ҵ���� 0.9%

class Insurance
{
public:
	Insurance() = delete;

	Insurance(string name, double rate)	: name(name), rate(rate) {}

	void SetName(string value)
	{
		name = value;
	}
	void SetRate(double value)
	{
		rate = value;
	}

	string GetName() const
	{
		return name;
	}
	double GetRate()
	{
		return rate;
	}

	double Calcurate(double value)
	{
		return value * rate / percentage;
	}

//protected:
private:
	string name;
	double rate;

	const int percentage = 100;
};

class Person
{
public:
	Person() = default;

	Person(double annualSalary) : annualSalary(annualSalary)
	{
		salary = annualSalary / YearCount;
	}

	void SetAnnualSalary(double value)
	{
		annualSalary = value;
		salary = value / YearCount;
	}

	double GetSalary() const
	{
		return salary;
	}
	double GetAnnualSalary() const
	{
		return annualSalary;
	}

private:
	double annualSalary = 0;
	double salary = 0;
};

template <typename T>
static T Input(const char* question)
{
	T storage;

	while (true)
	{
		cout << question;

		cin >> storage;

		if (cin.fail())
		{
			cin.clear();
			cin.ignore();
			system("cls");
		}
		else
		{
			break;
		}
	}

	return storage;
}

int main()
{
	Insurance nationalPension("���ο���", 4.5);
	Insurance healthInsurance("�ǰ�����", 3.495);
	Insurance longTermNursingInsurance("����纸��", 12.27);
	Insurance employmentInsurance("��뺸��", 0.9);

	Person person;

	person.SetAnnualSalary(Input<double>("������ �Է��ϼ��� (��) : "));

	double calcurate1 = nationalPension.Calcurate(person.GetSalary());
	double calcurate2 = healthInsurance.Calcurate(person.GetSalary());
	double calcurate3 = longTermNursingInsurance.Calcurate(calcurate2);
	double calcurate4 = employmentInsurance.Calcurate(person.GetSalary());

	double result = person.GetSalary() - (calcurate1 + calcurate2 + calcurate3 + calcurate4);

	cout << fixed << "���� : " << result << endl;

	return 0;
}