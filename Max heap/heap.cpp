#include <iostream>
using namespace std;
class heap{
int arr[100];
int size;
public:
heap()
{
  arr[0]=-1;
  size=0;
}
void insert(int x)
{
  size++;
  int idx=size;
  arr[idx]=x;
  while(idx>1)
  {
    int parent=idx/2;
    if(arr[parent]<arr[idx])
    {
      swap(arr[parent],arr[idx]);
      idx=parent;
    }
    else
    {
      return;
    }
  }
}
void print()
{
  for(int i=1;i<=size;i++)
  {
    cout<<arr[i]<<" ";
  }
}
void dlt()
{
  if(size==0)
  {
    cout<<"Bhau ks delete honar size ch nahi";
    return;
  }
  arr[1]=arr[size];
  size--;
  int root=1;
  while(root<size)
  { int left=2*root;
  int right=2*root+1;
    if(left<size&&arr[root]<arr[left])
    {
       swap(arr[root],arr[left]);
       root=left;
    }
    else if(right<size&&arr[root]<arr[right])
    {
      swap(arr[root],arr[right]);
      root=right;
    }
    else
    {
      return;
    }
  }
}
};
void heapify(int arr[],int n,int i)
{ 
  int large=i;
  int left=2*i;
  int right=2*i+1;
  if(left<n&&arr[large]<arr[left])
  {
    large=left;
  }
  if(right<n&&arr[large]<arr[right])
  {
    large=right;
  }
  if(large!=i)
  {
    swap(arr[large],arr[i]);
    heapify(arr,n,large);
  }
 
}
int main() {
 heap h;
 h.insert(50);
 h.insert(55);
 h.insert(53);
 h.insert(52);
 h.insert(54);
 h.print();
 h.dlt();
 cout<<endl;
 h.print();
 cout<<endl;
 int a[6]={-1,54,53,55,52,50};
 int n=5;
 for(int i=n/2;i>0;i--)
 {
  heapify(a,n,i);
 }
 for(int i=1;i<6;i++)
  {
    cout<<a[i]<<" ";
  }
  return 0;
}