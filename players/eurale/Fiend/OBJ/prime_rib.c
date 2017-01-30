/*  Changed to new heal format  7/29/02 - Eurale  */
#include "/open/ansi.h"
inherit "/obj/generic_heal.c";

void reset(int arg) {
  ::reset(arg);
  if(arg) return;

set_name("steak");
add_alias("prime rib");
set_short(HIR+"rare prime rib steak"+NORM);
set_long(
  "A large, juicy, rare piece of prime rib.  It is thick and seared to hold\n"+
  "in the juices and is large enough for any appetite.\n");

add_cmd("bite");
set_type("bites");
set_type_single("bite");
set_msg(
  HIR+"You take a healthy bite of the delicious prime rib.\n"+NORM);
set_msg2(
  " bites into the juicy prime rib.\n");
set_heal(50,50);
set_charges(3);
  set_msg_precharges("");
  set_msg_postcharges("");
set_stuff(10);  /*  intox  soak  stuff  */
set_value(500);
set_msg_stuffed(
  "You can't eat another bite at the moment.\n");
set_empty_msg(
  HIR+"You finish off the delicious prime rib.\n"+NORM);
}
