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
      "  The the once flat forest slowly turns into roaming hills.\n"+
      "The hills are steep and long with large trees and thick\n"+
      "vegetation surrounding you. You continue to push through\n"+
      "the forest in search of adventure.\n");
   add_item("forest","A large forest filled with trees and shrubs");
   add_item("shrubs","Small shrubs blanket the forest floor");
   add_item("trees","Huge trees that have been growing over the centuries");
   add_item("vegetation","Large plants that grow wild in the forest");
   add_item("hills","Long steep flowing hills that make movement tiring");
   add_item("leaves","Leaves rustle free from the trees and slowly float to the ground");
   add_smell("main","The forest smells musty and dank.");
   add_touch("trees","The trees bark is rough...Ouch!");
   add_listen("main","Strange sounds float through the air, making you feel uneasy.");
   add_exit("/players/fred/forest/Rooms/forest12.c","north");
   add_exit("/players/fred/forest/Rooms/forest9.c","south");
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
