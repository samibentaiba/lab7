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
        scanf("%d", SizeOfArray);
    } while (*SizeOfArray <= 0 || *SizeOfArray > MAX); //! size>=1
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
void deleteoc(int array[], int *SizeOfArray)
{
    printf("\n---------------------------------Deleting all occurrences of repeated numbers in the array:----------------------------------------------\n");
    int newIndex = 0;
    for (int i = 0; i < *SizeOfArray; i++)
    {
        int isUnique = 1;
        for (int j = 0; j < i; j++)
        {
            if (array[i] == array[j])
            {
                isUnique = 0;
                j = i;
            }
        }
        if (isUnique)
        {
            array[newIndex] = array[i];
            newIndex++;
        }
    }
    *SizeOfArray = newIndex;
    printf("\n");
}
void main()
{
    // STEP 0 INITIALIZING SIZE AND THE ARRAY
    int size;
    int index = 0;
    sizearray(&size);
    int array[size];
    // STEP 1 GIVING VALUE TO ARRAY
    scanarray(array, size);
    // STEP 3 CHECKING ARRAY
    printarray(array, size);
    // STEP 2 SORTING ARRAY
    deleteoc(array, &size);
    // STEP 3 CHECKING ARRAY
    printarray(array, size);
}
