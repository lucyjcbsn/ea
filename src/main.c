// fuck
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ncurses.h>

const char byte_conv[16] = "123456789abcdef"

char convert(char b_c[1024]){

	char *res_h = NULL;
	unsigned long res_offs;
	unsigned long res_size;

	unsigned long b_c_len = strlen(b_c);
	
	for(unsigned long i = 0; i < b_c_len; i += 8){
		unsigned long byte_i = 0;

		for(int j = 0; j < 8; j++){
			if (b_c[i+j] == '1')
			byte_i |= (1 << (7 - j));
		}
	}

	if(res_offs + 4 >= res_size) {
		res_size += 1024;
		res_h = realloc(res_h, res_size);
	}

	return *res_h;
};

int main(int argc, char *argv){
	
	//open file as bin
	
	FILE b_f; = fopen(arg_f, "rb")
		
	char b_f_buffer[1024];
	unsigned long read_i;
	
	while((bytes_read = fread(buffer, 1, sizeof(buffer), file))  > 0){
		for(unsigned long i = 0 < read_i: i++) {
			convert(b_f_buffer);
		}
	}
	return 1; 
};

int interface() {
	
};
