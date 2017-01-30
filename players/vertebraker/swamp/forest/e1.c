#include "../define.h"
inherit ROOM;

reset(arg) {
   if(arg) return;
   set_light(1);
   set_short("A dimly lit forest");
   set_long(
"     The dim forest extends here, and hovers around a single cleared\n"+
"dirt path that winds through the forest to the west.  Several tall\n"+
"sequoias stand as guardians through this part of the forest, and\n"+
"you sense animal life all around you, but see nothing.\n");
   set_chance(5);
   add_msg("You swat a gnat away from your face.");
   add_msg("A squirrel chitters at you and then runs back into the forest.");
   add_msg(
      "*caw! caw*");
   add_msg("*tweet tweet*");
   add_item("forest","The dim forest here is extended both east\n"+
      " and west, though the path starts here");
   add_item("sequoias","Massive sequoias stand like sentries against\n"+
      " the peaceful backdrop of the forest");
   add_item(({"path","dirt path"}),"The cleared dirt path seems to have been stamped out\n"+
      " by many human footsteps");
  add_exit("/players/vertebraker/castle/new/vortex","east");
   add_exit(FOREST+"e2","west"); }
