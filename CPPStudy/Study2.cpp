#pragma once
#include <iostream>
using namespace std;

#pragma region CUserInfo Class Definition
class CUserInfo {
public:
	int id = 0;
	string name = "";
	CUserInfo(int inputId, string inputName);
	CUserInfo(const CUserInfo& Sp);
};
CUserInfo::CUserInfo(int inputId, string inputName) {
	id = inputId;
	name = inputName;
}
CUserInfo::CUserInfo(const CUserInfo& Sp) {
	id = Sp.id;
	name = Sp.name;
}
#pragma endregion


#pragma region CDepositInfo Class Definition
class CDepositInfo
{
public:
	CDepositInfo& operator=(const CDepositInfo& sp)
	{
		DepositNormalResult = sp.DepositNormalResult;
		DepositTaxResult = sp.DepositTaxResult;

		return *this;
	}

	int pay;
	int period;
	const float interestrate = 0.03f;
	const float tax = 0.154f;
	float DepositNormalResult;
	float DepositTaxResult;
};

class CDepositCalculator {
public:
	CDepositInfo DepositNormalCalc(CDepositInfo info);
	CDepositInfo DepositTaxCalc(CDepositInfo info);
	void DepositPrintResult(CDepositInfo info);
};

CDepositInfo CDepositCalculator::DepositNormalCalc(CDepositInfo info)
{
	info.DepositNormalResult = info.pay * info.interestrate;
	info.DepositNormalResult += info.pay * info.period;
	return info;
}

CDepositInfo CDepositCalculator::DepositTaxCalc(CDepositInfo info)
{
	info.DepositTaxResult = info.DepositNormalResult - (info.DepositNormalResult * info.tax);
	info.DepositTaxResult += info.pay * info.period;
	return info;
}
void CDepositCalculator::DepositPrintResult(CDepositInfo info) {
	cout << fixed << "���� : �ſ� " << info.pay << "�� " << info.period << "���� ��ġ�ϸ� " << info.DepositTaxResult << "��" << endl;
}
#pragma endregion

class CSavingsInfo
{
public:
	CSavingsInfo& operator=(const CSavingsInfo& sp)
	{
		SavingsNormalResult = sp.SavingsNormalResult;
		SavingsTaxResult = sp.SavingsTaxResult;

		return *this;
	}

	int monthlypay;
	int period;
	const float interestrate = 0.04f;
	const float tax = 0.154f;
	int SavingsNormalResult;
	int SavingsTaxResult;
};

class CSavingsCalculator {
public:
	CSavingsInfo SavingsNormalCalc(CSavingsInfo info);
	CSavingsInfo SavingsTaxCalc(CSavingsInfo info);
	void SavingsPrintResult(CSavingsInfo info);
};

CSavingsInfo CSavingsCalculator::SavingsNormalCalc(CSavingsInfo info)
{
	info.SavingsNormalResult = (info.monthlypay * info.interestrate * (info.period + 1) * info.period / 2) / 12;
	info.SavingsNormalResult += info.monthlypay * info.period;

	return info;
}

CSavingsInfo CSavingsCalculator::SavingsTaxCalc(CSavingsInfo info)
{
	info.SavingsTaxResult = info.SavingsNormalResult - (info.SavingsNormalResult * info.tax);
	info.SavingsTaxResult += info.monthlypay * info.period;

	return info;
}
void CSavingsCalculator::SavingsPrintResult(CSavingsInfo info) {
	cout << fixed << "�ſ� " << info.monthlypay << "���� " << info.period << "���� �Ա��ϸ� " << info.SavingsTaxResult << "��" << endl;
}

void main()
{

	//����� ���� �Է�
	string TempName;
	int Tempid;
	cout << "���̵� �Է��ϼ��� : ";
	cin >> Tempid;
	cout << "�̸��� �Է��ϼ��� : ";
	cin >> TempName;
	CUserInfo user(Tempid, TempName);

	// ���� ����
	CDepositInfo DepositInfo = CDepositInfo();
	CDepositCalculator DepositCalc = CDepositCalculator();
	cout << "[���� �Է¶��Դϴ�.]" << endl;
	cout << "��ġ�� �ݾ��� �Է����ּ��� : ";
	cin >> DepositInfo.pay;
	cout << "��ġ�� �Ⱓ�� �Է����ּ��� : ";
	cin >> DepositInfo.period;
	DepositInfo = DepositCalc.DepositNormalCalc(DepositInfo);
	DepositInfo = DepositCalc.DepositTaxCalc(DepositInfo);

	// ���� ����
	CSavingsInfo SavingsInfo;
	CSavingsCalculator SavingsCalc;
	cout << "[���� �Է¶��Դϴ�.]" << endl;
	cout << "�ſ� �Ա��� �ݾ��� �Է����ּ��� : ";
	cin >> SavingsInfo.monthlypay;
	cout << "���� �Ⱓ�� �Է����ּ��� : ";
	cin >> SavingsInfo.period;
	SavingsInfo = SavingsCalc.SavingsNormalCalc(SavingsInfo);
	SavingsInfo = SavingsCalc.SavingsTaxCalc(SavingsInfo);

	//���
	CUserInfo user1(user);
	cout << user1.id << "/" << user1.name << endl;
	DepositCalc.DepositPrintResult(DepositInfo);
	SavingsCalc.SavingsPrintResult(SavingsInfo);
}