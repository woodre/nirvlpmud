#include "/players/eurale/closed/ansi.h"
inherit "obj/armor";
int n, ahp;

reset(arg){
   ::reset(arg);

set_name("cape");
set_short(HIR+"L"+GRY+"ong Grey Cap"+HIR+"E"+NORM);
set_long(
  "A long, grey cape with a high collar that ties around the neck.  It has\n"+
  "a wide crimson strip running across the bottom and nearly touches the\n"+
  "floor.\n");

set_type("cloak");
set_ac(2);
set_weight(3);
set_value(1300);
/*
set_save_flag();
*/
}
