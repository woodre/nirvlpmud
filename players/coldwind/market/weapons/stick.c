#include "/players/coldwind/define.h"
inherit "obj/weapon.c";

reset(arg){
  ::reset(arg);
  if (arg) return;

set_name("stick");
set_short("Wooden stick");
set_long(
  "  You are looking at a long wooden stick. It seems light,\n"+
  "but could be quite deadly for those who learn how to use it.\n"+
  "On a closer look, you notice some deep scratches in the oak\n"+
  "stick.\n");

set_type("stick"); 
set_class(14);
set_weight(2);
set_value(1100);
set_hit_func(this_object());
}

weapon_hit(attacker){

if(random(100) < 20){
	write("You block "+ attacker->query_name()+"'s attack with your stick..\n"+
	      "    "+BOLD+"You SMASH your stick on "+attacker->query_name()+"'s shoulder.\n"+NORM);
	say(
	environment(this_object())->query_name()+" blocks "+attacker->query_name()+"'s attack with the stick..\n"+
	            ""+BOLD+""+environment(this_object())->query_name()+" SMASHES the stick on "+attacker->query_name()+"'s shoulder.\n"+NORM);
	return 4;
       }
return 0;
}  	
  	
