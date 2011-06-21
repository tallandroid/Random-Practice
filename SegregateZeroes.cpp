#include<iostream>
#include<vector>
using namespace std;
/*void SegregateZeroes(int *array,int sizeOfArray)
{
	int sizeArray = sizeOfArray;
	int lh = 0;
	int rh = sizeArray -1;
	while(array[rh]==0)rh--;
	for(int lh = 0 ; lh == rh;lh++)
	{	
		if(array[lh] == 0)
		{	
			int temp = array[lh];
			for(int i = lh ; i == rh-i ;i++)
			{
				array[i] = array[i+1];
			}
			array[rh] = temp;
		}
	}
}*/

int main()
{
	int arr[] = {1,0,2,0,3,0,0,4,5,6,7,0,0,0};
	/*vector<int> array;
	for(int i=0;i<(sizeof(arr)/sizeof(arr[0]));i++)
	{
		array.push_back(arr[i]);
	}*/
	int sizeArray = (sizeof(arr)/sizeof(arr[0]));
	for(int i =0;i<sizeArray;i++)cout<<arr[i]<<"\t";
	cout<<endl;
	//SegregateZeroes(arr,(sizeof(arr)/sizeof(arr[0])));
        int lh = 0;
        int rh = sizeArray -1;
        while(arr[rh]==0)rh--;
        for(lh = 0 ; lh <= rh;lh++)
        {
                if(arr[lh] == 0)
                {
                        int temp = arr[lh];
                        for(int i = lh ; i <= rh ;i++)
                        {
                                arr[i] = arr[i+1];
                        }
                        arr[rh] = temp;
                }
        }
	for(int i =0;i<sizeArray;i++)cout<<arr[i]<<"\t";
	return 0;
}		
