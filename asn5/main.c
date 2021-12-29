
/* CS2211a 2021 */
/* Assignment 5 */
/* Ameena Naqvi */
/* 251173552 */ 
/* anaqvi23 */ 
/* December 1, 2021 */ 
#include "headers.h"

// This is the main program for the assignment 
int main (void)
{
    // Creates a newList to store the printer queue
    LIST* newList= createList();
    // Calls srand(time(NULL)) once to ensure randomizer acts correctly
    srand(time(NULL));
    // Enters a for loop based on a given number of max iterations
    for (int i=1; i<ITERATIONS; i++){
        // Each cycle there is a 10% chance that a printing job request will be added to the queue
        if(getFrequency()== 1){
            // if the 10% is hit insert the job request into the queue in order
            DOC *firstDoc = (DOC*) malloc(sizeof(DOC));
            initDoc(firstDoc, i);
            insertList(newList, firstDoc);
        }
        // Documents are printed simulatenously based on the printers capacity
        printDoc(newList);
        
    }
    printf("End of Program - * NAQVI *\nNumber of printer jobs left in queue: %d\n", newList->count);
    // All memory associated with the list is then freed
    freeList(newList);
  return 0;
} 
