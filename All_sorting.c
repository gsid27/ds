#include<stdio.h>
void display(int arr[],int no)
{
    for(int i=0;i<no;i++)
    {
        printf("\t%d",arr[i]);
    }
}
void swaping(int *arr,int x , int y)
{
    
    int temp;
    temp = arr[x];
    arr[x]=arr[y];
    arr[y]=temp;
    printf("\nSWAPPED %d and %d \n",arr[x],arr[y]);
}
/*strting of quick sorting :*/
void insertionsort(int a[10],int n)
{
for(int i=1;i<n;i++)
{
    int tmp=a[i];int j=i;
    while(j>0)
    {
        if(a[j-1]>tmp)
            a[j]=a[j-1];
        else
            break;
        j--;
    }
    a[j]=tmp;
    }
}

int median3(int arr[10],int left,int right)
{
    int mid;
  mid=(left+right)/2;
  if(arr[left]>arr[mid])
      swap(&arr[left],&arr[mid]);
  if(arr[left]>arr[right])
      swap(arr[left],&arr[right]);
  if(arr[mid]>arr[right])
      swap(&arr[mid],&arr[right]);
  swap(&arr[mid],&arr[right]);
  return(arr[right]);
}
void partition(int arr[10],int left,int right)
{
    int ne,pivot,i,j;
   ne=right-left+1;
   if(ne>3)
   {
      pivot=median3(arr,left,right);
      i=left,j=right-1;
      while(i<j)
      {
         while(arr[i]<=pivot)
            i++;
         while(arr[j]>pivot)
            j--;
         if(i<j)
            swap(&arr[i],&arr[j]);
         else
            break;
      }
      swap(&arr[i],&arr[right]);
      partition(arr,left,i-1);
      partition(arr,i+1,right);
   }
   else
      insertionsort(arr+left,ne);
}
void quick(int arr[],int n)
{
    partition(arr,0,n-1);
}
/*end of quick sort*/
/*start od merfe sort*/
#include<stdio.h>
int n,i,j,k,left,right,leftst,rightst,leftend,rightend;
void merge(int a[10],int leftst,int rightst,int rightend)
{
    int tmp[10];
    leftend=rightst-1;
    i=k=leftst;
    j=rightst;
    while(i<=leftend && j<=rightend)
    {
        if(a[i]<a[j])
            tmp[k++]=a[i++];
        else
            tmp[k++]=a[j++];
    }
    while(i<=leftend)
       tmp[k++]=a[i++];
    while(j<=rightend)
        tmp[k++]=a[j++];
    for(i=leftst;i<k;i++)
    {
        a[i]=tmp[i];
    }

}
void divide(int a[10],int left,int right)
{
    if(left<right)
    {
       int mid=(left+right)/2;
        divide(a,left,mid);
        divide(a,mid+1,right);
        merge(a,left,mid+1,right);
    }
}
void mergesort(int a[],int n)
{
    divide(a,0,n-1);
}
void main ()
{
int a[10],n,i;
printf("enter the no of elements:");
scanf("%d",&n);
for(i=0;i<n;i++)
{
   scanf("%d",&a[i]);
}
mergesort(a,n);
for(i=0;i<n;i++)
{
   printf("%d\t",a[i]);
}
}

/*end of merger sort*/
void insertion_sorting(int arr[],int no)
{
    for (int i = 1; i < no; ++i) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}
void selection_sorting(int arr[],int no)
{
    for(int i=0; i<no;i++)
    {
        for(int j = i+1;j<no;j++)
        {
            if(arr[j]<arr[i])
            {
                swaping(arr,j,i);
            }
        }
    }
}
void bubble_sorting(int arr[],int no)
{
    for(int i=0;i<no;i++)
    {
        int swap = 0;
        for (int j = 0;j<no-i-1;j++)
        {
            if(arr[j]>arr[j+1])
            {
                swap = 1;
                swaping(arr,j,j+1);
            }
        }
        if(!swap)
        {
            break;
        }
    }
}
void main()
{
    int no;
    int arr[100];
    printf("Enter the size of list :");
    scanf("%d",&no);
    for(int i =0;i<no;i++)
    {
        scanf("%d",&arr[i]);
    }
    //selection_sorting(arr,no);
    //bubble_sorting(arr,no);
    //insertion_sorting(arr,no);
    quick(arr,no);
    printf("\n done: ");
    display(arr,no);
}