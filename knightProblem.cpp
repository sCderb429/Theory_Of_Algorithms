// C++ program to find minimum steps to reach to
// specific cell in minimum moves by Knight
#include <queue>
#include <iostream>
using namespace std;

// structure for storing a cell's data
struct cell
{
    int x, y;
    int dis;
    cell() {}
    cell(int x, int y, int dis) : x(x), y(y), dis(dis) {}
};

// Utility method returns true if (x, y) lies
// inside Board
bool isInside(int x, int y, int N)
{
    if (x >= 1 && x <= N && y >= 1 && y <= N)
        return true;
    return false;
}

// Method returns minimum step to reach target position
int minStepToReachTarget(int knightPos[], int targetPos[],
                         int N)
{
    // x and y direction, where a knight can move
    int dx[] = {-2, -1, 1, 2, -2, -1, 1, 2};
    int dy[] = {-1, -2, -2, -1, 1, 2, 2, 1};

    // queue for storing states of knight in board
    queue<cell> q;

    // push starting position of knight with 0 distance
    q.push(cell(knightPos[0], knightPos[1], 0));

    cell t;
    int x, y;
    bool visit[N + 1][N + 1];

    // make all cell unvisited
    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= N; j++)
            visit[i][j] = false;

    // visit starting state
    visit[knightPos[0]][knightPos[1]] = true;

    // loop untill we have one element in queue
    while (!q.empty())
    {
        t = q.front();
        cout << "(" << t.x << ", " << t.y << " Dis: " <<  t.dis<<") ->";
        q.pop();

        // if current cell is equal to target cell,
        // return its distance
        if (t.x == targetPos[0] && t.y == targetPos[1])
            return t.dis;

        // loop for all reachable states
        for (int i = 0; i < 8; i++)
        {
            x = t.x + dx[i];
            y = t.y + dy[i];

            // If reachable state is not yet visited and
            // inside board, push that state into queue
            if (isInside(x, y, N) && !visit[x][y]) {
                visit[x][y] = true;
                q.push(cell(x, y, t.dis + 1));
                //cout << "(" << x << ", " << y << ") ->";
            }
        }
    }
}

/*int minStepsToTarget(int knightPos[], int targetPos[], int N){
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
            visit[x][y] = true;
            queue1.push(cell(x, y, square1.dis + 1));
        }

    }
}
*/

// Driver code to test above methods
int main()
{
    int N = 8;
    int knightPos[] = {4, 5};
    int targetPos[] = {1, 1};
    cout << minStepToReachTarget(knightPos, targetPos, N);
    return 0;
}