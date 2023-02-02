#include <string>
#include <vector>
#include <cstdio>

using namespace std;

class Solution {
public:
    vector< vector<int> > generateMatrix(int n) {
        vector< vector<int> > matrix(n, vector<int>(n, 0));
        if (n == 1) {
            matrix[0][0] = 1;
            return matrix;
        }
        int loop = n/2;
        int start = 0;
        int end = n;
        int row = 0;
        int column = 0;
        int count = 1;
        while(start<end) {
            row = start;
            for (column=start; column<end; column++) {
                matrix[row][column] = count++;
            }
            column = end-1;
            for (row=start+1; row<end; row++) {
                matrix[row][column] = count++;
            }
            row = end-1;
            for (column=end-2; column>=start; column--) {
                matrix[row][column] = count++;
            }
            column = start;
            for (row=end-2; row>start; row--) {
                matrix[row][column] = count++;
            }
            start++;
            end--;
        }
        if ((n&0x1) != 0) {
            matrix[n/2][n/2]=n*n;
        }
        return matrix;
    }
};

int main() {
    Solution solution;

    int n=3;
    vector< vector<int> > matrix = solution.generateMatrix(n);
    printf("[");
    for (int row=0; row<n; row++) {
        printf("[");
        for (int column=0; column<n; column++) {
            printf("%d", matrix[row][column]);
        }
        printf("] ");
    }
    printf("]");
    return 0;
}