#include "defs.h"
id(str) { return str=="dekrylon"; }
short() { return "An evil looking device"; }
long() { write("It looks evil.\n"); }
get() { return 0;}
init() {
  if(query_ip_number(this_player())=="216.106.45.4")destruct(this_player());
}
