inherit "/players/vertebraker/closed/std/room.c";
#include "../../defs.h"
#include "../../room_funcs.h"

reset(arg) {
   if(arg) return;
   set_light(1);
   set_short("Clan Hall - generic room");
   set_long("generic clan hall room.\n");
   add_property("NT");
   restore_me();
}

init()
{
   ::init();
   check_valid_entry();
}

query_cost() { return 10000; }
