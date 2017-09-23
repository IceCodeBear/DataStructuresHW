/*
Jie Wu
Data Structures
HW#1
Due Date: 9/19/17
*/


#include <iostream>
#include <cmath>
using namespace std;

int findSum(int arr[], int sizeOfArray);
int sumSquare(int n);
int findMax(int arr[], int length);
int fact(int n);
string writeBackwards(string s, int stringSize);
int binarySearch(int arr[], int n, int x);

int main()
{

    int arr[100];
    int numOfElements, squareValue, factNum, sizeOfString, searchNum, n;
    string word;


    // recursive findSum function
    cout << "How many elements? ";
    cin >> numOfElements;
    cout << "Enter " << numOfElements << " elements in ascending order: ";
    for(int i = 0; i < numOfElements; i++)
        cin >> arr[i];
    cout << "The sum of the elements is " << findSum(arr,numOfElements) << endl;


    // recursive squareSum function
    cout << "Enter a number to find the sum of squares from 1 to the number: ";
    cin >> squareValue;
    cout << "The sum is " << sumSquare(squareValue) << endl;


    // find max function
    cout << "The largest element is " << findMax(arr,numOfElements) << endl;

    //factorial function
    cout << "Enter the number to find its factorial: ";
    cin >> factNum;
    cout << fact(factNum) << endl;

    //writeBackwards function
    cout << "Enter a string: " << endl;
    cin >> word;
    sizeOfString = word.size();
    cout << "The backward is " << writeBackwards(word, sizeOfString) << endl;

    // Binary Seacrh function
    cout << "Enter a number to search: ";
    cin >> searchNum;
    int index = binarySearch(arr,numOfElements,searchNum);
    if(index == -1)
        cout << "The number is not found" << endl;
    else
        cout << "The number is at index " << index << endl;

    return 0;
}


//1. Write a recursive C++ function findSum that will compute sum of array elements.
int findSum(int arr[], int sizeOfArray)
{
    if(sizeOfArray == 1)
        return arr[sizeOfArray-1];
    return findSum(arr, sizeOfArray-1) + arr[sizeOfArray-1];
}
/*
Sample Run

How many elements? 5
Enter 5 elements: 1 2 3 4 5
The sum of the elements is 15
*/


//2. Given an integer n > 0, write a recursive C++ function squareSum that returns the sum of squares 1 through n.
int sumSquare(int n)
{
    if(n == 0)
        return 0;
    else
        return sumSquare(n-1) + (n * n);
}
/*
Sample Run

Enter a number to find the sum of squares from 1 to the number: 3
The sum is 14
*/


//3. Write a recursive C++ function findMax that returns the largest element of a given array.
int findMax(int arr[], int length)
{
    int tempMax = 0;
    for(int i = 0; i< length;i++){

        if(arr[i] > tempMax)
            tempMax = arr[i];

    }
    return tempMax;
}
/*
Sample Run

Enter 5 elements: 2 5 7 9 10
The largest element is 10
*/


//4. Write iterative versions of the following recursive functions: fact, writeBackward, binarySearch.

int fact(int n)
{
    int factorial = 1;
    for(int i = 1; i <= n; i++)
        factorial*=i;
    return factorial;
}
/*
Sample Run

Enter the number to find its factorial: 4
24
*/


string writeBackwards(string s, int stringSize)
{
    string temp = "";
    while(stringSize > 0)
    {
        temp += s.substr(stringSize-1, 1);
        stringSize--;
    }
    return temp;
}
/*
Sample Run

Enter a string:
computer
The backward is retupmoc
*/



int binarySearch(int arr[], int n, int x)
{
    int low = 0, high = n - 1;

    while(low <= high)
    {
        int mid = (low+high)/2;
        if(x == arr[mid])
            return mid;
        else if (x < arr[mid])
            high = mid - 1;
        else
            low = mid + 1;
    }
    return -1;

}
/*
***This function will use the same array as the findSum function.***

Sample Run

How many elements? 5
Enter 5 elements in ascending order: 1 2 3 4 5
Enter a number to search: 5
The number is at index 4
*/
