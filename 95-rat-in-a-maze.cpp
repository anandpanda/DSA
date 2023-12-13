#include <bits/stdc++.h>
using namespace std;
                
               // D  L  R   U
vector<int> dx = {1, 0, 0, -1};
vector<int> dy = {0, -1, 1, 0};

void solve(vector<vector<int>> &maze, int n, vector<string> &paths, vector<vector<int>> &visited, int x, int y, string tp){
    if(x==n-1 && y==n-1){
        paths.push_back(tp);
        return;
    }
    string dir = "DLRU";
    for(int i = 0; i < 4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(nx>=0 && nx<n && ny>=0 && ny<n && maze[nx][ny] && !visited[nx][ny]){
            visited[nx][ny] = 1;
            solve(maze, n, paths, visited, nx, ny, tp + dir[i]);
            visited[nx][ny] = 0;
        }
    }
}

vector<string> findPath(vector<vector<int>> &maze, int n){
    vector<string> paths;
    vector<vector<int>> visited(n, vector<int>(n,0));
    visited[0][0] = 1;
    solve(maze, n, paths, visited, 0, 0, "");
    return paths;
}

int main()
{
    int n = 4;
    vector<vector<int>> maze = {{1, 0, 0, 0},
                                {1, 1, 0, 1},
                                {1, 1, 0, 0},
                                {0, 1, 1, 1}};

    vector<string> path = findPath(maze, n);
    for (auto p : path)
        cout << p << " ";

    return 0;
}