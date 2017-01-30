#include "/players/fred/ansi.h"
inherit "/players/vertebraker/closed/std/room";
#define tp this_player()
#define tpn this_player()->query_name()

reset(int arg)
{
   if(arg) return;
   set_light(1);
   set_short(BOLD+BLK+"LoOpy ViLLaGe"+NORM);
   set_long(
      "  This the edge of the village. The streets are made of hard\n"+
      "packed dirt. A large looming forest is off to the west. Several\n"+ 
      "shops are off to the east.\n");
   add_item("streets","A long street running east and west");
   add_item("forest","A large dark forest. It's rumored to be filled with crazed animals");
   add_item("dirt","Packed hard dirt forms the road");
   add_listen("main","You can hear children laughing off in the distance.");
   add_exit("/players/fred/forest/Rooms/vill_1.c","west");
   add_exit("/players/fred/forest/Rooms/vill_3.c","east");
   add_object("/players/fred/forest/Mon/tdrunk.c");
}

