
/* CS2211a 2021 */
/* Assignment Five (05) */
/* Ameena Naqvi */
/* December 1, 2021 */

// This function returns a list and does not require any parameters
LIST* createList(void)
{
    LIST* list;
    list= (LIST*) malloc (sizeof (LIST)); 
    if (list)
    {
        list->head = NULL;
        list->count = 0;
     } // if
    return list;
} // createList
