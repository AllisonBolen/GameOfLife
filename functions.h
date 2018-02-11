#ifndef H_FUNCTIONS
#define H_FUNCTIONS

int read_file( char* filename, char **buffer );
int write_file( char* filename, char *buffer, int size);
void  makeBoard(int *r, int *c, char ***board, char* buffer);
void boardDimensions(int *r, int *c);
void userResponse(char *resp);
void getFileFromUser(char *fileName);
void getContNumFromUser(int *num); 
void saveFileTo(char *fileName);
void freeMem(char ***board, char **buffer, int *r, int *c);
void printBoard(char ***board, int *r, int *c);
void printBuffer(char *board);
void populateBoard(char ***board, char *buffer, int *r, int *c);
void overCrowding();
void underPopulation();
void survival();
void zombie();
#endif
