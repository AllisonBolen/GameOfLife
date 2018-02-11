#ifndef H_FUNCTIONS
#define H_FUNCTIONS


int read_file( char* filename, char **buffer );
int write_file( char* filename, char *buffer, int size);
void makeBoard(int *r, int *c, char ***board, char* buffer);
void makeCheck(int *r, int *c, int ***checkBoard);
void boardDimensions(int *r, int *c);
void userResponse(char *resp);
void getFileFromUser(char *fileName);
void getContNumFromUser(int *num); 
void saveFileTo(char *fileName);
void freeMem(char ***board, int *r, int *c);
void printBoard(char ***board, int *r, int *c);
void printCheckBoard(int ***board, int *r, int *c);
void printBuffer(char *board);
void populateCheck(int *r, int *c, int ***checkBoard);
void populateBoard(char ***board, char *buffer, int *r, int *c);
void overCrowding( char ***board, int ***checkBoard, int i, int j , int r, int c);
void underPopulation();
void survival();
void zombie();
#endif
