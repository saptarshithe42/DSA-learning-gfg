#include<iostream>
using namespace std;

int repeat(int arr[], int n)
{
	int slow = arr[0], fast = arr[0];

	do{
		slow = arr[slow];
		fast = arr[arr[fast]];
	
	}while(slow != fast);
	
	slow = arr[0];

	while(slow != fast)
	{
		slow = arr[slow];
		fast = arr[fast];
	}
	return slow;
}


int main()
{
    int arr[] = {5,5,2,3,0,4};
    int n = 6;

    cout << repeat(arr, n) << endl;


    
    return 0;
}