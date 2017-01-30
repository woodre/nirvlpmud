/*
 * Mini Didogger(s)
 * /Nintendo/Zelda/minidig.c
 * Cloud 2015
 * Special Attack
 * Blocks Exits
 * Slightly Increased AC/WC/HP
 * Agressive
 */
 
#include "/obj/ansi.h";
inherit "/obj/monster";

reset(arg) 
{
   ::reset(arg);
   if (!arg) 
   {	
     	set_name(""+HIY+"MiniDogger"+NORM+"");
     	set_alt_name("mini");
     	set_alt_name("dogger");
     	set_alias("minidogger");
     	set_short(""+HIY+"MiniDogger"+NORM+"");
     	set_race( "Urchin");
     	set_gender("urchin");
     	set_long("It looks like a large sea urchin with a big, green eyeball in the middle\n"+
                 "of it. The urchin's skin is a pale yellow and covered in uneven lumps.\n");     
     	set_level(15);
     	set_ac(13);
     	set_wc(21);
     	set_hp(250 + random(50));
     	set_al(-500);
     	set_aggressive(1);
     	
     	if(!present("rupee")) 
     		{
     			move_object(clone_object("players/cloud/Nintendo/Zelda/obj/yellowrupee.c"),
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
	write("Minidogger blocks the exit!\n");
	return 1;
}
nogod() 
{
	write("Minidogger blocks the exit!\n");
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
    	if(B > 89) pounce();
  	}
}

pounce()
{
	tell_object(attacker_ob,
    "\n\t"+HIY+""+query_name()+""+NORM+" leaps at you, pummeling into your chest!\n\n");  
    
  	tell_room(environment(),
   "\n\t"+HIY+""+query_name()+""+NORM+" leaps at "+attacker_ob->query_name()+" pummeling them in the chest!\n\n",({attacker_ob}));

    attacker_ob->hit_player(10+random(20), "other|earth");
}



