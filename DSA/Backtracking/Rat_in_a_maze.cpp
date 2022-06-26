#include<iostream>
using namespace std;
#define N 4
void printMatrix(int mat[N][N]);

bool isSafe(int maze[N][N], int i, int j)
{
    return (i < N && j < N && maze[i][j] == 1);
}

bool solveMazeRec(int maze[N][N], int i, int j, int sol[N][N])
{
    if(i == (N-1) && j == (N-1))
    {
        sol[i][j] = 1;
        return true;
    }

    if(isSafe(maze, i, j) == true)
    {
        sol[i][j] = 1;

        if(solveMazeRec(maze, i+1, j, sol) == true)
            return true;
        
        if (solveMazeRec(maze, i, j+1, sol) == true)
            return true;

        sol[i][j] = 0;
    }

    return false;
}

bool solveMaze(int maze[N][N])
{

    int sol[N][N] = {
            {0,0,0,0},
            {0,0,0,0},
            {0,0,0,0},
            {0,0,0,0}
            };

    if(solveMazeRec(maze, 0,0, sol) == false)
    {
        cout << "\nSolution doesn't exist\n";
        return false;
    }
    else{
        printMatrix(sol);
        return true;
    }
}


void printMatrix(int mat[N][N])
{
    cout << "\n";
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
        {
            cout << mat[i][j] << " ";
        }
        cout << "\n";
    }

    cout << "\n";
}

int main()
{
    int maze[N][N] = {
        {1,0,0,0},
        {1,1,0,1},
        {0,1,0,0},
        {1,1,1,1}
    };

    cout << std::boolalpha;
    cout << solveMaze(maze) << endl;
    

    
    return 0;
}