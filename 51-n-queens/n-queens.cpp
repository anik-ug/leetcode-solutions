class Solution {
public:
    bool isSafe(int n,vector<string>& nQueen,int row,int col){
        for(int i=0;i<n;i++){
            if(nQueen[i][col]=='Q'){
                return false;
            }
        }
        for(int i=row-1 , j=col-1;i>=0 && j>=0;i--,j--){
            if(nQueen[i][j]=='Q'){
                return false;
            }
        }
        for(int i=row-1,j=col+1;i>=0 && j>=0;i--,j++){
            if(nQueen[i][j]=='Q'){
                return false;
            }
        }

        //At every recursive call, you are trying to place exactly one queen in the current row. why we dont check for fixed row and varing col in solvve function

        return true;
    }
    void solve(int n,vector<vector<string>>& output,vector<string>& nQueen,int row){
        if(row==n){
            output.push_back(nQueen);
            return;
        }

        for(int col=0; col<n; col++){
            if(isSafe(n,nQueen,row,col)){
                nQueen[row][col] = 'Q';
                solve(n,output,nQueen,row+1);
                nQueen[row][col] = '.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>>output;
        vector<string>nQueen(n,string(n,'.'));
        solve(n,output,nQueen,0);
        return output;
    }
};