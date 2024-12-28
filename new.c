// C program to implement insert operation in
// an sorted array.
#include <stdio.h>

// Inserts a key in arr[] of given capacity.  n is current
// size of arr[]. This function returns n+1 if insertion
// is successful, else n.
int insertSorted(int arr[], int n, int key, int capacity)
{
    // Cannot insert more elements if n is already
    // more than or equal to capacity
    if (n >= capacity)
        return n;

    int i;
    for (i = n - 1; (i >= 0 && arr[i] > key); i--)
        arr[i + 1] = arr[i];

    arr[i + 1] = key;

    return (n + 1);
}


typedef struct Node
{
    int data ;
    struct Node *next ;
}node;




/* Driver code */


int delete(int *arr , int length ,int key) {
    int i , j ;

    for ( i = 0; i < length; i++)
        if (arr[i]==key)
            break;
    printf("i=%d\n" , i) ;
    if ( i >= length )
    return length ;

    for ( j = i ; j < length-1 ; ++j)
    arr[j]=arr[j+1] ;

    return --length ;
}
int main()
{

    int arr[] = { 10, 20, 20, 20, 30 } , length = sizeof(arr)/ sizeof(arr[0]);
    int ele = 30;

    printf("Array before deletion\n");
    for (int i = 0; i < length; i++)
        printf(" %d " , arr[i]) ;
    
    length  =  delete(arr , length , ele) ;

    printf("\nArray after deletion\n") ;
    for (int i = 0; i < length; i++)
        printf(" %d " , arr[i]) ;

    printf("\n");



    return 0;
}