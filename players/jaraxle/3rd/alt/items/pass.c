#include "/players/jaraxle/define.h"
inherit "/obj/treasure";

reset(arg)  {
   
   if(arg) return;
   
   set_id("mist");
   set_short("Mist to the --east--");
   set_long("You are still swimming in the sea.\n"+
      "You do see a great wall of mist to the east.\n"+
      "You can go east or west.\n");
   set_weight(0);
   set_value(0);
}
init(){
   ::init();
   add_action("enter_it","east");
   add_action("enter_it","e");
}

enter_it(){
  TP->move_player("leaves east#/players/jaraxle/3rd/alt/rooms/forest/pass.c");
      command("look",TP);
      return 1; }

get(){
   write("Get what?\n");
   return 0; }
