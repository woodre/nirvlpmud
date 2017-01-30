id(str) { return str == "torch" || str == "Mi002033"; }
short() { return "A pocket-sized butane torch"; }
long() {
  write("This thing is used to light really big cigars and minor\n"+
	"welding jobs.\n");
}
get() { return 1; }
query_weight() { return 1; }
query_value() { return 100; }
query_save_flag() { return 1; }
