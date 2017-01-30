#include "/open/ansi.h"
#define tp this_player()
#define tpn this_player()->query_name()
#define tpp this_player()->query_possessive()
inherit "room/room";

status rock;

reset(arg) {
rock = 1;

   if(arg) return;
   set_light(0);
   
   short_desc = MAG+"Kadath"+NORM;
   long_desc =
   "     The cemetary is a stupendous vista of cyclopean stone towers.\n"+
   "The tombs are covered with rocks of different sizes.  In the middle\n"+
   "of the cemetary is a monolith, as high as the eye can see.  A black\n"+
   "doorway is at the base.\n";
 
   items = ({
         "towers","The towers are huge and made of stone",
         "doorway","The doorway is 30 feet high",
         "grave","The grave is covered with rocks",
         "steps","Huge stone steps are south of here",
         "monolith","A stone of considerable size, that is shaped into a pyramidal apex",
         "cemetary","Tombs of different sizes are all over the cemetary",
         "tombs","The tombs are covered with rocks over each grave site",
         "rocks","The rocks are different sizes, one rock over one grave is oddly shaped.",
         "rock","The rock is oddly shaped and looks like it could be 'move'",
          });
 
   dest_dir = ({
         "/players/brittany/kadath/k27.c","east",
         "/players/brittany/kadath/k33.c","doorway",
          });
 
}
 
  init(){
  ::init();
   add_action("search","search");
   add_action("move_rock","move");
   add_action("doorway","doorway");
}
 
search(){
  notify_fail("You find nothing of interest.\n");
  return 0;
}

move_rock(str){
   if(!str ||  str != "rock") {
   notify_fail("What do you want to move?\n");
   return 0; }
 
   if(rock) {
 write("You move the rock and the tomb begins to shake.\n\n"+
   ""+HIR+"Something HUGE appears out of tomb."+NORM+"\n");
   move_object(clone_object("/players/brittany/kadath/NPC/gugs.c"),this_object());
     rock = 0;
   }
   else write("Nothing happens.\n");
   return 1; }

doorway(str){
   write("You enter the doorway.\n\n");
   say(tpn+" ENTERS the doorway.\n");
  tp->move_player("vault#/players/brittany/kadath/k33.c");
  return 1; }
