//the following implementation of the print in binary can be improved 
//by printing the reverse just by using recursion

#include<iostream>
#include<stdlib.h>
using namespace std;
string reverseString(string result)
{
	cout << " Entering function 1 \n ";
	string test;
	for (int i =result.length(); i>0 ; i--)
	{
		test += result[i];
	}
	return test;
}

int printInBinary(int num)
{
	string result ;
	if(num/2 == 1)
	{
		cout << "entering block 1 \n";
		result += '1';
		string final = reverseString(result);
		cout << final;
		return 0;
	}
	else if (num == 0)
	{
		cout << "Entering block 2 \n";
		string final = reverseString(result);	
		cout<< final;
		return 0;
	}
	else
	{	
		cout << "Entering block 3 \n";
		if (num%2)
			result +='1';
		else 
			result +='0';
		return printInBinary(num/2);
	}
}

int main()
{
	cout << "enter the number : \n";
	int num;
	cin >> num;
	printInBinary(num);
	return 0;
}
		
