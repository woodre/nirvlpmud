/*
 * Digdogger
 * /Nintendo/Zelda/dig.c
 * Cloud 2015
 * Splits into four smaller digdoggers after being hit
 * Place Holder
 * 
 */
 
#include "/obj/ansi.h";
inherit "/obj/monster";
#define DEST "/players/cloud/Nintendo/Zelda/rooms/dun5.c"



reset(arg) 
{
   ::reset(arg);
   if (!arg) 
   {	
     	set_name(""+HIY+"Digdogger"+NORM+"");
     	set_alt_name("dig");
     	set_alt_name("urchin");
     	set_alias("digdogger");
     	set_short(""+HIY+"Digdogger"+NORM+"");
     	set_race( "Urchin");
     	set_gender("urchin");
     	set_long("It looks like a huge sea urchin with an large, green eyeball in the middle\n"+
                 "of it. The urchin's skin is a pale yellow and covered in uneven lumps.\n");   
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
	write("You must first defeat "+HIY+"Digdogger"+NORM+" before advancing to the next level! \n");
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
    move_object(clone_object("/players/cloud/Nintendo/Zelda/mobs/minidig.c"), DEST);
    move_object(clone_object("/players/cloud/Nintendo/Zelda/mobs/minidig.c"), DEST);
    move_object(clone_object("/players/cloud/Nintendo/Zelda/mobs/minidig.c"), DEST);
    move_object(clone_object("/players/cloud/Nintendo/Zelda/mobs/minidig.c"), DEST);
    destruct(present("digdogger"));
    
    
}
