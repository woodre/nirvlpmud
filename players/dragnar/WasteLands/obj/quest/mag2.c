id(str) { return str=="key" || str=="mag2"; }
reset() {}
short() {
	return "A glowing key";
}
long() {
	write("A piece of a magical key.\n");
}
query_save_flag() { return 1; }
get() { return 1; }
query_value() { return 20; }
