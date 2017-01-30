/*
 * Aquamentus
 * /Nintendo/Zelda/aqua.c
 * Cloud 2015
 * Special Attack
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
     	set_name(""+HIG+"Aquamentus"+NORM+"");
     	set_alt_name("dragon");
     	set_alt_name("aqua");
     	set_alias("aquamentus");
     	set_short(""+HIG+"Aquamentus"+NORM+"");
     	set_race( "Dragon");
     	set_gender("male");
     	set_long("Green scales cover this young adult dragon. He is over twenty feet\n"+
                 "tall, and eight feet wide not including his wings. A meanacing\n"+
                 "expression covers his face. Ice-blue eyes stare at your every move.\n");     
     	set_level(18);
     	set_ac(15 + random(2));
     	set_wc(26 + random(2));
     	set_hp(400 + random(50));
     	set_al(-500);
     	set_aggressive(0);
     	
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
	write("You must first defeat "+HIG+"Aquamentus"+NORM+" before advancing to the next level!\n");
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
    	if(B > 59) dragon_breath();
  	}
}

dragon_breath()
{
	tell_object(attacker_ob,
    "\n\t"+HIG+""+query_name()+""+NORM+" blasts you with a cone of fire.\n\n");  
    
  	tell_room(environment(),
   "\n\t"+HIG+""+query_name()+""+NORM+" blasts "+attacker_ob->query_name()+" with a cone of fire .\n\n",({attacker_ob}));

    attacker_ob->hit_player(20+random(10), "other|fire");
}
