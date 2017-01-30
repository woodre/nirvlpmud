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
   "\t@@@@"+HIB+"X"+HIM+"~~"+NORM+RED+"="+GRN+"@@@\n"+
   "\t@@@@"+HIM+"~~"+NORM+GRN+"@"+BLU+"~"+NORM+GRN+"@@@\n"+
   "\t@@@@@@@"+BLU+"~"+NORM+GRN+"@@@\n"+
   "\t@@@@@@"+BLU+"~~"+NORM+GRN+"@@@\n"+
   "\t@@@@@"+BLU+"~~~"+NORM+GRN+"@@@\n"+
   "\t@@@@@"+BLU+"~~~"+NORM+GRN+"@@@\n"+NORM;
   items = ({
         "ooze",""+HIM+"Purple ooze seemingly out of nowhere.  The ooze might be sticky to the touch.\nIt smells rotten and repugnant"+NORM+"",
         "ground","You cannot see the ground under the ooze, only feel it solid beneath your feet",
         "trees","You see tree tops to the east, and a forest to the west",
         "tree tops","Bright green tree tops further to the west",
         "forest","A forest growing beautifully to the east, beyond the bridge",
         "pool", long_desc,
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
   add_action("east","east");
   add_action("west","west");
   add_action("north","north");
   add_action("south","south");
   add_action("cross","cross");
   add_action("the_key","key");
}

east(){
   write("You slosh eastward through the "+HIM+"Living Ooze"+NORM+".\n");
   this_player()->move_player("east#/players/jaraxle/3rd/ooze/rooms/roomw");
   return 1; }

west(){
   write("The west is blocked by a growth of trees.\n");
/*
write("You slosh west through the "+HIM+"Living Ooze"+NORM+".\n");
this_player()->move_player("north#/players/jaraxle/3rd/ooze/rooms/room2w");
*/
return 1; }


north(){
   write("You slosh north through the "+HIM+"Living Ooze"+NORM+".\n");
   this_player()->move_player("north#/players/jaraxle/3rd/ooze/rooms/room2n");
   return 1; }

south(){
   write("You slosh south through the "+HIM+"Living Ooze"+NORM+".\n");
   this_player()->move_player("south#/players/jaraxle/3rd/ooze/rooms/room2s");
   return 1; }

search_me(arg){
   if(!arg){
  write(HIM+"The pool of ooze ends abruptly near a forest.  Tall trees can\n"+
  "be seen to the west. The ooze stretched out smoothly to the east.\n"+
  "A strange stillness surrounds the area around the forest.\n"+NORM);
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
      GRN+"\t@"+NORM+" = Trees (impassable)\n"+
      MAG+"\t~"+NORM+" = Living Ooze!\n"+
      BLU+"\t~"+NORM+" = River of Despair\n"+
      RED+"\t="+NORM+" = Bridge Crossing\n"+
      RED+"\t$"+NORM+" = Further Access Denied!\n");
   return 1; }
