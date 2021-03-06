/*
 * Blue Octorok
 * /Nintendo/Zelda/mob4.c
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
  		
     	set_name("octorok");
     	set_alias("octorok");
     	set_short(""+HIB+"A Blue Octorok"+NORM+"");
     	set_race( "Octorok");
     	set_gender("male");
     	set_long("It appears to be a blue, octopus-like creature with a long\n"+
                 "mouth that protrudes from the small, round creature.\n");     
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
