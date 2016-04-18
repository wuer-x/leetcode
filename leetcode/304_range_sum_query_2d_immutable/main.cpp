#include <iostream>
#include <vector>

using namespace std;

class NumMatrix {
private:
    vector<vector<int> > this_sum;
public:
    NumMatrix(vector<vector<int> > &matrix) {
        if(matrix.size()==0 || matrix[0].size() == 0 ) return;

        
        int height = matrix.size();
        int length = matrix[0].size();

        vector<int> curr_row(length,0);
        vector<vector<int> > sum(height, curr_row);
        for(int i = 0 ; i < height ;i++){
            for(int j = 0 ; j < length ; j++){
                sum[i][j] = (j>=1?sum[i][j-1]:0) + (i>=1?sum[i-1][j]:0) - (i>0&&j>0?sum[i-1][j-1]:0) +matrix[i][j];
            }
        }

        this_sum = sum;
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        if(this_sum.size()==0 || this_sum.size()==0) return 0;
        return (this_sum[row2][col2]) + (row1>0&&col1>0?this_sum[row1-1][col1-1]:0) - (row1>0?this_sum[row1-1][col2]:0) -(col1>0?this_sum[row2][col1-1]:0);
    }

};



int main(){
    vector<vector<int> > matrix = {
        {3, 0, 1, 4, 2},
        {5, 6, 3, 2, 1},
        {1, 2, 0, 1, 5},
        {4, 1, 0, 1, 7},
        {1, 0, 3, 0, 5}
    };

    NumMatrix * m = new NumMatrix(matrix);
    cout<<m->sumRegion(2,1,4,3)<<endl;
    cout<<m->sumRegion(1,1,2,2)<<endl;
    cout<<m->sumRegion(1,2,2,4)<<endl;
    return 0;
}