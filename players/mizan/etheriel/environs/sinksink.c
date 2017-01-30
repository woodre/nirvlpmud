id(str) { return str == "sink"; }
short() { return "The kitchen sink"; }
long() {
  write("This is THE kitchen sink. It's the thing that every American\n"+
	"brings along when they feel like packing too much for a trip.\n");
}
query_weight() { return 10; }
query_value() { return 100; }
