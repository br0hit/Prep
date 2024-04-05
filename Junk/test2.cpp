#include<iostream>
using namespace std;


void Merge(int *arr, int start, int end)
{
    int mid = (start+end)/2;

    int len1,len2;

    len1 = mid-start+1;
    len2 = end - mid;

    // creating new arrays 

    int *arr1 = new int[len1];
    int *arr2 = new int[len2];

    // copying 

    int i,main_index;
    main_index=0;

    for(i=0;i<len1;i++)
    {
        arr1[i] = arr[main_index];
        main_index++;
    }
    
    for(i=0;i<len2;i++)
    {
        arr2[i] = arr[main_index];
        main_index++;
    }

    // Merging 

    int l1,l2;

    l1=0;
    l2=0;
    main_index=0;

    while(l1<len1 && l2<len2)
    {
        if(arr1[l1]<arr2[l2])
        {
            arr[main_index] = arr1[l1];
            main_index++;
            l1++;
        }
        else
        {
            arr[main_index] = arr2[l2];
            main_index++;
            l2++;  
        }
    }

    while(l1<len1)
    {
            arr[main_index] = arr1[l1];
            main_index++;
            l1++;
    }

    while(l2<len2)
    {
            arr[main_index] = arr2[l2];
            main_index++;
            l2++;
    }


}


void MergeSort(int *arr, int start, int end)
{
    if(start>=end)
    {
        return;
    }

    int mid= (start+end)/2;

    MergeSort(arr,start,mid);
    MergeSort(arr,mid+1,end);


    Merge(arr,start,end);
}

class Node
{
    int element;
    Node* left;
    Node
}


int main()
{

}