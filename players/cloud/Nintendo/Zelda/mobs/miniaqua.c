/*
 * Mini Aquadonger(s)
 * /Nintendo/Zelda/miniaqua.c
 * Cloud 2015
 * Special Attack
 * Blocks Exits
 * Agressive
 */
 
#include "/obj/ansi.h";
inherit "/obj/monster";

reset(arg) 
{
   ::reset(arg);
   if (!arg) 
   {	
     	set_name(""+RED+"Aquadonger"+NORM+"");
     	set_alt_name("mini");
     	set_alt_name("dogger");
     	set_alias("minidogger");
     	set_short(""+RED+"Mini Aquadonger"+NORM+"");
     	set_race( "Urchin");
     	set_gender("urchin");
     	set_long("\n"+
                 "\n");     
     	set_level(20);
     	set_ac(17);
     	set_wc(30);
     	set_hp(500);
     	set_al(-500);
     	set_aggressive(1);
     	
     	if(!present("rupee")) 
     		{
     			move_object(clone_object("players/cloud/Nintendo/Zelda/obj/redrupee.c"),
       			this_object());
   			}	
		
   }
}

void init()
{  	 
   	::init();
   	add_action("nogou","up");
   	add_action("nogod","down");
   	if (this_player() && this_player()->is_player())
   	{        
    	say(query_name() + " jumps to attack " + this_player()->query_name() + " !!!\n");
    	attack_object(this_player());       
   	}
}

nogou() 
{
	write("A Aquadonger blocks the exit!\n");
	return 1;
}
nogod() 
{
	write("A Aquadonger blocks the exit!\n");
	return 1;
}

heart_beat()
{
	int A;
	int B;
	int C;
	A = random(100);
	B = random(100);
	C = random(100);
	::heart_beat();
	if(!environment()) return;
  	if(attacker_ob && present(attacker_ob, environment(this_object())))
  	{
  		if(A > 89) pounce();
    	if(B > 89) dragon_breath();
    	if(C > 89) tail_swipe();
  	}
}

pounce()
{
	tell_object(attacker_ob,
    "\n\t"+HIY+""+query_name()+""+NORM+" leaps at you, pummeling into your chest!\n\n");  
    
  	tell_room(environment(),
   "\n\t"+HIY+""+query_name()+""+NORM+" leaps at "+attacker_ob->query_name()+" pummeling them in the chest!\n\n",({attacker_ob}));

    attacker_ob->hit_player(20+random(10), "other|earth");
}

dragon_breath()
{
	tell_object(attacker_ob,
    "\n\t"+HIG+""+query_name()+""+NORM+" blasts you with a cone of fire.\n\n");  
    
  	tell_room(environment(),
   "\n\t"+HIG+""+query_name()+""+NORM+" blasts "+attacker_ob->query_name()+" with a cone of fire .\n\n",({attacker_ob}));

    attacker_ob->hit_player(20+random(10), "other|fire");
}

tail_swipe()
{
	tell_object(attacker_ob,
    "\n\t"+HIY+""+query_name()+""+NORM+" sweeps its tail into your chest.\n\n");  
    
  	tell_room(environment(),
   "\n\t"+HIY+""+query_name()+""+NORM+" sweeps its tail into "+attacker_ob->query_name()+" knocking the wind out of them.\n\n",({attacker_ob}));

    attacker_ob->hit_player(20+random(10), "other|earth");
}




