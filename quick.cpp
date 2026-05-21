#include<iostream>
using namespace std;
int partition(int arr[] , int first ,int last) {
	int pivot=last;
	int i= first-1;
	int j= last;
	for(; j<last; j++)
	{
		if(arr[j]<pivot) {
			i++;
			swap(arr[i] , arr[j]);
		}
	}
	swap(arr[i+1] ,arr[last]);
	return i+1;
}
void quicksort (int arr[] ,int first,int last) {
	if(first>=last) {
		return;
	}
	int pi= partition(arr,first,last);
	quicksort(arr ,first ,pi-1);
	quicksort(arr, pi+1 , last);
}
int main()
{
	int n;
	int arr[n];
	cout<<"enter the number of element:";
	cin>>n;
	cout<<"enter the element:";
	for(int i=0; i<n; i++)
	{
		cin>>arr[i];
	}
	quicksort (arr,0,n-1);
	for(int i=0; i<n; i++)
	{
		cout<<arr[i]<<" ";
	}
	return 0;
}
