#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// ADD: needed .h
#include "data.h"
#include "list.h"

int main(int argc, char *argv[]) {

    //print argv
    for (int i = 0; i < argc; i++) {
       printf("argv[%d]: %s\n", i, argv[i]);
    }

	// Check to have at least 3 arguments in command line
    if (argc < 3) {
        return 1; // Indicate an error by returning a non-zero value
    }

    // Open input and output files
    FILE *inFile = fopen(argv[2], "r");
    if (inFile == NULL) {
        perror("Error opening input file");
        return 1; // Indicate an error
    }

    FILE *outFile = fopen(argv[3], "w");
    if (outFile == NULL) {
        perror("Error opening output file");
        fclose(inFile); // Close the input file
        return 1; // Indicate an error
    }


    // Open input and output files
    //FILE *inFile = fopen(argv[1], "r");
    //FILE *outFile = fopen(argv[2], "w");

    //create linked list
    //list_t *restaurant = listCreate();

    //SKIP HEADER FILE
    restaurantSkipHeaderLine(inFile);
    
    // Call the restaurantPrintHeader function to print the header
    restaurantPrintHeader(outFile);


    restaurant_t *r;
    while ((r = restaurantRead(inFile)) != NULL) {
        
        //add next record to list
        //listAppend(restaurant, r);
        //continue;
        // Call the restaurantPrint function to print each restaurant record
        restaurantPrint(outFile, r);
        // Don't forget to free allocated memory for r if necessary
    }

    // Close the opened files!
    fclose(inFile);
    fclose(outFile);

    return 0;
}
