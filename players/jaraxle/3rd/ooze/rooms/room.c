#include "/players/jaraxle/define.h"
inherit "/players/jaraxle/room2.c";

int i;
reset(arg) {
   if(arg) return;
   set_light(1);
   long_desc =
   "\n"+
   ""+GRN+"\t@@@@@@"+BLU+"~~~"+NORM+GRN+"@@\n"+
   "\t@@@@@@@"+BLU+"~"+NORM+GRN+"@@@\n"+
   "\t@@@@@@@"+BLU+"~"+NORM+GRN+"@@@\n"+
   "\t@@@@"+HIM+"~~"+NORM+GRN+"@"+BLU+"~"+NORM+GRN+"@@@\n"+
   "\t@@@@"+HIM+"~~"+HIB+"X"+NORM+RED+"="+GRN+"@@@\n"+
   "\t@@@@"+HIM+"~~"+NORM+GRN+"@"+BLU+"~"+NORM+GRN+"@@@\n"+
   "\t@@@@@@@"+BLU+"~"+NORM+GRN+"@@@\n"+
   "\t@@@@@@"+BLU+"~~"+NORM+GRN+"@@@\n"+
   "\t@@@@@"+BLU+"~~~"+NORM+GRN+"@@@\n"+
   "\t@@@@@"+BLU+"~~~"+NORM+GRN+"@@@\n"+NORM;
   items = ({
         "ooze",""+HIM+"Purple ooze seemingly out of nowhere.  The ooze might be sticky to the touch.\nIt smells rotten and repugnant"+NORM+"",
         "ground","You cannot see the ground under the ooze, only feel it solid beneath your feet",
         "bridge","A short wooden bridge crossing the "+HIB+"River of Despair"+NORM+"",
         "river","A wonderously clean river",
         "trees","You see tree tops to the west, and a forest to the east",
         "tree tops","Bright green tree tops further to the west",
         "forest","A forest growing beautifully to the east, beyond the bridge",
         "tops", "Bright green tree tops further to the west",
         "river of despair", "A wonderously clean river",
});
   
  for(i = 0; i < 1 + random(2); i++)
   {
   MOCO("/players/jaraxle/3rd/ooze/mon/ooze.c"),TO);
}
}

short(){ return HIM+"Living Ooze"+NORM; }
init(){
   ::init();
   add_action("search_me","search");
   add_action("touch","touch");
   add_action("west","west");
   add_action("north","north");
   add_action("south","south");
   add_action("east","east");
   add_action("cross","cross");
   add_action("the_key","key");
}

west(){
   write("You slosh westward through the "+HIM+"Living Ooze"+NORM+".\n");
   this_player()->move_player("west#/players/jaraxle/3rd/ooze/rooms/roomw");
   return 1; }

east(){
   write("You slosh eastward out of the "+HIM+"Living Ooze"+NORM+".\n");
   this_player()->move_player("east#/players/jaraxle/3rd/warrior/rooms/despair_bridge_ooze.c");
   return 1; }

north(){ write("Large trees block the north.\n"); return 1; }

south(){ write("Large trees block the south.\n"); return 1; }

search_me(arg){
   if(!arg){
      write(HIM+"   A living pool of bubbling, gurgling ooze.  The ooze covers the\n"+
         "ground in almost every direction.  The ooze shifts back and forth\n"+
         "very slowly. A bridge can be seen to the east, while tops of a few\n"+
         "trees are visible to the west.  Beyond the bridge is the edge of\n"+
         "the forest."+NORM+"\n");
      return 1; }
   if(arg == "ooze"){
      write("You search the ooze and find nothing.\n");
      say(TPN+" searches the ooze (yuck!).\n");
      return 1; }
   write("You search the "+arg+" and find nothing of intrest.\n");
   return 1; }

touch(arg){
   if(arg == "ooze"){
      if(!present("ooze",environment(this_player()))){ write("Your finger gets stuck for a moment in the gooey ooze.\n"); return 1; }
   }
}

the_key(str){
   write("\n"+
      BLU+"\tX"+NORM+" = You are here!\n"+
      ""+GRN+"\t@"+NORM+" = Trees (impassable)\n"+
      ""+MAG+"\t~"+NORM+" = Living Ooze!\n"+
      ""+BLU+"\t~"+NORM+" = River of Despair\n"+
      ""+RED+"\t="+NORM+" = Bridge Crossing\n"+
       ""+RED+"\t$"+NORM+" = Further Access Denied!\n");
   return 1; }
