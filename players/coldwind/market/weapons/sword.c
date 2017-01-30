#include "/players/coldwind/define.h"
inherit "obj/weapon.c";

reset(arg){
  ::reset(arg);
  if (arg) return;

set_name(BOLD+"hosam"+NORM);
set_short(BOLD+"Hosam "+NORM+"the broadsword");
set_long(
  "   Hosam has a wide blade and extremly sharp edges. A\n"+
  "few stars decorates the hilt of the broadsword. The\n"+
  "weapon is finely made, but it is somewhat heavy and\n"+
  "would require great strength to take full advantage of.\n");

set_type("sword"); 
set_class(17);
set_weight(5);
set_value(10000);
set_hit_func(this_object());
}

weapon_hit(attacker){
int W;

W = random(20);
if (W>16) {
	write("Your broadsword "+HIR+"cuts "+NORM+"deep into "+BOLD+attacker->query_name()+"'s"+NORM+" flesh... \n"+NORM);
	say(
	environment(this_object())->query_name()+"'s braodsword "+HIR+"cuts "+NORM+"deep into "+BOLD+attacker->query_name()+"'s"+NORM+" flesh... \n"+NORM);            
	return 7;
       }
	   if (W>11)
	   if( random(tp->query_attrib("str")) > 15)
      {
	write(HIC+"You feel better as Hosam drinks from "+attacker->query_name()+"'s "+HIR+"blood"+HIC+" and heals you..\n"+NORM);
	say(HIC+
	""+environment(this_object())->query_name()+" heals as the broadsword drinks from "+attacker->query_name()+"'s "+HIR+"blood"+HIC+".\n"+NORM);
	return 4;
	this_player()->heal_self(random(2) +1);

       }
return 0;
}  	
  	
