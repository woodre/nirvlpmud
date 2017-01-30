#include "/players/jaraxle/define.h"
inherit "/players/jaraxle/room2.c";

reset(arg) {
   if(arg) return;
   set_light(1);
   long_desc =
   "\n"+
   ""+GRN+"\t@@@@@"+YEL+"#"+GRN+"@@@@@\n"+
   "\t@@@@@"+YEL+"#"+GRN+"@@@@@\n"+
   "\t@@@@@"+HIB+"X"+NORM+GRN+"@@@@@\n"+
   "\t@@"+BLK+".--"+YEL+"#"+BLK+"--."+GRN+"@@\n"+
   "\t@@"+BLK+"|\\   /|"+GRN+"@@\n"+
   "\t@@"+BLK+"| \\_/ |"+GRN+"@@\n"+
   "\t@@"+BLK+"| / \\ |"+GRN+"@@\n"+
   "\t@@"+BLK+"|/___\\|"+GRN+"@@\n"+ 
   "\t@@@@@@@@@@@\n"+
   "\t@@@@@@@@@@@"+NORM+"\n";
   items = ({
         "forest","The deep forest of Third Earth.\nTrees grow heavily around the path",
         "path","A grassy trail through the forest",
         "pyramid","The top of a black pyramid can be seen far off in the distance",
         "top","The top of a black pyramid can be seen far off in the distance",
         "trees","Large oak trees grow around the path",
         "grass","Thick grass which grows over the path",
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

north(){
   write("You follow the path to the north.\n");
   TP->move_player("north#/players/jaraxle/3rd/warrior/rooms/pyr_path2");
   return 1; }

south(){
   write("You follow the path to the south.\n");
   TP->move_player("south#/players/jaraxle/3rd/warrior/rooms/pyr_path4");
   return 1; }

east(){ write("The forest blocks you in from the east.\n"); return 1; }
west(){ write("The forest blocks you in from the west.\n"); return 1; }

search_me(arg){
if(!arg){
  write("The "+BLK+"Dark Pyramid"+NORM+" can be seen shortly ahead of the path.\n"+
        ""+HIW+"Lightning"+NORM+" crackles overhead, as the sky strangely seems\n"+
        "to darken as the path reaches to the pyramid.  An eerie\n"+
        "stillness falls over the forest.\n");
return 1; }
  write("You search the "+arg+" and find nothing of intrest.\n");
   return 1; }

the_key(){
   write("\n"+
      BLU+"\tX"+NORM+" = You are here!\n"+
      GRN+"\t@"+NORM+" = Trees (impassable)\n"+
      YEL+"\t#"+NORM+" = Walkable Path\n"+
      RED+"\t$"+NORM+" = Further Access Denied!\n");
   return 1; }
