/* Race-setter */
#include "/players/snow/color.h"
id(str) { return str == "racer"; }
short() { return "Racer"; }
init() { if(this_player()->query_real_name() == "snow") add_action("set_racer","racer"); }
set_racer(string str) {
  object ob;
  if(!str) { write("Racer who?\n"); return 1; }
  ob = find_player(str);
  if(!ob) { write(str+" is not online.\n"); return 1; }
  ob->set_race(BOLD+RED+"SandStorm"+OFF);
  write(str+" race set to "+BOLD+RED+"SandStorm"+OFF+"\n");
  return 1; }
