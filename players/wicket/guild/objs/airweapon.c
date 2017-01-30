#include <ansi.h>
inherit "/obj/weapon.c";

int dtype;									/* We'll use this for seeing what type of dtype we're gonna do */

reset(arg) {
	::reset(arg);
	
	if(arg) return;
	set_id("staff");
	set_alias("wicket_elementalist_staff");
	set_short("An "+RED+"Ancient "+NORM+"Staff of the "+RED+"El"+YEL+"em"+GRN+"en"+CYN+"ts"+NORM+" ("+BOLD+"Enshrouded "+NORM+"by "+YEL+"Air"+NORM+")");     /* Fix this if you'd like! */
	set_long(
	"A solid wooden staff that has been weathered and beaten. Down the\n"+							/* Fix this, obviously ;) */
	"long wooden shaft of the staff are tattered and well worn. A glowing\n"+
	"orb rests at the top of the staff between some piece of the staff\n"+
	"that seem to wrap around the orb holding onto the orbs life essence.\n"+
	"Ancient Symbols are carved down the side of the staff and hum with\n"+
	"amazing power.\n"+
	"                   "+YEL+"        00000                                   \n"+
	"                          0     0                                  \n"+
	"                          0  0  0                                  \n"+
	"                          0     0                                  \n"+
	"                           00000                                   \n"+
	"                            Air"+NORM+"                                    \n");
	set_weight(2);
 set_class(10); 
	set_value(0);							/* Worthless since they can conjure it */
	set_type("staff");
	set_params("other|wind", 5, "beat_dat_ass");
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
	int air;

	gob = present("wicket_element_orb", environment(this_object()));
	
	air = (int)gob->query_AIR();
	
	if(!random(5))
	{
		say(this_player()->query_name()+"'s weapon "+HIY+"flashes"+NORM+" as "+YEL+"air"+NORM+" glides from the staff ripping through "+attacker->query_name()+".\n");
		  write("Your weapon "+HIY+"flashes"+NORM+" as "+YEL+"air"+NORM+" glides from the staff ripping through "+attacker->query_name()+"\n"+NORM+
"                                                                \n"+NORM+
HIW+"	           .-~*~--,.   .-.                            \n"+NORM+ 
HIW+"          .-~-. ./OOOOOOOOO\.'OOO`9~~-.                     \n"+NORM+ 
HIW+"        .`OOOOOO.OOM.OLSONOOOOO@@OOOOOO\                    \n"+NORM+ 
HIW+"       /OOOO@@@OO@@@OO@@@OOO@@@@@@@@OOOO`.                  \n"+NORM+
HIW+"    .-'OO@@@@WW@@@W@WWWWWWWWOOWW@@@@@OOOOOO}                \n"+NORM+
HIW+"    /OOO@@O@@@@W@@@@@OOWWWWWOOWOO@@@OOO@@@OO|               \n"+NORM+
HIW+"   lOOO@@@OO@@@WWWWWW"+HIY+"\\"+HIW+"OWWWWO"+HIY+"\\"+HIW+"WWWOOOOOO@@@O.'                \n"+NORM+
HIW+"    \OOO@@@OOO@@@@@@OOW"+HIY+"\\      \\"+HIW+"WWWW@@@@@@@O'.                \n"+NORM+
HIW+"    `,OO@@@OOOOOOOOOOWW"+HIY+"\\      \\"+HIW+"WWWW@@@@@@OOO)                \n"+NORM+
HIW+"      \,O@@@@@OOOOOOWWWWW"+HIY+"\\      \\"+HIW+"WW@@@@@OOOO.'               \n"+NORM+
HIW+"        `~c~8~@@@@WWW@@"+HIY+"\\       \\"+HIW+"WOO|\UO-~'                 \n"+NORM+
HIW+"             (OWWWWWW@@0"+HIY+"\\    ___\\"+HIW+"WO)                       \n"+NORM+
HIW+"               `~-~''    "+HIY+"\\   \\"+HIW+"WW=*'                        \n"+NORM+
HIY+"                         _\\   \\                            \n"+NORM+  
HIY+"                        \\      \\                           \n"+NORM+ 
HIY+"                         \\     _\\                          \n"+NORM+      
HIY+"                          \\   \\                             \n"+NORM+               
HIY+"                           \\  \\                             \n"+NORM+
HIY+"                            \\  \\                            \n"+NORM+
HIY+"                             \\ \\                            \n"+NORM+
HIY+"                              \\ \\                           \n"+NORM+
HIY+"                               \\\\                           \n"+NORM+
HIY+"                                \\\                          \n"+NORM+ 
HIY+"                                                           \n"+NORM+
HIY+"                                                           \n\n"+NORM+ 
BOLD+"             "+HIY+"Lightning"+NORM+" strikes it's target!!!      \n"+NORM+
  "\n");
		return air;
	}
}