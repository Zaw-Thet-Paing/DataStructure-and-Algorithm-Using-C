#include<stdio.h>

int BinarySearch(int arr[], int arrSize, int value);

int main()
{

    int arr[] = {00,10,20,30,40,50,60,70,80,90};
    int arrSize = sizeof(arr)/sizeof(arr[0]);

    int indexFound = BinarySearch(arr, arrSize, 50);

    if(indexFound != -1){
        printf("%d found at index %d\n", arr[indexFound], indexFound);
    }else{
        printf("Value not found!");
    }

    return 0;
}

int BinarySearch(int arr[], int arrSize, int value)
{
    int low = 0;
    int height = arrSize - 1;

    while(low <= height){
        int mid = (low + height) / 2;
        if(arr[mid] == value){
            return mid;
        }else if(arr[mid] > value){
            height = mid -1;
        }else{
            low = mid + 1;
        }
    }

    return -1;
}