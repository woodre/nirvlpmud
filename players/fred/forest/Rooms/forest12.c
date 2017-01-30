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
      "  The path continues up the side of the steep hill. The forest\n"+
      "is less sparse here as you near the top of the hill. Several \n"+
      "fallen trees lay near your feet as you continue your trek.\n");

   add_item("forest","A large forest filled with trees and shrubs");
   add_item("shrubs","Small shrubs blanket the forest floor");
   add_item("trees","Large trees that fell down over the years");
   add_item("hill","A steep hill that leads up to a plateau");
   add_item("plateau","A large flat plateau at the top of the hill");
   add_smell("main","The forest smells musty and dank.");
   add_touch("trees","The trees bark is rough...Ouch!");
   add_listen("main","Strange sounds float through the air, making you feel uneasy.");
   add_exit("/players/fred/forest/Rooms/forest13.c","west");
   add_exit("/players/fred/forest/Rooms/forest10.c","south");
   add_exit("/players/fred/forest/Rooms/forest39.c","northeast");
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
