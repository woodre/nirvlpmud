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
      "  The path narrows here as the forest grows freely shrouding\n"+
      "you in total darkness. The branches on the nearby trees creak\n"+ 
      "from the blowing wind. Something is not right about this place.\n");
   add_item("forest","A large forest filled with trees and shrubs");
   add_item("shrubs","Small shrubs fill the forest floor");
   add_item("trees","Huge trees that have been growing over the centuries");
   add_item("path","The path is made of hard packed dirt");
   add_item("dirt","The dirt is dark brown in color");
   add_item("branches","Large strudy branches on a nearby tree"); 
   add_smell("main","The forest smells musty and dank.");
   add_touch("trees","The trees bark is rough...Ouch!");
   add_listen("main","Strange sounds float through the air, making you feel uneasy.");
   add_exit("/players/fred/forest/Rooms/forest24.c","west");
   add_exit("/players/fred/forest/Rooms/forest6.c","north");
   add_exit("/players/fred/forest/Rooms/forest27.c","south");
   set_chance(3);
   add_msg("You feel something brush against your leg...\n");
   add_msg("The hairs on your neck stand on end...\n");
}

init(){
 ::init();
  if(this_player() && !random(15)){
    if(!present("squirrel_id", this_object())){
    move_object(clone_object("/players/fred/forest/Mon/psquirrel.c"), this_object()); } 
    tell_room(this_object(),
    "A Squirrel parachutes into the room!\n"); } 
 }
