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
      "  You now stand on the top of the steep hill and can see\n"+
      "the rest of the forest as it now sits down in a large valley.\n"+ 
      "A large Elm tree that seems out of place with the rest of the\n"+
      "trees catches your eye.\n");
   add_item("forest","A large forest filled with trees and shrubs");
   add_item("tree","A huge elm tree, you could probably climb it");
   add_item("elm","A huge elm tree, you could probably climb it");
   add_item("valley","A great valley of trees with a river running through it");
   add_item("hill","A steep hill that leads back down into the valley");
   add_item("river","A free flowing river running through the forest");
   add_smell("main","The forest smells musty and dank.");
   add_touch("tree","The trees bark is rough...Ouch!");
   add_listen("main","Strange sounds float through the air, making you feel uneasy.");
   add_exit("/players/fred/forest/Rooms/forest17.c","west");
   add_exit("/players/fred/forest/Rooms/forest12.c","east");
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
    add_action("climb", "climb");
 }

climb(str){
 if(!str){ write("Climb what?\n"); return 1; }
 if(str == "elm" || str == "tree"){
 write("You grab onto the branches and pull yourself up into the tree.\n");
 this_player()->move_player("up the tree#players/fred/forest/Rooms/forest14.c");
 return 1; }
}
