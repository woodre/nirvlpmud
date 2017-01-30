#include "/players/feldegast/defines.h"

inherit "obj/monster";

reset(arg) {
  ::reset(arg);
  set_name("escher");
  set_alias("merchant");
  set_short("Master Escher the Merchant");
  set_long(
"Master Escher is an aged, but successful merchant of dubious standing in\n"+
"many communities.  He wears a flamboyant orange burnous and a fez upon his\n"+
"shiny head.\n");
  set_level(12);
  set_hp(200);
  set_wc(17);
  set_ac(9);
  add_money(500+random(200));
  set_gender("male");
  set_race("human");
  set_al(500);
  set_chat_chance(5);
  load_chat("Escher says: Greetings, Effendi.  Would you care to sample some of my fine wares?\n");
}
