/* Preserved corpse - from the necro guild, used in the Bone Market
   -Daranath   */
#include <ansi.h>

string name;
int corpse_level;

reset() { }

set_name(n) { name = n; }

short() {
  if(!name) {
  set_name("an unknown victim"); }
  return "corpse of "+name+" ("+YEL+"preserved"+NORM+")";
}

long() {
write("The perfectly preserved corpse of "+name+".\n"+
       "The corpse is ready to be traded in for credit.\n");
}

id(str) {
  return str == "corpse" || str == "preserved corpse" || str == "preserved";
}

set_corpse_level(arg) {
  corpse_level = arg;
  return 1; 
}
query_weight() { return 1; }
query_value() { return 0; }
query_preserved() { return 1; }
get() {return 1; }

query_corpse_level() {return corpse_level; }

