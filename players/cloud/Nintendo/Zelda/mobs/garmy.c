/*
 * Ganon Army Summon
 * /Nintendo/Zelda/garmy.c
 * Cloud 2015
 * Blocks exit for Ganon
 */

 
#include "/obj/ansi.h";
inherit "/obj/monster";

reset(arg) 
{
   ::reset(arg);
   if (!arg) 
   {	
     	set_name("moblin");
     	set_alias("moblin");
     	set_short(""+HIW+"Moblin Guard"+NORM+"");
     	set_race( "Moblin");
     	set_gender("male");
     	set_long("This creature looks to be a mix of a human and a bulldog.\n"+
                 "It wears a blue tunic and is carrying a large sword.\n");     
     	set_level(15);
     	set_ac(12);
     	set_wc(20);
     	set_hp(250);
     	set_al(-500);
     	set_aggressive(0);
   }
   
}

void init()
{
	if (this_player() && this_player()->is_player())
   	{    
	   	tell_room(environment(),
			"\n"+HIB+""+query_name()+""+NORM+" jumps to attack "+this_player()->query_name()+"\n");    
    	say(query_name() + " jumps to attack " + this_player()->query_name() + " !!!\n");
    	attack_object(this_player());       
   	}  	 
   	::init();
   	add_action("nogod","down");
}

nogod() 
{
	write("The moblin guard blocks your path.\n");
	return 1;
}