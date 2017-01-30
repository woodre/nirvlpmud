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
      "  The path comes to an opening in the forest where the\n"+
      "trees and shrubs aren't nearly as thick. You notice a cave\n"+ 
      "off to the side and feel warm air as it rushes past you\n"+
      "from within.\n");
   add_item("forest","A large forest filled with trees and shrubs");
   add_item("shrubs","Small shrubs blanket the forest floor");
   add_item("trees","Huge trees that have been growing over the centuries");
   add_item("leaves","Leaves rustle free from the trees and slowly float to the ground");
   add_item("cave","A larger cave, it looks inviting");
   add_item("path","A small path cut through the forest by other travellers");
   add_smell("main","The forest smells musty and dank.");
   add_touch("trees","The trees bark is rough...Ouch!");
   add_listen("main","Strange sounds float through the air, making you feel uneasy.");
   add_exit("/players/fred/forest/Rooms/forest27.c","northwest");
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
    add_action("enter", "enter");
  }

enter(str){
  if(!str){ write("What would you like to enter?\n"); return 1; }
  if(str == "cave"){
  write("You walk into the cave.\n");
  this_player()->move_player("into the cave#players/fred/forest/Rooms/forest32.c");
    return 1; }
}
