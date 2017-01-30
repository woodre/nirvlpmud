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
      "  You pass through a clearing and a large pond spreads out in\n"+
      "front of you. The water is clean and clear as light beams reflect\n"+ 
      "off of it as they pass through the trees.\n");
   add_item("water","Sparkling blue water");
   add_item("pond","It looks like there is something in the water, maybe you could dive into it");
   add_item("trees","Huge trees that have been growing over the centuries");
   add_item("light","Beams of light are almost blinding");
   add_item("rocks","Large rocks that have algae growing on them");
   add_item("algae","Green slimy gunk");
   add_smell("main","The air is cool and crisp here.");
   add_touch("water","The water is cold to the touch.....BRRr!!");
   add_touch("algae","It squishes between your fingers...YUCK!!");
   add_listen("main","Waves are splashing against the rocks.");
   add_exit("/players/fred/forest/Rooms/forest22.c","east");
   add_exit("/players/fred/forest/Rooms/forest40.c","west");
   set_chance(3);
   add_msg("Water sprays on your face as it splashes against the rocks...\n");
   add_object("/players/fred/forest/Mon/flamin.c");
   add_object("/players/fred/forest/Mon/flamin.c");
}

init(){
 ::init();
  if(this_player() && !random(15)){
    if(!present("squirrel_id", this_object())){
    move_object(clone_object("/players/fred/forest/Mon/psquirrel.c"), this_object()); } 
    tell_room(this_object(),
    "A Squirrel parachutes into the room!\n"); } 
  add_action("dive", "dive");
 }

dive(str){
  if(!str){ write("Dive what?\n"); return 1; }
  if(str == "into pond" || str == "pond"){
  write("You dive into the cold pond!\n");
  this_player()->move_player("into the pond#players/fred/forest/Rooms/forest8.c");
  return 1; }
}
