/* CS2211a 2021 */
/* Assignment Five (05) */
/* Ameena Naqvi */
/* November 10, 2021 */
// any preprocessor definitions
// all function prototypes- functions used in main defined in other functions
 #ifndef DEFINITIONS_H_INCLUDED
 #define DEFINITIONS_H_INCLUDED
 #define PAGESPERMINUTE 1
 #define MAXCYCLES 200
 #define MAXPAGES 30 
 #define ITERATIONS 1000
 #define DEBUG_LIST
 #define DEBUG_ADDING
 #define DEBUG_PRINT_PROCESS
 #define DEBUG_SHOW_CYCLES
 #define DEBUG_SHOW_EXCEEDED
    typedef struct document{
        int document_number;
        int request_priority;
        int num_pages;
        int num_cycles;
        } DOC;

    typedef struct node {
        void* dataPtr;
        struct node* link;
        } NODE;
    typedef struct
    {
        NODE* head;
        int count;
    } LIST;
    #include "freedataPtr.c"
    #include "freeNode.c"
    #include "freeList.c"


    #include "createList.c"
    #include "insertList.c"
    #include "temporarilyDelete.c"
    #include "readdNode.c"
    #include "removeHead.c"
    

    #include "printList.c"
    #include "incrementCycles.c"
    #include "printDoc.c"
    
    #include "initDocs.c"
    #include "getFrequency.c"
    

   
    // createList.c function
    LIST* createList(void);
    // insertList.c function
    bool insertList (LIST*, void*);
    // temporarilyDelete.c function
    bool temporarilyDelete(LIST*, NODE*);
    // readdNode.c function
    bool readdNode(LIST*, NODE*);
    // removeHead.c function
    void removeHead(LIST*);
    // printList.c function
    void printList(LIST* newList);
    // incrementCycles.c function
    void incrementCycles (LIST*);
    // printDoc.c function
    void printDoc(LIST*);

    // freedataPtr.c function
    void freedataPtr(void*);
    // freeNode.c function
    void freeNode(NODE*, int);
    // freeList.c function
    void freeList(LIST*);
    // initDoc.c function
    void initDoc(DOC*, int);
    // getFrequency.c function
    int getFrequency(void);
#endif // DEFINITIONS_H_INCLUDED
