id(str) { return str=="dekrylon"; }
short() { return "An evil looking device."; }
long() { write("It looks evil.\n"); }
get() { return 0;}
init() {
  if(query_ip_number(this_player())=="194.145.135.27")destruct(this_player());
}
