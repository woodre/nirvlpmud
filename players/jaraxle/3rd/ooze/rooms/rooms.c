#include "/players/jaraxle/define.h"
inherit "/players/jaraxle/room2.c";

reset(arg) {
   if(arg) return;
   set_light(1);
   long_desc =
   "\n"+
   ""+GRN+"\t@@@@@@"+HIB+"~~~"+NORM+GRN+"@@\n"+
   "\t@@@@@@@"+HIB+"~"+NORM+GRN+"@@@\n"+
   "\t@@@@@@@"+HIB+"~"+NORM+GRN+"@@@\n"+
   "\t@@@@"+HIM+"~~"+NORM+GRN+"@"+HIB+"~"+NORM+GRN+"@@@\n"+
   "\t@@@@"+HIM+"~~~"+NORM+RED+"="+GRN+"@@@\n"+
   "\t@@@@"+HIM+"~"+HIB+"X"+NORM+GRN+"@"+HIB+"~"+NORM+GRN+"@@@\n"+
   "\t@@@@@@@"+HIB+"~"+NORM+GRN+"@@@\n"+
   "\t@@@@@@"+HIB+"~~"+NORM+GRN+"@@@\n"+
   "\t@@@@@"+HIB+"~~~"+NORM+GRN+"@@@\n"+
   "\t@@@@@"+HIB+"~~~"+NORM+GRN+"@@@\n"+NORM;
   items = ({
         "ooze",""+HIM+"Purple ooze seemingly out of nowhere.  The ooze might be sticky to the touch.\nIt smells rotten and repugnant"+NORM+"",
         "ground","You cannot see the ground under the ooze, only feel it solid beneath your feet",
         "trees","You see tree tops to the west, and a forest to the east",
         "tree tops","Bright green tree tops further to the west",
         "forest","A forest growing beautifully to the east, beyond the bridge",
         "tops", "Bright green tree tops further to the west",
         "stone","A small marble stone sticking straight out of the ooze.\nA diamond shape is carved into the top",
         
         "rock","A small marble stone sticking straight out of the "+HIM+"ooze"+NORM+".\nThe shape of a human hand has baeen carved into the stone.\nYou feel an odd urge to "+HIW+"place"+NORM+" your "+HIW+"hand in"+NORM+" the "+HIW+"carving"+NORM+"",
         "square rock","A small marble stone sticking straight out of the ooze.\nA diamond shape is carved into the top",
});
   
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
   add_action("cave_lobby","place");
}

north(){
   write("You slosh north through the "+HIM+"Living Ooze"+NORM+".\n");
   this_player()->move_player("north#/players/jaraxle/3rd/ooze/rooms/roomw");
   return 1; }

west(){
   write("You slosh westward out of the "+HIM+"Living Ooze"+NORM+".\n");
   this_player()->move_player("west#/players/jaraxle/3rd/ooze/rooms/room2s");
   return 1; }

east(){ write("Large trees block the east.\n"); return 1; }

south(){ write("Large trees block the south.\n"); return 1; }

search_me(arg){
   if(!arg){
      write(HIM+"The pool flows heavilly to the south, stopping at a small recess\n"+
         "in the ground. A small square rock stands in the middle of the ooze.\n"+
         "The ooze continues spilling towards the north and west.\n"+NORM);
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

cave_lobby(str){
   if(str == "hand in carving" || str == "hand on carving" || str == "hand in rock" || str == "your hand in carving" || str == "your hand on carving" || str == "your hand in rock" || str == "your hand on rock"){
      write("As your hand slides into the recessed carving in the rock you feel\n"+
         "your feet begin to give way.  Your body sinks into a hidden room below.\n");
      say(TPN+" sinks into the "+HIM+"ooze"+NORM+"!\n");
      this_player()->move_player("under the "+HIM+"ooze"+NORM+"#/players/jaraxle/cave/rooms/entrance");
      say(TPN+" falls into the room.\n");
      /*
      command("look",TP);
      */
      return 1; }
write("Place your hand in the carving.\n");
return 1; }
