/*
 * Red Darknut
 * /Nintendo/Zelda/mob6.c
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
  		
     	set_name("darknut");
     	set_alias("darknut");
     	set_short(""+HIR+"A Red Darknut"+NORM+"");
     	set_race( "Darknut");
     	set_gender("male");
     	set_long("Thick Red armor and a sturdy steel shield make up this knight-like creature.\n"+
                 "No eyes can be seen from behind the large metal helmet its wearing.\n");     
     	set_level(17);
     	set_ac(14);
     	set_wc(23);
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
