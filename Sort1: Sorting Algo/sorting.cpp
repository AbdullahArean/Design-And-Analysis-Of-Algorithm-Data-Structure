#include <stdio.h>

bool comparator(int a, int b)
{
    return a>b;
}
void swap(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}
void bubblesort(int arr[], int n) //Function for implementing bubble sort
{

    for (int i = 0; i < n - 1; i++) //Outer Loop
    {
        bool flag = false;                  //to make it more efficient
        for (int j = 0; j < n - 1 - i; j++) //inner loop
        {
            if (arr[j] > arr[j + 1]) //Comparison
            {                        //Swapping
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                //	printf("ran\n");
                flag = true;
            }
        }
        if (!flag)
            return;
    }
}
void insertionsort(int arr[], int n) //Function for implementing insertion sort
{
    for (int i = 1; i < n; i++)
    {
        int temp = arr[i];
        int j = i - 1;
        while (j >= 0 && comparator(arr[j], temp))
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = temp;
    }
}
void selectionsort(int arr[], int n) //Function for implementing selection sort
{
    for (int i = 0; i < n - 1; i++)
    {
        int temp = arr[i], ref = i;
        for (int j = i; j < n; j++)
        {
            if (arr[j] < temp)
            {
                temp = arr[j];
                ref = j;
            }
        }
        int temp2 = arr[i];
        arr[i] = temp;
        arr[ref] = temp2;
    }
}
void merge(int arr[], int start, int mid, int end)
{

    int len1 = mid - start + 1;
    int len2 = end - mid;

    int leftArr[len1], rightArr[len2];

    for (int i = 0; i < len1; i++)
        leftArr[i] = arr[start + i];
    for (int j = 0; j < len2; j++)
        rightArr[j] = arr[mid + 1 + j];

    int i, j, k;
    i = 0;
    j = 0;
    k = start;

    while (i < len1 && j < len2)
    {
        if (leftArr[i] <= rightArr[j])
        {
            arr[k] = leftArr[i];
            i++;
        }
        else
        {
            arr[k] = rightArr[j];
            j++;
        }
        k++;
    }

    while (i < len1)
    {
        arr[k] = leftArr[i];
        i++;
        k++;
    }

    while (j < len2)
    {
        arr[k] = rightArr[j];
        j++;
        k++;
    }
}
void mergeSort(int arr[], int start, int end)
{
    if (start < end)
    {

        int mid = start + (end - start) / 2;
        mergeSort(arr, start, mid);
        mergeSort(arr, mid + 1, end);
        merge(arr, start, mid, end);
    }
}
void countingsort(int a[], int n, int max, int min)
{
    int count[1000006] = {0}, i, j;
    if (min <= 0)
    {
        for (int i = 0; i < n; i++)
        {
            count[a[i] - min]++;
        }
        int k = 0;
        for (i = 0; i <= max - (min); ++i)
        {
            for (j = 1; j <= count[i]; ++j)
            {
                a[k++] = i + (min);
            }
        }
    }
    else
    {

        for (i = 0; i < n; ++i)
            count[a[i]] = count[a[i]] + 1;
        int k = 0;
        for (i = 0; i <= max; ++i)
        {
            for (j = 1; j <= count[i]; ++j)
            {
                a[k++] = i;
            }
        }
    }
}
int getMax(int arr[], int n)
{
    int mx = arr[0];
    for (int i = 1; i < n; i++)
        if (arr[i] > mx)
            mx = arr[i];
    return mx;
}
void countSort(int arr[], int n, int exp)
{
    int output[n]; // output array
    int i, count[10] = { 0 };
 
    // Store count of occurrences in count[]
    for (i = 0; i < n; i++)
        count[(arr[i] / exp) % 10]++;
 
    // Change count[i] so that count[i] now contains actual
    //  position of this digit in output[]
    for (i = 1; i < 10; i++)
        count[i] += count[i - 1];
 
    // Build the output array
    for (i = n - 1; i >= 0; i--) {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }
 
    // Copy the output array to arr[], so that arr[] now
    // contains sorted numbers according to current digit
    for (i = 0; i < n; i++)
        arr[i] = output[i];
}
void radixsort(int arr[], int n)
{
    // Find the maximum number to know number of digits
    int m = getMax(arr, n);
 
    // Do counting sort for every digit. Note that instead
    // of passing digit number, exp is passed. exp is 10^i
    // where i is current digit number
    for (int exp = 1; m / exp > 0; exp *= 10)
        countSort(arr, n, exp);
}
int Partition(int arr[], int low, int high)
{
    int pivot = arr[high]; // pivot
    int i = (low - 1);     // Index of smaller element and indicates the right position of pivot found so far

    for (int j = low; j <= high - 1; j++)
    {
        // If current element is smaller than the pivot
        if (arr[j] < pivot)
        {
            i++; // increment index of smaller element
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}
void QuickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        /* pi is partitioning index, arr[p] is now 
        at right place */
        int pi = Partition(arr, low, high);

        // Separately sort elements before
        // partition and after partition
        QuickSort(arr, low, pi - 1);
        QuickSort(arr, pi + 1, high);
    }
}
void display(int arr[], int size)
{
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}
int main()
{
    int arr[1000006];
    ///*
    int max = -10000001; //for counting sort
    int min = 10000001;  //for counting sort
    //*/
    int t;
    scanf("%d", &t);
    for (int i = 0; i < t; i++)
    {
        scanf("%d", &arr[i]);

        // /*
        if (arr[i] > max) //for counting sort
            max = arr[i]; //for counting sort
        if (arr[i] < min) //for counting sort
            min = arr[i]; //for counting sort
        // */
    }

    //Printing Given Array
    printf("Original array\n");
    display(arr, t);

    radixsort(arr,t);
    //bubblesort(arr, t);             //for bubule sort
    //selectionsort(arr, t);          //for selection sort
    //insertionsort(arr, t);          //for insertion sort
    //countingsort(arr, t, max, min); //for counting sort
    //mergeSort(arr, 0, t - 1);       //for mergesort
    //QuickSort(arr, 0, t - 1);       //for quick Sort

    //Printing Resulted Sorted Array
    printf("Sorted array\n");
    display(arr, t);
    return 0;
}