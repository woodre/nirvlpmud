#include "/players/eurale/closed/ansi.h"
inherit "obj/weapon";

reset(arg){
  ::reset(arg);
  if (arg) return;

set_name("sword");
set_alias("shortsword");
set_alt_name("sword");
set_short(GRY+"grey shortsword"+NORM);
set_long(
  "This small, lightweight sword has a grey handle and sharp double edges.\n");

set_type("knife");
set_class(16);
set_weight(1);
set_value(450);
}

clean_up() { return 0; }
