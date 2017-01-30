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
      "  The trees are thinner here and light flows through the leaves\n"+
      "lighting the beaten path. A rotting log with moss growing on it\n"+
      "sits off to the side of the path. The path widens to the south.\n");
   add_item("forest","A large forest filled with trees and shrubs");
   add_item("shrubs","Small shrubs blanket the forest floor");
   add_item("trees","Large trees that have been growing over the ages");
   add_item("leaves","Leaves rustle free from the trees and slowly float to the ground");
   add_item("path","A small path that cuts through the forest");
   add_item("light","Streams of light that flow through the canopy of trees");  
   add_item("log","A large log with moss growing all over it");
   add_item("moss","Greenish goo..."); 
   add_smell("main","The forest smells musty and dank.");
   add_touch("trees","The trees bark is rough...Ouch!");
   add_listen("main","Strange sounds float through the air, making you feel uneasy.");
   add_exit("/players/fred/forest/Rooms/forest6.c","east");
   add_exit("/players/fred/forest/Rooms/forest22.c","north");
   add_exit("/players/fred/forest/Rooms/forest24.c","south");
   set_chance(3);
   add_msg("You feel something brush against your leg...\n");
   add_msg("The hairs on your neck stand on end...\n");
}

cmd_search(str)
{
   if(str == "log")
      {
      write("As you bend down to search the log a large snake slithers out.\n");
      move_object(clone_object("/players/fred/forest/Mon/snake.c"), 
      this_object()); 
    return 1; 
   }
   else {
   write("Search what?\n");
   return 1; }
}

init(){
 ::init();
  if(this_player() && !random(15)){
    if(!present("squirrel_id", this_object())){
    move_object(clone_object("/players/fred/forest/Mon/psquirrel.c"), this_object()); }
    tell_room(this_object(),
    "A Squirrel parachutes into the room!\n"); } 
 }
