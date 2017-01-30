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
      "   As you trudge through the thick forest you come across a deep\n"+
      "ravine. Large boulders protrude from the ground making it difficult\n"+ 
      "to pass. A murder of crows scream from within the trees.  You feel\n"+
      "uneasy.\n");
   add_item("forest","A large forest filled with trees and shrubs");
   add_item("ravine","A large steep ravine that jets downward");
   add_item("boulders","Really BIG rocks");
   add_item("trees","Large trees that block out the sun");
   add_item("ground","Hard packed dirt");
   add_item("crows","You can't spot them within the trees");
   add_item("shrubs","Small bushes that fill the forest");
   add_smell("main","The forest smells musty and dank.");
   add_touch("trees","The trees bark is rough...Ouch!");
   add_listen("main","Strange sounds float through the air, making you feel uneasy.");
   add_exit("/players/fred/forest/Rooms/forest23.c","west");
   add_exit("/players/fred/forest/Rooms/forest10.c","north");
   add_exit("/players/fred/forest/Rooms/forest5.c","south");
   add_exit("/players/fred/forest/Rooms/forest11.c","east");
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
