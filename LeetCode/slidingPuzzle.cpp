#include<bits/stdc++.h>
using namespace std;

string swapZero(string board, int swapWith, int zeroPosition)
{
    string newBoard = "";
    for(int i=0; i<6; i++)
    {
        if(i == zeroPosition)
        {
            newBoard += board[swapWith];
        }
        else if(i == swapWith)
        {
            newBoard += board[zeroPosition];
        }
        else{
            newBoard += board[i];
        }
    }

    return newBoard;
}

int slidingPuzzle(vector<vector<int>>& board) 
{
    vector<vector<int>> adj = {{1, 3}, {0, 2, 4}, {1, 5}, {0, 4}, {1, 3, 5}, {2, 4}};
    string target = "123450";
    string boardStr = "";
    int positionZero = 0;
    int steps = 0;
    for(int i = 0; i<2; i++){
        for(int j=0; j<3; j++)
        {
            if(board[i][j] == 0) positionZero = boardStr.size();
            boardStr += to_string(board[i][j]);
        }
    }
    queue<pair<pair<string, int>, int>> q;
    unordered_set<string> visited;
    q.push({{boardStr, positionZero}, 0});

    while (!q.empty())
    {
        int currentZeroPosition = q.front().first.second;
        string currentBoard = q.front().first.first;
        int steps = q.front().second;
        q.pop();

        if(currentBoard == target) return steps;

        if(visited.find(currentBoard) != visited.end()) continue;
        visited.insert(currentBoard);

        for(auto x: adj[currentZeroPosition])
        {
            string tempBoard = swapZero(currentBoard, x, currentZeroPosition);
            q.push({{tempBoard, x}, steps+1});
        }
    }
    

    return -1;
}

int main()
{
    vector<vector<int>> board = {{4,1,2},{5,0,3}};
    cout<<slidingPuzzle(board)<<endl;
}