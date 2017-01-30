/*
*      File:             /players/lacar/area/park/obj/club2.c
*      Function:         obj
*      Author(s):        Lacar@nirvana
*      Copyright:        Copyright (c) 2006 Lacar (Carla J Merrill)
*                                All Rights Reserved
*      Source:    	11/22/2006
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
set_short("Stone club");
set_long("A club made from stone. It looks like the giant just took \n\
it right from a cave.\n");
set_type("club");
set_class(12);
set_weight(8);
set_value(100);
set_hit_func(this_object());
}

weapon_hit(attacker){
   int W;
   W = random(20);
   if(W > 15)  {
      
      say("The club knocks you down!\n");
      write("The club smahes your foe!\n");
      return 3;
      
   }
   return;
}
	