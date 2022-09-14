#include <iostream>
using namespace std;

class CUser
{
public:
	CUser()
	{
		cout << "constructor" << endl;
	}

	int GetID() const
	{
		return id;
	}

	void SetID(int nParam)
	{
		id = nParam;
	}

private:
	int id = 0;
};

int main()
{
	CUser user;
	user.SetID(10);

	cout << user.GetID() << endl;

	//�Ʒ� ���� ������ ���ñ�?
	CUser user2(user);
	cout << user2.GetID() << endl;

	return 0;
}