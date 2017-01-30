inherit "/players/vertebraker/closed/std/room.c";
#include "../../defs.h"
#include "../../room_funcs.h"

reset(arg) {
   if(arg) return;
   set_light(1);
   set_short("Clan Hall - Owners room");
   set_long("generic clan hall room.\nowner only.\n");
   add_property("NT");
   restore_me();
   set_no_clean(1);
}

init()
{
   ::init();
   check_valid_entry();
}

query_owner_room() { return 1; }
query_cost() { return 100000; }
