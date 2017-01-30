#include "/players/fred/ansi.h"
inherit "/players/vertebraker/closed/std/room";
#define tp this_player()
#define tpn this_player()->query_name()

reset(int arg)
{
   if(arg) return;
   set_light(1);
   set_short(BOLD+"CRaZed FoReSt"+NORM);
   set_long(
      "  Within the confines of the trees light is clearly visible.\n"+
      "Several arrows stick out of some of the larger branches. As \n"+
      "you look around you realize how high up you are. Be careful\n"+
	"you wouldn't want to fall!\n");
   add_item("arrows","A small arrow that is embedded into the tree");
   add_item("branches","They are strong and sturdy");
   add_item("trees","Huge trees that have been growing over the centuries");
   add_touch("trees","The trees bark is rough...Ouch!");
   add_listen("main","Strange sounds float through the air, making you feel uneasy.");
   add_exit("/players/fred/forest/Rooms/forest14.c","west");
   add_object("/players/fred/forest/Mon/monkey.c");
}

