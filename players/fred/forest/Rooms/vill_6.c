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
      "  You are now in the main portion of the village. The \n"+
      "streets are made of hard packed dirt. Several shops line\n"+
      "the streets here. There is a weapons shop off to the south.\n");
   add_item("streets","A long street running east and west");
   add_item("dirt","Packed hard dirt forms the road");
   add_item("shops","Old run down shops that supply the village with goods");
   add_listen("main","You can hear children laughing in the distance.");
   add_exit("/players/fred/forest/Rooms/vill_5.c","west");
   add_exit("/players/fred/forest/Rooms/vill_7.c","east");
   add_exit("/players/fred/forest/Rooms/wshop.c","south");
}

