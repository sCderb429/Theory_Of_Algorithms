//
// Created by Scott Derbes on 11/22/18.
//
#include <iostream>
#include <queue>
using namespace std;

struct Square{
    int x, y;
    int dis;
    square() {}
    square(int x, int y, int dis) : x(x), y(y), dis(dis) {}
};

int** constructGraph(int N){
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {

        }
    }
    return array;
}

//Function to check if piece is on the board
bool isInside(int x, int y, int N){
    if (x >= 1 && x <= N && y >= 1 && y <= N)
        return true;
    return false;
}

void minStepsToTarget(int N, int knight[], int target[]){

}

int main(){
    int N = 30;
    int knightPos[] = {1, 1};
    int targetPos[] = {30, 30};
    minStepsToTarget(N, knightPos, targetPos);
    return 0;
}