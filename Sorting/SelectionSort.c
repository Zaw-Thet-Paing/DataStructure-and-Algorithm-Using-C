#include<stdio.h>

int arr[] = {50,10,60,00,30,90,40,80,20,70};
int arrSize = sizeof(arr) / sizeof(arr[0]);

void SelectionSort();
void show();
void swap(int a, int b);

int main()
{
    printf("Before sorting\n");
    show();

    SelectionSort();

    printf("After sorting\n");
    show();

    return 0;   
}

void SelectionSort()
{
    for(int i = 0; i<arrSize-1; i++){
        int min = i;
        for(int j = i; j< arrSize; j++){
            if(arr[min] > arr[j]){
                min = j;
            }
        }
        swap(min, i);
    }
}

void show()
{
    for(int i = 0; i<arrSize; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void swap(int a, int b)
{
    int temp = arr[a];
    arr[a] = arr[b];
    arr[b] = temp;
}