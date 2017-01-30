#include "/players/jaraxle/define.h"
inherit "/players/jaraxle/3rd/silence/rooms/silence.c";

reset(arg) {
   if(arg) return;
   set_light(1);
   long_desc =
   "\n"+
   ""+GRN+"\t@@@@@@@@@@@"+NORM+"\n"+
   ""+GRN+"\t@"+CYN+"#"+GRN+"@@@"+BLU+"X"+YEL+"####"+GRN+"@"+NORM+"\n"+
   ""+GRN+"\t@@@@"+YEL+"#"+GRN+"@@@@@@\n"+NORM+""+
   ""+RED+"\t$"+NORM+YEL+"#"+GRN+"@@"+YEL+"######"+HIM+"~"+NORM+"\n"+
   ""+GRN+"\t@"+YEL+"####"+GRN+"@@@@"+YEL+"#"+HIM+"~"+NORM+"\n"+
   ""+GRN+"\t@@@@"+YEL+"######"+HIM+"~"+NORM+"\n"+
   ""+GRN+"\t@"+YEL+"#"+GRN+"@@@@@"+YEL+"#"+GRN+"@@@"+NORM+"\n"+
   ""+GRN+"\t@"+YEL+"#"+GRN+"@@@"+YEL+"##"+GRN+"@@@@"+NORM+"\n"+
   ""+GRN+"\t@@"+YEL+"#####"+GRN+"@@@@"+NORM+"\n"+
   ""+GRN+"\t@@@@@@@@@@@\n"+NORM+"";
   items = ({
         "path","You stand on a grassy path that leads to the east.\nThere is a crossing to the west",
         "crossing","A grassy path that crosses to the west",
         "forest","A thick forest, full of trees",
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
add_action("southwest","southwest");
}

west(){
   write("The trees block the path to the west.\n"); 
   return 1; }

south(){
   write("The trees block the path to the south.\n"); 
   return 1; }

east(){
   write("You follow the path to the east.\n");
   this_player()->move_player("east#/players/jaraxle/3rd/silence/rooms/2G");
   return 1; }

north(){ write("The trees block the path to the north.\n"); return 1; }

southwest(){
write("You follow the path to the southwest.\n");
this_player()->move_player("east#/players/jaraxle/3rd/silence/rooms/3E");
return 1; }


search_me(str){
   if(!str){
write("Before you is a long thin path stretching\n"+
      "to the east. Trees line the path on both\n"+
      "sides.  To the southwest a meadow can be\n"+
      "seen through a split between two large trees\n");
      return 1; }
   write("You search the "+str+" and find nothing of intrest.\n");
   return 1; }
