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
void pritarray(int array[], int SizeOfArray)
{
    printf("\n---------------------------------Printing the array:----------------------------------------------\n");
    for (int index = 0; index < SizeOfArray; index++)
        printf("[%d]", array[index]);
    printf("\n");
}
void main()
{
    // STEP 0 INITIALIZING
    int size;
    int index = 0;
    do
    {
        printf("Give a size for the array\n");
        scanf("%d", &size);
    } while (size <= 0 || size > MAX); //! size>=1
    int array[size - 1];
    // STEP 1 INSERTING The Sorted Array
    printf("Give a value of the index[%d]=", index);
    scanf("%d", &array[index]);
    index++;
    while (index < size)
    {
        printf("Give a value of the index[%d]=", index);
        scanf("%d", &array[index]);
        if (array[index - 1] > array[index])
        {
            index--;
            printf("\nYou Insert Wrong way:\nReInsert the index [%d]=", index);
        }
        index++;
    }; // !index >= size
    pritarray(array, size);
    // STEP 2 INSERTING NEW VALUE
    // int newarray[size];
    int newvalue;
    printf("Give a value to insert in the array:\n");
    scanf("%d", &newvalue);
    /*     bool isinserted = false;
        for (int jindex = 0; jindex < size + 1; jindex++)
        {
            if (newvalue < array[jindex] && !isinserted)
            {
                newarray[jindex] = newvalue;
                isinserted = true;
            }
            else
            {
                if (isinserted)
                    newarray[jindex] = array[jindex - 1];
                else
                    newarray[jindex] = array[jindex];
            }
        }
        if (!isinserted)
            newarray[size] = newvalue; */
    // Find insertion point and shift elements
    for (index = size - 1; index >= 0 && array[index] > newvalue; index--)
        array[index + 1] = array[index];
    // Insert new value
    array[index + 1] = newvalue;
    size++;
    pritarray(array, size);
}
/*
old array : [5][6][8][9][14][16][18][20][21]
new array : [5][6][8][9][14][16][18][20][21][-1]
==> is crazment every time nkraziw rah nhato value li rah nkraziwha f an temp value
[4] ==> [5] ==> [6] ==> >>>>
[7] ==> [8] ==> [9] ==> >>>>
[22] ==> [-1]
 */
