/*
*      File:             /players/lacar/area/park/obj/pinecone.c
*      Function:         obj
*      Author(s):        Lacar@nirvana
*      Copyright:        Copyright (c) 2007 Lacar (Carla J Merrill)
*                                All Rights Reserved
*      Source:    		
*      Notes:            area
*      Change History:
*/
#include <ansi.h>
inherit "obj/weapon.c";

reset(arg){
  ::reset(arg);
  if (arg) return;

set_name("pine cone");
set_alias("pine cone");
set_short("pine cone");
set_long("A four inch long brown pine cone from a tree. It is six \n\
inches around and has a one inch thick handle.\n");
set_type("club");
set_class(12);
set_weight(1);
set_value(250);
set_hit_func(this_object());
}
  message_hit=({
    "pounded"," with the sheer force of the Pine Cone",
    "nicked"," by the Pine CONE",
    "hit"," with deadly accuracy",
    "knocked"," down with the top of the Cone",
    "banged"," upside the knee",
    "shattered","'s shin into pieces",
    "scratched"," on the legs.",
)
    
weapon_hit(attacker){
   if(random(13) > 8) {
      
      say("The pine cone scratches you.\n");
      write("The pine cone slices your foe!\n");
      return 6;
    
   }
   return;
}
	