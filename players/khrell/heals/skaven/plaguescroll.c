#include "/players/khrell/ansi.h"
#define tp this_player()->query_name()
inherit "/obj/generic_heal.c";

void reset(int arg) {
  ::reset(arg);
  if(arg) return;

  set_name("scroll");
  set_short(YEL+"Scroll of a Thousand "+CYN+"Poxes "+RED+"("+HIR+"Virulent"+NORM+RED+")"+NORM);
  set_long(
"   One of the infamous scrolls of a Thousand Poxes.  Objects of\n"+
"power to the skaven and a danger to use.  Beware when reading \n"+
"it as the power contained within can be unstable.\n"+
"To use it: 'read scroll'\n");

  add_cmd("read");
  set_type_single("read");
  set_msg(
"   You read the dire runes of the "+YEL+"scroll of a Thousand "+CYN+"poxes"+NORM+"\n"+
"The runes fade and the scroll crumbles to dust.\n"
  );
  set_msg2(
  " reads a scroll.\n"+
  "The scroll crumbles to dust.\n"+
  tp+" is is bathed in a dark "+GRN+"green"+NORM+" aura.\n");
  set_heal(-(random(100)), random(300));
  set_charges(1);
  set_msg_precharges("<");
  set_msg_postcharges(">");
  set_intox(-20);
  set_value(10000);
  set_msg_intoxed(
  "\n");
  set_empty_msg(
  "You are bathed in the corrupting magics of the Horned God.\n");

}
