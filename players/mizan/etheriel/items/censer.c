id(str) { return str == "censer"; }
short() { return "A smoky censer"; }
long() { write("This is an ordinary censer, but it is bejewelled with a\n"+
	"magnificent quartz headstone, and constantly emits a soft, silky,\n"+
	"cloudlike vapor.\n"); }
get() { return 1; }
query_weight() { return 2; }
query_value() { return 700; }
