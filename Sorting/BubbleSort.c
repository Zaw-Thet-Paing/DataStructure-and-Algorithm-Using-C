#include<stdio.h>

int arr[] = {50,10,60,00,30,90,40,80,20,70};
int arrSize = sizeof(arr) / sizeof(arr[0]);

void BubbleSort();
void show();
void swap(int a, int b);

int main()
{
    printf("Before sorting\n");
    show();

    BubbleSort();

    printf("After sorting\n");
    show();

    return 0;
}

void BubbleSort()
{
    for(int i = arrSize-1; i > 1; i--){
        for(int j = 0; j<i; j++){
            if(arr[j] > arr[j+1]){
                swap(j, j+1);
            }
        }
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