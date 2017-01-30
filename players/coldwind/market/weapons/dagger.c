#include "/players/coldwind/define.h"
inherit "obj/weapon.c";

reset(arg){
  ::reset(arg);
  if (arg) return;

set_name("dagger");
set_short("Dark dagger");
set_long(
  "   A well-balanced dagger gleams with dark light.\n"+
  "It's short blade has a slight twist and the handle\n"+
  "is wrapped in leather to allow better holding.\n");

set_type("dagger"); 
set_class(16);
set_weight(2);
set_value(5000);
set_hit_func(this_object());
}

weapon_hit(attacker){

if(random(100) < 20){
	write("Your dagger "+HIK+"gleams "+NORM+"with darkness..\n"+
	      "         "+RED+"Blood splashs the floor as you open "+attacker->query_name()+"'s gut. \n"+NORM);
	say(
	environment(this_object())->query_name()+"'s dagger "+HIK+"gleams "+NORM+"with darkness..\n"+
	                     "         "+RED+"Blood splashs the floor as you open "+attacker->query_name()+"'s gut. \n"+NORM);            
	return 5;
       }
return 0;
}  	
  	
