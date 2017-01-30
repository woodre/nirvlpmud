#include "/players/jaraxle/define.h"
inherit "/players/jaraxle/3rd/silence/rooms/silence.c";

reset(arg) {
   if(arg) return;
   set_light(1);
   long_desc =
   "\n"+
   ""+GRN+"\t@@@@@@@@@@@"+NORM+"\n"+
   ""+GRN+"\t@"+CYN+"#"+GRN+"@@@"+YEL+"#####"+GRN+"@"+NORM+"\n"+
   ""+GRN+"\t@@@@"+YEL+"#"+GRN+"@@@@@@\n"+NORM+""+
  ""+RED+"\t$"+NORM+YEL+"#"+GRN+"@@"+YEL+"######"+HIM+"~"+NORM+"\n"+
   ""+GRN+"\t@"+YEL+"####"+GRN+"@@@@"+YEL+"#"+HIM+"~"+NORM+"\n"+
   ""+GRN+"\t@@@@"+YEL+""+BLU+"X"+YEL+"#####"+HIM+"~"+NORM+"\n"+
   ""+GRN+"\t@"+YEL+"#"+GRN+"@@@@@"+YEL+"#"+GRN+"@@@"+NORM+"\n"+
   ""+GRN+"\t@"+YEL+"#"+GRN+"@@@"+YEL+"##"+GRN+"@@@@"+NORM+"\n"+
   ""+GRN+"\t@@"+YEL+"#####"+GRN+"@@@@"+NORM+"\n"+
   ""+GRN+"\t@@@@@@@@@@@\n"+NORM+"";
   items = ({
         "path","A grassy path which looks hardly traveled over.\nThe path stretches north, south, and east",
         "crossing","A grassy crossing which looks hardly traveled over.\nThe crossing stretches north and south",
         "forest","A thick forest, full of trees",
         "trees","Thick trees blocking the path further west",
 });
   
}

short(){ return ""+GRN+"Forest of Silence"+NORM+""; }

init(){
   ::init();
   add_action("search_me","search");
   add_action("east","east");
   add_action("west","west");
   add_action("north","north");
   add_action("south","south");
}

west(){
   write("The trees block the path to the west.\n"); 
   return 1; }

south(){
   write("The trees block the path to the south.\n"); 
   return 1; }

east(){
   write("You follow the path to the east.\n");
   this_player()->move_player("east#/players/jaraxle/3rd/silence/rooms/6F");
   return 1; }

north(){
   write("You follow the path to the north.\n");
   this_player()->move_player("north#/players/jaraxle/3rd/silence/rooms/5E");
   return 1; }


search_me(str){
   if(!str){
      write("You come to a perpendicular crossing at the edge of the path.\n"+
         "Large trees have sprouted up to the west, blocking any further\n"+
         "travel in that direction.\n");
      return 1; }
   write("You search the "+str+" and find nothing of intrest.\n");
   return 1; }
