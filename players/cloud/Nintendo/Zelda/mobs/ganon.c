/*
 * Ganon
 * /Nintendo/Zelda/mobs/ganon.c
 * Cloud 2015
 * Blocks Exit if moblins are summoned
 * Summons Monsters
 * Heals while fighting, enhanced WC, AC and HP
 * Very Powerful Special Attack 
 */
 
#include "/obj/ansi.h";
inherit "/obj/monster";
#define DEST "/players/cloud/Nintendo/Zelda/rooms/dun9.c"
int X;
int A;

reset(arg) 
{
   ::reset(arg);
   if (!arg) 
   {	
     	set_name(""+RED+"Ganon"+NORM+"");
     	set_alias("ganon");
     	set_short(""+RED+"Ganon"+NORM+"");
     	set_race( "Beast");
     	set_gender("male");
     	set_long("\n"+
        		 "\n"+
        		 "\n");    
     	set_level(29);
     	set_ac(28 + random(3));
     	set_wc(55 + random(3));
     	set_hp(2200 + random(100));
     	set_al(1000);
     	set_aggressive(0);
     	X=random(100);
     	if(X > 89)
     	{     	
     		if(!present("egg")) 
     		{
     			move_object(clone_object("players/cloud/Nintendo/Zelda/obj/egg.c"),
       			this_object());
   			}
		}
		
		else
		{
			if(!present("triforce")) 
     		{
     			move_object(clone_object("players/cloud/Nintendo/Zelda/obj/triforce.c"),
       			this_object());
   			}	
		}	
     	
     			
		
	}
}

heart_beat()
{
	int B;
	B = random(25);
	::heart_beat();
	if(!environment()) return;
  	if(attacker_ob && present(attacker_ob, environment(this_object())))
  	{
    	if(B == 0) ganon_shadow();
    	if(B == 1) ganon_pound();
    	if(B == 2) ganon_magma();
    	if(B == 3) ganon_heal();
    	if(B == 4) ganon_summon();
    	if(B == 5) ganon_pound();
    	if(B == 6) ganon_magma();
    	if(B == 9) ganon_heal();
    	if(B == 11) ganon_pound();
    	if(B == 13) ganon_pound();
    	if(B == 19) ganon_magma();
    	if(B == 20) ganon_heal();
    	if(B == 21) ganon_summon();
    	if(B == 22) ganon_pound();
    	if(B == 23) ganon_magma();
    	if(B == 24) ganon_shadow();
  	}
}

ganon_pound()
{
	tell_object(attacker_ob,
    "\n\t"+RED+""+query_name()+""+HIK+" POUNDS"+NORM+" you with his huge fist.\n\n");  
    
  	tell_room(environment(),
   	"\n\t"+RED+""+query_name()+""+HIK+"POUNDS"+NORM+" "+attacker_ob->query_name()+" with his huge fist.\n\n",({attacker_ob}));

    attacker_ob->hit_player(80+random(20), "other|dark");
}

ganon_shadow()
{
	

	tell_object(attacker_ob,
   		"\n\t"+RED+""+query_name()+""+HIK+" disappears into the SHADOWS."+NORM+"\n\n" +
   		"\t"+HIK+"You feel something brush past you several times in fast succession."+NORM+"\n" +
   		"\t"+RED+""+query_name()+""+HIK+" reappears behind you, shoving his claws deep into your back."+NORM+"\n\n");	
	tell_room(environment(),
   		"\n\t"+RED+""+query_name()+""+HIK+" disappears into the SHADOWS."+NORM+"\n\n" +
   		"\t"+HIK+"You feel something brush past you several times in fast succession."+NORM+"\n" +
   		"\t"+RED+""+query_name()+""+HIK+" reappears behind "+attacker_ob->query_name()+", shoving his claws deep into their back."+NORM+"\n\n",({attacker_ob}));  
	attacker_ob->hit_player(150+random(50), "other|dark");
   
}

ganon_heal()
{
	tell_room(environment(),
			"\n\t"+RED+""+query_name()+" shimmers with a red light!"+NORM+"\n\n");
	this_object()->add_hit_point(40 + random(5));
}

ganon_magma()
{
    tell_object(attacker_ob,
		"\n\t"+RED+""+query_name()+" spews"+RED+" MAGMA"+NORM+" all over you! You cry out in pain!!"+NORM+".\n\n");	
	tell_room(environment(),
		"\n\t"+RED+""+query_name()+" spews"+RED+" MAGAMA"+NORM+" all over "+attacker_ob->query_name()+". They cry out in pain!!\n\n",({attacker_ob}));	
	attacker_ob->hit_player(100+random(50), "other|fire");
}

ganon_summon()
{
	if(A < 5)
	{
		tell_room(environment(),
			"\n\t"+RED+""+query_name()+""+NORM+" growls loudly and a moblin joins the battle!\n\n");   
    	move_object(clone_object("/players/cloud/Nintendo/Zelda/mobs/garmy.c"), DEST);
    	A++;
	}
	else
	{
		tell_room(environment(),
			"\n\t"+RED+""+query_name()+" shimmers with a red light!"+NORM+"\n\n");
	}
	
}