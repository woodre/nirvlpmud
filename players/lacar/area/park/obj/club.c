/*
*      File:             /players/lacar/area/park/obj/club.c
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

set_name("Club");
set_alias("club");
set_short("Wooden club");
set_long("A short club of wood which looks like it may break any\n\
minute. There seems to be scars along its shaft from many battles\n");
set_type("club");
set_class(12);
set_weight(1);
set_value(250);
set_hit_func(this_object());
}

weapon_hit(attacker){
   int W;
   W = random(20);
   if(W > 15)  {
      
      say("The club belted you in the gut!\n");
      write("The club smahes your foe!\n");
      return 3;
      
   }
   return;
}
	