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
   ""+GRN+"\t@"+YEL+"####"+GRN+"@@@@"+BLU+"X"+HIM+"~"+NORM+"\n"+
   ""+GRN+"\t@@@@"+YEL+"######"+HIM+"~"+NORM+"\n"+
   ""+GRN+"\t@"+YEL+"#"+GRN+"@@@@@"+YEL+"#"+GRN+"@@@"+NORM+"\n"+
   ""+GRN+"\t@"+YEL+"#"+GRN+"@@@"+YEL+"##"+GRN+"@@@@"+NORM+"\n"+
   ""+GRN+"\t@@"+YEL+"#####"+GRN+"@@@@"+NORM+"\n"+
   ""+GRN+"\t@@@@@@@@@@@\n"+NORM+"";
   items = ({
         "path","A grassy path which looks well traveled over.\nThe path stretches north and south, making an\nabrupt stop back east as it meets the "+HIM+"Living Ooze"+NORM+"",
         "forest","A thick forest, full of trees",
  "ooze",""+HIM+"Purple ooze seemingly out of nowhere.  The ooze might be sticky to the touch.\nIt smells rotten and repugnant"+NORM+"",
  "living ooze",""+HIM+"Purple ooze seemingly out of nowhere.  The ooze might be sticky to the touch.\nIt smells rotten and repugnant"+NORM+"",
  "trees","Tall trees, growing in a small group making up a forest",
});
   
}

short(){ return ""+GRN+"Forest of Silence"+NORM+""; }

init(){
   ::init();
   add_action("the_key","key");
   add_action("search_me","search");
   add_action("east","east");
   add_action("west","west");
   add_action("north","north");
   add_action("south","south");
}

east(){
write("You step off the path into the "+HIM+"Living Ooze"+NORM+".\n");
this_player()->move_player("into the "+HIM+"Living Ooze"+NORM+"#/players/jaraxle/3rd/ooze/rooms/room2w");
return 1; }

west(){
   write("A tree blocks the path to the west.\n");
   return 1; }

north(){
write("You follow the path to the north.\n");
this_player()->move_player("north#/players/jaraxle/3rd/silence/rooms/4J");
return 1; }

south(){
write("You follow the path to the south.\n");
this_player()->move_player("north#/players/jaraxle/3rd/silence/rooms/6J");
return 1; }

the_key(str){
   write("\n"+
      ""+BLU+"\tX"+NORM+" = You are here!!\n"+
      ""+GRN+"\t@"+NORM+" = Trees (impassable)\n"+
      ""+YEL+"\t#"+NORM+" = Walkable Paths\n"+
      ""+MAG+"\t~"+NORM+" = Living Ooze!\n"+
      ""+CYN+"\t#"+NORM+" = ?\n"+
      ""+RED+"\t$"+NORM+" = Further Access Denied!\n");
   return 1; }

search_me(str){
   if(!str){
      write("You stand at the beginning of a soft, grassy path.\n"+
         "The colorful forest looms around the path underfoot.\n");
      return 1; }
   write("You search the "+str+" and find nothing of intrest.\n");
   return 1; }
