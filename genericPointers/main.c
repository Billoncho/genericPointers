/*
Name:          Billy Gene Ridgeway
Purpose:       Learn about generic pointers in C.
Date:          June 26th. 2022
*/

#include <stdio.h>

#define LENGTH 3

int data[LENGTH];			// some integers
char *words[LENGTH];		// some strings

int main(int argc, char **argv) {       // argc gives us the number or count of arguments. **argv is a pointer to a pointer that points to a char.
                                        // argv is initialized with any arguments passed in from the command line.
                                        // The first argument in argv is the program name itself. Subsiquent arguments are any strings entered
                                        // after the program name.
	void *gp;			                // a generic pointer

	printf("Generic Pointer Example\n\n");

	// Initialize our integer array.
	for (int i = 0; i < LENGTH; i++) {
		data[i] = i;
	}
	for (int i = 0; i < LENGTH; i++) {
		printf("%d\n", data[i]);        // Prints the array of integers stored in the array "data".
	}

    printf("\n");

	// initialize our string array.
	words[0] = "zero";
	words[1] = "one";
	words[2] = "two";
	for (int i = 0; i < LENGTH; i++) {
		printf("%s\n", words[i]);
	}

    printf("\n");

	// Generic Pointer

	gp = data;								        // Set the generic pointer to the start of the integer array.
	printf("\nThe data array address is:  %p\n", gp);		// Print out the address of the generic pointer.

	printf("The item pointed to by gp is: %d.\n", *(int*)gp);     // Print out the integer pointed to by gp by using a cast to int (int*) and dereferencing it with '*' to print the stored value.

	gp = (int*)gp + 1;                                      // The cast tells the compiler what the address type is and so we can do address arthimetic. Here we increment by one.
	printf("The item pointed to by gp is now: %d.\n", *(int*)gp); // Print out the second integer pointed to by the generic pointer by casting it to an int and dereferencing it.

    gp = (int*)gp + 1;                                      // The cast tells the compiler what the address type is and so we can do address arthimetic. Here we increment by one.
	printf("The item pointed to by gp is now: %d.\n", *(int*)gp); // Print out the second integer pointed to by the generic pointer by casting it to an int and dereferencing it.

	gp = words;								            // Sets the generic pointer to the start of the string array "words".
	printf("\nThe words array address is:  %p\n", gp);		// Prints out the address of the string array "words".

	printf("The item pointed to by gp is: %s.\n", *(char**)gp);       // Prints out the string item pointed to by gp by casting it to char (char**) and using the dereferencer '*' to print out the value.

	gp = (char**)gp + 1;                                        // The cast tells the compiler what the address type is and so we can do address arthimetic. Here we increment by one.
	printf("The item pointed to by gp is now: %s.\n", *(char**)gp);   // Prints out the second string item by casting it to char and dereferencing it.

    gp = (char**)gp + 1;                                        // The cast tells the compiler what the address type is and so we can do address arthimetic. Here we increment by one.
	printf("The item pointed to by gp is now: %s.\n", *(char**)gp);   // Prints out the second string item by casting it to char and dereferencing it.

	return 0;
}
