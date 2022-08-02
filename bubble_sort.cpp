#include <iostream>
using namespace std;

// prints array 
void print_array(int arr[], int size){
    cout << "{ ";
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << " }" << endl;
}

// bubble sort algorithm
void bubble_sort(int arr[], int n){
    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < n - i - 1; j++)
            if (arr[j] > arr[j + 1]){
                swap(arr[j], arr[j + 1]);

                cout << "update: ";
                print_array(arr, n);
            }
}
  
// Driver code
int main(){
    int arr[] = {5, 1, 4, 2, 8};
    int size = sizeof(arr) / sizeof(arr[0]);

    bubble_sort(arr, size);

    cout << "Sorted array: " << endl;
    print_array(arr, size);

    return 0;
}

