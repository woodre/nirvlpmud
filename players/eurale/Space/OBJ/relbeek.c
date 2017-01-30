/*  Changed to new heal format 7/31/02 - Eurale  */
#include "/open/ansi.h"
inherit "/obj/generic_heal.c";

void reset(int arg) {
  ::reset(arg);
  if(arg) return;

set_name("wafer");
add_alias("yellow wafer");
add_alias("relbeek");
set_short(HIY+"thin yellow relbeek wafer"+NORM);
set_long(
  "This thin, yellow wafer appears to be some kind of cookie.  It doesn't\n"+
  "appear to be from this area and smells a bit like stinkweed.\n");

add_cmd("eat");
set_type("bites");
set_type_single("bite");
set_msg(
  HIY+"You bite off a piece of the thin wafer and swallow it.\n"+NORM);
set_msg2(
  " bites off a piece of the thin wafer\n");
set_heal(50,50);
set_charges(3);
  set_msg_precharges(HIY+"["+NORM);
  set_msg_postcharges(HIY+"]"+NORM);
set_stuff(9);  /*  intox  soak  stuff  */
set_value(400 + random(100));
set_msg_stuffed(
  "You feel too full for another bite of the wafer.\n");
set_empty_msg(
  HIY+"You chew up the last bite of yellow wafer and swallow it.\n"+NORM);
}
