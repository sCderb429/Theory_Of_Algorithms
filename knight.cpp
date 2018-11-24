//
// Created by Scott Derbes on 11/22/18.
//
#include <iostream>
#include <queue>
using namespace std;

struct square(){
    int x, y;
    int dis;
    square() {}
    square(int x, int y, int dis) : x(x), y(y), dis(dis) {}
};

//Function to check if piece is on the board
bool isInside(int x, int y, int N){
    if (x >= 1 && x <= N && y >= 1 && y <= N)
        return true;
    return false;
}

int minStepsToTarget(int knightPos[], int targetPos[], int N){
    //Ways the piece can move
    int xAxis[] = {-2,-2,-1,-1, 1, 1, 2, 2};
    int yAxis[] = {-1, 1,-2, 2,-2, 2,-1, 1};

    //Create Queue for Knight moves
    queue<square> queue1;

    //Add starting position to queue
    queue1.push(square(knightPos[0], knightPos[1], 0));

    //Declare new instance of square struct
    typedef struct square square1;
    int x,y;
    bool visit[N+1][N+1];

    //Make all cells unvisited
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= N; j++) {
            visit[i][j] = false;
        }
    }

    //Visit Starting Square
    while(!queue1.empty()){
        //Set Square equal to front of q and remove it
        square1 = queue1.front();
        queue1.pop();

        //Return distance if to target location if at target
        if(square1.x == targetPos[0] && square1.y == targetPos[1]){

        }

    }
}

int main(){
    int N = 30;
    int knightPos[] = {1, 1};
    int targetPos[] = {30, 30};
    cout << minStepsToTarget(int knightPos[], int targetPos[], int N)
    return 0;
}