#include <bits/stdc++.h>
using namespace std;

void heapify(int arr[], int n, int i)
{
    int smallest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    int t;

    if (l < n && arr[l] > arr[smallest])
        smallest = l;

    if (r < n && arr[r] > arr[smallest])
        smallest = r;

    if (smallest != i) {
        t = arr[i];
        arr[i] = arr[smallest];
        arr[smallest] = t;

        heapify(arr, n, smallest);
    }
}

void heapSort(int arr[], int n)
{
    int t;
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    for (int i = n - 1; i >= 0; i--)
    {
        t = arr[i];
        arr[i] = arr[0];
        arr[0] = t;

        heapify(arr, i, 0);
    }
}

void printArray(int arr[], int n)
{
    for (int i = 0; i < n; ++i)
        cout << arr[i] << " ";
    cout << "\n";
}

int main()
{
    int a[] = {34, 25, 8, 25, 63, 376, 582, 1}; //Sample Array Input
    int n = sizeof(a) / sizeof(a[0]);
    cout<<"Before sorting array elements are - \n";
    printArray(a, n);
    heapSort(a, n);
    cout<<"\nAfter sorting array elements are - \n";
    printArray(a, n);
    return 0;
}
