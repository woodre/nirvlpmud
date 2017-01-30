/*  Changed to new heal format 7/29/02 - Eurale  */
/*  Cost:  35 hps @ soak 14 * 10/pt = 350 * 3 drinks = 1050  */

#include "/open/ansi.h"
inherit "/obj/generic_heal.c";

void reset(int arg) {
  ::reset(arg);
  if(arg) return;

set_name("tea");
add_alias("sassafras tea");
add_alias("flask");
set_short(BOLD+"flask of sassafras tea"+NORM);
set_long(
  "A flask of invigorating sassafras tea that has been brewed to perfection\n"+
  "and bottled in an ordinary flask.  The label reads: G. Hayes Brewing, Inc.\n");

add_cmd("drink");
set_type("drinks");
set_type_single("drink");
set_msg(
  BOLD+"You bring the flask to your lips and drink some sassafras tea.\n"+NORM);
set_msg2(
  " drinks some sassafras tea from the flask.\n");
set_heal(35,35);
set_charges(3);
  set_msg_precharges("");
  set_msg_postcharges("");
set_soak(14);  /*  intox  soak  stuff  */
set_value(300);
set_msg_soaked(
  "You're much too full to take another drink.\n");
set_empty_msg(
  BOLD+"You empty the flask and stomp it into bits.\n"+NORM);
}
