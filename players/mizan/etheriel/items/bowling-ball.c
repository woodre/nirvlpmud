id(str) { return str == "ball"; }
short() { return "A broken bowling ball"; }
long() {
  write("Eep. These things are very hard to break. Nonetheless, this indeed\n"+
	"is a _broken_ bowling ball. Pretty useless, eh?\n");
}
query_weight() { return 5; }
query_value() { return 60; }
