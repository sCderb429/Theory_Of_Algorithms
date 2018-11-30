// CPP code for printing shortest path between
// two vertices of unweighted graph
#include <bits/stdc++.h>
using namespace std;

// utility function to form edge between two vertices
// source and dest
void add_edge(vector<int> adj[], int src, int dest){
    adj[src].push_back(dest);
    adj[dest].push_back(src);
}

bool isInside(int x, int y){
     if (x >= 1 && x <= 8 && y >= 1 && y <= 8) {
         return true;
     }
     return false;
}

int corToK(int cor[]){
    int i = cor[0];
    int j = cor[1];

    int k = 8 * (i - 1) + j -1;

    return k;
}

int kToCor(int k){
    int x = (k / 3) + 1;
    int y = (k % 3) + 1;

    return x,y;
}


bool isValidMove(vector<int> adj[], int srcX, int srcY){
    int dx[] = {-2, -1, 1, 2, -2, -1, 1, 2};
    int dy[] = {-1, -2, -2, -1, 1, 2, 2, 1};

    //For each vertice
        for (int i = 0; i < 8; i++){
            int xVal = srcX + dx[i];
            int yVal = srcY + dy[i];
            if(isInside(xVal, yVal)){
                int srcCor[] = {xVal, yVal};
                int srcK = corToK(srcCor);
                int destCor[] = {xVal, yVal};
                int destK = corToK(destCor);
                add_edge(adj, srcK, destK);
                cout << "New Edge: Src - " << srcK << " Dest - " << destK << "\n ";
            }
        }
    }

void buildGraph(vector<int> adj[]){
    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            isValidMove(adj, i, j);
        }
    }
}

// a modified version of BFS that stores predecessor
// of each vertex in array p
// and its distance from source in array d
bool BFS(vector<int> adj[], int src, int dest, int v,
         int pred[], int dist[])
{
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
void printShortestDistance(vector<int> adj[], int s,
                           int dest, int v)
{
    // predecessor[i] array stores predecessor of
    // i and distance array stores distance of i
    // from s
    int pred[v], dist[v];

    if (BFS(adj, s, dest, v, pred, dist) == false)
    {
        cout << "Given source and destination"
             << " are not connected";
        return;
    }

    // vector path stores the shortest path
    vector<int> path;
    int crawl = dest;
    path.push_back(crawl);
    while (pred[crawl] != -1) {
        path.push_back(pred[crawl]);
        crawl = pred[crawl];
    }

    // distance from source is in distance array
    cout << "Shortest path length is : "
         << dist[dest];

    // printing path from source to destination
    cout << "\nPath is::\n";
    for (int i = path.size() - 1; i >= 0; i--)
        cout << path[i] << " ";
}

// Driver program to test above functions
int main()
{
    // Number of Vertices
    int v = 64;

    // array of vectors is used to store the graph
    // in the form of an adjacency list
    vector<int> adj[v];
    int srcCor[] = {2, 1}, targetCor[] = {2,2};

    buildGraph(adj);

    int source = corToK(srcCor);
    int target = corToK(targetCor);
    // Creating graph given in the above diagram.
    // add_edge function takes adjacency list, source
    // and destination vertex as argument and forms
    // an edge between them.

    printShortestDistance(adj, source, target, v);
    return 0;
}