// { Driver Code Starts
//Initial template for C++

#include <vector>
#include <iostream>

using namespace std;
void rotate (vector<vector<int> >& matrix);


// } Driver Code Ends
//User function template for C++

/* matrix : given input matrix, you are require
 to change it in place without using extra space */
void rotate(vector<vector<int> >& matrix)
{
    int n = matrix.size();
    int rl, cl;
    if (n % 2 == 0) {
        rl = n / 2 - 1;
        cl = n / 2 - 1;
    }
    else {
        rl = n / 2 - 1;;
        cl = n / 2;
    }
    for (int i = 0; i <= rl; i++) {
        for (int j = 0; j <= cl; j++) {
            int r = i, c = j;
            int carry = matrix[r][c];
            for (int k = 0; k < 4; k++) {
                // while((n-1-c) > n/2 || r > n/2) {
                int temp = matrix[n-1-c][r];
                matrix[n-1-c][r] = carry;
                carry = temp;
                temp = r;
                r = n-1-c;
                c = temp;
            }
        }
    }
}


// { Driver Code Starts.

int main()
{
    int n;
    cin >> n;
    vector<vector<int> > matrix;
    for (int i = 0; i < n; i++) {
        matrix.push_back(vector<int>());
        for (int j = 0; j < n; j++) {
            int temp;
            cin >> temp;
            matrix[i].push_back(temp);
        }
    }
    rotate(matrix);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            cout << matrix[i][j] << ' ';
        cout << '\n';
    }
    return 0;
}

// } Driver Code Ends