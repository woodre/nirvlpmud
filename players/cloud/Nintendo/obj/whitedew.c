/*
 * Dr.Pepper Ten
 * /players/cloud/Nintendo/ten.c
 * Cloud 2013
 */


#include "/obj/ansi.h"
inherit "/obj/generic_heal.c";

void reset(int arg) {
  ::reset(arg);
  if(arg) return;

	set_name("Mountain Dew White Out");
	add_alias("white");
	set_short(""+HIG+"Mountain Dew "+HIW+"White Out"+NORM+"");
	set_long("It's a can of "+HIG+"Mountain Dew "+HIW+"White Out"+NORM+".\n"+
			 "'drink white' to refresh yourself.\n");
	set_type_single("gulp");
	set_type("gulps");
	set_msg("You take a big gulp of "+HIG+"Mountain Dew "+HIW+"White Out."+NORM+"\n");
	set_msg2(" takes a gulp of "+HIG+"Mountain Dew "+HIW+"White Out."+NORM+"\n");         
	set_value(600);
	add_cmd("drink");
	set_heal(50,0);
	set_charges(3);
	set_soak(4);      
	set_stuff(4);
	set_msg_stuffed("\n\tYou are too full to drink any more Dew!\n");
	set_msg_soaked("\n\tYou are too full to drink any more Dew!\n");
	set_empty_msg("You finish the can of "+HIW+"dew"+NORM+"\n"); 

}
