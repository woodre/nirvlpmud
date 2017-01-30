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
      "  You now stand at the bottom of the deep ravine. Rocks cover the\n"+
      "area making everything look desolate. A patch of thick trees stand\n"+ 
      "off to the west.\n");
   add_item("rocks","Light gray rocks that form the ground you walk on");
   add_item("ravine","A large steep ravine");
   add_item("trees","Huge trees that have been growing over the centuries");
   add_listen("main","Strange sounds float through the air, making you feel uneasy.");
   add_exit("/players/fred/forest/Rooms/forest22.c","west");
   add_exit("/players/fred/forest/Rooms/forest6.c","south");
   add_exit("/players/fred/forest/Rooms/forest9.c","east");
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
