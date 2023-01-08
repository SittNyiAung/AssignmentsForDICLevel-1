//
// Created by Saito on 1/7/2023.
//


#include "stdio.h"
#include "math.h"

void bubbleSort(int data[], int size){
    for(int i=0; i<size-1; i++){
        for(int j=0; j<(size-i)-1; j++){
            if(data[j] > data[j+1]){
                int temp= data[j];
                data[j] = data[j+1];
                data[j+1] = temp;
            }
        }
    }

}

int jumpSearch(int arr[], int size, int key){
    int step = sqrt(size);
    int previous = 0;
    int halfOfStep = step/2;

    while( arr[step-1] < key){
        previous = step;
        step = step + sqrt(size);
        if(previous >= size){           //if no key in array
            return -1;
        }
    }
    while(arr[previous+halfOfStep] > key){
        for(int j=previous; j<previous+halfOfStep; j++){
            if(arr[j] == key){
                return j;
            }
        }
        return -1;
    }

    for(int k=previous+halfOfStep; k<step; k++){
        if(arr[k] == key){
            return k;
        }
    }

    return -1;
}


int main(){

    int arr[]={19,22,53,4,57,36,75,89,90,50,10,102,123,54,35,75,84,12,56,78,116,632,773,322,431,353,21,1,5,34};
    int size = sizeof(arr) / sizeof(arr[0]);
    bubbleSort(arr,size);

    int toFind = 52;

    for(int i=0; i<size; i++){
        printf(":%d ",arr[i]);
    }
    printf("\n");


    int indexNumber = jumpSearch(arr, size, toFind);
    if(indexNumber == -1){
        printf("Not found %d.\n",toFind);
    }else{
        printf("Found at index: %d\n",indexNumber);
    }

    return 0;
}