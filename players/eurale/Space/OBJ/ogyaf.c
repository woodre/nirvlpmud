/*  Changed over to new heal format 7/30/02 - Eurale  */
#include "/open/ansi.h"
inherit "/obj/generic_heal.c";

void reset(int arg) {
  ::reset(arg);
  if(arg) return;

set_name("ogyaf");
add_alias("liquid");
add_alias("luminescent liquid");
set_short(HIC+"luminescent liquid"+NORM);
set_long(
  "A syrupy liquid from another world that glows with an inner luminescence.\n"+
  "Small fleks of an unknown material float suspended in the thick liquid.\n");

add_cmd("drink");
set_type("drinks");
set_type_single("drink");
set_msg(
  HIC+"You gulp down a swallow of the thick, luminescent liquid.\n"+NORM);
set_msg2(
  " take a drink of some unknown liquid.\n");
set_heal(50,50);
set_charges(3);
  set_msg_precharges(HIC+"{"+NORM);
  set_msg_postcharges(HIC+"}"+NORM);
set_soak(10);  /*  intox  soak  stuff  */
set_value(400 + random(50));
set_msg_soaked(
  "You are too full for another drink of the luminescent liquid.\n");
set_empty_msg(
  HIC+"You finish off the luminescent liquid.\n"+NORM);
}
