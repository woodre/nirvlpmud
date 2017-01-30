#include "/players/fred/ansi.h"
inherit "/players/vertebraker/closed/std/room";
#define tp this_player()
#define tpn this_player()->query_name()

reset(int arg)
{
   if(arg) return;
   set_light(1);
   set_short(BOLD+"CRaZed PoNd"+NORM);
   set_long(
      "  You are surrounded by icy cold water and it's hard to think\n"+
      "clearly. Small plants are growing on the bottom of the pond. It\n"+ 
      "looks like the only way to get out of here is to 'swim'.\n");
   add_item("water","Sparkling blue water");
   add_item("plants","Small green plants gently sway back and forth from the current");
   add_object("/players/fred/forest/Mon/pbcarp.c");
   add_object("/players/fred/forest/Mon/pbcarp.c");
}

init(){
 ::init();
  add_action("swim", "swim");
 }

swim(){
  write("You swim to the top of the water and climb out of the pond.\n");
  this_player()->move_player("to the top of the pond#players/fred/forest/Rooms/forest21.c");
  return 1; }
