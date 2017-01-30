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
      "  The path widens as you walk into a large clearing. Fallen trees\n"+
      "are all around you now with few trees remaining standing. Sounds fill\n"+ 
      "the forest making you hesitant to continue on. Something makes you \n"+
      "feel uneasy.\n");
   add_item("forest","A large forest filled with trees and shrubs");
   add_item("shrubs","Small shrubs blanket the forest floor");
   add_item("trees","Large trees that have fallen over through the years");
   add_item("leaves","Leaves rustle free from the trees and slowly float to the ground");
   add_item("path","The path cuts through the forest making movement possible");
   add_smell("main","The forest smells musty and dank.");
   add_touch("trees","The trees bark is rough...Ouch!");
   add_listen("main","Strange sounds float through the air, making you feel uneasy.");
   add_exit("/players/fred/forest/Rooms/forest13.c","east");
   add_exit("/players/fred/forest/Rooms/forest18.c","west");
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
