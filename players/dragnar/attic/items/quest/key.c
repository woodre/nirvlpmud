id(str) { return str=="key" || str=="cultkey"; }
reset() {}
short() {
	return "A key";
}
long() {
	write("A key from the darkside cult.\n");
}
get() { return 1; }
query_value() { return 20; }
query_save_flag() { return 1; }
