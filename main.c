#include<io.h>
#include<stdlib.h>

void quicksort(int arr[20],int,int);
void bubblesort(int arr[20],int);
void display(int arr[20],int);
void insertion_sort(int arr[20],int);
void selection_sort(int arr[20],int);


int main()
{int count;int arr[20];int ch;

    while(1){
    printf("\n==================================\n");
    printf("\n1>array creation\n2>quick sort\n3>bubble sort\n4>display\n5>insertion sort\n6>selection sort");
    printf("\n==================================\n");
   printf("enter your choice:");
   scanf("%d",&ch);
   switch(ch){
   case 1:
             printf("enter the number of element to be put:");
             scanf("%d",&count);
             printf("\nenter the number in array:");
             for(int i=0;i<count;i++)
             scanf("%d",&arr[i]);
             break;

   case 2:
             quicksort(arr,0,count-1);
             printf("\nsorted by quick sort");
             break;
   case 3:
              bubblesort(arr,count);
              printf("\nsorted by bubble sort");
              break;
   case 4:
              display(arr,count);
              break;
   case 5:
              insertion_sort(arr,count);
              printf("\nSorted by insertion sort");
              break;
    case 6:
              selection_sort(arr,count);
              printf("\nsortedd by selection sort");
   }
   }
}
/*
pi
0   1   2  3   4
9   5   8  2   1
i              j
*/

void quicksort(int arr[20],int first,int last)
{
    int i,j,pivot,temp;
    if(first<last)         //condition till last
    {
        i=first;j=last;pivot=first;
        while(i<j)                           //loop till j crossess i
        {
            while(arr[i]<=arr[pivot] && i<last)
                i++;                            //i++ till number>pivot
            while(arr[j]>arr[pivot])
                j--;                             //j-- till number<pivot
            if(i<j)
            {                             //if one number in i is greater that pivot shift it to right part
            temp=arr[i];
            arr[i]=arr[j];
            arr[j]=temp;
            }                               //first partition over

        }
        temp=arr[j];                     //when j crossess i i.e j>pivot so exchange it j with pivot
        arr[j]=arr[pivot];
        arr[pivot]=temp;

        quicksort(arr,first,j-1);       //two array with left and right passes recursively except pivot number
        quicksort(arr,j+1,last);        //         4    2  | 3   |   5      7
    }                                   //       first j-1 |  pi | j+1     last
                                         //        1 array |     | 2 array
}
/*
0   1   2  3   4
9   5   8  2   1
ij
*/
void bubblesort(int arr[20],int n)
{ int i,j,temp,swapped;
    for(i=0;i<n-1;i++)
    {
       swapped=0;
        for(j=0;j<n-1-i;j++)
        {
            if(arr[j]>arr[j+1])
            {
                temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
           swapped=1;
        }
        if(swapped==0)                //if no swapping done then swapped ==0
            break;                    //these means array is sorted so break the loop
    }

}
void display(int arr[20],int n)
{
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
}

//insertion sort
/*
i    j
0    1   2  3   4             //the sorted array created at every loop execution
9    5   8  2   1             //first arr[j-1]> arr[j] checked if true swap
j-1  j                        //else i++  {due to j-- the condition is checked the loop is reverted back }
*/

void insertion_sort(int arr[20],int n)
{int i,j,temp;
    for(i=0;i<n-1;i++)
    {
        for(j=i+1;j>0 && arr[j-1]>arr[j];j--)
        {
            temp=arr[j-1];
            arr[j-1]=arr[j];
            arr[j]=temp;
        }
    }
}
/*
0   1   2  3   4
9   5   8  2   1
i   j
*/

void selection_sort(int arr[20],int n)
{
    int i,j,temp;
    for(i=0;i<n-1;i++)
    {
        for(j=i+1;j<n;j++)
        {
            if(arr[i]>arr[j])
        {
                temp=arr[i];
                arr[i]=arr[j];
                arr[j]=temp;
        }
       }
    }
}
