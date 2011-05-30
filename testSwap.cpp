#include<iostream>
#include<vector>
using namespace std;
int count = 0;
void Swap(int &a , int &b)
{
	count ++;
	int temp = a;
	a = b;
	b = temp;
}
int main()
{
	vector<int> array(10);
	for(int i =0;i<10;i++)
	{
		array[i] = 10-i;
	}
	for (int i = 0; i<9;i++)
	{
		for (int j = 0; j < 9-i;j++)
		{
			Swap(array[j],array[j+1]);
		}
	}
	cout << count <<endl;
return 0;
}
