#include "/players/jaraxle/define.h"
inherit "/obj/treasure";

reset(arg)  {
   if(arg) return;
   set_id("portal");
   set_short("A portal to the Wastelands("+RED+"3031"+NORM+")");
   set_long("A strange portal in the center of the room.\n");
   set_weight(0);
   set_value(0);
}
init(){
   ::init();
   add_action("enter_it","enter");
}

enter_it(arg){
   
   if(arg == "portal"){
      write("You enter the portal out to another realm.\n");
      TP->move_player("into th portal#/players/jaraxle/3rd/alt/wastes/rooms/entrance.c");
      say("Appears out of a hazing portal.\n");
      command("look",TP);
      return 1; }
   notify_fail("Enter portal.\n"); return 0; }

get(){
   write("Get what?\n");
   return 0; }
