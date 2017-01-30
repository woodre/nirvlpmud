#include "/players/coldwind/define.h"
inherit "obj/weapon.c";

reset(arg){
  ::reset(arg);
  if (arg) return;

set_name("bow");
set_short("Bow and "+HIY+"fire"+NORM+" arrows");
set_long(
  "   This simple arabian bow is well ballanced; its string is\n"+
  "tight and strong. A bag of magical arrows comes with the bow.\n"+
  "The arrow heads are pointed and covered with a strange substance\n"+
  "that can burst in fire from the slightest friction. You think the\n"+
  "arrows should burn your foes as they hit them.\n");

set_type("bow"); 
set_class(15);
set_weight(2);
set_value(3000);
set_hit_func(this_object());
}

weapon_hit(attacker){

if(random(100) < 20){
	write("Your arrow "+HIK+"HITS "+NORM+""+attacker->query_name()+" in the chest..\n"+
	""+HIR+"Flames "+NORM+"burst from "+attacker->query_name()+". \n");
	say(
	environment(this_object())->query_name()+"'s arrow "+HIK+" HITS "+NORM+""+attacker->query_name()+" in the chest..\n"+
	""+HIR+"Flames "+NORM+"burst from "+attacker->query_name()+". \n");
	return 6;
       }
return 0;
}  	
  	
