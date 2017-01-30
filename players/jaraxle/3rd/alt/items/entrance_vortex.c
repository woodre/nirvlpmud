#include "/players/jaraxle/define.h"
inherit "/obj/treasure";

int num;

reset(arg)  {
   if(arg) return;
   
   set_id("vortex");
   set_short("A swirling vortex");
   set_long("A swirling vortex of mist and shadow.\n");
   set_weight(0);
   set_value(0);
}
init(){
   ::init();
   add_action("enter_it","enter");
}

enter_it(arg){
   if(arg == "vortex"){
      write("You enter the vortex through to another realm.\n");
      TP->move_player("into the vortex#/players/jaraxle/3rd/alt/rooms/church.c");
      say("Appears out of a swirling vortex.\n");
      return 1; }
   notify_fail("Enter vortex.\n"); return 0; }

get(){
   write("Get what?\n");
   return 0; }
