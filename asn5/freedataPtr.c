/* CS2211a 2021 */
/* Assignment Five (05) */
/* Ameena Naqvi */
/* December 1, 2021 */

// Based on a data pointer this function will free the memory associated with that data pointer
// This is called by freeList and inside the printDoc function
void freedataPtr(void* dataPtr){
    free(dataPtr);
    dataPtr = NULL;
    return;
}
