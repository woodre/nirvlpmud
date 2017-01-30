/* Basic preserved corpse for the Necromancer Guild.
   -Daranath   */

string name;
int corpse_level;

reset() { }

set_name(n) { name = n; }

short() {
  if(!name) {
  set_name("an unknown victim"); }
  return "corpse of "+name+" (preserved)";
}

long() {
write("The perfectly preserved corpse of "+name+".\n"+
       "The corpse is ready for harvesting.\n");
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
get() {return 1; }

query_corpse_level() {return corpse_level; }

