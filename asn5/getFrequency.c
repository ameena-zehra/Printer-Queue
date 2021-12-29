/* CS2211a 2021 */
/* Assignment Five (05) */
/* Ameena Naqvi */
/* December 1, 2021 */

// This function is used to set the frequency at which print jobs are added, it is called by the main function
// Each iteration is 1 is returned then the print job will be executed
int getFrequency(void){
    int lower = 0, upper = 100; 
    int randomizedint = (rand() % (upper-lower+1))+lower;
    if (randomizedint<=10){
        return 1; // 10% that a new print job will be executed
    }
    return 0;
}