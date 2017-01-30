/*
 * Blue Tektite
 * /Nintendo/Zelda/mob5.c
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
  		
     	set_name("tektite");
     	set_alias("tektite");
     	set_short(""+HIB+"A Blue Tektite"+NORM+"");
     	set_race( "Tektite");
     	set_gender("male");
     	set_long("A blue spider-like creature. It jumps around the area with \n"+
                 "strong legs. It seems to be very dexterous.  \n");     
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
