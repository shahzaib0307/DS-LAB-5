#include <iostream>
using namespace std;

bool isSafe(int arr[4][4], int x, int y, int n) {
    if (x < n && y < n && arr[x][y] == 1) {
        return true;
    }
    return false;
}

bool ratinMaze(int arr[4][4], int x, int y, int n, int** solArr) {

    if (!isSafe(arr, x, y, n))return false;

    if (x == 2 && y == 0) {
        solArr[x][y] = 1;
        return true;
    }

    if (1) {
        solArr[x][y] = 1;

        if (ratinMaze(arr, x + 1, y, n, solArr)) {
            return true;
        }

        if (ratinMaze(arr, x, y + 1, n, solArr)) {
            return true;
        }
 if  (ratinMaze(arr, x - 1, y, n, solArr)) {
            return true;
        }

        if  (  ratinMaze(arr, x, y - 1, n, solArr)) {
            return true;
        }
        
        solArr[x][y] = 0;
        return false;
    }

    return false;
}

int main() {
    int n = 4;

    int maze[4][4] = {
        {1,1,1,1},
        {0, 0, 0, 1},
        {1,1,0,1},
        {1, 1, 1, 1}
    };

    int** solution = new int*[n];
    for (int i = 0; i < n; i++) {
        solution[i] = new int[n];
        for (int j = 0; j < n; j++) {
            solution[i][j] = 0;
        }
    }

    if (ratinMaze(maze, 0, 0, n, solution)) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cout << solution[i][j] << " ";
            }
            cout << "\n";
        }
    } else {
        cout << "No path found.\n";
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cout << solution[i][j] << " ";
            }
            cout << "\n";
        }
    }

    for (int i = 0; i < n; i++) {
        delete[] solution[i];
    }
    delete[] solution;

    return 0;
}
