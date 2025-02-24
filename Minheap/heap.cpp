#include <bits/stdc++.h> 
using namespace std;
void heapify(vector<int>&arr,int n,int i)
{ 
  int large=i;
  int left=2*i+1;
  int right=2*i+2;
  if(left<n&&arr[large]>arr[left])
  {
    large=left;
  }
  if(right<n&&arr[large]>arr[right])
  {
    large=right;
  }
  if(large!=i)
  {
    swap(arr[large],arr[i]);
    heapify(arr,n,large);
  }
 
}
vector<int> buildMinHeap(vector<int> &arr)
{
    // Write your code here
    int n=arr.size();
    for(int i=(n/2)-1;i>=0;i--)
    {
        heapify(arr,n,i);
    }
    return arr;
}

