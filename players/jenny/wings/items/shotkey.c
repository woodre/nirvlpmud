#include "/players/jenny/define.h"
inherit "/obj/treasure.c";
reset(arg) {
   if(arg) return;
   set_id("jennyshotkey");
   set_alias("key");
   set_short("A key");
   set_long(
      "This is a small brass key.\n");
   set_weight(1);
   set_value(0);
   set_save_flag(1);
}
