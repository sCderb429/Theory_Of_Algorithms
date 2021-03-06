// CPP code for printing shortest path between
// two vertices of unweighted graph
#include <iostream>
#include <list>
#include <vector>
using namespace std;

//Connects to points on Graph with an edge
void add_edge(vector<int>* adj, int src, int dest){

    adj[src].push_back(dest);
    adj[dest].push_back(src);
}

bool isInside(int x, int y){
    if (x >= 1 && x <= 8 && y >= 1 && y <= 8) {
        return true;
    }
    return false;
}

int corToK(int* cor){
    int i = cor[0];
    int j = cor[1];

    int k = 8 * (i - 1) + j - 1;

    return k;
}

int kToCorX(int k){
    int x = (k / 8) + 1;

    return x;
}

int kToCorY(int k){
    int y = (k % 8) + 1;

    return y;
}

//Checks if the spaces are a valid move for the Knight, and adds an edge between the two
bool isValidMove(vector<int>* adj, int srcX, int srcY){
    //Possible Moves for Chess Piece
    int dx[] = {-2, -1, 1, 2, -2, -1, 1, 2};
    int dy[] = {-1, -2, -2, -1, 1, 2, 2, 1};

    //For each vertice
    for (int i = 0; i < 8; i++){//Go through each possible move
        int xVal = srcX + dx[i]; //Find possible x move
        int yVal = srcY + dy[i]; //Find possible y move

        if(isInside(xVal, yVal)){// Check if possible moves are inside the board
            int srcCor[] = {srcX, srcY}; // Turn Src into a cooridinate
            int srcK = corToK(srcCor); // Turn cooridinate into K value
            int destCor[] = {xVal, yVal}; // Turn Possible moves into a Cooridante
            int destK = corToK(destCor); //Turn possible moves into a K value
            add_edge(adj, srcK, destK);
            cout << "New Edge: Src - " << srcK << " Dest - " << destK << "\n ";
        }
    }
}

void buildGraph(vector<int>* adj){
    for (int i = 1; i < 9; ++i) {
        for (int j = 1; j < 9; ++j) {
            isValidMove(adj, i, j);
        }
    }
}

// a modified version of BFS that stores predecessor
// of each vertex in array p
// and its distance from source in array d
bool shortestPath(vector<int>* adj, int src, int dest, int v, int pred[]) {

    int dist[v];
    // a queue to maintain queue of vertices whose
    // adjacency list is to be scanned as per normal
    // DFS algorithm
    list<int> queue;

    // boolean array visited[] which stores the
    // information whether ith vertex is reached
    // at least once in the Breadth first search
    bool visited[v];

    // initially all vertices are unvisited
    // so v[i] for all i is false
    // and as no path is yet constructed
    // dist[i] for all i set to infinity
    for (int i = 0; i < v; i++) {
        visited[i] = false;
        dist[i] = INT_MAX;
        pred[i] = -1;
    }

    // now source is first to be visited and
    // distance from source to itself should be 0
    visited[src] = true;
    dist[src] = 0;
    queue.push_back(src);

    // standard BFS algorithm
    while (!queue.empty()) {
        int u = queue.front();
        queue.pop_front();
        for (int i = 0; i < adj[u].size(); i++) {
            if (visited[adj[u][i]] == false) {
                visited[adj[u][i]] = true;
                dist[adj[u][i]] = dist[u] + 1;
                pred[adj[u][i]] = u;
                queue.push_back(adj[u][i]);

                // We stop BFS when we find
                // destination.
                if (adj[u][i] == dest)
                    return true;
            }
        }
    }
    return false;
}

// utility function to print the shortest distance
// between source vertex and destination vertex
void printPath(vector<int> adj[], int s,
               int dest, int v)
{
    // predecessor[i] array stores predecessor of
    // i and distance array stores distance of i
    // from s
    int pred[v];

    if (shortestPath(adj, s, dest, v, pred) == false) {
        cout << "Given source and destination"
             << " are not connected";
        return;
    }

    // vector path stores the shortest path
    vector<int> path;
    int start = dest;
    path.push_back(start);
    while (pred[start] != -1) {
        path.push_back(pred[start]);
        start = pred[start];
    }
    // Print the path of the shortest route
    cout << "\nPath is:\n";
    for (int i = path.size() - 1; i >= 0; i--) {
        cout << path[i];
        cout << "(" << kToCorX(path[i]) << "," << kToCorY(path[i]) << ") ";
    }
}


// Driver program to test above functions
int main() {
    // Number of Vertices
    int v = 64;
    int predecessor[v];

    // array of vectors is used to store the graph
    // in the form of an adjacency list
    vector<int> adj[v];
    int srcCor[] = {3, 3}, targetCor[] = {3, 4};

    //Build a graph with 64 vertices
    buildGraph(adj);

    int source = corToK(srcCor);
    int target = corToK(targetCor);
    // Creating graph given in the above diagram.
    // add_edge function takes adjacency list, source
    // and destination vertex as argument and forms
    // an edge between them.

    shortestPath(adj, source, target, v, predecessor);

    printPath(adj, source, target, v);
    return 0;
}