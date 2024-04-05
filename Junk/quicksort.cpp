#include<iostream>
using namespace std;

int findIndex(int *arr, int start, int end )
{
    int pivot_index;
    pivot_index = start;

    int i,min_number;

    for(i=start+1, min_number=0 ;i<end+1;i++)
    {
        if(arr[i]<arr[start]) min_number++;
    }

    int temp;

    pivot_index += min_number;

    temp = arr[pivot_index];
    arr[pivot_index] = arr[start];
    arr[start]= temp;

    int k,j;

    for(k=pivot_index+1,j=0;k<end+1;k++)
    {
        if(arr[k]<arr[pivot_index])
        {
            while(arr[j]<arr[pivot_index] && j<pivot_index)
            {
                j++;
            }

            temp = arr[k];
            arr[k] = arr[j];
            arr[j] = temp;
            j++;
        }
    }


    return pivot_index;

}

void quickSort(int *arr, int start, int end)
{

    if(start>=end)
    {
        return;
    }


    int pivot;
    // assumign pivot is the start element 
    pivot = arr[start];

    int pivot_index,temp;

    pivot_index = findIndex(arr, start, end);

    quickSort(arr,start,pivot_index-1);
    quickSort(arr,pivot_index+1,end);

}

int main()
{
    int n,k;

    int arr[5] = {1,5,2,10,3};
    n=5;

    quickSort(arr, 0, n-1);

    for(k=0;k<n;k++)
    {
        cout<<arr[k];
    }


}