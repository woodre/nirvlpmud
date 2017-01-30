inherit "/players/vertebraker/closed/std/room.c";
#include "../../defs.h"
#include "../../room_funcs.h"

reset(arg) {
   if(arg) return;
   set_light(1);
   set_short("Clan Hall - portals room");
   set_long("clan hall portal room.\n");
   add_property("NT");
   restore_me();
   set_no_clean(1);
   add_exit("/room/vill_green","green");
   add_exit("/players/saber/ryllian/portal","portal_room");
   add_exit("/room/vill_green","my_login");
}

init()
{
   ::init();
   check_valid_entry();
   add_action("my_login","my_login");
}

int my_login()
{
  say(TP->query_name() + " leaves to their login room.\n");
  move_object(TP,(string)TP->query_home());
  "/bin/play/_look"->cmd_look();
  return 1;
}

query_cost() { return 150000; }
