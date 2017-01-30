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
   ""+GRN+"\t@"+YEL+"###"+BLU+"X"+GRN+"@@@@"+YEL+"#"+HIM+"~"+NORM+"\n"+
  ""+GRN+"\t@@@@"+YEL+"######"+HIM+"~"+NORM+"\n"+
   ""+GRN+"\t@"+YEL+"#"+GRN+"@@@@@"+YEL+"#"+GRN+"@@@"+NORM+"\n"+
   ""+GRN+"\t@"+YEL+"#"+GRN+"@@@"+YEL+"##"+GRN+"@@@@"+NORM+"\n"+
   ""+GRN+"\t@@"+YEL+"#####"+GRN+"@@@@"+NORM+"\n"+
   ""+GRN+"\t@@@@@@@@@@@\n"+NORM+"";
   items = ({
         "path","A grassy path which looks well traveled over.\nThe path stretches north, south, and west",
         "forest","A thick forest, full of trees",
         "trees","Thick trees blocking the path further east",
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

east(){
   write("The trees block the path to the east.\n"); 
   return 1; }

south(){
   write("You follow the path to the south.\n");
  this_player()->move_player("south#/players/jaraxle/3rd/silence/rooms/6E");
   return 1; }

west(){
   write("You follow the path to the west.\n");
   this_player()->move_player("west#/players/jaraxle/3rd/silence/rooms/5D");
   return 1; }

north(){
   write("You follow the path to the north.\n");
   this_player()->move_player("north#/players/jaraxle/3rd/silence/rooms/4E");
   return 1; }


search_me(str){
   if(!str){
write("The path opens wide up in almost every single\n"+
      "direction.  The northern and southern paths\n"+
      "bend back to the east.  While a lone path \n"+
      "stretches out to the west.\n");
      return 1; }
   write("You search the "+str+" and find nothing of intrest.\n");
   return 1; }
