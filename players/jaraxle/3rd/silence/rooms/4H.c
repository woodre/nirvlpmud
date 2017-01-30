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
   ""+RED+"\t$"+NORM+YEL+"#"+GRN+"@@"+YEL+"###"+BLU+"X"+YEL+"##"+HIM+"~"+NORM+"\n"+
   ""+GRN+"\t@"+YEL+"####"+GRN+"@@@@"+YEL+"#"+HIM+"~"+NORM+"\n"+
   ""+GRN+"\t@@@@"+YEL+"######"+HIM+"~"+NORM+"\n"+
   ""+GRN+"\t@"+YEL+"#"+GRN+"@@@@@"+YEL+"#"+GRN+"@@@"+NORM+"\n"+
   ""+GRN+"\t@"+YEL+"#"+GRN+"@@@"+YEL+"##"+GRN+"@@@@"+NORM+"\n"+
   ""+GRN+"\t@@"+YEL+"#####"+GRN+"@@@@"+NORM+"\n"+
   ""+GRN+"\t@@@@@@@@@@@\n"+NORM+"";
   items = ({
         "path","A grassy path that has been well walked over.\nThe path leads from east to west",
         "forest","A thick forest, full of trees",
         "trees","Huge RedWood and Oak trees standing proud overhead",
         "gaps","Spaces between the branches of the treetops where sunlight can shine through",
         "branches","Thick oak and redwood branches reaching across the top of the forest",
         "sunlight","Patches of bright sunlight beam in from gaps in the treetops",
         "oak trees","Thick oak trees, tall with age",
         "redwood trees","Mammoth red tinted trees",
         "large trees","Huge RedWood and Oak trees standing proud overhead",
         "redwood","Mammoth red tinted trees",
         "oak","Thick oak trees, tall with age",
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

west(){
write("You follow the path to the west.\n");
this_player()->move_player("west#/players/jaraxle/3rd/silence/rooms/4G");
   return 1; }

south(){
write("The trees block the path to the south.\n"); 
return 1; }

east(){
write("You follow the path to the east.\n");
this_player()->move_player("east#/players/jaraxle/3rd/silence/rooms/4I");
return 1; }

north(){ write("The trees block the path to the north.\n"); return 1; }

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
    write("You're standing in the middle of a grassy path.\nThe large trees stand tall over your head\nfiltering the sunlight from above.\n");
      return 1; }
   write("You search the "+str+" and find nothing of intrest.\n");
   return 1; }
