/*
 * Dodongo
 * /Nintendo/Zelda/dodo.c
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
     	set_name(""+HIY+"Dodongo"+NORM+"");
     	set_alt_name("lizard");
     	set_alt_name("dodo");
     	set_alias("dodongo");
     	set_short(""+HIY+"Dodongo"+NORM+"");
     	set_race( "Dinosaur");
     	set_gender("male");
     	set_long("Overlapping yellow scales rib this beast from head to tail. A large,\n"+
                 "sharp horn pertrudes from its massive head. The mouth of this lizard-\n"+
                 "looking creature is full of many large, jagged teeth.\n");     
     	set_level(19);
     	set_ac(16 + random(2));
     	set_wc(28 + random(2));
     	set_hp(450 + random(50));
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
	write("You must first defeat "+HIY+"Dodongo"+NORM+" before advancing to the next level! \n");
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
    	if(B > 59) tail_swipe();
  	}
}

tail_swipe()
{
	tell_object(attacker_ob,
    "\n\t"+HIY+""+query_name()+""+NORM+" sweeps its tail into your chest.\n\n");  
    
  	tell_room(environment(),
   "\n\t"+HIY+""+query_name()+""+NORM+" sweeps its tail into "+attacker_ob->query_name()+" knocking the wind out of them.\n\n",({attacker_ob}));

    attacker_ob->hit_player(25+random(15), "other|earth");
}
