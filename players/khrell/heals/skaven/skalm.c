#include "/open/ansi.h"
#define tp this_player()->query_name()
inherit "/obj/generic_heal.c";

void reset(int arg) {
  ::reset(arg);
  if(arg) return;

set_name("scroll");
add_alias("heal");
set_short("A scroll of full heal");
set_long(
  "A scroll of full heal.\n"+
  "To use it: 'read scroll'\n");

add_cmd("read");
set_type_single("read");
set_msg("You read the silver runes of the scroll of healing.\n"+
  "The runes fade away into darkness as the scroll bursts into flames.\n"
  );
set_msg2(
  " reads a scroll.\n"+
  "The scroll bursts into flames.\n"+
  tp+" is fully healed.\n");
set_heal(700,700);
set_charges(1);
  set_msg_precharges("<");
  set_msg_postcharges(">");
set_intox(0);  /*  intox  soak  stuff  */
set_value(10000);
set_msg_intoxed(
  "\n");
set_empty_msg(
  "You are fully healed.\n");

}