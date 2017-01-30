/*
 * Blue Moblin
 * /Nintendo/Zelda/mob3.c
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
     	set_short(""+HIB+"A Blue Moblin"+NORM+"");
     	set_race( "Moblin");
     	set_gender("male");
     	set_long("This creature looks to be a mix of a human and a bulldog.\n"+
                 "It wears a blue tunic and is carrying a large spear.\n");     
     	set_level(17);
     	set_ac(14);
     	set_wc(23 + random(2));
     	set_hp(350);
     	set_al(-500);
     	set_aggressive(0);
     	
     	X=random(100);
     	if(X > 80)
     	{     	
     		if(!present("rupee")) 
     		{
     			move_object(clone_object("players/cloud/Nintendo/Zelda/obj/yellowrupee.c"),
       			this_object());
   			}
		}
		
		else
		{
			if(!present("rupee")) 
     		{
     			move_object(clone_object("players/cloud/Nintendo/Zelda/obj/bluerupee.c"),
       			this_object());
   			}	
		}
   }
   
}
