#include<iostream>
using namespace std;
void swap(int& a1, int& a2);


const int lenth = 5;
int main()
{

	int a[lenth]{};

	for (int i = 0; i < lenth; i++)
	{
		cin >> a[i];
	}

	for (int j = 1; j <= (lenth) * (lenth); j++)
	{
		for (int i = 0; i <= lenth - 2; i++)
		{
			swap(a[i], a[i + 1]);
		}

	}

	for (int i = 0; i < lenth; i++)
	{
		cout << a[i] << endl;
	}

	cout << "ok";


	return 0;
}

void swap(int& a1, int& a2)
{
	int temp;
	if (a1 >= a2)
	{
		temp = a2;
		a2 = a1;
		a1 = temp;
	}
}
