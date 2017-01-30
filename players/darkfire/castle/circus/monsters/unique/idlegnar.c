#include "/players/feldegast/defines.h"

inherit "/obj/monster.c";
inherit "/players/darkfire/obj/color.c";

reset(arg) {
  ::reset(arg);
  if(arg) return;
  set_name("idlegnar");
  set_alt_name("byron");
  set_alias("duke");
  set_short(hir("Idle")+"gnar the Matron");
  set_long("An idling matron.");
  set_gender("female");
  set_race("human");
  set_level(20);
  set_wc(30);
  set_ac(17);
  set_hp(500);
  set_al(500);
  add_money(4000);  
}
