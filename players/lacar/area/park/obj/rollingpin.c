/*
*      File:             /players/lacar/area/park/obj/rollingpin.c
*      Function:         obj
*      Author(s):        Lacar@nirvana
*      Copyright:        Copyright (c) 2006 Lacar (Carla J Merrill)
*                                All Rights Reserved
*      Source:    		11/22/2006
*      Notes:            area
*      Change History:
*/
inherit "obj/weapon.c";
#define attacked (this_object()->query_attack())

reset(arg){
  ::reset(arg);
  if (arg) return;

set_name("Rolling pin");
set_alias("pin");
set_short("rolling pin");
set_long("A rolling pin used in cooking and baking\n\
It is covered with white flour and looks well used\n");
set_type("club");
set_class(12);
set_weight(5);
set_value(150);
set_hit_func(this_object());
}

weapon_hit(attacker){
   int W;
   W = random(20);
   if(W > 15)  {
      
      say("The rolling pin hits you over the head!\n");
      write("The rolling pin rolls over your foe!\n");
      return 3;
      
   }
   return;
}
	