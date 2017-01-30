/*
*      File:             /players/lacar/area/park/obj/pixiestick.c
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

set_name("pixie stick");
set_alias("stick");
set_short("pixie stick");
set_long("A piece of wood which looks like a snake. It is long and\n\
slender in apperance.\n");
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
      
      say("The pixie stick slices at you\n");
      write("The pixie stick nicks your foe!\n");
      return 3;
      
   }
   return;
}
	