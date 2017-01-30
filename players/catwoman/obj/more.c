#define mmore "nmore"
/*
#include "soul_com.c"
*/
#define CHUNK 16
static string more_file;
static int more_line;
nmore(str) {
	if (!str)
		return 0;
	more_file = str;
	more_line = 1;
	if (cat(more_file, more_line, CHUNK) == 0) {
		write("No such file\n");
		return 1;
	}
	input_to("even_more");
	write("More:  (line " + (CHUNK + 1) + ")  ");
	return 1;
}
static even_more(str){
	if (str == "" || str == "d")
		more_line += CHUNK;
	else if (str == "q") {
		write("Ok.\n");
		return;
	} else if (str == "u") {
		more_line -= CHUNK;
		if (more_line < 1)
		    more_line = 1;
	}
	if (cat(more_file, more_line, CHUNK) ==0) {
		more_file =0;
		write("EOF\n");
		return;
	}
	write("More:  (line " + (more_line + CHUNK) + ")  ");
	input_to("even_more");
}

