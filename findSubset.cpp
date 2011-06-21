#include<iostream>
using namespace std;
int findSubset(string result , string output)
{
	if (output.length()==0)
	{
		cout<<result<<"\n";
		return 0;
	}
	else 
	{
		findSubset(result+output[0], output.substr(1,output.length()));
		findSubset(result , output.substr(1, output.length()));
	}
}

int main()
{
	findSubset("","abcd");
	return 0;
}

