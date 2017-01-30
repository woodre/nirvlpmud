/******************************************************************************
 *  
 *  File:           controller.c
 *  
 *  Author(s):      Vital@Nirvana
 *  
 *  Copyright:      Copyright (c) 1997 Vital@Nirvana
 *                  All Rights Reserved.
 *  
 *  Source:			Started 3/6/01.
 *  
 *  Notes:			
 *  
 *  Change History: 
 *  
 *  
 *****************************************************************************/

#include <ansi.h>
#include "/players/vital/closed/headers/vital.h"
#include "/players/vital/dest/include/spaceport.h"
inherit "/players/vital/closed/std/monster.c";

reset(arg) {
    ::reset(arg);
    if(arg) return;
	set_name();
	set_alias();
	set_short();
	set_long("\
This large, robotic figure blends in with the background so well \n\
that it is almost invisible..\n");
	set_level(24);
	set_assist(SPNPC+"spoon.c", 2, 200, 1000);
	set_chance(random(25)+25);
	set_spell_mess1("Controller "+BLINK+HIY+"pulses "+NORM+" with electricity.\n\n");
	set_spell_mess2(HIR+"Spa"+HIW+"rks"+NORM+" fly!\n\t\t"+BLINK+" Phhhzzzzt"+NORM+"\n\t\t\t\t"+HIY+"Bling!"+NORM+"\n");
	set_spell_dam(random(15)+5);
	set_info("This computer has actually designed other computers. The computers and equipment that it designed are of a fantastic value and quality.\n");
}
