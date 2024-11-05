#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "fileutil.h"

// DIRECTIONS
// Choose whether you are doing the 2D array or
// the array of arrays.
// For the 2D array,
//    implement loadFile2D, substringSearch2D, and free2D.
// For the array of arrays, 
//    implement loadFileAA, substringSearchAA, and freeAA.


// Load the text file from the given filename.
// Return a pointer to the array of strings.
// Sets the value of size to be the number of valid
// entries in the array (not the total array length).
char ** loadFileAA(char *filename, int *size)
{
	FILE *in = fopen(filename, "r");
	if (!in)
	{
	    perror("Can't open file");
	    exit(1);
	}
	
	// TODO
	// Allocate memory for an array of strings (arr).

	*size = 0;
	int capacity = 100;
	char **arr = malloc(capacity * sizeof(char *));

	// Read the file line by line.
	char line[1000];
    while (fgets(line, sizeof(line), in)) {
        // Remove newline character if present
        char *newline = strchr(line, '\n');
        if (newline) {
            *newline = '\0';
        }

		// Expand array if necessary (realloc).
		if (*size >= capacity) {
			capacity += 50;
			arr = realloc(arr, capacity * sizeof(char *));
		}

		// Allocate memory for the string (str).
		arr[*size] = malloc(strlen(line + 1));

		// Copy each line into the string (use strcpy).
		strcpy(arr[*size], line);
		*size = *size + 1;


	}

	//   Attach the string to the large array (assignment =).
	fclose(in);
	return arr;
}

// Search the array for the target string.
// Return the found string or NULL if not found.
char * substringSearchAA(char *target, char **lines, int size)
{
	for(int i = 0; i < size; i++) {
		if(strstr(lines[i], target)){
			return lines[i];
		} 
	}
	return NULL;
}


// Free the memory used by the array
void freeAA(char ** arr, int size)
{
	for(int i = 0; i < size; i++) {
		free(arr[i]);
	}
	free(arr);
}

