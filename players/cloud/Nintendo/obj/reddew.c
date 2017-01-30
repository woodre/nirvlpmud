/*
 * Mountain Dew Code Red
 * /players/cloud/Nintendo/reddew.c
 * Cloud 2012
 */


#include "/obj/ansi.h"
inherit "/obj/generic_heal.c";

void reset(int arg) {
  ::reset(arg);
  if(arg) return;

	set_name("Mountain Dew Code Red");
	add_alias("red");
	set_short(""+HIG+"Mountain Dew"+HIR+" (Code Red)"+NORM+"");
	set_long("It's a can of "+HIG+"Mountain Dew"+HIR+" (Code Red)"+NORM+".\n"+
			 "'drink red' to refresh yourself.\n");
	set_type_single("gulp");
	set_type("gulps");
	set_msg(""+HIG+"You take a big gulp of Mountain Dew"+HIR+" (Code Red)"+NORM+".\n");
	set_msg2(" takes a gulp of "+HIG+"Mountain Dew"+HIR+" (Code Red)"+NORM+".\n");         
	set_value(500);
	add_cmd("drink");
	set_heal(0,60);
	set_charges(3);
	set_soak(8);      
	set_stuff(8);
	set_msg_stuffed("\n\tYou are too full to drink any more dew!\n");
	set_msg_soaked("\n\tYou are too full to drink any more dew!\n");
	set_empty_msg("You finish the can of "+RED+"dew."+NORM+"\n"); 

}
