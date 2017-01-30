/* no idea where this is coming from */
#include "/players/jaraxle/define.h"
inherit "/obj/treasure";

reset(arg)  {
   if(arg) return;
   
   set_id("aura");
   set_short(HIW+"A hazing aura"+NORM);
   set_long("An "+HIW+"aura"+NORM+" which envelopes the entire courtyard.\n");
   
   
   set_weight(0);
   set_value(0);
}
init(){    
   ::init();    
   add_action("castle_locked","north");
   add_action("castle_locked","west");
   add_action("castle_locked","east");
   add_action("castle_locked","southeast");
   add_action("castle_locked","southwest");
   
}
castle_locked(){
  return 0;
   if(!present("KnightInvite",TP)){
      write("The aura of righteous locks further passage.\n");
      return 1; }
}

get(){ return 0; }

short() { return 0; }

long() { return; }
