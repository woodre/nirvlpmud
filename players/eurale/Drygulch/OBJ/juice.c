/*  Changed to new heal format on 7/29/02 - Eurale  */
#include "/open/ansi.h"
inherit "/obj/generic_heal.c";

void reset(int arg) {
  ::reset(arg);
  if(arg) return;

set_name("juice");
add_alias("cactus juice");
add_alias("jug");
set_short(HIG+"jug of cactus juice"+NORM);
set_long(
  "A jug of cactus juice squeezed from the prickly pear cactus.  It is said\n"+
  "that this juice has a very sobering effect on anyone who drinks it while\n"+
  "intoxicated.\n");

add_cmd("drink");
set_type("drinks");
set_type_single("drink");
set_msg(
  HIG+"You tip back the jug and take a swig of cactus juice.\n"+NORM);
set_msg2(
  " take a swig of bitter cactus juice.\n");
set_heal(0,0);
set_charges(3);
  set_msg_precharges(HIG+"<"+NORM);
  set_msg_postcharges(HIG+">"+NORM);
set_intox(-13);  /*  intox  soak  stuff  */
set_value(300);
set_empty_msg(
  HIG+"You finish off the bitter cactus juice and break the jug.\n"+NORM);
}
