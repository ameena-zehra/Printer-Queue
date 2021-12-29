/* CS2211a 2021 */
/* Assignment Five (05) */
/* Ameena Naqvi */
/* December 1, 2021 */

// Based on a node pointer this function will free the memory associated with that node pointer as well as the data pointer
// This is called by freeList
void freeNode(NODE* nodePtr, int a){
    if((nodePtr->dataPtr!=NULL)){
        freedataPtr(nodePtr->dataPtr);
    }
    free(nodePtr);
    nodePtr = NULL;
    return;
}