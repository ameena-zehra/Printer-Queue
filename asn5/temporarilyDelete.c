/* CS2211a 2021 */
/* Assignment Five (05) */
/* Ameena Naqvi */
/* December 1, 2021 */

// This function is used for the bonus portion of the assignment
// When a cycle count exceeds max cycles it is temporarily deleted from the list only to be readded later
bool temporarilyDelete(LIST* list, NODE* nodetoChange){
    // Iterates through the list looking for the target node
    struct node dummy;
    struct node* prev = &dummy;
    dummy.link = (list->head);
    struct node* current = list->head;
    // If target node is the head then it is replaced with the next node
    if(nodetoChange->dataPtr==current->dataPtr){
        list->head = current->link;
        (list->count)--;
    }
    // Looks for the target within the list
    while (current!=NULL){
        if(nodetoChange->dataPtr==current->dataPtr){
            if(current->link!=NULL){
                prev->link = current->link;
                (list->count)--;
            }
            else{
                prev->link = NULL;
                (list->count)--;
            }            
            return true;
        }
        prev = current;
        current = current->link;
    }
    return false;
} // temporarilyDelete