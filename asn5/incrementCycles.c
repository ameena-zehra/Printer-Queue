/* CS2211a 2021 */
/* Assignment Five (05) */
/* Ameena Naqvi */
/* December 1, 2021 */

// This increments the cycles of all printers currently in queue
void incrementCycles (LIST* newList){
    // Iterates through the list starting with the head node
    struct node* current = newList->head;
    while (current!=NULL){
        int docNumber = (*((DOC*)current->dataPtr)).document_number;
        int pageCount = (*((DOC*)current->dataPtr)).num_pages; 
        int requestPriority = (*((DOC*)current->dataPtr)).request_priority;
        // Increments number of cycles and prints the incremented amount is DEBUG_SHOW_CYCLES is on
        ((DOC*)current->dataPtr)->num_cycles++;
        int numCycles = (*((DOC*)current->dataPtr)).num_cycles; 
        #if defined (DEBUG_SHOW_CYCLES)
            printf("Increment Cycle - Document:%5d    Pages:%4d    Priority:%2d    Cycle Count:%4d\n",docNumber, pageCount, requestPriority, numCycles);
        #endif
        // if maxCycles are exceeded must go through the process of temporarily deleting them from the list only to readd them later
        if ((numCycles==MAXCYCLES)&&(requestPriority!=0)){
            #if defined (DEBUG_SHOW_EXCEEDED)
                printf("EXCEEDED CYCLE COUNT - Document:%5d    Pages:%4d    Priority:%2d    Cycle Count:%4d\n",docNumber, pageCount, requestPriority, numCycles);
            #endif
            
            (*((DOC*)current->dataPtr)).request_priority =0;
            temporarilyDelete(newList, current);
            readdNode(newList,current);
        }
        current = current->link;
    }
}
