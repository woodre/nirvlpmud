#include "/players/maledicta/ansi.h"
inherit "obj/weapon.c";

reset(arg){
  ::reset(arg);
  if (arg) return;
set_name("vaxe");

set_short("Vibro-Axe");
set_long(
  " This huge Axe is made of titanium. From its oversized double-edged\n"+
  "head, to the long steel haft, it is sturdy and deadly. A high powered\n"+
  "micro motor gives its razor sharp edge a rythmic pulse that allows\n"+
  "it to slice through nearly any material.\n");

set_type("axe"); 
set_class(17);
set_weight(3);
set_value(1000);
set_hit_func(this_object());
}

weapon_hit(attacker){

if(random(100) < 20){
	write("Your vibro-axe "+HIR+"CUTS"+NORM+" into "+attacker->query_name()+" "+
	"with a vengeance!\n");
	say(
	environment(this_object())->query_name()+" "+BOLD+""+BLK+"CUTS"+NORM+" "+
	""+attacker->query_name()+" deep in the chest!\n");
	return 2;
       }
return 0;
}  	
  	
