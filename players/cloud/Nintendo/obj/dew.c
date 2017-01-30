/*
 * Mountain Dew
 * /players/cloud/Nintendo/dew.c
 * Cloud 2013
 */


#include "/obj/ansi.h"
inherit "/obj/generic_heal.c";

void reset(int arg) {
  ::reset(arg);
  if(arg) return;

	set_name("Mountain Dew");
	add_alias("dew");
	set_short(""+HIG+"Mountain Dew"+NORM+"");
	set_long("It's a can of "+HIG+"Mountain Dew"+NORM+".\n"+
			 "'drink dew' to refresh yourself.\n");
	set_type_single("gulp");
	set_type("gulps");
	set_msg(""+HIG+"You take a big gulp of Mountain Dew."+NORM+"\n");
	set_msg2(" takes a gulp of "+HIG+"Mountain Dew."+NORM+"\n");         
	set_value(600);
	add_cmd("drink");
	set_heal(50,50);
	set_charges(3);
	set_soak(8);      
	set_stuff(8);
	set_msg_stuffed("\n\tYou are too full to drink any more dew!\n");
	set_msg_soaked("\n\tYou are too full to drink any more dew!\n");
	set_empty_msg(""+HIG+"You finish the can of dew."+NORM+"\n"); 

}
