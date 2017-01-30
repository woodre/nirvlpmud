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
   ""+RED+"\t$"+NORM+YEL+"#"+GRN+"@@"+YEL+"####"+BLU+"X"+YEL+"#"+HIM+"~"+NORM+"\n"+
   ""+GRN+"\t@"+YEL+"####"+GRN+"@@@@"+YEL+"#"+HIM+"~"+NORM+"\n"+
   ""+GRN+"\t@@@@"+YEL+"######"+HIM+"~"+NORM+"\n"+
   ""+GRN+"\t@"+YEL+"#"+GRN+"@@@@@"+YEL+"#"+GRN+"@@@"+NORM+"\n"+
   ""+GRN+"\t@"+YEL+"#"+GRN+"@@@"+YEL+"##"+GRN+"@@@@"+NORM+"\n"+
   ""+GRN+"\t@@"+YEL+"#####"+GRN+"@@@@"+NORM+"\n"+
   ""+GRN+"\t@@@@@@@@@@@\n"+NORM+"";
   items = ({
    "path","A grassy path leading you east and west",
    "trees","The forest grows on the sides of the path.\nLarge trees grow to the north and south.\nYou notice a glint of light sparkle through the northern treeline",
    "northern treeline","A small break between two trees.\nIt looks like you can go "+HIW+"north"+NORM+" from here",
    "treeline","Look "+HIW+"northern treeline"+NORM+" or "+HIW+"southern treeline"+NORM+"",
    "southern treeline","Trees growing close together, on the southern end of this path",

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
this_player()->move_player("west#/players/jaraxle/3rd/silence/rooms/4H");
   return 1; }

south(){
write("The trees block the path to the south.\n"); 
return 1; }

east(){
write("You follow the path to the east.\n");
this_player()->move_player("east#/players/jaraxle/3rd/silence/rooms/4J");
return 1; }

north(){ 
write("You walk north, between the trees.\n");
this_player()->move_player("into the trees#/players/jaraxle/3rd/silence/rooms/tree1");
return 1; }

search_me(str){
   if(!str){
    write("The path leads you between two rows of large trees.\n"+
    "Stretching to the east and west, the path wanders\n"+
    "through the forest peacefully.\n");
      return 1; }
   write("You search the "+str+" and find nothing of intrest.\n");
   return 1; }
