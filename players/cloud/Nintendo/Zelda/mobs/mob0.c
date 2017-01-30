/*
 * Red Moblin
 * /Nintendo/Zelda/mob0.c
 * Cloud 2010
 */

 
#include "/obj/ansi.h";
inherit "/obj/monster";
int X;

reset(arg) 
{
   ::reset(arg);
   if (!arg) 
   {
	   	object gold;
  		gold = clone_object("obj/money");
  		gold->set_money(0);
  		move_object(gold,this_object());
  		
     	set_name("moblin");
     	set_alias("moblin");
     	set_short(""+HIR+"A Red Moblin"+NORM+"");
     	set_race( "Moblin");
     	set_gender("male");
     	set_long("This creature looks to be a mix of a human and a bulldog.\n"+
                 "It wears a red tunic and is carrying a large spear.\n");     
     	set_level(16);
     	set_ac(13);
     	set_wc(21 + random(2));
     	set_hp(300);
     	set_al(-500);
     	set_aggressive(0);
     	
     	X=random(100);
     	if(X > 80)
     	{     	
     		if(!present("rupee")) 
     		{
     			move_object(clone_object("players/cloud/Nintendo/Zelda/obj/bluerupee.c"),
       			this_object());
   			}
		}
		
		else
		{
			if(!present("rupee")) 
     		{
     			move_object(clone_object("players/cloud/Nintendo/Zelda/obj/greenrupee.c"),
       			this_object());
   			}	
		}
   }
}
