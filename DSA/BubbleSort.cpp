#include<iostream>

using namespace std;

void bubbleSort(int arr[], int n) {
    for(int i=1; i<n-1;i++) {
        for(int j=0; j<n-i; j++) {
            if(arr[j] > arr[j+1]) {
                arr[j] = arr[j] ^ arr[j+1]; // swapping arr[j] And arr[j+1]
                arr[j+1] = arr[j] ^ arr[j+1];
                arr[j] = arr[j] ^ arr[j+1];
            }
        }
    }
}

int main() {
    int n;
    cin>>n;
    int arr[n];

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    bubbleSort(arr, n);

    for (int i = 0; i < n; i++)
    {
        cout << arr[i];
    }

}