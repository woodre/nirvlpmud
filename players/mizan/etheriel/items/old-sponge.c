id(str) { return str == "sponge"; }
short() { return "An old, greasy sponge"; }
long() {
  write("This thing appears to have cleaned one too many dishes. \n"+
	"It is falling apart and is generally worthless.\n");
}
query_value() { return 25; }
query_weight() { return 1; }
