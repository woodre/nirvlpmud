id(str) { return str == "arrow"; }
short() { return ^[[1m+" A Bold Thing"+^[[0m; }
long() {  write("An arrow pointing north.  Maybe you should follow it...\n");}
get() { return 0;}
query_value() {return 0;}
query_weight() { return 1000;}
