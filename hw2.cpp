/*
Name: Jie Wu
Assignment: hw2.cpp
Due Date: 10/3/17
*/


#include <iostream>
using namespace std;

void fillArray(int arr[], int numOfElements);
void rotate(int arr[], int d, int n);
int maxProfit(int prices[], int numOFPrices);
void printArray(int arr[], int n);
void pushZerosToEnd(int arr[], int n);
void mergeArrays(int arr1[], int arr2[], int n1, int n2, int arr3[]);

int main()
{
    int arr[100], arr2[100], arr3[100], prices[100];
    int numOfElements, rotateElement, numOfPrices,profit;
    cout << "How many elements? ";
    cin >> numOfElements;
    cout << "Enter " << numOfElements << " elements: ";
    fillArray(arr,numOfElements);

    cout << "----------Rotate function---------" << endl;
    cout << "Enter the number of elements you want to rotate: ";
    cin >> rotateElement;
    rotate(arr, rotateElement, numOfElements);

    cout << "----------maxProfit function---------" << endl;
    cout << "How many prices? ";
    cin >> numOfPrices;
    cout << "Enter the prices:";
    fillArray(prices,numOfPrices);
    profit = maxProfit(prices,numOfPrices);
    cout << profit << endl;

    cout << "----------pushZeroToEnd function---------" << endl;
    cout << "How many elements? ";
    cin >> numOfElements;
    cout << "Enter " << numOfElements << " elements: ";
    fillArray(arr,numOfElements);
    pushZerosToEnd(arr, numOfElements);

    cout << "----------mergeArray function----------" << endl;
    cout << "How many elements in each sorted array? ";
    cin >> numOfElements;
    cout << "Enter " << numOfElements << " elements for the merge function: ";
    fillArray(arr,numOfElements);
    cout << "Enter " << numOfElements << " elements for the merge function: ";
    fillArray(arr2,numOfElements);
    mergeArrays(arr,arr2,numOfElements,numOfElements,arr3);

    return 0;
}
void fillArray(int arr[], int numOfElements)
{
    for(int i = 0; i < numOfElements; i++)
        cin >> arr[i];
}
void printArray(int arr[], int n)
{
    for(int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;

}
void rotate(int arr[], int d, int n)
{
    int temp;
    for(int i = 0; i<d; i++)
    {
        temp = arr[0];
        for(int j = 0; j<n; j++)
        {
            arr[j]=arr[j+1];
        }
        arr[n-1]=temp;
    }
    printArray(arr,n);
}

int maxProfit(int prices[], int numOfPrices)
{
    int size = numOfPrices;
    if (size < 2)
        return 0;

    int buy = prices[0];
    int profit = 0;

    for (int i = 1; i <size; ++i) {
        if (prices[i] >= buy)
            profit = max(profit, prices[i] - buy);
        else
            buy = prices[i];
    }
    return profit;

}

void pushZerosToEnd(int arr[], int n)
{
    for(int i = 0; i < n; i++)
    {
        if(arr[i] == 0)
        {
            for(int j = i; j<n-1; j++)
                arr[j] = arr[j+1];
            arr[n-1]=0;
        }
    }
    printArray(arr,n);
}

void mergeArrays(int arr1[], int arr2[], int n1, int n2, int arr3[])
{
    int a=0,b=0,c=0,n3;
    while(a < n1 && b < n2)
    {
        if(arr1[a] < arr2[b])
            arr3[c++] = arr1[a++];
        else
            arr3[c++] = arr2[b++];
    }
    if(a < n1)
    {
        for(int m = a; m < n1; m++)
            arr3[c++]=arr1[m];
    }
    else
    {
        for(int m = b; m < n2; m++)
            arr3[c++]=arr2[m];
    }
    n3 = n1+n2;
    printArray(arr3,n3);
}
/*
Sample Run

How many elements? 7
Enter 7 elements: 1 2 3 4 5 6 7
----------Rotate function---------
Enter the number of elements you want to rotate: 2
3 4 5 6 7 1 2
----------maxProfit function---------
How many prices? 6
Enter the prices:7 1 5 3 6 4
5
----------pushZeroToEnd function---------
How many elements? 8
Enter 8 elements: 1 2 0 4 3 0 5 0
1 2 4 3 5 0 0 0
----------mergeArray function----------
How many elements in each sorted array? 4
Enter 4 elements for the merge function: 1 3 4 5
Enter 4 elements for the merge function: 2 4 6 8
1 2 3 4 4 5 6 8
*/
