#include <stdio.h>
#include <stdbool.h>
// Insertion of a value (even if it exists) in a sorted array.
// steps:
// step 1 : fill a an array in sorted way
// step 2 : find a way to to insert value in the right index while findout the sort way
//===============================
// steps:
// step 1 : fill an array in sorted way and try to insert in that way the value
#define MAX 100 // Declare MAX as a macro constant
void sizearray(int *SizeOfArray)
{

    do
    {
        printf("Give a size for the array\n");
        scanf("%d", &SizeOfArray);
    } while (SizeOfArray <= 0 || SizeOfArray > MAX); //! size>=1
}
void printarray(int array[], int SizeOfArray)
{
    printf("\n---------------------------------Printing the array:----------------------------------------------\n");
    for (int index = 0; index < SizeOfArray; index++)
        printf("[%d]", array[index]);
    printf("\n");
}
void scanarray(int array[], int SizeOfArray)
{
    printf("\n---------------------------------Scanning the array:----------------------------------------------\n");
    for (int index = 0; index < SizeOfArray; index++)
    {
        printf("\nGive a value of the index[%d]=", index);
        scanf("%d", &array[index]);
    }
    printf("\n");
}
void sortarray(int array[], int SizeOfArray)
{
    printf("\n---------------------------------sorting the array:----------------------------------------------\n");

    for (int index = 1; index < SizeOfArray; index++)
    {
        printarray(array, SizeOfArray);
        int key = array[index];
        int jindex = index - 1;
        while (jindex >= 0 && array[jindex] > key)
        {
            array[jindex + 1] = array[jindex];
            jindex = jindex - 1;
        }
        array[jindex + 1] = key;
    }

    printf("\n");
}
void main()
{
    // STEP 0 INITIALIZING SIZE AND THE ARRAY
    int size;
    int index = 0;
    sizearray(&size);
    int array[size - 1];
    // STEP 1 GIVING VALUE TO ARRAY
    scanarray(array, size);
    // STEP 3 CHECKING ARRAY
    printarray(array, size);
    // STEP 2 SORTING ARRAY
    sortarray(array, size);
    // STEP 3 CHECKING ARRAY
    printarray(array, size);
}
