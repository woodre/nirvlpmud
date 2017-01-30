/*
 * Link
 * /Nintendo/Zelda/mobs/link.c
 * Cloud 2015
 * Trades coins for rupee's found in the Zelda area
 * Very Rare Chance to Drop Good Equipment. 5%Tunic 10%Shield 20%Sword
 * Heals while fighting, enhanced WC, AC and HP, Runs, Strong Special Attack, Placebo Attack
 */
 

 
#include "/obj/ansi.h";
inherit "/obj/monster";
int X;
int Z;
int Y;

reset(arg) 
{
   ::reset(arg);
   if (!arg) 
   {
	   	object gold;
  		gold = clone_object("obj/money");
  		gold->set_money(30000);
  		move_object(gold,this_object());
  		
     	set_name(""+HIG+"Link"+NORM+"");
     	set_alias("link");
     	set_short(""+HIG+"Link"+NORM+"");
     	set_race( "Hylian");
     	set_gender("male");
     	set_long(
     	"A short hylian looking fellow wearing a weird green tunic.\n"+
        "His ears point out from inside a long green hood. You may\n"+
        "be able to "+HIM+"trade"+NORM+" him some rupee's for some coin\n");    
     	set_level(29);
     	set_ac(28 + random(3));
     	set_wc(55 + random(3));
     	set_hp(2200 + random(100));
     	set_al(1000);
     	set_aggressive(0);
     	
     	X=random(100);
     	if(X > 94)
     	{     	
     		if(!present("tunic")) 
     		{
     			move_object(clone_object("players/cloud/Nintendo/Zelda/obj/tunic.c"),
       			this_object());
   			}
		}
		Z=random(100);
		if(Z > 89)
		{
			if(!present("shield"))
			{
				move_object(clone_object("players/cloud/Nintendo/Zelda/obj/shield.c"),
				this_object());
			}		
		}
		Y=random(100);
		if(Y > 79)
		{
			if(!present("sword"))
			{
				move_object(clone_object("players/cloud/Nintendo/Zelda/obj/sword.c"),
				this_object());
			}
		}		
		
	}
}

heart_beat()
{
	int B;
	B = random(20);
	::heart_beat();
	if(!environment()) return;
  	if(attacker_ob && present(attacker_ob, environment(this_object())))
  	{
    	if(B == 0) cross_slash();
    	if(B == 1) cross_slash();
    	if(B == 2) fancy_strike();
    	if(B == 3) link_heal();
    	if(B == 4) fancy_strike();
    	if(B == 5) cross_slash();
    	if(B == 6) fancy_strike();
    	if(B == 9) link_heal();
    	if(B == 11) cross_slash();
    	if(B == 13) cross_slash();
    	if(B == 19) link_retreat();
  	}
}

cross_slash()
{
	tell_object(attacker_ob,
    "\n\t"+HIG+""+query_name()+" performs a"+HIW+""+BOLD+" Cross"+HIK+"-"+HIR+"Slash"+NORM+" maneuver. The "+HIB+"Master "+HIW+"Sword"+NORM+" carves into your flesh.\n\n");  
    
  	tell_room(environment(),
   	"\n\t"+HIG+""+query_name()+" performs a"+HIW+""+BOLD+" Cross"+HIK+"-"+HIR+"Slash"+NORM+" on "+attacker_ob->query_name()+".\n\n",({attacker_ob}));

    attacker_ob->hit_player(80+random(20), "other|light");
}

link_retreat()
{
	

	tell_object(attacker_ob,
   	"\n\t"+HIG+""+query_name()+""+NORM+" steps back from the fight.\n\n" +
   	"\tHe then opens a small bottle. A fairy rushes out and\n" +
   	"\tswirls about him. Grinning, "+HIG+"Link"+NORM+" corks the bottle.\n\n");
	
	tell_room(environment(),
   	"\n\t"+HIG+""+query_name()+""+NORM+" steps back from the fight.\n\n" +
   	"\tHe then opens a small bottle. A fairy rushes out and\n" +
   	"\tswirls about him. Grinning, "+HIG+"Link"+NORM+" corks the bottle.\n\n",({attacker_ob})); 
   	
   	random_move();
   
	this_object()->add_hit_point(40 + random(20));
   
}

link_heal()
{
	tell_object(attacker_ob,
	"\n\t"+HIG+""+query_name()+""+NORM+" takes a swig of "+HIW+"milk"+NORM+" and looks much better.\n\n");
	
	tell_room(environment(),
	"\n\t"+HIG+""+query_name()+""+NORM+" takes a swig of "+HIW+"milk"+NORM+" and looks much better.\n\n",({attacker_ob}));
	
	this_object()->add_hit_point(30 + random(10));
}

fancy_strike()
{
    tell_object(attacker_ob,
	"\n\t"+HIG+""+query_name()+" swirls the "+HIB+"Master "+HIW+"Sword"+NORM+" around his body"+NORM+".\n\n");
	
	tell_room(environment(),
	"\n\t"+HIG+""+query_name()+" swirls the "+HIB+"Master "+HIW+"Sword"+NORM+" around his body"+NORM+".\n\n",({attacker_ob}));
}

init()
{
	::init();
	add_action("trade","trade");
}

trade(str)
{
	object green, blue, yellow, red, purple;
    green = present("green_rupee", this_player());
    blue = present("blue_rupee", this_player());
    yellow = present("yellow_rupee", this_player());
    red = present("red_rupee", this_player());
    purple = present("purple_rupee", this_player());

	if(str == "rupee")
    {
	        
		if(green)
       	{
			write("Link takes the rupee and gives you 1000 coins.\n");
           	this_player()->add_money(1000); 
           	destruct(green);
        	return 1;
       	}
                
      	if(blue)
      	{
			write("Link takes the rupee and gives you 1500 coins.\n");
          	this_player()->add_money(1500); 
          	destruct(blue);
        	return 1;
       	}
       	
       	if(yellow)
      	{
			write("Link takes the rupee and gives you 2000 coins.\n");
          	this_player()->add_money(2000); 
          	destruct(yellow);
        	return 1;
       	}
                
       	if(red)
      	{
			write("Link takes the rupee and gives you 2500 coins.\n");
         	this_player()->add_money(2500); 
         	destruct(red);
        	return 1;
      	}
                
       	if(purple)
      	{
			write("Link takes the rupee and gives you 5000 coins.\n");
          	this_player()->add_money(5000); 
          	destruct(purple);
			return 1;
        }
                
        else
		{
	    	write("Link says, It looks like you dont have any rupee's to trade. \n");
			return 1;
		}
		
	}
	
	else
	{
		write("Link says, I only trade coins for rupee's. \n");
		return 1;
	}	
	
}
   