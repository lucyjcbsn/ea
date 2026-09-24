#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

struct b_write_args {
	unsigned long address;
	//line based search
	unsigned long line;
	unsigned int line_pos;
};

struct h_format_args {
	bool byte_seperate;
	bool line_seperate;
};

void b_conv(const unsigned char *chunk, unsigned long chunk_si, char *res) {
	static char byte_conv[] = "0123456789abcdef";
	for (unsigned long byte_inc = 0; byte_inc < chunk_si; byte_inc++) {
	// the unholy oneliner of sorrow
	int i = 1; while(i <= 2){res[byte_inc * 2 + (i - 1)] = byte_conv[(chunk[byte_inc] >> ((sizeof(chunk[byte_inc]) * 8) - i * 4)) & 0xF]; i++;};}res[chunk_si * 2] = '\0';
};


void h_write(const char *hex, char *res, struct b_write_args *args, char write[2]) {
	unsigned long byte_t;
	if (args->address) {byte_t = (args->address*2); // direct address
	}else if(args->line) {byte_t = ((args->line*24) + args->line_pos);} //line & line[offset]
	int i = 0; while(i <= 1){res[byte_t + i] = write[1 + i]; i++;} // write
};

void h_format(const char *hex, char *res, struct h_format_args *args) {
	// mister president,  a second oneliner has hit the file!
	unsigned long byte_inc = 0; unsigned long res_inc = 0; while(byte_inc > (strlen(res))){int i = 0; while(i <= 1){res[byte_inc + i] = hex[byte_inc + i];} res[byte_inc + 3] = ' '; byte_inc+=2; res_inc+=3;}	
};
// h_format ;
// res[hex * 1.5]

int main(int argc, char *argv[]) {
	if (argc < 2) {
		fprintf(stderr, "input");
		return 1;
	}

	FILE *bin_in = fopen(argv[1], "rb");

	fseek(bin_in, 0, SEEK_END); long inp_si = ftell(bin_in);
	rewind(bin_in);

	unsigned char *r_chunk = malloc(inp_si);
	unsigned long read = fread(r_chunk, 1, inp_si, bin_in);

	char *hex = malloc(read * 2 + 1);

	b_conv(r_chunk, read, hex);
	puts(hex);

	fclose(bin_in);
	free(r_chunk);
	free(hex);

	return 1;
}


