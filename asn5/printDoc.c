/* CS2211a 2021 */
/* Assignment Five (05) */
/* Ameena Naqvi */
/* December 1, 2021 */

// This function serves as the living printer for the program
void printDoc(LIST* newList){
    
    static NODE currentprintJob;
    // Starts out by printint out a list of printer jobs currently in queue
    // Only does this if the debug_list is defined
    if (newList->count==0){
        #if defined (DEBUG_LIST)
                printf("EMPTY QUEUE - no print jobs currently in queue\n");
        #endif
        if (currentprintJob.dataPtr!=NULL){
            int docNumber = ((DOC*)currentprintJob.dataPtr)->document_number;
            int requestPriority = ((DOC*)currentprintJob.dataPtr)->request_priority;
            ((DOC*)currentprintJob.dataPtr)->num_pages-=PAGESPERMINUTE;
            int pageCount = ((DOC*)currentprintJob.dataPtr)->num_pages;
            #if defined (DEBUG_PRINT_PROCESS)
                printf("PRINTING - DOCUMENT:    %d PAGE:   %d priority: %d\n", docNumber, pageCount, requestPriority);
            #endif
            
            if(pageCount<=0){
                int docNumber = ((DOC*)currentprintJob.dataPtr)->document_number;
                int cycleCount = ((DOC*)currentprintJob.dataPtr)->num_cycles;
                printf("Print Job Completed - Document Number:%5d   -   Cycle Count:%6d\n", docNumber, cycleCount);
                currentprintJob.dataPtr = NULL;
            }
        }
        return;
    }
    // Tests if the newList count is not equal to 0
    else if (newList->count!=0){
        // If the current job data pointer is not null meaning the printer is occuped
        // Then print out the current queue of print jobs
        // AND incrementCycles
        if (currentprintJob.dataPtr!=NULL){
            #if defined (DEBUG_LIST)
                printList(newList);
            #endif
            incrementCycles(newList);
        }
        // If the newList is empty and the current print job is equal to null
        // Then print empty queue
        else{
            #if defined (DEBUG_LIST)
                printf("EMPTY QUEUE - no print jobs currently in queue\n");
            #endif
        }

    }
    

    
    // Test if there is no document being printed
    if (currentprintJob.dataPtr==NULL){
        // if no document is currently being printed take the current print job node off the linked list
        int docNumber = ((DOC*)newList->head->dataPtr)->document_number;
        int requestPriority = ((DOC*)newList->head->dataPtr)->request_priority;
        int pageCount = ((DOC*)newList->head->dataPtr)->num_pages;
        int numCycles = ((DOC*)newList->head->dataPtr)->num_cycles;
        DOC* documenttoStore = (DOC*) malloc(sizeof(DOC));
        documenttoStore->document_number = docNumber;
        documenttoStore->request_priority = requestPriority;
        documenttoStore->num_pages = pageCount;
        documenttoStore->num_cycles = numCycles;
        // Using the remove head function to delete the head node and free that memory
        removeHead(newList);
        struct node dummy;
        struct node* prev = &dummy;
        dummy.dataPtr = documenttoStore;
        currentprintJob =  dummy;
        
        
    } 
    int docNumber = ((DOC*)currentprintJob.dataPtr)->document_number;
    int requestPriority = ((DOC*)currentprintJob.dataPtr)->request_priority;
    // Decrements by the page per minute value
    ((DOC*)currentprintJob.dataPtr)->num_pages-=PAGESPERMINUTE;
    int pageCount = ((DOC*)currentprintJob.dataPtr)->num_pages;
    #if defined (DEBUG_PRINT_PROCESS)
        printf("PRINTING - DOCUMENT:%4d PAGE:%4d priority:%2d\n", docNumber, pageCount, requestPriority);
    #endif
    // if the page count is less than or equal to 0 then the print job is complemented and the output message is displayed
    if(pageCount<=0){
        int docNumber = ((DOC*)currentprintJob.dataPtr)->document_number;
        int cycleCount = ((DOC*)currentprintJob.dataPtr)->num_cycles;
        printf("Print Job Completed - Document Number:%5d   -   Cycle Count:%6d\n", docNumber, cycleCount);
        // In this case the data pointer memory associated with current print job is freed
        // As current print job is not a dynamically allocated node it does not need to be freed
        currentprintJob.dataPtr = NULL;
        freedataPtr(currentprintJob.dataPtr);
        return;
    }
    return;
    

}
