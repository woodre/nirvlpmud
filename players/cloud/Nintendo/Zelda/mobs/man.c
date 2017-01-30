/*
 * Manhandla
 * /Nintendo/Zelda/man.c
 * Cloud 2015
 * Special Attack
 * Agressive
 * Slightly Enhanced AC/WC/HP
 */
 
#include "/obj/ansi.h";
inherit "/obj/monster";
int X;

reset(arg) 
{
   ::reset(arg);
   if (!arg) 
   {	
     	set_name(""+MAG+"Manhandla"+NORM+"");
     	set_alt_name("man");
     	set_alt_name("plant");
     	set_alias("manhandla");
     	set_short(""+MAG+"Manhandla"+NORM+"");
     	set_race("Plant");
     	set_gender("plant");
     	set_long("It is a large, spinning, man-eating flower. The defining characteristic\n"+
                 "of this giant plant is its four symmetrical hands or claws growing around.\n"+
                 "a central core. It slowly spins in place.\n");     
     	set_level(20);
     	set_ac(17 + random(2));
     	set_wc(30 + random(2));
     	set_hp(500 + random(100));
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
	write("You must first defeat "+MAG+"Manhandla"+NORM+" before advancing to the next level! \n");
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
    	if(B > 59) flame_thrower();
  	}
}

flame_thrower()
{
	tell_object(attacker_ob,
    "\n\t"+HIY+""+query_name()+""+NORM+" engulfs you in "+RED+"FIRE"+NORM+".\n\n");  
    
  	tell_room(environment(),
   "\n\t"+HIY+""+query_name()+""+NORM+" engulfs "+attacker_ob->query_name()+" in "+RED+"FIRE"+NORM+".\n\n",({attacker_ob}));

    attacker_ob->hit_player(30+random(20), "other|fire");
}
