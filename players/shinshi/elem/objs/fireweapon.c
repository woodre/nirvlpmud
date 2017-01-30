#include <ansi.h>
inherit "/obj/weapon.c";

int dtype;									/* We'll use this for seeing what type of dtype we're gonna do */

reset(arg) {
	::reset(arg);
	
	if(arg) return;
	set_id("staff");
	set_alias("wicket_elementalist_staff");
	set_short("An "+RED+"Ancient "+NORM+"Staff of the "+RED+"El"+YEL+"em"+GRN+"en"+CYN+"ts"+NORM+" ("+BOLD+"Enshrouded"+NORM+" in "+HIR+"Fire"+NORM+")");     /* Fix this if you'd like! */
	set_long(
	"A solid wooden staff that has been weathered and beaten. Down the\n"+							/* Fix this, obviously ;) */
	"long wooden shaft of the staff are tattered and well worn. A glowing\n"+
	"orb rests at the top of the staff between some piece of the staff\n"+
	"that seem to wrap around the orb holding onto the orbs life essence.\n"+
	"Ancient Symbols are carved down the side of the staff and hum with\n"+
	"amazing power.\n"+
	"                   "+RED+"        00000                                   \n"+
	"                          0     0                                  \n"+
	"                          0     0                                  \n"+
	"                          0     0                                  \n"+
	"                           00000                                   \n"+
	"                            Fire"+NORM+"                                   \n");
	set_weight(2);
 set_class(10); 
	set_value(0);							/* Worthless since they can conjure it */
	set_type("staff");
	set_params("other|fire", 5, "beat_dat_ass");
	message_hit = ({
		HIR+"A N N I H I L A T E"+NORM, " causing bones to break and shatter",
		HIR+"A N N I H I L A T E"+NORM, " through the torso",
		HIY+"crushed"+NORM, " in the ribcage",
		HIG+"busted"+NORM, " in the jaw",
		HIG+"bonked"+NORM, " on the head",
		HIC+"whacked"+NORM, " across the knuckles",
		HIC+"cracked"+NORM, " in the arm"
		
	});
}

drop()
{
	write("The "+RED+"El"+YEL+"em"+GRN+"en"+CYN+"ts"+NORM+" reclaim the staff of their ancestors!\n");
	destruct(this_object());
	return 1;
}
	

is_elementalist_weapon() { return 1; }


beat_dat_ass(attacker)
{
	object gob;
	int fire;

	gob = present("wicket_element_orb", environment(this_object()));
	
	fire = (int)gob->query_FIRE();
	
	if(!random(5))
	{
		say(this_player()->query_name()+"'s weapon "+HIY+"flashes"+NORM+" as "+RED+"fire"+NORM+" glides from the staff ripping through "+attacker->query_name()+".\n");
		  write("Your weapon "+HIY+"flashes"+NORM+" as "+RED+"fire"+NORM+" glides from the staff ripping through "+attacker->query_name()+"\n"+NORM+ 
RED+"                                                                 \n"+NORM+    
RED+"                     (     (    (                                \n"+NORM+ 
RED+"                     )\\ )  )\\ ) )\\ )                             \n"+NORM+    		
RED+"                    (()/( (()/((()/( (                           \n"+NORM+ 
RED+"                    /(_)) /(_))/(_)))\\                           \n"+NORM+   
RED+"                   (_))"+HIR+"_|"+NORM+RED+"("+HIR+"_"+NORM+RED+")) ("+HIR+"_"+NORM+RED+")) (("+HIR+"_"+NORM+RED+")                             \n"+NORM+ 
HIR+"                   | |_  |_ _|| _ \| ___|                         \n"+NORM+     
HIR+"                   | __|  | | |   /| _|                          \n"+NORM+     
HIR+"                   |_|   |___||_|_\\|____|                         \n"+NORM+                            
RED+"                     )\\ )  )\\ ) )\\ )                             \n"+NORM+                     
RED+"                    (()/( (()/((()/( (                           \n"+NORM+                         
RED+"                    /(_)) /(_))'/(_)))\\                          \n"+NORM+                            
RED+"                   ( )) |( )) ( )) (( )                          \n"+NORM+
RED+"                                                                 \n"+NORM+
RED+"             Fire"+NORM+" burns into your opponent.                  \n"+NORM+  
  "\n");                      
		return fire;
	}
}
	
/*weapon_hit(attacker)
{
	object gob;
	int air, earth, fire, water;
	int rand;
	
	gob = present("wicket_element_orb", environment(this_object()));
	rand = random(4);
	
	air = (int)gob->query_AIR();
	earth = (int)gob->query_EARTH();
	fire = (int)gob->query_FIRE();
	water = (int)gob->query_WATER();
	
	if(rand == 0)
	{
		say(this_player()->query_name()+"'s weapon "+HIY+"flashes"+NORM+" as "+RED+"fire"+NORM+" glides from the staff ripping through "+attacker->query_name()+".\n");
		write("Your weapon "+HIY+"flashes"+NORM+" as "+HIR+"fire"+NORM+" glides from the staff ripping through "+attacker->query_name()+".\n");
		return 3 + random(3);
	}
	
	if(rand == 1)
	{
		say(this_player()->query_name()+"'s weapon flashes as "+CYN+"water"+NORM+" glides from the staff ripping through "+attacker->query_name()+".\n");
		write("Your weapon "+HIY+"flashes"+NORM+" as "+CYN+"water"+NORM+" glides from the staff ripping through "+attacker->query_name()+".\n");
		return 3 + random(3);
	}
	
	if(rand == 2)
	{
		say(this_player()->query_name()+"'s weapon "+HIY+"flashes"+NORM+" as "+YEL+"air"+NORM+" glides from the staff ripping through "+attacker->query_name()+".\n");
		write("Your weapon "+HIY+"flashes"+NORM+" as "+YEL+"air"+NORM+" glides from the staff ripping through "+attacker->query_name()+".\n");
		return 3 + random(3);
	}
	
	if(rand == 3)
	{
		say(this_player()->query_name()+"'s weapon "+HIY+"flashes"+NORM+" as "+GRN+"stone shards"+NORM+" glide from the staff ripping through "+attacker->query_name()+".\n");
		write("Your weapon flashes as "+GRN+"stone shards"+NORM+" glide from the staff ripping through "+attacker->query_name()+".\n");
		return 3 + random(3);
	}
}*/
