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
   ""+GRN+"\t@@@@"+YEL+"#####"+BLU+"X"+HIM+"~"+NORM+"\n"+
   ""+GRN+"\t@"+YEL+"#"+GRN+"@@@@@"+YEL+"#"+GRN+"@@@"+NORM+"\n"+
   ""+GRN+"\t@"+YEL+"#"+GRN+"@@@"+YEL+"##"+GRN+"@@@@"+NORM+"\n"+
   ""+GRN+"\t@@"+YEL+"#####"+GRN+"@@@@"+NORM+"\n"+
   ""+GRN+"\t@@@@@@@@@@@\n"+NORM+"";
   items = ({
         "path","A grassy path which looks well traveled over.\nThe path stretches north and west, making an\nabrupt stop back east as it meets the "+HIM+"Living Ooze"+NORM+"",
         "forest","A thick forest, full of trees",
  "ooze",""+HIM+"Purple ooze seemingly out of nowhere.  The ooze might be sticky to the touch.\nIt smells rotten and repugnant"+NORM+"",
  "living ooze",""+HIM+"Purple ooze seemingly out of nowhere.  The ooze might be sticky to the touch.\nIt smells rotten and repugnant"+NORM+"",
  "trees","Tall trees, growing in a small group making up a forest",
   "mound","A small mound in the shape of an ant hill.\nThere is a hole in the top of the mound",
   "hole","A little hole you might be able to "+HIW+"squeeze"+NORM+" into",
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
    add_action("enter_mound","squeeze");
}

west(){
write("You follow the path to the west.\n");
this_player()->move_player("west#/players/jaraxle/3rd/silence/rooms/6I");
   return 1; }

north(){
write("You follow the path to the north.\n");
this_player()->move_player("north#/players/jaraxle/3rd/silence/rooms/5J");
return 1; }

south(){
write("Trees block the path to the south.\n");
return 1; }

east(){ write("The "+HIM+"Living Ooze"+NORM+" blocks your way to the east.\n"); return 1; }
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
    write("You are standing in the southeast corner of the forest.\n"+
    "The "+HIM+"Living Ooze"+NORM+" traps you in from the east.  A small\n"+
    "mound grows on the side of the path.\n");
      return 1; }
   write("You search the "+str+" and find nothing of intrest.\n");
   return 1; }

enter_mound(str){
if(!str){ write("Squeeze into where?\n"); return 1; }
if(str == "into hole"){
write("You wriggle yourself into the mound.\n");
this_player()->move_player("into the mound#/players/jaraxle/3rd/silence/rooms/hole1");
return 1; }
write("Squeeze into hole.\n"); 
return 1; }
