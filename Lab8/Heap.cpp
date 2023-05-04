#include <iostream>
using namespace std;

// function to heapify the tree
void heapify(int arr[], int n, int root)
{
   int largest = root;
   int left = 2*root + 1;
   int right = 2*root + 2;
   // build heapify
   if(left < n && arr[largest] < arr[left]){
        largest = left;
   }
   if (right < n && arr[largest] < arr[right]){
        largest = right;
   }
   if (largest != root){
        swap(arr[root], arr[largest]);
        heapify(arr,n,largest);
   }
}

/* print contents of array */
void displayArray(int arr[], int n)
{
   for (int i=0; i<n; ++i)
   cout << arr[i] << " ";
   cout << "\n";
}

// implementing heap sort
void heapSort(int arr[], int n)
{
   //build heap
    for (int i = n / 2 - 1; i >= 0; i--){
        heapify(arr, n, i);
    }
    cout << "Example heap array.\n";
    displayArray(arr, n);

   // extracting elements from heap one by one
    for (int j = n - 1; j >= 0; j--){
        swap(arr[0], arr[j]);
        heapify(arr, j, 0);
    }
}

// main program
int main()
{
    int n;
    cout << "Enter the size of the array." << endl;
    cin >> n;
    int heap_arr[n];
    int element;
    cout << "Enter elements into the array." << endl;
    for(int i = 0 ; i < n ; i++){
        cin >> element;
        heap_arr[i] = element;
    }

   /*int heap_arr[] = {0,1,2,3,4,5,6,7,8,9,10};
   int n = sizeof(heap_arr)/sizeof(heap_arr[0]);*/

   cout<<"Input array"<<endl;
   displayArray(heap_arr,n);

   heapSort(heap_arr, n);
   cout << "Sorted array"<<endl;
   displayArray(heap_arr, n);
}
