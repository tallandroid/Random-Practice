#include<iostream>
#include<vector>
#include<map>
using namespace std;

struct tuple{
  int count;
	string str;
};

tuple FrequentWords(string str)
{
	map<char,int> LetterMap;
	int sizeStr = str.size();
	//cout << sizeStr;
	int count = 1;
	for(int i = 0; i<sizeStr;i++)
	{
		if(str[i] != ' '){
		map<char,int>::iterator it = LetterMap.find(str[i]);
		if(it != LetterMap.end())
			 (it->second)++;			
		else 
			LetterMap.insert(map<char,int>::value_type(str[i],count));
	}
	}

	int maxFrequent = -1;
	for(map<char,int>::iterator it = LetterMap.begin(); it != LetterMap.end(); it++)
	{
			if(it->second > maxFrequent)
				maxFrequent = it->second;
	}
	
	string s;
	for(map<char,int>::iterator it = LetterMap.begin(); it != LetterMap.end(); it++)
  {
          if(it->second == maxFrequent)
        		s += it->first;	
  }
	tuple testTuple;
	testTuple.count = maxFrequent;
	testTuple.str = s;
	return testTuple;	
 }
	

void printMostFrequentWords(vector<string> V)
{
	int sizeArray = V.size();
	for (int i = 0;i<sizeArray;i++)
	{
		cout<<FrequentWords(V[i]).str<<" "<<FrequentWords(V[i]).count<<endl;
	}
	//cout<<LetterMap['H']<<endl;
}

int main()
{
	vector<string> V(2);
	for(int i =0;i<V.size();i++)
	{
		cout << "enter the string " <<"\n";
		getline(cin,V[i]);
	}	
	printMostFrequentWords(V);
	return 0;
}
