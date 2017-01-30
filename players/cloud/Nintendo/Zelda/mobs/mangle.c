/*
 * Mangleohma
 * /Nintendo/Zelda/mobs/mangle.c
 * Cloud 2015
 * Three mobs put into one. Manhandla/Gleeok/Gohma
 * 5 Special Attacks all can go off single round
 * Increased AC On Closed Eye
 * Agressive
 */
 
#include "/obj/ansi.h";
inherit "/obj/monster";
int E;

reset(arg) 
{
   ::reset(arg);
   if (!arg) 
   {	
     	set_name(""+HIR+"Mangleohma"+NORM+"");
     	set_alt_name("mangle");
     	set_alias("mangleohma");
     	set_short(""+HIR+"Mangleohma"+NORM+"");
     	set_race( "Mix");
     	set_gender("male");
     	set_long("\n"+
                 "\n");     
     	set_level(27);
     	set_ac(25);
     	set_wc(48);
     	set_hp(1500);
     	set_al(-500);
     	set_aggressive(1);
     	     	
     	if(!present("rupee")) 
     	{
	     	move_object(clone_object("players/cloud/Nintendo/Zelda/obj/purplerupee.c"),
       		this_object());
	     	
	     	move_object(clone_object("players/cloud/Nintendo/Zelda/obj/purplerupee.c"),
       		this_object());
	     	
     		move_object(clone_object("players/cloud/Nintendo/Zelda/obj/purplerupee.c"),
       		this_object());
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
	write("You must first defeat "+HIR+"Mangleohma"+NORM+" before advancing to the next level! \n");
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
  		if(A > 74) flame_thrower();
    	if(B > 74) shoot_beam();
		if(C > 69) fire_one();
    	if(C > 74) fire_two();
    	if(C > 89) fire_three();
    	if(E < 15) E++;
    	if(E == 4) close_eye();
		if(E == 11) open_eye();
		if(E == 15) E = 0;
	} 
		
	
}

shoot_beam()
{
	tell_object(attacker_ob,
    "\n\t"+HIC+""+query_name()+""+NORM+" shoots a beam of light at you.\n\n");  
    
  	tell_room(environment(),
   "\n\t"+HIC+""+query_name()+""+NORM+" shoots a beam of light at "+attacker_ob->query_name()+".\n\n",({attacker_ob}));

    attacker_ob->hit_player(30+random(10), "other|laser");
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

flame_thrower()
{
	tell_object(attacker_ob,
    "\n\t"+HIY+""+query_name()+""+NORM+" engulfs with "+RED+"FIRE"+NORM+".\n\n");  
    
  	tell_room(environment(),
   "\n\t"+HIY+""+query_name()+""+NORM+" engulfs "+attacker_ob->query_name()+" in "+RED+"FIRE"+NORM+".\n\n",({attacker_ob}));

    attacker_ob->hit_player(30+random(10), "other|fire");
}

fire_one()
{
	tell_object(attacker_ob,
    "\n\t"+HIB+""+query_name()+""+NORM+" launches a fireball at you from its center head.\n\n");  
    
  	tell_room(environment(),
   "\n\t"+HIB+""+query_name()+""+NORM+" launches a fireball at "+attacker_ob->query_name()+" with its center head.\n\n",({attacker_ob}));

    attacker_ob->hit_player(15+random(10), "other|fire");
}

fire_two()
{
	tell_object(attacker_ob,
    "\t"+HIB+""+query_name()+""+NORM+" launches a SECOND fireball at you from its right head.\n\n");  
    
  	tell_room(environment(),
    "\t"+HIB+""+query_name()+""+NORM+" launches a SECOND fireball at "+attacker_ob->query_name()+" from right head.\n\n",({attacker_ob}));

    attacker_ob->hit_player(15+random(10), "other|fire");
}

fire_three()
{
	tell_object(attacker_ob,
    "\t"+HIB+""+query_name()+""+NORM+" launches a THIRD fireball at you from its left head.\n\n");  
    
  	tell_room(environment(),
    "\t"+HIB+""+query_name()+""+NORM+" launches a THIRD fireball at "+attacker_ob->query_name()+" from its left head.\n\n",({attacker_ob}));

    attacker_ob->hit_player(15+random(10), "other|fire");
}

