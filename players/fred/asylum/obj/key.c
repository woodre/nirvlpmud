inherit "/obj/treasure";
#include <ansi.h>

reset(arg) {
  if(arg) return;
  set_id("key");
  set_alias("key#413");          
  set_short("A small key");
  set_long(
  "A small iron key.\n");
  set_weight(1);
  set_value(5);
  set_dest_flag(1);
}
