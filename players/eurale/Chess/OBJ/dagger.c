#include "/players/eurale/closed/ansi.h"
inherit "obj/weapon";

reset(arg){
  ::reset(arg);
  if (arg) return;

set_name("dagger");
set_alias("platinum dagger");
set_alt_name("knife");
set_short(HIY+"platinum dagger"+NORM);
set_long(
  "This small, lightweight dagger has a platinum handle and sharp double edges.\n");

set_type("knife");
set_class(16);
set_weight(1);
set_value(450);
}

clean_up() { return 0; }
