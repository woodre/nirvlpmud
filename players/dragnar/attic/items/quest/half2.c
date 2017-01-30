id(str) { return str=="key" || str=="half2"; }
reset() {}
short() {
	return "A glowing key";
}
long() {
	write("Half of a magical key.\n");
}
query_save_flag() { return 1; }
get() { return 1; }
query_value() { return 20; }
