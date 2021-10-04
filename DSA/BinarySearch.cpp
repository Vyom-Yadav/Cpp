#include <iostream>
using namespace std;

int binarySearch(int arr[], int n, int key)
{
    int ans = -1;
    int s = 0;
    int e = n;
    int mid = 0;
    while (s <= e)
    {
        mid = (s + e) / 2;

        if (arr[mid] == key)
        {
            ans = mid;
            break;
        }
        else if (arr[mid] > key)
        {
            e = mid - 1;
        }
        else
        {
            s = mid + 1;
        }
    }
    return ans;
}

int main()
{

    int n;
    cin >> n;

    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cout<<binarySearch(arr,n,11)<<endl;

    return 0;
}