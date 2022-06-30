// https://practice.geeksforgeeks.org/problems/arranging-the-array1131/1/#
// rearrange array for -ve el to be before +ve el, preserve the relative order of same case els
// modified quick select algo with rotation applied to preserve order

#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>

using namespace std;

void Rearrange(int arr[], int n);

int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++)
        cin>>arr[i];
        long long j=0;
      
        Rearrange( arr, n);
      
        for (int i = 0; i < n; i++) 
            cout << arr[i] << " "; 
        cout << endl;  
    }
    return 0; 
} // } Driver Code Ends


void rotateSect(int arr[], int l, int r) {
    int temp = arr[r];
    for (int i = r; i > l; i--) {
        arr[i] = arr[i-1];
    }
    arr[l] = temp;
}

void swapEl(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

void Rearrange(int arr[], int n)
{
    // Your code goes here
    int pivotInd = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] < 0) {
            swapEl(arr[i], arr[pivotInd]);
            pivotInd++;
            if (i - pivotInd >= 1) {
                rotateSect(arr, pivotInd, i);
            }
        }
    }
}