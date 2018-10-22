//
// Created by Scott Derbes on 10/22/18.
//
#include <iostream>
#include <array>
#include <ctime>
#include <climits>
#include <random>

using namespace std;

int maxSubArray(int array[], int low, int high);
int maxCrossingSubarray(int array[], int low, int mid, int high);
int nonrecursive(int array[], int size);

int main(){
    int arraySize = 100000;
    auto *insertArray = new int[arraySize]; //Create arrays
    auto *insertArray2 = new int[arraySize]; //Create arrays


    random_device rd; // obtain a random number from hardware
    mt19937 eng(rd()); // seed the generator
    uniform_int_distribution<> distr(-100, 100);

    for(int i = 0; i < arraySize; i++){//Fill insertArray with random ints
        insertArray[i] = distr(eng);
        //cout << insertArray[i] << " ";
    }

    for(int i = 0; i < arraySize; i++){//Fill insertArray with random ints
        insertArray2[i] = distr(eng);
        //cout << insertArray2[i] << " ";
    }

    int maxSum1 = maxSubArray(insertArray, 0, 10000);
    cout << "\n\nThe maxSum is " << maxSum1 << "\n";

    //int maxSum2 = nonrecursive(insertArray, arraySize);
    //cout << "\n\nThe maxSum is " << maxSum2 << "\n";
}

int maxSubArray(int array[], int low, int high){

    if(low == high) {
        return (low, high, array[low]);
    }
    else{
        int mid = (low + high) / 2;

        int leftMaxSum = maxSubArray(array, low, mid);
        int rightMaxSum = maxSubArray(array, mid, high);
        int crossingMaxSum = maxCrossingSubarray(array, low, mid, high);

        if(leftMaxSum >= rightMaxSum && leftMaxSum >= crossingMaxSum){
            return leftMaxSum;
        }
        else if(rightMaxSum >= leftMaxSum && rightMaxSum >= crossingMaxSum){
            return rightMaxSum;
        }
        else{
            return crossingMaxSum;
        }
    }
}

int maxCrossingSubarray(int *array, int low, int mid, int high) {
    int leftSum = INT_MIN;
    int rightSum = INT_MIN;
    int maxRight, maxLeft, maxSum;
    int sum = 0;

    for(int j = mid; j > low; j--){
        sum = sum + array[j];
        if(sum > leftSum){
            leftSum = sum;
            maxLeft = j;
        }
    }

    for(int k = mid + 1; k < high; k++){
        sum = sum + array[k];
        if(sum > rightSum){
            rightSum = sum;
            maxRight = k;
        }
    }

    maxSum = leftSum + rightSum;


    return (maxLeft, maxRight, maxSum);
}

int nonrecursive(int array[], int size){
    int current, max;
    current = max = 0;

    for(int i = 0; i <= size; i++){
        current = current + array[i];
        if(max < current){
            max = current;
        }

        if(current < 0){
            current = 0;
        }
    }

    return current;
}

