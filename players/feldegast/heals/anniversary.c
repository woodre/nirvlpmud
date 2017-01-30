/*
A souvenir for Nirvana's 10th anniversary.
Feb 26, 2001
*/
#include "defs.h"

inherit "/obj/generic_heal.c";

void reset(int arg) {
  ::reset(arg);
  if(arg) return;
  set_name("savignon");
  add_alias("cabernet");
  add_alias("cabernet savignon");
  add_alias("wine");
  add_alias("bottle");
  set_short("A bottle of "+RED+"Cabernet Savignon"+NORM);
  set_long(
    "This is an expensive bottle of a perfectly aged cabernet savignon.\n"+
    "This vintage was passed out especially for Nirvana's 10th anniversary\n"+
    "celebration and makes an excellent collector's item.\n");
  set_type("sips");
  set_msg("You carefully sip the cabernet savignon.\n");
  set_msg2(" enjoys a glass of cabernet savignon.\n");
  add_cmd("drink");
  add_cmd("swig");
  add_cmd("sip");
  set_heal(50,50);
  set_charges(3);
  set_intox(4);
  set_value(1500);
}

void init() {
  ::init();
  add_action("cmd_read", "read");
}

int cmd_read(string str) {
  if(str=="label" || str=="bottle") {
    write("The label on the bottle reads: February 26, 1991.\n");
    return 1;
  }
}
