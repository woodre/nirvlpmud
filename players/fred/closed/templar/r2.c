inherit "/players/vertebraker/closed/std/room";
#include <ansi.h>


reset(int arg)
{
   if(arg) return;
   set_light(1);
   set_short(BOLD+"Cave Entrance"+NORM);
   set_long(
      "  In front of you is the mouth of a very large cave.  Large\n"+
      "jagged rocks jut up from the earth casting dark shadows on the\n"+
      "ground.  Scorched pieces of armor and a few old rusted weapons\n"+
      "are scattered around on the ground.  \n");
   add_item("cave","A dark cave....");
   add_item("mouth","A huge opening leading into the cave.");
   add_item("rocks","Sharp jagged rocks.");
   add_item("ground","The ground is made of of smaller rocks.");
   add_item("shadows","Dark lingering shadows making it ahard to see.");
   add_item("armor","Various pieces of armor that are scorched and broken.");
   add_item("weapons","Old rusted weapons.....whose are they?");
   set_chance(5);
   add_msg("A loud rumbling sound escapes from the mouth of the cave.\n");
   add_msg("A small burst of flame from inside the cave casts a glimpse of light.\n");
   add_exit("/players/fred/closed/templar/r3.c","enter");
   add_exit("/players/jaraxle/templar/rooms/quest.c","back");
}

