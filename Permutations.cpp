/*this is a random spam late night 3 in attempt 
 * to recall the lost coding skills
 * author: Harshit Rohatgi
 * Date: 5th September 2010
 * -----------------------------
 * a week later's random spam at afternoon 3 :/
 *
 */
#include<iostream>
using namespace std;
void GenPermutations(string orig, string perm)
{
	if (perm=="")
	{
		cout << orig << "\n";
		return;
	}
	else 
		for(int i=0;i<perm.length();i++)
		{
			string soFar = orig + perm[i];
			string remaining  = perm.substr(0,i)+perm.substr(i+1,perm.length()-i);
			GenPermutations(soFar,remaining);
			//orig = "";
		}
}

int main()
{
	string original;
	getline(cin,original);
	GenPermutations("",original);
	return 0;
}
