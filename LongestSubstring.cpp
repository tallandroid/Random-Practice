/*
 * A program to find the smallest substring containing the given two words
 * Author: Harshit Rohatgi
 * Date: 18th Feb 2010
 * Comments skipped ^_^
 */
#include<iostream>
#include<fstream>
#include<string>
#include<limits.h>
#include<assert.h>
using namespace std;
int low = -1;
int high = INT_MAX;
int NumWords(string str)
{
	int length = str.size();
	int count = 0;
	for (int i = 0;i<length;i++)
	{
		if((str[i] ==' ')||str[i] =='.') //count the spaces and fullstops 
			count ++;
	}
	return count+1;
}

void LongSubstr(string str1,string str2,string str)
{
	int str1Index = -1;
	int str2Index;
	int str1Index1 = -1;
	int str2Index1;
	int minCount = str.length(); 
	assert(!str1.empty() && !str2.empty());
	while(true)
	{
		string temp;
		string temp1;
		str1Index = str.find(str1 , str1Index+1);
		str2Index = str.find(str2 , str1Index);
		str1Index1 = str.find(str2 , str1Index1+1);
		str2Index1 = str.find(str1 , str1Index1);
		if((str1Index == -1)||(str2Index == -1))break;
		if((str1Index1 == -1)||(str2Index1 == -1))break;
		for(int i = str1Index;i < str2Index;i++)
		{
			temp += str[i];
		}
		temp += ' ';
		temp += str2;
		for(int i = str1Index1;i < str2Index1;i++)
		{
			temp1 += str[i];
		}
		temp1 += ' ';
		temp1 += str1;
		int count = NumWords(temp);
		int count1 = NumWords(temp1);
		int tempCount = (count>count1)?count1:count;
		if(count<count1)
		{
			if(count<minCount){
				minCount = tempCount;
				low = str1Index; 
				high = str2Index + str2.size();
			}
		}
		else
		{
			if(count1<minCount){
				minCount = tempCount;
				low = str1Index1; 
				high = str2Index1 + str1.size();
			}
		}
		
	}
}

int main()
{
	ifstream fin;
	if(fin.fail())
	{
		fin.clear();
	}
	string filename , str,line,substr1,substr2;
	cout << "Enter the file name : ";
	cin>>filename;
	cout<< "Enter substrings to be found : ";
	cin>>substr1>>substr2;
	fin.open(filename.c_str());
	while (getline(fin,line))str+=line;
	LongSubstr(substr1,substr2,str);
	string output;
	for(int i = low; i != high;i++)
	{
		output+=str[i];
	}
	cout<<output<<"\n";
	return 0;
}
