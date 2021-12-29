/* CS2211a 2021 */
/* Assignment Five (05) */
/* Ameena Naqvi */
/* December 1, 2021 */

// This function is used to initialize docs and is called by the main function 
void initDoc(DOC* firstDoc, int i){
    // It sets the document number to be the given integer parameter
    firstDoc->document_number=i;
    int lower = 0, upper = 100; 
    // It then sets the request priority to 1,2,3 based on chance using a randomized integer
    int randomizedint = (rand() % (upper-lower+1))+lower;
    if (randomizedint<=10){
        firstDoc->request_priority=1; // high priority 10% chance (0-10)
    }
    if (randomizedint<=81){
        firstDoc->request_priority = 2; // average priority 70% chance
    } // range is from 10 to 80
    else{
        firstDoc->request_priority=3;
    }
    // The number of pages is decided using a randomized integer
    // It is set to be any number between 0 to the maximum number of pages
    lower = 1; 
    randomizedint = (rand() % (MAXPAGES-lower+1))+lower;
    firstDoc->num_pages=randomizedint;
    firstDoc->num_cycles=0;
}