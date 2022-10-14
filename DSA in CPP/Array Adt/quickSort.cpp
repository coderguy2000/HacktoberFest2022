#include <bits/stdc++.h>

using namespace std;

void swap(int arr[], int pos1, int pos2)
{
    int temp;
    temp = arr[pos1];
    arr[pos1] = arr[pos2];
    arr[pos2] = temp;
}

int partition(int arr[], int low, int high, int pivot)
{
    int i = low;
    int j = low;
    while (i <= high)
    {
        if (arr[i] > pivot)
        {
            i++;
        }
        else
        {
            swap(arr, i, j);
            i++;
            j++;
        }
    }
    return j - 1;
}

void quickSor(int arr[], int low, int high)
{
    if (low < high)
    {
        int pivot = arr[high];
        int pos = partition(arr, low, high, pivot);

        quickSor(arr, low, pos - 1);
        quickSor(arr, pos + 1, high);
    }
}
void quickSort(int input[], int size)
{

    quickSor(input, 0, size - 1);
}
int main()
{
    int n;
    cin >> n;

    int *input = new int[n];

    for (int i = 0; i < n; i++)
    {
        cin >> input[i];
    }

    quickSort(input, n);
    for (int i = 0; i < n; i++)
    {
        cout << input[i] << " ";
    }

    delete[] input;
}