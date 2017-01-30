#include "/players/feldegast/defines.h"

inherit "/obj/monster.c";
inherit "/players/darkfire/obj/color.c";

reset(arg) {
  ::reset(arg);
  if(arg) return;
  set_name("desi");
  set_alt_name("bartender");
  set_alias("vendor");
  set_short(cyn("Desi")+" the Wench");
  set_long("A boring barkeep.\n");
  set_gender("female");
  set_race("human");
  set_level(20);
  set_wc(30);
  set_ac(17);
  set_hp(500);
  set_al(500);
  add_money(4000);
  set_a_chat_chance(10);
  set_chance(5);
}
