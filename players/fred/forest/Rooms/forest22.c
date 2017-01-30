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
      "  The trees are especially thick here blocking out all light.\n"+
      "This part of the forest has never been fully explored. The sounds\n"+ 
      "of water can be heard off in the distance.\n");
   add_item("forest","A large forest filled with trees and shrubs");
   add_item("shrubs","Small bushes that fill the forest");
   add_item("trees","Huge trees that have been growing over the centuries");
   add_smell("main","The forest smells musty and dank.");
   add_touch("trees","The trees bark is rough...Ouch!");
   add_listen("main","You hear water off in the distance.");
   add_exit("/players/fred/forest/Rooms/forest21.c","west");
   add_exit("/players/fred/forest/Rooms/forest7.c","south");
   add_exit("/players/fred/forest/Rooms/forest23.c","east");
   set_chance(3);
   add_msg("You feel something brush against your leg...\n");
   add_msg("The hairs on your neck stand on end...\n");
   add_object("/players/fred/forest/Mon/wchuck.c");
}

init(){
 ::init();
  if(this_player() && !random(15)){
    if(!present("squirrel_id", this_object())){
    move_object(clone_object("/players/fred/forest/Mon/psquirrel.c"), this_object()); } 
    tell_room(this_object(),
    "A Squirrel parachutes into the room!\n"); } 
 }
