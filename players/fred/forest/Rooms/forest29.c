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
      "  The trees seem less dense here and walking becomes easier.\n"+
      "A run down cabin is nestled a small patch of foliage to your\n"+
      "right. There is a large flock of birds sitting in the trees\n"+
      "making noise overhead.\n");
   add_item("cabin","The door is missing and the windows are all broken.");
   add_item("trees","Huge trees that have been growing over the centuries");
   add_item("foliage","Large plants that grow wild around the area");
   add_item("birds","A flock of birds sitting comfortably in the trees");
   add_listen("main","The sound of birds chirping fills the air.");
   add_exit("/players/fred/forest/Rooms/forest28.c","northeast");
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
  if(!str){ write("Enter what?\n"); return 1; }
  if(id(str)){
  write("You cautiously enter the cabin.\n");
  this_player()->move_player("into the cabin#players/fred/forest/Rooms/forest30.c");
  return 1; }
}

movem(str){
 if(str == "ne" || str == "northeast"){
 say(tpn+ "leaves northeast.\n");
 this_player()->move_player("/players/fred/forest/Rooms/forest28.c");
 return 1; }
 }
