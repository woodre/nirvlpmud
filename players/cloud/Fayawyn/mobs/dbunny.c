/*
 * Dust Bunny
 * /mobs/dbunny.c
 * Cloud 2009
 */

 
#include "/obj/ansi.h"

inherit "/obj/monster";
int X;
reset(arg) 
{
   ::reset(arg);
   
   if (!arg) 
   {
		object gold;
  		gold = clone_object("obj/money");
  		gold->set_money(random(100) + 5000);
  		move_object(gold,this_object());

     	set_name("bunny");
     	set_short(""+HIK+"A Dust Bunny"+NORM+"");
     	set_race( "Bunny");
     	set_gender("male");
     	set_long("It is a large bunny made completly of dust!\n"+
         	     "Every move he makes floods the room with dust.\n");     
     	set_level(20);
     	set_ac(17);
     	set_wc(30);
     	set_hp(random(100) + 450);
     	set_al(-250);
     	set_aggressive(0);
     	set_a_chat_chance(10);
     	load_a_chat("The bunny collects more dust!\n");
 		
     	X=random(100);
     	if(X < 3)
     	{     	
     		if(!present("ring")) 
     		{
     			move_object(clone_object("players/cloud/Fayawyn/obj/dring.c"),
       			this_object());
   			}
		}
		else
		{
		return 1;
		}
   }
}

heart_beat()
{
  ::heart_beat();
  if(!environment()) return;
  if(attacker_ob && present(attacker_ob, environment(this_object())))
  {
    if(random(100) > 68) bunny_assult();

  }
}

bunny_assult()
{
  tell_object(attacker_ob,
    "\n"+HIK+"The "+query_name()+" envelops you in cone of dust."+NORM+"\n");
    
  tell_room(environment(),
   "\n"+HIK+"The "+query_name()+" envelops  "+attacker_ob->query_name()+" with a cone of dust."+NORM+"\n", ({attacker_ob}));
    
  attacker_ob->hit_player(20+random(10));
}