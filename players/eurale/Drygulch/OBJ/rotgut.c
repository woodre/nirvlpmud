/*  Changed over to new heal format 7/29/02 - Eurale  */
/*  Cost:  35hps @ intox 14 * 10/pt = 350 * 3 drinks = 1050  */

#include "/open/ansi.h"
inherit "/obj/generic_heal.c";

void reset(int arg) {
  ::reset(arg);
  if(arg) return;

set_name("rotgut");
add_alias("bottle");
add_alias("stubby bottle");
set_short(BOLD+"stubby bottle of rotgut"+NORM);
set_long(
  "A homemade brew of rotgut bottled in a short stubby bottle.  The label\n"+
  "reads 'Eurale's Bottling Co. est 1886'.\n");

add_cmd("drink");
set_type("drinks");
set_type_single("drink");
set_msg(
  BOLD+"You hold your breath and take a pull of rotgut from the bottle.\n"+NORM);
set_msg2(
  " drinks some rotgut from the bottle.\n");
set_heal(35,35);
set_charges(3);
  set_msg_precharges(BOLD+"<"+NORM);
  set_msg_postcharges(BOLD+">"+NORM);
set_intox(14);  /*  intox  soak  stuff  */
set_value(300);
set_msg_intoxed(
  BOLD+"You're too drunk to have another drink.\n"+NORM);
set_empty_msg(
  BOLD+"You BURP LOUDLY as you finish off another bottle of rotgut.\n"+NORM);
}
