#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
// ADD: needed .h
#include "data.h"


// define struct for record(row)
struct restaurant{
	int census_year;
	int block_id;
	int property_id;
	int base_property_id;
	char *building_address;
	char *clue_small_area;
	char *business_address;
	char *trading_name;
	int industry_code;
	char *industry_description;
	char *seating_type;
	int number_of_seats;
	double longitude;
	double latitude;
};


// Skip the header line of .csv file "f"
void restaurantSkipHeaderLine(FILE *f) {
	while (fgetc(f) != '\n');
}

// new READ function
restaurant_t *restaurantRead(FILE *f) {

	char input[MAX_LINE_LEN + 1];

	restaurant_t *r = (restaurant_t*)malloc(sizeof(restaurant_t));

    if (fgets(input, MAX_LINE_LEN + 1, f) == NULL){
		return NULL;
	} else {

	// Allocate memory for strings before copying data
        r->building_address = (char*)malloc(MAX_FIELD_LEN + 1);
        r->clue_small_area = (char*)malloc(MAX_FIELD_LEN + 1);
        r->business_address = (char*)malloc(MAX_FIELD_LEN + 1);
        r->trading_name = (char*)malloc(MAX_FIELD_LEN + 1);
        r->industry_description = (char*)malloc(MAX_FIELD_LEN + 1);
        r->seating_type = (char*)malloc(MAX_FIELD_LEN + 1);

        int true_count = 0;
		
        true_count += int_scan(input, &r->census_year, true_count);
		true_count += int_scan(input, &r->block_id, true_count);
		true_count += int_scan(input, &r->property_id, true_count);
		true_count += int_scan(input, &r->base_property_id, true_count);
		true_count += str_scan(input, r->building_address, true_count);
		true_count += str_scan(input, r->clue_small_area, true_count);
		true_count += str_scan(input, r->business_address, true_count);
		true_count += str_scan(input, r->trading_name, true_count);
		true_count += int_scan(input, &r->industry_code, true_count);
		true_count += str_scan(input, r->industry_description, true_count);
		true_count += str_scan(input, r->seating_type, true_count);
		true_count += int_scan(input, &r->number_of_seats, true_count);
		true_count += double_scan(input, &r->longitude, true_count);
        true_count += double_scan(input, &r->latitude, true_count);
		
		return r;
	}
}

//check if field is empty
int empty_field(int count, char* input){
    if (input[count] == ','){
        return 1;
    }
    return 0;
}

//check if theres a double quotation mark
int case_quotation(int count, char* input){
    if(input[count] == '\"'){
        return 1;
    }
    return 0;
}

//scan string
int str_scan(char* src, char* location, int count){
    int char_q = 0;
    if (empty_field(count, src)){
            strcpy(location, "");
            char_q = 0;
            char_q++;
        }
        else if (case_quotation(count, src)){
            count += 1;
            sscanf(src + count, "%[^\"]%n,", location, &char_q);
            char_q += 3;
        }
        else{
			sscanf(src + count, "%[^,],%n", location, &char_q);
        }
    return char_q;
}

//scan double
int double_scan(char* src, double* location, int count){
    int char_q = 0;
    sscanf(src + count, "%128lf,%n)", location, &char_q);
    return char_q;
}


//scan int
int int_scan(char* src, int* location, int count){
    int char_q = 0;
    double temp_store;
    sscanf(src + count, "%lf,%n)", &temp_store, &char_q);
    *location = (int) temp_store;
    return char_q;
}




// Prints a restaurant record *r to file "f"
void restaurantPrint(FILE *f, restaurant_t *r) {
		fprintf(f, "%-20d %-20d %-20d %-20d %-80s %-30s %-80s %-30s %-20d %-20s %-30s %-20d %-15.1lf %-15.1lf\n",
				r->census_year, r->block_id, r->property_id, r->base_property_id, 
				r->building_address, r->clue_small_area, r->business_address, r->trading_name, r->industry_code, 
				r->industry_description, r->seating_type, r->number_of_seats, r->longitude, r->latitude);
} 


// Prints the header line for the list of restaurants
void restaurantPrintHeader(FILE *f) {
	// Prints the header line
	fprintf(f, "RESTAURANT LIST\n");
	// The format string below is reproduced from the one in restaurantPrint
	fprintf(f, "%-20s %-20s %-20s %-20s %-80s %-30s %-80s %-30s %-20s %-20s %-30s %-20s %-15s %-15s\n",
			"census_year", "block_id", "property_id", "base_property_id", 
			"building_address", "clue_small_area", "business_address", "trading_name", "industry_code", 
			"industry_description", "seating_type", "number_of_seats", "longitude", "latitude");
}



