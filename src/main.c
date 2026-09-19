#include <stdio.h>
#include <stdlib.h>
#include <curses.h>

void b_conv(const unsigned char *chunk, unsigned long chunk_si, char *res) {
	static char byte_conv[] = "0123456789abcdef";
	for (unsigned long byte_inc = 0; byte_inc < chunk_si; byte_inc++) {
	int icount = 1; while(icount <= 2){res[byte_inc * 2 + (icount - 1)] = byte_conv[(chunk[byte_inc] >> ((sizeof(chunk[byte_inc]) * 8) - icount * 4)) & 0xF]; icount++;};}
}


int main(int argc, char *argv[]) {
	if (argc < 2) {
		fprintf(stderr, "input");
	}

	FILE *bin_in = fopen(argv[1], "br");

	fseek(bin_in, 0, SEEK_END); long inp_si = ftell(bin_in);
	rewind(bin_in);

	unsigned char *r_chunk = malloc(inp_si);
	unsigned long read = fread(r_chunk, 1, inp_si, bin_in);

	char *hex = malloc(read * 2 + 1); hex[0] = '\0';

	b_conv(r_chunk, read, hex);
	//puts(hex);

	fclose(bin_in);
	free(r_chunk);
	free(hex);

	return 1;
}

int interface_init(char h_in, char h_in_len) {


	
	initscr();

	getch();

	return 1;
}

