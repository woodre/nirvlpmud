#include "/players/eurale/closed/ansi.h"

inherit "obj/armor";

reset(arg) {
set_name("badge");
set_alias("marshall badge");
set_short(HIY+"Marshall badge"+NORM);
set_long(
  "A silver badge with the work 'Marshall' hammered into it.\n");

set_ac(2);
set_type("shield");
set_weight(1);
set_value(700);
}

/*
query_save_flag() { return 1; }
*/
