/*  Changed to new heal format 7/29/02 - Eurale  */
/*  Cost:  -13 soak @ 20/per = 260 * 5 drinks = 1300  */

#include "/open/ansi.h"
inherit "/obj/generic_heal.c";

void reset(int arg) {
  ::reset(arg);
  if(arg) return;

set_name("snakeoil");
add_alias("oil");
add_alias("jar");
set_short(HIG+"jar of snakeoil"+NORM);
set_long(
  "This concoction is rumored to sooth the stomaches of those who have had\n"+
  "too many non-alcoholic drinks and are feeling poorly.  It is bottled by\n"+
  "Gabby Hayes behind his wagon and is his own special recipe.\n");

add_cmd("drink");
set_type("drinks");
set_type_single("drink");
set_msg(
  HIG+"You unscrew the jar lid and drink some snakeoil.\n"+NORM);
set_msg2(
  " unscrews the jar lid and drinks some snakeoil.\n");
set_heal(0,0);
set_charges(5);
  set_msg_precharges("");
  set_msg_postcharges("");
set_soak(-13);  /*  intox  soak  stuff  */
set_value(150);
set_empty_msg(
  HIG+"You finish off the snakeoil and throw the bottle.\n"+NORM);
}
