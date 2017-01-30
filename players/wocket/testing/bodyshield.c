#include "/players/wocket/closed/ansi.h"
inherit "/obj/armor.c";

reset(arg){
  set_id("shield");
  set_short(HIC+"A bodyshield"+NORM+" (FOR TESTCHAR USE ONLY)");
  set_alias("bodyshield");
  set_type("shield");
  set_ac(10);
  set_weight(1);
  set_value(-100000);
}
