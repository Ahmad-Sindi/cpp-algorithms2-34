/* Algorithm Challenge & Problem Solving
 * 34 - Return Number Index in Array
 *
 * This program fills an array (max size 100) with random numbers from 1 to 100. Then it reads a number from the user and searches for it inside the array.
 *
 * If the number exists:
 *      → The program returns its index (0-based) and its order (1-based).
 * Otherwise:
 *      → It returns -1 to indicate the number was not found.
 *
 * Concepts Reinforced:
 *   - Random number generation
 *   - Array traversal and linear search
 *   - Input validation
 *   - Returning position/index based on search results
 */

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

// Generates a random number in the given range [From, To]
int Randnumber(int From, int To)
{
    return rand() % (To - From + 1) + From;
}

// Fills the array with random numbers between 1 and 100
void FillArrayWithRandomNumbers(int arr[100], int &arrLength)
{
    cout << "Enter number of elements:\n";
    cin >> arrLength;

    for (int i = 0; i < arrLength; i++)
        arr[i] = Randnumber(1, 100);
}

// Prints array elements on one line
void PrintArray(int arr[100], int arrLength)
{
    for (int i = 0; i < arrLength; i++)
        cout << arr[i] << " ";

    cout << "\n";
}

// Searches for a number and returns index if found, otherwise -1
short FindNumberPositionInArray(int Number, int arr[100], int arrLength)
{
    /*
        This function searches for a number inside the array.
        If found → returns its index.
        If not found → returns -1.
    */
    for (int i = 0; i < arrLength; i++)
    {
        if (arr[i] == Number)
            return i; // Found → return index immediately
    }

    return -1; // Not found
}

// Reads a number from the user
int ReadNumber()
{
    int Number;
    cout << "\nPlease enter a number to search for:\n";
    cin >> Number;
    return Number;
}

int main()
{
    // Seed random generator (call only once)
    srand((unsigned)time(NULL));

    int arr[100], arrLength;

    FillArrayWithRandomNumbers(arr, arrLength);

    cout << "\nArray Elements:\n";
    PrintArray(arr, arrLength);

    int Number = ReadNumber();
    cout << "\nNumber you are looking for: " << Number << endl;

    short NumberPosition = FindNumberPositionInArray(Number, arr, arrLength);

    if (NumberPosition == -1)
        cout << "\nThe number was NOT found in the array.\n";
    else
    {
        cout << "The number was found at index (0-based): " << NumberPosition << endl;
        cout << "The number was found at order (1-based): " << NumberPosition + 1 << endl;
    }

    return 0;
}
