//
// Created by Scott Derbes on 10/22/18.
//

/*
 * Author: Scott Derbes
 * Date: 9/10/2018
 * Name: Main.cpp
 * Define: Runs a simple insertion sort and merge sort in order to see how long they take.
 */
#include <iostream>
#include <array>
#include <ctime>
#include <climits>
#include <random>

using namespace std;

void insertSort(int array[], int size);
void mergeSort(int array[], int start, int mid, int end);

int main() {
    int arraySize = 100000;
    auto *insertArray = new int[arraySize]; //Create arrays
    auto *mergeArray = new int[arraySize];

    mt19937 rng(time(nullptr));
    uniform_int_distribution<int> distribution(0,10000);
    int dist = distribution(rng);

    for(int i = 0; i <arraySize;i++){//Fill insertArray with random ints
        insertArray[i] = dist;
    }

    for(int j = 0; j <arraySize;j++){//Fill mergeArray with random ints
        mergeArray[j] = dist;
    }

    insertSort(insertArray, arraySize);

    mergeSort(mergeArray, 0, arraySize/2 ,arraySize);

    return 0;
}

void insertSort(int array[],int size){
    clock_t start;
    double duration;

    start = clock();

    for(int i = 2; i <= size; i++){
        int key = array[i];

        int j = i - 1;
        while(j > 0 && array[j] > key){
            array[j + 1] = array[j];
            j -= 1;
        }
        array[j + 1] = key;
    }
    duration = ( clock() - start ) / (double) CLOCKS_PER_SEC;
    cout<<"InsertSort took: "<< duration <<'\n';
}

void mergeSort(int array[], int start, int mid, int end){
    clock_t beginClock;
    double duration;

    beginClock = clock();

    int firsthalf = mid - start + 1;
    int secondHalf = end - mid;
    int subArray[firsthalf], subArrayTwo[secondHalf];

    for(int i = 0; i <= firsthalf; i++){
        subArray[i] = array[i];
    }

    for(int j = mid + 1; j <= secondHalf; j++){
        subArrayTwo[j] = array[j];
    }

    subArray[firsthalf + 1] = INT_MAX;
    subArrayTwo[secondHalf + 1] = INT_MAX;

    int i = 1;
    int j = 1;

    for(int k = start; k <= end; k++){
        if(subArray[i] <= subArrayTwo[j]){
            array[k] = subArray[i];
            i += 1;
        }
        else{
            array[k] = subArrayTwo[j];
            j += 1;
        }
    }

    duration = (clock() - beginClock ) / (double) CLOCKS_PER_SEC;
    cout<<"MergeSort took: "<< duration <<'\n';
}
