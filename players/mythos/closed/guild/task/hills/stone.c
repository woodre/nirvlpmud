#include "/players/mythos/closed/guild/def.h"
inherit "obj/treasure";
reset(arg) {
  set_id("stone");
  set_alias("darkstone");
  set_alt_name("DarkStone");
  set_short(BOLD+"DarkStone"+NORM);
  set_long("\n");
  set_weight(2);
  set_value(0);
  call_out("checks",6);
}

checks() {
  if(!living(ep)) {
    destruct(this_object());
    tell_room(ep,"The DarkStone flares and is gone!\n");
  return 1;}
call_out("checks",3);
return 1;}

