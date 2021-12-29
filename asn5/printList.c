
/* CS2211a 2021 */
/* Assignment Five (05) */
/* Ameena Naqvi */
/* December 1, 2021 */

// This prints the full list of the current printer queue
// It is only called when the DEBUG_LIST is turned on
void printList(LIST* newList){
    struct node* current = newList->head;
    printf("Current Printer Queue Size:%2d\n", newList->count);
    while (current!=NULL){
        int docNumber = ((DOC*)current->dataPtr)->document_number;
        int pageCount = ((DOC*)current->dataPtr)->num_pages; 
        int requestPriority = ((DOC*)current->dataPtr)->request_priority;
        int numCycles = ((DOC*)current->dataPtr)->num_cycles; 
        printf("Current Printer Queue : DocNum:%4d     NumofPages%4d      PriorityLevel%2d      NumOfCycles%4d\n",docNumber, pageCount, requestPriority, numCycles);
        current = current->link;
    }
    printf("END OF LIST\n");
}