#include<iostream>
using namespace std;
bool isPali(string str)
{
	int len = str.length();
	if (len <= 1)
		return true;
	else if(str[0] == str[len -1]){
		return isPali(str.substr(1,len-2));    
 }
 	else return false;
}

string longestPali(string str)
{
  int len = str.length();
	string maxPali = "";
	int maxLen = -1;
	for (int i = 0;i < len;i++)
	{
  	for(int j = len-1; j>i; j--)
		{
    	if(isPali(str.substr(i,j-i+1))){
      	if(j-i+1 > maxLen)
				{
      		maxLen = j-i+1;
					maxPali = str.substr(i,j-i+1);
    }
   }
  }  
 }
	return maxPali;	
}

int main()
{
    string str = "cddcbaddabcbaxyz";
	//cout << isPali(str);
	string pali = longestPali(str);
	cout << pali;
	return 0;
}
