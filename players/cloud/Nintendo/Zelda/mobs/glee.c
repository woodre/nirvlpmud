/*
 * Gleeok
 * /Nintendo/Zelda/glee.c
 * Cloud 2015
 * Special Attacks - Fires one, two or three fireballs.
 * All three have a chance of going off same round. Damage decending.
 * Slightly Enhanced AC/WC/HP
 * Agressive
 */
 
#include "/obj/ansi.h";
inherit "/obj/monster";
int X;

reset(arg) 
{
   ::reset(arg);
   if (!arg) 
   {	
     	set_name(""+HIG+"Gleeok"+NORM+"");
     	set_alt_name("glee");
     	set_alt_name("dragon");
     	set_alias("gleeok");
     	set_short(""+HIG+"Gleeok"+NORM+"");
     	set_race( "dragon");
     	set_gender("male");
     	set_long("A giant, green, three-headed dragon. Sharp spined fins run across\n"+
                 "its back and tail. Huge wings rest against its body. The heads move \n"+
                 "back and forth, swaying almost. \n");     
     	set_level(21);
     	set_ac(19 + random(2));
     	set_wc(34 + random(2));
     	set_hp(600 + random(100));
     	set_al(-500);
     	set_aggressive(1);
     	
     	X=random(100);
     	if(X > 80)
     	{     	
     		if(!present("rupee")) 
     		{
     			move_object(clone_object("players/cloud/Nintendo/Zelda/obj/purplerupee.c"),
       			this_object());
   			}
		}
		
		else
		{
			if(!present("rupee")) 
     		{
     			move_object(clone_object("players/cloud/Nintendo/Zelda/obj/redrupee.c"),
       			this_object());
   			}	
		}
   }
}

void init()
{  	 
   	::init();
   	add_action("nogou","up");
}

nogou() 
{
	write("You must first defeat "+HIB+"Gleeok"+NORM+" before advancing to the next level! \n");
	return 1;
}

heart_beat()
{
	int B;
	B = random(100);
	::heart_beat();
	if(!environment()) return;
  	if(attacker_ob && present(attacker_ob, environment(this_object())))
  	{
    	if(B > 69) fire_one();
    	if(B > 74) fire_two();
    	if(B > 89) fire_three();
  	}
}

fire_one()
{
	tell_object(attacker_ob,
    "\n\t"+HIB+""+query_name()+""+NORM+" launches a fireball at you from its center head.\n\n");  
    
  	tell_room(environment(),
   "\n\t"+HIB+""+query_name()+""+NORM+" launches a fireball at "+attacker_ob->query_name()+" with its center head.\n\n",({attacker_ob}));

    attacker_ob->hit_player(15+random(20), "other|fire");
}

fire_two()
{
	tell_object(attacker_ob,
    "\t"+HIB+""+query_name()+""+NORM+" launches a SECOND fireball at you from its right head.\n\n");  
    
  	tell_room(environment(),
    "\t"+HIB+""+query_name()+""+NORM+" launches a SECOND fireball at "+attacker_ob->query_name()+" from right head.\n\n",({attacker_ob}));

    attacker_ob->hit_player(15+random(15), "other|fire");
}

fire_three()
{
	tell_object(attacker_ob,
    "\t"+HIB+""+query_name()+""+NORM+" launches a THIRD fireball at you from its left head.\n\n");  
    
  	tell_room(environment(),
    "\t"+HIB+""+query_name()+""+NORM+" launches a THIRD fireball at "+attacker_ob->query_name()+" from its left head.\n\n",({attacker_ob}));

    attacker_ob->hit_player(15+random(10), "other|fire");
}

