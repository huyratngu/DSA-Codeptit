#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
void solve(int row, int col, int n, vector<vector<int>> &maze, string &path, vector<string> &result, vector<vector<bool>> &visited) {
    if(row == n - 1 && col == n - 1) {
        result.push_back(path);
        return;
    }
    visited[row][col] = true;
    if(row + 1 < n && maze[row + 1][col] == 1 && !visited[row+1][col]) {
        path.push_back('D');
        solve(row + 1, col, n, maze, path, result, visited);
        path.pop_back();
    }
    if(col + 1 < n && maze[row][col + 1] == 1 && !visited[row][col+1]) {
        path.push_back('R');
        solve(row, col + 1, n, maze, path, result, visited);
        path.pop_back();
    }
    if(col - 1 >= 0 && maze[row][col - 1] == 1 && !visited[row][col-1]) {
        path.push_back('L');
        solve(row, col - 1, n, maze, path, result, visited);
        path.pop_back();
    }
    if(row - 1 >= 0 && maze[row - 1][col] == 1 && !visited[row-1][col]) {
        path.push_back('U');
        solve(row - 1, col, n, maze, path, result, visited);
        path.pop_back();
    }
    visited[row][col] = false;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<vector<int>> maze(n, vector<int>(n));
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++) {
                cin >> maze[i][j];
            }
        }
        if(maze[0][0] == 0 || maze[n-1][n-1] == 0) {
            cout << -1 << "\n";
        }
        else {
            vector<string> results;
            string path;
            vector<vector<bool>> visited(n, vector<bool>(n, false));
            solve(0, 0, n, maze, path, results, visited);
            sort(results.begin(), results.end());
            if(!results.empty()) {
                for(const string& paths : results) {
                    cout << paths << " ";
                }
                cout << "\n";
            }
            else {
                cout << -1 << "\n";
            }
        }
    }
    return 0;
}
