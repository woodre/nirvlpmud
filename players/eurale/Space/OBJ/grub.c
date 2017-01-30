/*  Changed to new heal format 7/30/02 - Eurale  */
#include "/open/ansi.h"
inherit "/obj/generic_heal.c";

void reset(int arg) {
  ::reset(arg);
  if(arg) return;

set_name("grub");
add_alias("space grub");
set_short(HIG+"space grub"+NORM);
set_long(
  "This disgusting looking grub-like creature comes from another world.  It\n"+
  "is covered in an oozing green slime and smells as if it is fermenting.\n");

add_cmd("eat");
set_type("bites");
set_type_single("bite");
set_msg(
  HIG+"You gnaw off a piece of the slimy grub and swallow it.\n"+NORM);
set_msg2(
  " gnaws off a piece of space grub.\n");
set_heal(40 + random(16),40 + random(16));
set_charges(3);
  set_msg_precharges("<[");
  set_msg_postcharges("]>");
set_intox(10);  /*  intox  soak  stuff  */
set_stuff(10);
set_value(380 + random(50));
set_msg_intoxed(
  "You feel too woozy to take another bite.\n");
set_msg_stuffed(
  "You can't force another bite of the grub past your lips.\n");
set_empty_msg(
  HIG+"You stuff the last oozing piece of space grub into your mouth.\n"+NORM);
}
