/* CS2211a 2021 */
/* Assignment Five (05) */
/* Ameena Naqvi */
/* December 1, 2021 */

// This function is used for the bonus portion of the assignment
// When a cycle count exceeds max cycles it is temporarily deleted from the list only and then readded by this function
bool readdNode(LIST* list, NODE* nodetoAdd){
    int priorityNewNode = ((DOC*)nodetoAdd->dataPtr)->request_priority;
    int docnumNewNode = ((DOC*)nodetoAdd->dataPtr)->document_number;
    int pagenumNewNode = ((DOC*)nodetoAdd->dataPtr)->num_pages;
    int numCycles = ((DOC*)nodetoAdd->dataPtr)->num_cycles;
    
    // If our list is empty the node is made as the lists' head
    if (list->count == 0){
        list->head = nodetoAdd;
        (list->count)++;
        return true;
    }
    // If the list is not empty the list is iterated to find the proper point of insertion for the node
    struct node dummy;
    struct node* prev = &dummy;
    dummy.link = (list->head);
    struct node* current = prev->link;
    
    while ((current!= NULL)) {
        // Priority of the current node and the page number are used to assess where the node should be inserted
        int priorityCurrentNode = ((DOC*)current->dataPtr)->request_priority;
        // If priority of new node is less than the priority of current node then the node is added to the left of the current node
        if (priorityNewNode<priorityCurrentNode){
            // Add to Left
            if(prev->link==list->head){
                // Add to Left
                // Special case where the current is the head node
                // The head node is replaced by the new node
                nodetoAdd->link = current;
                list->head = nodetoAdd;
                (list->count)++;
                return true;
            }
            // Occurs when the current is not the head node but the point of insertion is still found
            prev->link = nodetoAdd;
            nodetoAdd->link = current;
            (list->count)++;
            return true;
        }
       
        prev = prev->link;
        if(current->link==NULL){
            break;
        }
        current = current->link;
        
        
    }
    
    // Add to Right or Rear
    // If none of the above conditions are ever satisfied in the list then the node is added to the right of last node
    // This means that it is added to the rear
    nodetoAdd->link = NULL;
    current->link = nodetoAdd;
    (list->count)++;
    return true;

} // readdNode