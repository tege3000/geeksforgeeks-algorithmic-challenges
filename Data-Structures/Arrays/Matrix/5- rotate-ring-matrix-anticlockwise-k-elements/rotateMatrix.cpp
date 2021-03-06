/*
 * Topic:
 * Rotate each ring of matrix anticlockwise by K elements
 *
 * Description:
 * Given a matrix of order M*N and a value K, the task is
 * to rotate each ring of the matrix anticlockwise by K
 * elements. If in any ring elements are less than and equal
 * K then don’t rotate it.
 */
#include <iostream>
#include <vector>

// when using other test cases, change these values
#define Row 3
#define Col 4
using namespace std;

// display array
void printArr(int arr[Row][Col]) {
    for(int i = 0; i < Row; i++) {
        for(int j = 0; j < Col; j++) {
            cout << arr[i][j] << " ";
        }
        cout << "\n";
    }
}

void rotateMatrix(int arr[Row][Col], int k) {
    
    for(int a = 0; a < (min(Row, Col))/2; a++) {
        vector<int> inner;
        for(int i = a; i < Col-a; i++) {
            inner.push_back(arr[a][i]);
        }
        
        for(int i = a+1; i < Row-a; i++) {
            inner.push_back(arr[i][Col-(a+1)]);
        }
        
        for(int i = (Col-(a+1))-1; i >= a; i--) {
            inner.push_back(arr[Row-(a+1)][i]);
        }
        
        for(int i = (Row-(a+1))-1; i > a; i--) {
            inner.push_back(arr[i][a]);
        }
        
        
        //rotate left by k
        rotate(inner.begin(), inner.begin()+k, inner.end());
        
        // now populate array with new rotated values
        int start = 0;
        for(int i = a; i < Col-a; i++) {
            arr[a][i] = inner[start];
            start++;
        }
        
        for(int i = a+1; i < Row-a; i++) {
            arr[i][Col-(a+1)] = inner[start];
            start++;
        }
        
        for(int i = (Col-(a+1))-1; i >= a; i--) {
            arr[Row-(a+1)][i] = inner[start];
            start++;
        }
        
        for(int i = (Row-(a+1))-1; i > a; i--) {
            arr[i][a] = inner[start];
            start++;
        }
    }
    
    printArr(arr);
    
}

int main() {
//    // Test Case 1
//    int a[Row][Col] = { {1,  2,  3,  4},
//        {5,  6,  7,  8},
//        {9,  10, 11, 12},
//        {13, 14, 15, 16}  };
    
    // Tese Case 2
    //    int a[Row][Col] = {{1, 2, 3},
    //     {4, 5, 6},
    //     {7, 8, 9}
    //     };
    
    //    // Test Case 3
    int a[Row][Col] = {{1, 2, 3, 4},
        {10, 11, 12, 5},
        {9, 8, 7, 6}};
    int k = 2;
    rotateMatrix(a, k);
    return 0;
}
