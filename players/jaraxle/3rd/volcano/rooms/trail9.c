#include "/players/jaraxle/define.h"
inherit "/players/jaraxle/room2.c";
int i;
reset(arg) {
   if(arg) return;
   set_light(1);
   long_desc =
   "\n"+
   ""+GRN+"\t@@@@@@@@@@@\n"+
   "\t@@@@@@@@@@@\n"+
   "\t@@@@"+YEL+"##"+GRN+"@@@@@\n"+
   "\t@@@"+YEL+"#"+RED+"**"+YEL+"#"+GRN+"@@@@\n"+
   ""+YEL+"\t####"+NORM+RED+"**"+YEL+"#"+GRN+"@@@@\n"+
   "\t@@@"+HIB+"X"+NORM+RED+"**"+YEL+"#"+GRN+"@@@@\n"+
   "\t@@@@"+YEL+"##"+GRN+"@@@@@\n"+
   "\t@@@@@@@@@@@\n"+
   "\t@@@@@@@@@@@\n"+
   "\t@@@@@@@@@@@"+NORM+"\n";
   items = ({ 
         "trees","Thick trunks reach high up sprouting with abuntant amounts of foliage\nThe trees bar passage in any direction around the path",
         "volcano","The volcano rises high above.\nThe volcano's girth prohibits viewing anything around it.\nThere is a trail following around the base of the volcano",
         "base","The wide base of the volcano is a dark, burned orange color.\nA smooth trail follows it around to the southeast and north",
         "forest","The forest follows on the left edge of the trail.\nThe trees have grown very close together, prohibiting venture into the forest from here",
    "cave","A large gaping cave you can "+HIW+"enter"+NORM+".\nThere is a feeling of static around\nthe mouth of the cave",
         "trail","A smooth sandy trail follows closely around the base of the volcano\nThe trail leads north and southeast",
});
   
  for(i = 0; i < 0 + random(3); i++)
   {
    MOCO("/players/jaraxle/3rd/volcano/mons/snake.c"),TO);
}
}
short(){ return "Third Earth"; }

init() {
   
   ::init();
   
   add_action("north","north");
   add_action("south","south");
   add_action("the_key","key");
   add_action("enter","enter");
   add_action("west","west");
   add_action("east","east");
   add_action("southeast","southeast");
   add_action("search_me","search");
}

north(){ 
    write("You follow the trail to the north.\n");
   TP->move_player("north#/players/jaraxle/3rd/volcano/rooms/path4");
return 1; }

south(){ write("The forest blocks you in from the south.\n"); return 1; }
west(){ write("The forest blocks you in from the west.\n"); return 1; }
east(){ write("The volcano blocks you in from the east.\n"); return 1; }

southeast(){
   write("You follow the trail to the southeast.\n");
   TP->move_player("southeast#/players/jaraxle/3rd/volcano/rooms/trail8");
return 1; }

search_me(arg){
if(!arg){
  write("A flat, soft trail following close to the volcano.  The forest\n"+
        "lines the trail on the left side to create the look of a tunnel\n"+
        "without a ceiling.  The volcano on the right still sends off a \n"+
        "feeling of heat from behind the rock base.\n");
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

enter(arg){ 
         int CAVE;
   if(arg == "cave"){
      switch(random(3)){
         case 1: CAVE = "bravely"; break; case 2: CAVE = "cautiously"; break;
case 0: CAVE = "carefully"; break; }
      write("\nYou "+CAVE+" enter the cave of the "+HIB+"Blue"+
" Dragon"+NORM+".\n");
TP->move_player("into the volcano#/players/jaraxle/cont/bdragon/rooms/r1.c");
      return 1; }
   notify_fail("Enter what?\n");
   return 0;
}
