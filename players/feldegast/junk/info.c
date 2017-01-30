#include "/players/feldegast/defines.h"
inherit "obj/treasure";
reset(arg) {
  set_id("ball");
  set_alias("orb");
  set_short("Crystal Ball of Useless Information");
  set_long("A perfect sphere made out of crystal, with swirling mists\n"+
           "inside.  For some useless information, type 'ui'.\n");
  set_weight(0);
  set_value(-5000);
}
init() {
  if(this_player()->is_player() &&
     this_player()->query_level() < 20) destruct(this_object());
  add_action("cmd_ui","ui");
}
int cmd_ui(string str) {
  write("Call outs: ");
  write(sizeof(call_out_info())+"\n");
  write("Ranger pool: ");
  write("/players/beck/closed/Master"->QPowerPoints("Power Ranger"));
  write("\n");
  write("DRanger pool: ");
  write("/players/beck/DarkRangers/RangerMaster"->QPowerPoints());
  write("\n");
  return 1;
}
