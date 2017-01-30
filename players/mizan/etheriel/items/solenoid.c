id(str) { return str == "solenoid"; }
short() { return "A broken solenoid"; }
long() {
  write("This is a broken electromechanical device. It looks \n"+
	"carbon-scored and burnt beyond repair.\n");
}
query_value() { return 10; }
query_weight() { return 2; }
