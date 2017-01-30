/*
 * Gohma
 * /Nintendo/Zelda/mobs/gohma.c
 * Cloud 2015
 * Special Attacks
 * Increased AC On Closed Eye
 * Slightly Increased HP/AC/WC
 * Agressive
 */
 
#include "/obj/ansi.h";
inherit "/obj/monster";
int E;
int X;

reset(arg) 
{
   ::reset(arg);
   if (!arg) 
   {	
     	set_name(""+HIC+"Gohma"+NORM+"");
     	set_alt_name("gohma");
     	set_alt_name("arthropod");
     	set_alias("gohma");
     	set_short(""+HIC+"Gohma"+NORM+"");
     	set_race( "arthropod");
     	set_gender("male");
     	set_long("It is a giant blue arthropod with a prominent single eye. It has six legs and\n"+
                 "two pincers under the eye, which seems to be its mouth.\n");     
     	set_level(22);
     	set_ac(20 + random(2));
     	set_wc(38 + random(2));
     	set_hp(700 + random(100));
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
	write("You must first defeat "+HIC+"Gohma"+NORM+" before advancing to the next level! \n");
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
    	if(B > 59) shoot_beam();
    	if(E < 10) E++;
    	if(E == 4) close_eye();
		if(E == 9) open_eye();
		if(E == 10) E = 0;
	} 
		
	
}

shoot_beam()
{
	tell_object(attacker_ob,
    "\n\t"+HIC+""+query_name()+""+NORM+" shoots a beam of light at you.\n\n");  
    
  	tell_room(environment(),
   "\n\t"+HIC+""+query_name()+""+NORM+" shoots a beam of light at "+attacker_ob->query_name()+".\n\n",({attacker_ob}));

    attacker_ob->hit_player(40+random(20), "other|laser");
}

close_eye()
{ 	
    	tell_room(environment(),
    	"\n\t"+HIC+"Gohma "+HIR+"Closes"+HIC+" His Eye, Shielding Him From Damage!!"+NORM+".\n\n");    
    	/* Find command to increase temporary ac without increasing EXP */  	
}

open_eye()
{	
    	tell_room(environment(),
    	"\n\t"+HIC+"Gohma "+HIR+"Opens"+HIC+" His Eye!!"+NORM+".\n\n");
    	/* Find command to return ac back to initial ac */
    	 	
}
