id(str) { return str == "opener"; }
short() { return "A can opener (broken)"; }
long() {
  write("This was once a perfectly functional can opener, but the blade has\n"+
	"been mangled beyond repair.\n");
}
get() { return 1; }
query_value() { return 1; }
query_weight() { return 1; }
