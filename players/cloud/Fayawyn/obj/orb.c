/*
 *  Orb of Darkness
 *  Cloud 2009
 *	/obj/orb.c
 *	Random Drop Rate
 *	Lower Int Stat on random roll
 *  uses mana to provide special attack
*/

#include "/obj/ansi.h"
 inherit "obj/weapon.c";

 reset(arg) {
    ::reset(arg);
    if (arg) return;

    set_name("Orb");
    set_alias("orb");
    set_short(""+HIM+"Orb "+NORM+"of "+HIK+"darkness"+NORM+"");
    set_long("An "+HIK+"orb"+NORM+" made of swirling "+HIM+"purple mist"+NORM+". Energy radiates\n" +
    		 "from the orb, constently creating small gusts of "+HIC+"wind"+NORM+".\n");
    set_class(20);
    set_weight(3);
    set_value(3000);
    set_hit_func(this_object());
}

weapon_hit(attacker){
int W;
W = random(200);
if(W > 150)
{
	if(this_player()->query_sp() < 5)
	{
		return 1;
    }
	if(this_player()->query_attrib("int") > 24) 
	{
		this_player()->add_sp(-random(5));
			
    	say("\n\t"+HIK+"The orb "+HIM+"releases a bolt of darkness into its foe."+NORM+"\n\n");

   		write("\n\t"+HIM+"Your orb releases a bolt of "+HIK+"darkness"+HIM+" into your foe."+NORM+"\n\n");
    	
   		attacker->hit_player(10,"other|dark");
   		
	}
}	
if(W < 3)
{
	
	if(this_player()->query_attrib("int") > 24)
	{
		int M;
		M = (this_player()->query_attrib("int"));
		write("\n\t"+HIK+" The ORB "+HIR+"feeds"+HIK+" off your intelligence"+NORM+"\n\n");
		this_player()-> set_attrib("int", M - 1);
		this_player()->reset(1);
		this_player()->save_me();
		

		
		return 1;
	}
    	
   	else
   	{
   		write("\n\t"+HIK+" The Orb tries to harness your intelligence, but fails"+NORM+"\n\n");
   	}
}

    
return;    
}

