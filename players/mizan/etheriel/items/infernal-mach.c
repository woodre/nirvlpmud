id(str) { return str == "book"; }
short() { return "A copy of The Infernal Machine"; }
long() {
  write("This is a book written by the multi-talented Jean Cocteau.\n"+
	"You should read this book if you like eccentric and uniquely\n"+
	"written plays. (not this! Go out and buy the book! :)\n");
}
get() { return 1; }
query_weight() { return 1; }
query_value() { return 100; }
