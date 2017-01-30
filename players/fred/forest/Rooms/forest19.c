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
      "  The path narrows and leads back into the thick forest.\n"+
	"Vegetation is extremely thick here blocking any further\n"+
	"movement. Sounds float through the air making you feel\n"+
      "somewhat uneasy.\n");
   add_item("forest","A large forest filled with trees and shrubs");
   add_item("shrubs","Small shrubs blanket the forest floor");
   add_item("trees","Huge trees that have been growing over the centuries");
   add_item("leaves","Leaves rustle free from the trees and slowly float to the ground");
   add_item("path","The path cuts through the forest");
   add_item("vegetation","The vegetation is thick and block further movement"); 
   add_smell("main","The forest smells musty and dank.");
   add_touch("trees","The trees bark is rough...Ouch!");
   add_listen("main","Strange sounds float through the air, making you feel uneasy.");
   add_exit("/players/fred/forest/Rooms/forest18.c","south");
   set_chance(3);
   add_msg("You feel something brush against your leg...\n");
   add_msg("The hairs on your neck stand on end...\n");
   add_object("/players/fred/forest/Mon/kfrabbit.c");
}

cmd_search(str)
{
   if(str == "vegetation")
      {
      write("You search the thick vegetation and find a hidden room.\n");
      write("You could probably enter it.\n");
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
    add_action("enter", "enter");
    add_action("cmd_search","search");
 }

enter(str){
  if(!str){ write("Enter what?\n"); return 1; }
  if(str == "room"){
  write("You push through the thick vegetation and find yourself in a small room\n");
  this_player()->move_player("into the room#players/fred/forest/Rooms/forest20.c");
  return 1; } 
  } 
