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
   ""+RED+"\t$"+NORM+YEL+"#"+GRN+"@@"+YEL+"#"+BLU+"X"+YEL+"####"+HIM+"~"+NORM+"\n"+
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
}

west(){
   write("You follow the path to the west.\n");
   this_player()->move_player("west#/players/jaraxle/3rd/silence/rooms/4E");
   return 1; }

south(){
   write("The trees block the path to the south.\n"); 
   return 1; }

east(){
   write("You follow the path to the east.\n");
   this_player()->move_player("east#/players/jaraxle/3rd/silence/rooms/4G");
   return 1; }

north(){ write("The trees block the path to the north.\n"); return 1; }


search_me(str){
   if(!str){
      write("You stand before a crossing in the path to the west.\n"+
         "Trees protect you from the north and the south, while\n"+
         "the path leads back through the forest to the east.\n");
      return 1; }
   write("You search the "+str+" and find nothing of intrest.\n");
   return 1; }
