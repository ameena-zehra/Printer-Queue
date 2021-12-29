/* CS2211a 2021 */
/* Assignment Five (05) */
/* Ameena Naqvi */
/* December 1, 2021 */

// Based on a given list parameter this function will remove its head
void removeHead(LIST* newList)
    {
    
    NODE* nodePtrtoFree = (newList->head);
    if (newList->head->link != NULL){
        newList->head = newList->head->link;
    }
    (newList->count)--;
    // Frees the dynamic memory associated with the head node
    int a = 1;
    if(nodePtrtoFree!=NULL){
        freeNode(nodePtrtoFree, 1);
    }
    
    //freeNode(nodePtrtoFree);
    return ;
} // removeHead