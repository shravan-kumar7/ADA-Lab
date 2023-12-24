#include<iostream>
#include<ctime>
using namespace std;

int partition(int arr[], int low, int high)
{
    int pivot=arr[high];
    int i=low-1;
    for (int j=low;j<high;j++)
    {
        if(arr[j]<pivot)
        {
            i++;
            swap(arr[i],arr[j]);
        }
    }
    i++;
    int temp=arr[i];
    arr[i]=pivot;
    arr[high]=temp;
    return i;
}


void quickSort(int arr[],int low,int high){
	if(low>=high)
        return;
    int pidx = partition(arr,low,high);
    quickSort(arr,low,pidx-1);
    quickSort(arr,pidx+1,high);
	
}
		
int main(){

	srand(time(0));  
	cout<<"Enter number of elements in array: ";
	int n;
	cin>>n;
	int arr[n];
    for(int i=0;i<n;i++)
    {
        arr[i]=(rand()%100);
    }
    cout<<"Random Array: ";
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;

    clock_t start = clock();
	quickSort(arr,0,n-1);
   	clock_t end = clock();

    double time_taken = double(end - start) / double(CLOCKS_PER_SEC);
    cout << "Time taken by program is : "  <<fixed<<time_taken<<" sec\n";

	cout<<"After Quick Sort: ";
	for(int i=0;i<n;i++){
		cout<<arr[i]<<" ";
	}
	cout<<endl;
	
	return 0;
}
 
