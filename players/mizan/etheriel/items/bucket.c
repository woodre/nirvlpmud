id(str) { return str == "bucket"; }
short() { return "An empty bucket"; }
long() {
  write("This is an empty green bucket. It looks like it was once used\n"+
	"to hold used motor oil. Pleasant.\n");
}
get() { return 1; }
query_weight() { return 1; }
query_value() { return 10; }
