/*
 * Aquadonger
 * /Nintendo/Zelda/mobs/aquadong.c
 * Cloud 2015
 * Three mobs put into one. Aquamentus/Dodongo/Digdogger
 * Splits into 4 smaller Aquadongers after being hit
 * Place Holder
 */

#include "/obj/ansi.h";
inherit "/obj/monster";
#define DEST "/players/cloud/Nintendo/Zelda/rooms/dun8.c"



reset(arg) 
{
   ::reset(arg);
   if (!arg) 
   {	
     	set_name(""+HIR+"Aquadonger"+NORM+"");
     	set_alt_name("aqua");
     	set_alias("aquadonger");
     	set_short(""+HIR+"Aquadonger"+NORM+"");
     	set_race( "Mix");
     	set_gender("male");
     	set_long("\n"+
                 ".\n");   
     	set_level(1);
     	set_ac(1);
     	set_wc(1);
     	set_hp(5000);
     	set_al(-500);
     	set_aggressive(0);
     	set_no_exp_value();
     	
     	
   }
}

void init()
{  	 
   	::init();
   	add_action("nogou","up");
}

nogou() 
{
	write("You must first defeat "+HIR+"Aquadonger"+NORM+" before advancing to the next level! \n");
	return 1;
}

heart_beat()
{
	int B;
	B = (1 + random(100));
	::heart_beat();
	if(!environment()) return;
  	if(attacker_ob && present(attacker_ob, environment(this_object())))
  	{
    	if(B > 0) break_apart();
  	}
}

break_apart()
{ 
	tell_room(environment(),
	"\n\t"+HIY+""+query_name()+""+NORM+" breaks apart into several smaller clones of itself!\n\n");   
    move_object(clone_object("/players/cloud/Nintendo/Zelda/mobs/miniaqua.c"), DEST);
    move_object(clone_object("/players/cloud/Nintendo/Zelda/mobs/miniaqua.c"), DEST);
    move_object(clone_object("/players/cloud/Nintendo/Zelda/mobs/miniaqua.c"), DEST);
    move_object(clone_object("/players/cloud/Nintendo/Zelda/mobs/miniaqua.c"), DEST);
    destruct(present("aquadonger"));
    
    
}
