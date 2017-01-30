id(str) { return str == "bottle"; }
short() { return "A bottle of dehydrated water"; }
long() {
  write("This is a bottle of dehydrated water.\n"+
	"It is empty.\n");
}
get() { return 1; }
query_save_flag() { return 1; }
query_weight() { return 1; }
