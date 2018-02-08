#include <stdio.h>
#include <stdlib.h>
//#include <library.h>

int main(int argc, int** argv[]){
  printf("%s\n", argv[1]);
  char* buffer;
  char** board;
  //buffer = malloc(500 * sizeof(char));
  int size = read_file( argv[1], &buffer );
  printf("%s", buffer);
  int r,c,i,j; 
  printf ("\nHow many rows do you have?\n");
  scanf("\n%d",&r);
  printf("\nrows: %d",r);
  printf("\nHow many columns do you have?\n");
  scanf("\n%d",&c);
  printf("\ncolumns: %d",c);
  printf ("\nMakeBoard:\n");
  makeBoard(r, c, &board, buffer);
  printf("\n It didnt work\n ");
  
 /*for (i = 0; i < strlen(buffer); i++){
	if(buffer[i] == '\n'){
		//printf("this is a new line \n");
	}
	else{
	printf("%c", buffer[i]);
	}	
   
  }*/
	printf("\n");
  return 0;


 /* 
  int r = 4;
  int c = 4;
  printf ("\nWould you like to save the file type Y for yes or N for no.\n");
  makeBoard(r, c, &board, buffer);
  printf("\n It didnt work");
  return 0;
 */ 
}
