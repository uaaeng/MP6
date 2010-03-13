/* -Jasen Kintner(Student id # 30447417)
   -Robert Gingras(Student id # 30967759)
   -Machine Problem 6 - The Mouse and His Cheese.
   
   -Created: 3/6/2010
   -Last Modified: 
*/

/*  Things to do:
1. Build Shell
2. Read maze into array
3. Traverse maze into different array (output to file?)
4. Find all paths
5. Find shortest path
maze reading: rights is +1 left is -1 up is -cols and down is +cols
				check order is right, down, left, up
*/

#include <stdio.h>
#include <stdlib.h>
//#include <time.h>

#define MAX_SIZE 100

void main(){
	
	int ch, count, rows, cols;
	char Filename[200];
	FILE *infile;

	count=0;
	rows=0;

	printf ("Please enter the name of the file: ");											//allows user to scan in the name of a file
	scanf("%s", Filename);	
	infile = fopen(Filename, "r");															//opens the file in read mode
	
	/* count characters and rows in the stream */
	while (1) {
        ch = fgetc(infile);
		if (ch == 10)									// check for rows by counting newlines (10)
			++rows;

        if (ch == EOF)									// check for end of file
            break;
        ++count;
    }

	cols = count/rows;									// calculate columns from rows

    printf("Number of characters in %s is %d\n", Filename, count);
	printf("Rows:%d  Columns:%d (including newlines)\n", rows, cols);

    fclose(infile);
	/* end count characters in the stream */

	/* load into dynamic memory (heap) here */
	fopen(Filename, "r");
	
	char *maze;
	int i,j;
	
	maze = (char *) malloc (sizeof(char) * rows * cols);
	i=0;
	for (i=0; i<rows ; i++){							//i is starting at 33 not sure why
		for (j=0; j<cols ; j++) {
			*(maze + i * cols + j) = fgetc(infile);
		}
	}
	
	for (i=0; i<rows ; i++){
		for (j=0; j<cols ; j++){
			printf ("%c", maze[i*cols + j]);
		}
	}
	//printf("-1 is %c\n", maze[-1]);
	//printf("7 is %c\n", maze[7]);
	//printf("28 is %c\n", maze[28]);
	fclose (infile);
	free (maze);
				/**maze=(char**)malloc(rows*sizeof(*maze));
				
				for (i=0; i<rows ; i++) {
					maze[i]=(char*)malloc(cols*sizeof(maze)); 
				}*/
				
				// fill memory and use direct pointers there?

	/* end load into dynamic memory (heap) here */
}