#include "/players/fred/ansi.h"
inherit "/players/vertebraker/closed/std/room";
#define tp this_player()
#define tpn this_player()->query_name()

reset(int arg)
{
   if(arg) return;
   set_light(0);
   set_short(BOLD+"CRaZed FoReSt"+NORM);
   set_long(
      "  The tall trees grow up all around you. There is a free\n"+
      "flowing river off to the southeast.  A large tree stump is\n"+ 
      "sits in the middle of the path. Paths lead off in several\n"+
      "directions.\n");
   add_item("trees","Large trees that form a canopy over you");
   add_item("river","A free flowing river, it looks cold");
   add_item("stump","An old tree stump");
   add_item("path","A trail carved out of the forest");
   add_item("forest","A large forest of trees and shrubs");
   add_item("shrubs","Small bushes that fill the forest"); 
   add_smell("main","The forest smells musty and dank.");
   add_touch("trees","The trees bark is rough...Ouch!");
   add_listen("main","You hear water rushing in the distance");
   add_exit("/players/fred/forest/Rooms/forest5.c","east");
   add_exit("/players/fred/forest/Rooms/forest7.c","west");
   add_exit("/players/fred/forest/Rooms/forest23.c","north");
   add_exit("/players/fred/forest/Rooms/forest25.c","south");
   set_chance(3);
   add_msg("You feel something brush against your leg...\n");
   add_msg("The hairs on your neck stand on end...\n");
   add_object("/players/fred/forest/Mon/kfrabbit.c");
}

init(){
 ::init();
  if(this_player() && !random(15)){
    if(!present("squirrel_id", this_object())){
    move_object(clone_object("/players/fred/forest/Mon/psquirrel.c"), this_object()); }
    tell_room(this_object(),
    "A Squirrel parachutes into the room!\n"); } 
 }
