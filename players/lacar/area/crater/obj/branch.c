/*
*      File:             /players/lacar/area/crater/obj/branch.c
*      Function:         obj
*      Author(s):        Lacar@nirvana
*      Copyright:        Copyright (c) 2007 Lacar (Carla J Merrill)
*                                All Rights Reserved
*      Source:    		
*      Notes:           area
*      Change History:
*/
#include <ansi.h>

inherit "obj/weapon.c";
#define attacked (this_object()->query_attack())

reset(arg){
  ::reset(arg);
  if (arg) return;

set_name("branch");
set_alias("stick");
set_short("stick");
set_long("A piece of thick wood which is long and slender in apperance.\n");
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
      
      say("The branch swings at you.\n");
      write("The branch bashes your foe!\n");
      return 3;
      
   }
   return;
}
	