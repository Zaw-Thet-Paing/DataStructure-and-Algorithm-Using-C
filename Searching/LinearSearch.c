#include<stdio.h>

int LinearSearch(int arr[], int arrSize, int value);

int main()
{
    int arr[] = {00,10,20,30,40,50,60,70,80,90};
    int arrSize = sizeof(arr)/sizeof(arr[0]);

    int indexFound = LinearSearch(arr, arrSize, 50);

    if(indexFound != -1){
        printf("%d found at index %d\n", arr[indexFound], indexFound);
    }else{
        printf("Value not found!");
    }

    return 0;
}

int LinearSearch(int arr[], int arrSize, int value)
{
    for(int i = 0; i<arrSize; i++){
        if(arr[i] == value){
            return i;
        }
    }
    return -1;
}