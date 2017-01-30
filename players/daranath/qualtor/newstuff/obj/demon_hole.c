#define tp this_player()->query_name()
#include <ansi.h>
inherit "obj/treasure";
reset(arg)
{   if (arg) return;

   set_id("demon_hole");
   set_alias("hole");
set_short(BOLD+BLK+"A dark hole torn in the roadway"+NORM);
set_long("A large hole has been torn into the roadway here, apparently from\n"+
         "within the ground itself, almost as if something clawed its way\n"+
         "into the city. Ash streams from the hole itself, spewing into\n"+
         "into the sky. This must be the source of the ash falling \n"+
         "over Qual'tor's Ghost Ward.\n\nYou can "+HIR+"descend"+NORM+" into the hole, if you dare.\n\n");
   set_weight(10000);
   set_value(1);
}

init()  {
  ::init();
  add_action("descend","descend");
        }

descend() {
if(present("golem")) {
write("The Ashen Golem prevents you from leaving down into the hole.\n");
return 1; }
  write("\nYou feel the heat of the ash beat against your face as you climb\n"+
        "down into the large hole.\n\n");
  this_player()->move_player("into the hole#players/daranath/qualtor/newstuff/rift.c");
return 1;
}

get()  { return 0; }
