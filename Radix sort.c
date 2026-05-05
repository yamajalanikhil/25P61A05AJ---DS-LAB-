#include<stdio.h>

#include <stdlib.h>

//function to find maximum element

int getMax(int arr[],int n){

int max = arr[0];

for (int i=1; i<n; i++)

{

if(arr[i]>max)

max = arr[i];

}

return max;}

//Counting Sort based on digit

void CountingSort (int arr[], int n, int place) {
int *output = (int *)malloc(n*sizeof(int));

int count[10]={0};

//count occurrences

for (int i = 0; i<n;i++)

{

 int digit=(arr[i]/place)%10;

 count[digit]++;

}

// cummulative Count

for (int i=1;i<10;i++)

{

count[i]+= count[i-1];

}

//Build output array (stable)
for (int i=n-1; i>=0 ;i--) {

int digit = (arr[i]/place)%10;

output[count[digit]-1] = arr[i];

count[digit]--;

}

//copy back to original array

for (int i=0; i<n;i++){

arr[i]=output[i];

}

free(output); // free memory

}

//Radix Sort

void radixSort(int arr[] , int n) {

int Max= getMax(arr,n);
for (int place =1; Max/place >0; place*=10){

CountingSort(arr,n,place);

}

}

//print array

void printArray(int arr[], int n){

for (int i=0; i<n;i++) {

printf("%d ", arr[i]);

}

printf("\n");

}

// Main function
int main(){

int n;

printf("Enter number of elements:");

scanf("%d",&n);

// Dynamic allocation (no restriction)

int *arr= (int *)malloc(n* sizeof(int));

if(arr == NULL){

printf("Memory allocation failed\n");

return 1;

}

printf(" Enter %d elements:\n", n);

for (int i=0; i<n;i++) {

scanf("%d", &arr[i]);

}

printf("original array : \n");
printArray(arr, n);

radixSort(arr, n);

printf("Sorted array:\n");

printArray(arr, n);

free(arr);

return 0;

}
