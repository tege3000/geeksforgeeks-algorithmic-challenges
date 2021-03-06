// Topic: Program for array rotation
//
// Description: Write a function rotate(ar[], d, n) that rotates
// arr[] of size n by d elements.
//
// MY SOLUTION

#include <iostream>
using namespace std;

void printArray(int arr[], int n) {
    for(int i = 0; i < n; i ++) {
        cout << arr[i] << " ";
    }
}


// second attempt. Works in O(n) time
void rotate(int arr[], int k, int n) {
    int newArr[n];
    for(int i = 0; i < n; i++) {
        newArr[i] = arr[(k+i)%n];
    }
    
    for(int i = 0; i < n; i++) {
        arr[i] = newArr[i];
    }
    
}



// // Initial attempt.
// // Time complexity is O(n^2)
//
// using namespace std;
// void rotate(int arr[], int d, int n) {
//     int el;
//     for(int i = 0; i < d; i++) {
//         el = arr[0];

//         for(int i = 0; i < n-1; i++) {
//             arr[i] = arr[i+1];
//         }

//         arr[n-1] = el;
//     }
//     printArray(arr, n);
// }

int main()
{
    int d, n;
    int arr [] =  {1,2,3,4, 5, 6, 7};
    n = sizeof(arr)/sizeof(arr[0]);
    d = 2; // d measures how far to rotate the array
    rotate(arr, d, n);
    printArray(arr, n);
    
    return 0;
}

