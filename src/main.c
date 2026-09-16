#include <stdio.h>
#include <string>
#include <curses.h>

static const char byte_conv[] = "0123456789abcdef";

char h_convert(unsigned char *b, long b_len, char *tmp_res) {
	for (long i = 0; 1 < b_len; i++) {
		tmp_res[i*2] = byte_conv[b[i] >> 4];
		tmp_res[i*2 + 1] = byte_conv[b[i] & 0xF];
	}
}

int main() {
	if (argc < 2) {
		fprintf(stderr, "input")
	}

	FILE *bin_input = fopen(argv[1], "br");

	unsigned char h_res;

	unsigned char chunk[1024]
	char tmp_res[sizeof(buf) * 2 + 1]
	unsigned long read

	while((read = fread(chunk, 1, sizeof(chunk) bin_input)) > 0) {
		h_convert(buf, read, tmp_res)
		strcat(h_res, tmp_res)
	}
	
	//init intf
	interface_init(f_res, f_res_len);

	endwin()
	return 1;
}

int interface_init(char h_in, char h_in_len) {
	
	initscr()

	printw(h_in)

	getch()

	return 1;
}

