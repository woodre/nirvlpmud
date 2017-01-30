#include "/players/jaraxle/define.h"
inherit "/players/jaraxle/room2.c";

reset(arg) {
   if(arg) return;
   set_light(1);
   
 long_desc =
   "\n"+
   ""+GRN+"\t@@@@@@@@@@@\n"+
   "\t@@@@@@@@@@@\n"+
   "\t@@@@"+YEL+"##"+GRN+"@@@@@\n"+
  "\t@@@"+YEL+"#"+RED+"**"+YEL+"#"+GRN+"@@@@\n"+
  ""+YEL+"\t#"+HIB+"X"+NORM+YEL+"##"+RED+"**"+YEL+"#"+GRN+"@@@@\n"+
   "\t@@@"+YEL+"#"+RED+"**"+YEL+"#"+GRN+"@@@@\n"+
   "\t@@@@"+YEL+"##"+GRN+"@@@@@\n"+
   "\t@@@@@@@@@@@\n"+
   "\t@@@@@@@@@@@\n"+
   "\t@@@@@@@@@@@"+NORM+"\n";
   items = ({
         "trees","Thick trunks reach high up sprouting with abuntant amounts of foliage.\nThe trees bar passage in any direction around the path",
         "path","The path looks rarely traveled.\nIt is mostly noticed by the dark stones which litter the ground.\nThe path leads east and west",
         "stones","Dark stones lying about over the path",
         "volcano","The volcano can be seen above the trees.\nSmoke rises from the peak",
         "smoke","Bright white smoke billows from the volcanos crest",
         "summit","The top of the volcano, from which steam is rising out of",
         "forest","The forest here is hard to travel.\nThere is a difficult path leading from west through to the east",
});
}
   
short(){ return "Third Earth"; }
init() {
   
   ::init();
   add_action("north","north");
   add_action("south","south");
   add_action("west","west");
   add_action("search_me","search");
   add_action("east","east");
   add_action("the_key","key");
}
east() {
   write("You follow the path to the east.\n");
   TP->move_player("east#/players/jaraxle/3rd/volcano/rooms/path3");
   return 1; }

west() {
   write("You follow the path to the west.\n");
   TP->move_player("west#/players/jaraxle/3rd/volcano/rooms/path");
   return 1; }

north(){ write("Thick forests block you in from the north.\n"); return 1; }

south(){ write("Thick forests block you in from the south.\n"); return 1; }

search_me(str){
if(!str){
        write("A path narrowly slices through the trees.  The forest grows\n"+
        "thick, and unexplorable around the path.  A volcano to the\n"+
        "east begins to take shape above the foliage.\n");
return 1; }
write("You search "+str+" but find nothing of interest.\n");
return 1; }

the_key(){
   write("\n"+
      BLU+"\tX"+NORM+" = You are here!\n"+
      GRN+"\t@"+NORM+" = Trees (impassable)\n"+
      YEL+"\t#"+NORM+" = Walkable Path\n"+
      RED+"\t*"+NORM+" = Volcano\n"+
      RED+"\t$"+NORM+" = Further Access Denied!\n");
   return 1; }
