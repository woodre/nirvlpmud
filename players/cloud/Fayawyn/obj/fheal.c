/*
 * Fairy Bottle
 * fheal
 * Cloud 2007
 */


#include "/obj/ansi.h"
inherit "/obj/generic_heal.c";

void reset(int arg) {
  ::reset(arg);
  if(arg) return;

	set_name("Fairy Bottle");
	add_alias("fairy");
	add_alias("bottle");
	add_alias("fairies");
	set_short(""+HIC+"Fairy Bottle"+NORM+"");

	set_long("\A clear, glass bottle used to seize fairies. Towards the middle,\n\
etched in the glass, are the letters "+BCYN+""+HIW+"E  A  T    M  E"+NORM+". Perhaps\n\
you would like to "+HIC+"eat"+NORM+" one of the delicious "+HIC+"fairies"+NORM+".\n");

	set_type_single("fairy");
	set_type("fairies");
	set_msg(""+HIW+"Fairy, the other white meat."+NORM+"\n");

	set_msg2(" stuffs a screaming "+HIC+"fairy"+NORM+" into their mouth."+NORM+"\n\
The screams stop after a "+HIR+"juicy"+NORM+" crunch and a "+HIK+"wicked"+NORM+" grin."+NORM+"\n");
          
	set_value(800);
	add_cmd("eat");
	set_heal(50,50);
	set_charges(3);
	set_soak(8);      
	set_stuff(8);
	set_msg_stuffed(""+FLASH+"You are too FULL to eat another delicious fairy!"+NORM+"\n");
	set_empty_msg("The "+HIR+"last"+NORM+" fairy has been devoured.\n"); 

}
