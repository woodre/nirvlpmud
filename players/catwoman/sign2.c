id (str) {return str== "notice";}
get () { return 0;}
query_weight() {return 200;}
query_value() { return 0;}
init() {
  add_action("read", "read");
  add_action("summon", "enter");

return;
}
read(str) {
int val;
   if(!str) {
   write("\n");
   return 1;
   }
   if (sscanf(str, "%d", val) !=1) {
   write("w?\n");
   return 1;
   }
   call_other(this_player(), "add_money", val);
   write("what?\n");
   return 1;
}
summon(str) {
object player,creature;
string name, junk, junk2;
int here_now;
 here_now = 1;
  if(!str) here_now = 0;
  if(here_now == 1) name = str;
  if(here_now == 1) player = find_living(lower_case(name));
  if(!player) {
  write("No player by that name.\n");
  return 1; }
  say(call_other(this_player(), "query_name") + "'s staff glows for a " +
  "moment then a figure assembles itself\nin front of you.\n");
  creature = clone_object("/players/catwoman/monster/dw2.c");
move_object(creature,environment(player));
  return 1;
}

