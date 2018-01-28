#ifndef			__H_LIB__
#define			__H_LIB__

// As this is an *.h file, this is an interface.  No
// code is provided for how the function should work.

//read data from a read_file
int read_file( char* filename, char **buffer );

//write data to a file
int write_file( char* filename, char *buffer, int size);

// check for fewer than two live cells = death = underpopulation
// return 1 fora state change and a 0 for no state change
int underpopulation(char** cellLocation);

// check for more than three neighbors = death = overpopulation
// return 1 for a state change return 0 for no change: ie if it dies return one
int overpopulation(char** cellLocation);

// check for two or three live neighbors = stays alive = survives
// return 1 for a death retrun 0 for no state change
int survives(char** cellLocation);

// check for a dead cell with three live neighbors = comes back to life = zombie
// return 1 for a revival and 0 for no state change
int zombie(char** cellLocation);

// create the board from the users input
int createBoard(char** arr);

#endif
