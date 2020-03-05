#include<iostream>
using namespace std;
void insertion_sort(int arr[],int n)
{
	int key,i,j;
	for(i=1;i<n;i++)
	{
		key=arr[i];
		j=i-1;
		while(j>=0 && arr[j]>key)
		{
			arr[j+1]=arr[j];
			j--;
		}
		arr[j+1]=key;
	}
}
void merge(int arr[],int l,int m,int r)
{
	int i,j,k,n1=m-l+1,n2=r-m;
	int L[n1],R[n2];
	for(i=0;i<n1;i++)
	L[i]=arr[l+i];
	for(i=0;i<n2;i++)
	R[i]=arr[m+1+i];
	i=j=0;
	k=l;
	while(i<n1 && j<n2)
	{
		if(L[i]<=R[j])
			arr[k++]=L[i++];
		else
		    arr[k++]=R[j++];
	}
	while(i<n1)
	    arr[k++]=L[i++];
	while(j<n2)
	    arr[k++]=R[j++];
}
void merge_sort(int arr[],int l ,int r)
{
	if(l<r)
	{
		int m=(l+r)/2;
		merge_sort(arr,l,m);
		merge_sort(arr,m+1,r);
		merge(arr,l,m,r);
	}
}
void swap(int *a,int *b)
{
	int temp=*a;
	*a=*b;
	*b=temp;
}
int partition(int arr[],int l,int h)
{
	int x=arr[h];
	int i=l-1;
	for(int j=l;j<h;j++)
	{
		if(arr[j]<x)
		{
			i++;
			swap(arr[j],arr[i]);
		}
	}
	swap(arr[i+1],arr[h]);
	return i+1;
}
void quick_sort(int arr[],int l,int h)
{
	if(l<h)
	{
		int p=partition(arr,l,h);
		quick_sort(arr,l,p-1);
		quick_sort(arr,p+1,h);
	}
}
void max_heapify(int arr[],int i,int n)
{
	int l=2*i+1,r=2*i+2,largest;
	if(l<n && arr[l]>arr[i])
	largest=l;
	else
	largest=i;
	if(r<n && arr[r]>arr[largest])
	largest=r;
	if(largest!=i)
	{
		swap(arr[i],arr[largest]);
		max_heapify(arr,largest,n);
	}
}
void build_heap(int arr[],int n)
{
	for(int i=(n/2)-1;i>=0;i--)
	max_heapify(arr,i,n);
	
	for(int i=n-1;i>=0;i--)
	{
		swap(arr[0],arr[i]);
		max_heapify(arr,0,i);
	}
}
void print(int arr[],int n)
{
	for(int i=0;i<n;i++)
	cout<<arr[i]<<" ";
	cout<<endl;
}
int main()
{
	int n;
	cout<<"enter the length of array = ";
	cin>>n;
	int arr[n];
	cout<<"\nenter the array element = \n";
	for(int i=0;i<n;i++)
	cin>>arr[i];
	cout<<"Insertion sort = \n";
	insertion_sort(arr,n);
	print(arr,n);
	cout<<"Merge sort = \n";
	merge_sort(arr,0,n-1);
	print(arr,n);
	cout<<"Quick_sort = \n";
	quick_sort(arr,0,n-1);
	print(arr,n);
	cout<<"Build heap = \n";
	build_heap(arr,n);
	print(arr,n);
	return 0;
}

