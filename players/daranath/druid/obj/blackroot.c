#include <ansi.h>

inherit "obj/treasure";

reset(arg) {
  if(arg) return;

set_id("blackroot");
set_alias("root");
set_short(BOLD+BLK+"Blackroot"+NORM);
set_long("A small bunch of colorful berries, they seem to be in perfect\n"+
         "condition, perhaps to be used somehow.\n");
set_weight(1);
set_value(5+random(10));
}

query_druid_comp() {return 1; }
