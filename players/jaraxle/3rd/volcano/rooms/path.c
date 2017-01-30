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
  ""+BLU+"\tX"+NORM+YEL+"###"+RED+"**"+YEL+"#"+GRN+"@@@@\n"+
   "\t@@@"+YEL+"#"+RED+"**"+YEL+"#"+GRN+"@@@@\n"+
   "\t@@@@"+YEL+"##"+GRN+"@@@@@\n"+
   "\t@@@@@@@@@@@\n"+
   "\t@@@@@@@@@@@\n"+
   "\t@@@@@@@@@@@"+NORM+"\n";
   items = ({
         "trees","Thick trunks reach high up sprouting with abuntant amounts of foliage.\nThe trees bar passage in any direction",
         "path","The path has been rarely traveled.\nIt is mostly noticed by the dark stones which litter the ground.\nThe path leads further east",
         "stones","Small grey and tan stones randomly lay on the path",
         "volcano","The volcano can be seen above the trees.\nSmoke rises from the peak",
         "smoke","Bright white smoke billows from the volcano's crest",
         "summit","The top of the volcano, from which steam is rising out of",
         "forest","The forest here is hard to travel.\nThe path between the trees slithers through a few trees to the east",
});
   
}
short(){ return "Third Earth"; }
init() {
   
   ::init();
   
   add_action("the_key","key");
   add_action("west","west");
   add_action("north","north");
   add_action("south","south");
   add_action("east","east");
   add_action("search_me","search");
}
east() {
   write("You follow the path to the east.\n");
   TP->move_player("east#/players/jaraxle/3rd/volcano/rooms/path2");
   return 1; }


west() {
   write("You walk east into the forest.\n");
   TP->move_player("west#/players/jaraxle/3rd/warrior/rooms/roome2.c");
   return 1; }

north(){ write("Thick trees block you from the north.\n"); return 1; }

south(){ write("Thick trees block you from the south.\n"); return 1; }

search_me(arg){
if(!arg){
        write("A rough path twisting between the trees.  The path winds its way\n"+
        "through the forest running east and west.  You see a volcano far\n"+
        "off to the east with smoke rising slowly from the summit.\n");
return 1; }
  write("You search the "+arg+" and find nothing of intrest.\n");
   return 1; }

the_key(){
   write("\n"+
      BLU+"\tX"+NORM+" = You are here!\n"+
      GRN+"\t@"+NORM+" = Trees (impassable)\n"+
      YEL+"\t#"+NORM+" = Walkable Path\n"+
      RED+"\t*"+NORM+" = Volcano\n"+
      RED+"\t$"+NORM+" = Further Access Denied!\n");
   return 1; }
