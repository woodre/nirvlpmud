#include "/players/jenny/define.h"
inherit "/obj/treasure.c";
reset(int arg) {
  if(arg) return;
  set_id("tatoo");
set_short();
set_long("A tatoo of a french whore giving a blowjob to a drunken sailor.\n");
set_value(0);
set_save_flag(1);
}
extra_look() { return ENVTO->query_name()+" has a tatoo on the arm"; }
query_auto_load() { return "/players/jenny/tatoo.c:"; }
drop() {return 1;}
