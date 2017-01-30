#include "/players/mythos/closed/ansi.h"


inherit "obj/treasure";

reset(arg) {
  if(arg) return;
  set_id("bag");
  set_short("A large closed bag");
  set_long("A bag of wind... only a powerful entity may use this.\n");
  set_weight(2);
  set_value(10000);
}
