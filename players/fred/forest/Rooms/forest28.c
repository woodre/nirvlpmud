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
      "  The path that you once followed now disappears within the\n"+
      "thick foliage of the forest. You are not sure where you are\n"+
      "anymore and look around for any sign of where to go. A path\n"+
      "leads back to the east. Strange noises fill the air.\n");
   add_item("forest","A large forest filled with trees and shrubs");
   add_item("shrubs","Small shrubs blanket the forest floor");
   add_item("trees","Huge trees that have been growing over the centuries");
   add_item("foliage","Large plants that grow wild around this area");
   add_item("path","A small path from other travellers");
   add_smell("main","The forest smells musty and dank.");
   add_touch("trees","The trees bark is rough...Ouch!");
   add_listen("main","Strange sounds float through the air, making you feel uneasy.");
   add_exit("/players/fred/forest/Rooms/forest26.c","east");
   set_chance(3);
   add_msg("You feel something brush against your leg...\n");
   add_msg("The hairs on your neck stand on end...\n");
}

cmd_search(str)
{
   if(str == "forest")
      {
      write("A path opens up to the southwest.\n");
      write("Perhaps you could walk down it.\n");
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
   add_action("walk", "walk");
  }

walk(str){
  if(str == "path" || str == "down path"){
  write("You walk down the path.\n");
  this_player()->move_player("down the path#players/fred/forest/Rooms/forest29.c");
  return 1; }
}
