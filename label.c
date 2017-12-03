#include "label.h"
#include <stdio.h>
#include <string.h>

int labels = 0;

int label_create(){
	labels++;
	return labels;
}

const char *label_name( int label ){
	char string[5];
	sprintf(string, ".L%d", label);
	return strdup(string);
}
