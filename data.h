
#ifndef _DATA_H_
#define _DATA_H_

// Constant definitions
#define MAX_FIELD_LEN 128
#define MAX_LINE_LEN 512

// Data definitions
typedef struct node node_t;
typedef struct restaurant restaurant_t;

// Function prototypes

// Skip the header line of .csv file "f"
void restaurantSkipHeaderLine(FILE *f);

// Reads a restaurant from file "f" to build a restaurant_t data
// Returns the pointer, or NULL if reading is unsuccessful
restaurant_t *restaurantRead(FILE *f);

//Scanning
int empty_field(int count, char* input);

int double_scan(char* src, double* location, int count);

int int_scan(char* src, int* location, int count);

int case_quotation(int count, char*input);

int str_scan(char* src, char* location, int count);


// Prints the header line for the list of students
void restaurantPrintHeader(FILE *f); // Add FILE parameter

// Prints a student record s to file "f"
void restaurantPrint(FILE *f, restaurant_t *r);

#endif
