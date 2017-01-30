id(str) { return str == "shaker"; }
short() { return "A salt shaker"; }
long() {
  write("This is an ordinary salt shaker. It appears to be stolen from\n"+
	"a cafeteria or something...\n");
}

get() { return 1; }
query_value() { return 10; }
