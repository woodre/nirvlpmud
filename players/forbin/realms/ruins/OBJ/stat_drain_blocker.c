#include "/players/forbin/realms/ruins/ruinsdefine.h"
#include "/players/forbin/logging.h"

inherit "obj/treasure";

id(str) { return (::id(str) || str == "no_more_stat_drainage"); }

reset(arg)  {
  if(arg) return;
  set_id("stat_drain_blocker");
  set_weight(0);
  set_value(0);
}

drop() { return 1; }

get() { return 0; }

can_put_and_get() { return 0; }
