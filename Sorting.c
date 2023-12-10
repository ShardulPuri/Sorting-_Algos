#include<stdio.h>
#include<stdlib.h>
//Bubble Sort
void BublleSort(int a[],int n)
{
    int t,i,j;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n-i-1;j++)
        {
            if(a[j]>a[j+1])
            {
                t=a[j];
                a[j]=a[j+1];
                a[j+1]=t;
            }
        }
    }
    return;
}
//Selection Sort
void SelectionSort(int a[],int n)
{
    int i,t,j,min;
    for(i=0;i<n;i++)
    {
        j=i;
        min=i;
        while(j<n)
        {
            if(a[j]<a[min])
            {
                min=j;
            }
            j++;
        }
        t=a[i];
        a[i]=a[min];
        a[min]=t;
    }
    return;
}
//Insertion Sort
void InsertSort(int a[],int n)
{
    int i,j,temp;
    for(i=1;i<n;i++)
    {
        temp=a[i];
        j=i-1;
        while(j>=0 && a[j]>temp)
        {
            a[j+1]=a[j];
            j--;
        }
        a[j+1]=temp;
    }
    return;
}
//Merge Sort
void merge(int *arr,int l,int mid, int r)
{
    int i,j,k;
    int n1=mid-l+1;
    int n2=r-mid;
    int L[n1],R[n2];
    for(i=0;i<n1;i++)
    {
        L[i]=arr[l+i];
    }
    for(i=0;i<n2;i++)
    {
        R[i]=arr[mid+i+1];
    }
    i=0;
    j=0;
    k=l;
    while(i<n1 && j<n2)
    {
        if(L[i]<R[j])
        {
            arr[k]=L[i];
            i++;
        }
        else
        {
            arr[k]=R[j];
            j++;
        }
        k++;
    }
    while(i<n1)
    {
        arr[k]=L[i];
        i++;
        k++;
    }
    while(j<n2)
    {
        arr[k]=R[j];
        j++;
        k++;
    }
}
void MergeSort(int *arr,int l,int r)
{
    if(l<r)
    {
        int mid=(l+r)/2;
        MergeSort(arr,l,mid);
        MergeSort(arr,mid+1,r);
        merge(arr,l,mid,r);
    }
}

void swap(int *p,int *q)
{
    int temp;
    temp=(*p);
    *p=*q;
    *q=temp;
    return;
}
int partition(int*arr,int l,int r)
{
    int pivot=arr[r];
    int j,i=l-1;
    for(j=l;j<=r;j++)
    {
        if(arr[j]<pivot)
        {
            i++;
            swap(&arr[i],&arr[j]);
        }
    }
    swap(&arr[i+1],&arr[r]);
    return i+1;
}
void QuickSort(int *arr,int l,int r)
{
    if(l<r)
    {
        int pivot=partition(arr,l,r);
        QuickSort(arr,l,pivot-1);
        QuickSort(arr,pivot+1,r);
    }
}
//Display Function
void display(int a[],int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        printf("%d ",a[i]);
    }
}
int main()
{
    int n,i;
    printf("Enter limit:");
    scanf("%d",&n);
    int a[n];
    printf("Enter elements:");
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    printf("\nArray after Bubble sort: ");
    BublleSort(a,n);
    display(a,n);
    printf("\nArray after Selection sort: ");
    SelectionSort(a,n);
    display(a,n);
    printf("\nArray after Insertion sort: ");
    InsertSort(a,n);
    display(a,n);
    printf("\nArray after Merge sort: ");
    MergeSort(a,0,n-1);
    display(a,n);
    printf("\nArray after Quick sort: ");
    QuickSort(a,0,n-1);
    display(a,n);
}
