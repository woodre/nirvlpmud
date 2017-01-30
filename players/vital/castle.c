#include "/players/vertebraker/closed/CastleDefs.h"
#include "/players/vertebraker/closed/load_object.h"

#define NAME "Vital"
#undef DEST
#define DEST "room/mount_top"

/*
Vital's Place on the Mud
*/

id(str) { return str == "spaceport"; }

short() {
   return "A Large Spaceport";
}

long() {
   write("  This is the largest spaceport you have ever seen. It \n\
      may even be the only spaceport you have ever seen. If you \n\
      continue on up the mountain you will reach it.\n");
}

init() {
  add_action("move_up", "up");
  add_action("move_up", "u");
}

move_up(str) {
   say(capitalize(this_player()->query_name())+
      " climbs on up the mountain to the very top.\n");
   this_player()->move_player( 
      "up the mountain#/players/vital/dest/spaceport/rooms/enter.c");
   write_file("/players/vital/dest/spaceport/save/travel.log",
      ctime(time())+this_player()->query_name()+
      ": lvl="+this_player()->query_level()+
      ", coins="+this_player()->query_money()+".\n"); 
   say(capitalize(this_player()->query_name())+" arrives.\n");
   return 1;
}

reset(arg) {
   object obj;
   if (arg)
      return;
   move_object(this_object(), DEST);
   destruct(clone_object("/players/vital/closed/tool/p.c"));
   /*
   destruct(clone_object("/players/vital/Rangers/HonorRangerCommunicator.c"));
   */
   destruct(clone_object("/players/guilds/Rangers/HonorRangerCommunicator.c"));
   destruct(clone_object("/players/guilds/Rangers/RangerCommunicator.c"));
   /*
   destruct(clone_object("/players/vital/Rangers/RangerCommunicator.c"));
   */
   /*     destruct(clone_object("/players/vital/closed/meta/obj.c")); */
   
}
is_castle(){return 1;}

