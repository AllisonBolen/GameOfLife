#ifndef H_FUNCTIONS
#define H_FUNCTIONS

int read_file( char* filename, char **buffer );
int write_file( char* filename, char *buffer, int size);
int makeBoard(int r, int c, char ***board, char buffer);
#endif
