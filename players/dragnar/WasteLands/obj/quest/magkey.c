id(str) { return str=="key" || str=="magkey"; }
reset() {}
short() {
	return "A glowing magical key";
}
long() {
	write("The key seems to give off a bright light, it is difficult to look at it for\n"+
"a long period of time.\n");
}
query_save_flag() { return 1; }
get() { return 1; }
query_value() { return 20; }
