#include "/players/khrell/define.h"
#include <ansi.h>
inherit "obj/armor";

reset(arg) {
   set_name("clanrat shield");
   set_alias("shield");
   set_short("A Clanrat Shield");
   set_long(
      "This is the standard shield used by clanrats.\n");
   set_ac(2);
   set_type("shield");
   set_weight(2);
   set_value(500);
}
