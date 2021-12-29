
/* CS2211a 2021 */
/* Assignment Five (05) */
/* Ameena Naqvi */
/* December 1, 2021 */

// This function inserts a given item pointer in the list based on its priority and number of pages
bool insertList (LIST* list, void* itemPtr)
    {
    // Creates a new node
    NODE* newNode;
    if (!(newNode = (NODE*)malloc(sizeof(NODE)))) return false; 
    newNode = (NODE*)malloc(sizeof(NODE));
    newNode-> dataPtr = itemPtr;
    int priorityNewNode = ((DOC*)newNode->dataPtr)->request_priority;
    int docnumNewNode = ((DOC*)newNode->dataPtr)->document_number;
    int pagenumNewNode = ((DOC*)newNode->dataPtr)->num_pages;
    // If our list is empty the node is made as the lists' head
    if (list->count == 0){
        list->head = newNode;
        (list->count)=1;
        #if defined (DEBUG_ADDING)
            printf("Adding to Queue - Doc:%2d NoPages:%3d Priority:%2d\n", docnumNewNode, pagenumNewNode, priorityNewNode);
        #endif
        
        return true;
    }
    // If the list is not empty the list is iterated to find the proper point of insertion for the node
    struct node dummy;
    struct node* prev = &dummy;
    dummy.link = (list->head);
    struct node* current = prev->link;
    int pagenumCurrentNode = ((DOC*)current->dataPtr)->num_pages;
    while ((current!= NULL)) {
        // Priority of the current node and the page number are used to assess where the node should be inserted
        int priorityCurrentNode = ((DOC*)current->dataPtr)->request_priority;
        // If priority of new node is less than the priority of current node then the node is added to the left of the current node
        if (priorityNewNode<priorityCurrentNode){
            // Add to Left
            // Special case where the current is the head node
            // The head node is replaced by the new node
            if(prev->link==list->head){
                newNode->link = current;
                list->head = newNode;
                (list->count)++;
                #if defined (DEBUG_ADDING)
                    printf("Adding to Queue - Doc:%2d NoPages:%3d Priority:%2d\n", docnumNewNode, pagenumNewNode, priorityNewNode);
                #endif
                return true;
            }
            // Occurs when the current is not the head node but the point of insertion is still found
            prev->link = newNode;
            newNode->link = current;
            (list->count)++;
            #if defined (DEBUG_ADDING)
                printf("Adding to Queue - Doc:%2d NoPages:%3d Priority:%2d\n", docnumNewNode, pagenumNewNode, priorityNewNode);
            #endif
            return true;
        }
        // If the priority of the new node is equal to the priority of the current node then the page numbers are used to assess the appropriate point of insertion
        // Only occurs if page number of new node is less than the page number of current node
        if ((priorityNewNode!=0)&&(priorityNewNode==priorityCurrentNode)&&(pagenumNewNode<pagenumCurrentNode)){
            // Add to Left
            // Special case where the current is the head node
            // The head node is replaced by the new node
            if(prev->link==list->head){
    
                newNode->link = current;
                list->head = newNode;
                (list->count)++;
                #if defined (DEBUG_ADDING)
                    printf("Adding to Queue - Doc:%2d NoPages:%3d Priority:%2d\n", docnumNewNode, pagenumNewNode, priorityNewNode);
                #endif
                return true;
            }
            // Occurs when the current is not the head node but the point of insertion is still found
            prev->link = newNode;
            newNode->link = current;
            (list->count)++;
            #if defined (DEBUG_ADDING)
                printf("Adding to Queue - Doc:%2d NoPages:%3d Priority:%2d\n", docnumNewNode, pagenumNewNode, priorityNewNode);
            #endif
            return true;
        }
       
        prev = prev->link;
        if(current->link==NULL){
            break;
        }
        current = current->link;
        if(current!=NULL){
            pagenumCurrentNode = ((DOC*)current->dataPtr)->num_pages;
        }
        
    }
    
    // Add to Right or Rear
    // If none of the above conditions are ever satisfied in the list then the node is added to the right of last node
    // This means that it is added to the rear
    newNode->link = NULL;
    current->link = newNode;
    (list->count)++;
    #if defined (DEBUG_ADDING)
        printf("Adding to Queue - Doc:%2d NoPages:%3d Priority:%2d\n", docnumNewNode, pagenumNewNode, priorityNewNode);
    #endif
    return true;
    
} // insertList

