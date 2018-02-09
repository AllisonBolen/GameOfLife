#ifndef H_FUNCTIONS
#define H_FUNCTIONS

int read_file( char* filename, char **buffer );
int write_file( char* filename, char *buffer, int size);
void  makeBoard(int *r, int *c, char ***board, char* buffer);
void boardDimensions(int *r, int *c);
void userResponse(char *resp);
void getFileFromUser(char *fileName);
void getContNumFromUser(int *Num); 
void freeMem(char ***board, char **buffer);
#endif
