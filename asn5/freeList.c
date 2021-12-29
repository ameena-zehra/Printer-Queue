/* CS2211a 2021 */
/* Assignment Five (05) */
/* Ameena Naqvi */
/* December 1, 2021 */

// Based on a list pointer this function will free the memory associated with all the nodes, data pointer and the final list pointer itself
// Called by the main function
void freeList(LIST* list){
    while((list->count>=0)){
	int a = 0;    
        if(list->head->link!=NULL){
            list->head = list->head->link;
            freeNode(list->head, a);
        }
        else{
            printf("not freed\n");
        }
        (list->count)--; 
    } 
    free(list);
    //printf("The document number of the head list %d\n", ((DOC*)list->head->dataPtr)->document_number);

}
