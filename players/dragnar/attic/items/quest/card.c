id(str) { return str=="card" || str=="scicard"; }
short() {
	return "An autorization card";
}
long() {
	write("It has a picture of the scientist, only he looks much younger in it.\n"+
"it says 'USA GOVERNMENT' across the top, and it has a type of hologram\n"+
"over the whole thing that you have never seen before.\n");
}
query_save_flag() { return 1; }
get() { return 1; }
