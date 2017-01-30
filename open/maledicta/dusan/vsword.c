#include "/players/maledicta/ansi.h"
inherit "obj/weapon.c";

reset(arg){
  ::reset(arg);
  if (arg) return;

set_name("sword");
set_short("Vibro-Sword");
set_long(
  "  This finely crafted hi-tech Blade is made of titanium, its razor sharp\n"+
  "edge honed to perfection.  Its rythmic movements allows it to slice through\n"+
  "most materials, including flesh. As its frequency matches that of its\n"+
  "victim's natural rythms, the result is nearly the same as a hot knife\n"+
  "cutting butter.\n");

set_type("sword"); 
set_class(16);
set_weight(2);
set_value(800);
set_hit_func(this_object());
}

weapon_hit(attacker){

if(random(100) < 20){
	write("Your vibro-sword "+BOLD+""+BLK+"SLASHES"+NORM+" "+
	""+attacker->query_name()+" in the chest!\n");
	say(
	environment(this_object())->query_name()+" "+BOLD+""+BLK+"SLASHES"+NORM+" "+
	""+attacker->query_name()+" deep in the chest!\n");
	return 2;
       }
return 0;
}  	
  	
