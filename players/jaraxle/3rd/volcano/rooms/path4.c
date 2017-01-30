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
  ""+YEL+"\t###"+HIB+"X"+NORM+RED+"**"+YEL+"#"+GRN+"@@@@\n"+
   "\t@@@"+YEL+"#"+RED+"**"+YEL+"#"+GRN+"@@@@\n"+
   "\t@@@@"+YEL+"##"+GRN+"@@@@@\n"+
   "\t@@@@@@@@@@@\n"+
   "\t@@@@@@@@@@@\n"+
   "\t@@@@@@@@@@@"+NORM+"\n";
   items = ({
         "trees","Thick trunks reach high up sprouting with abuntant amounts of foliage\nThe trees bar passage in any direction around the path",
         "path","The path looks rarely traveled.\nIt is mostly noticed by the dark stones which litter the ground.\nThe path leads west towards the forest.\nThe path changes into a smooth trail which follows the base of the volcano north and south",
         "stones","Dark stones lying about over the path",
         "volcano","The volcano rises high above.\nThe volcanos girth prohibits viewing anything around it.\nThere is a trail following around the base of the mountain",
         "base","The wide base of the volcano is a dark, burned orange color.\nA smooth trail follows it around",
         "forest","The forest ends at the trail which follows the base of the volcano.\nA path leads into the forest towards the west",
         "trail","A smooth sandy trail follows closely around the base of the volcano.\nThe trail leads north and south",
});
         
}


short(){ return "Third Earth"; }

init() {
   
   ::init();
   
   add_action("north","north");
   add_action("south","south");
   add_action("the_key","key");
   add_action("west","west");
   add_action("east","east");
   add_action("search_me","search");
}
north() {
   write("You follow the trail to the north.\n");
   TP->move_player("north#/players/jaraxle/3rd/volcano/rooms/trail1");
   return 1; }     

south() {
   write("You follow the trail to the south.\n");
   TP->move_player("south#/players/jaraxle/3rd/volcano/rooms/trail9");
   return 1; }


west() {
   write("You walk east into the forest.\n");
   TP->move_player("east#/players/jaraxle/3rd/volcano/rooms/path3");
   return 1; }

east(){ write("The volcano blocks you to the east.\n"); return 1; }


search_me(arg){
if(!arg){
        write("The path through the forest opens up to a slim trail that follows\n"+
        "the volcano to the north and south. The base of the volcano is dark\n"+
        "orange with singes of black. The volcano radiates a feeling of heat\n"+
        "from behind the rocky base.\n");
return 1; }
  write("You search "+arg+" and find nothing of intrest.\n");
   return 1; }

the_key(){
   write("\n"+
      BLU+"\tX"+NORM+" = You are here!\n"+
      GRN+"\t@"+NORM+" = Trees (impassable)\n"+
      YEL+"\t#"+NORM+" = Walkable Path\n"+
      RED+"\t*"+NORM+" = Volcano\n"+
      RED+"\t$"+NORM+" = Further Access Denied!\n");
   return 1; }
