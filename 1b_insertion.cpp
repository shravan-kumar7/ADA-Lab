#include<iostream>
#include<ctime>
using namespace std;

void insertionsort(int arr[],int n)
{
	 int i,key,j;
	 for(i=1;i<n;i++)
	 {
		  key=arr[i];
		  j=i-1;
		  while(j>=0 && arr[j]>key)
		  {
			   arr[j+1] =arr[j];
			   j=j-1;
		  }
		   arr[j+1]=key;
	 }
 }
 
 void printarray(int arr[],int n)
 {
  int i;
  for(i=0;i<n;i++)
  cout<<arr[i]<<" ";
  cout<<endl;
  }
  
  int main()
  {
   clock_t start, end;
   srand(time(0));  
	int arr[5];
    for(int i=0;i<5;i++)
    {
        arr[i]=(rand()%100);
    }
    cout<<"Array: ";
    for(int i=0;i<5;i++)
    {
        cout<<arr[i]<<" ";
    }
     cout<<endl;
	int n = sizeof(arr) / sizeof(arr[0]);
    start = clock();
     insertionsort(arr,n);
     end = clock();
 
    double time_taken = double(end - start) / double(CLOCKS_PER_SEC);
    cout << "Time taken by program is : "  <<fixed<<time_taken;
    cout << " sec " << endl;
    cout<<"Sorted array: ";
    printarray(arr,n);
     
    return 0;
  }  