#include "/players/wocket/closed/ansi.h"
inherit "/obj/weapon.c";

reset(arg){
  ::reset(arg);
  if(arg) return;
  set_short(BOLD+BLK+"Nothing"+OFF);
  set_long("You can not focus upon anything.\n");
  set_class(0);
  set_weight(0);
  set_light(-2);
  set_alias("nothing");
  set_id("nothing");
}
