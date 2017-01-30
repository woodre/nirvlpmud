#include "/players/feldegast/defines.h"

inherit "/obj/monster.c";
inherit "/players/darkfire/obj/color.c";

reset(arg) {
  ::reset(arg);
  if(arg) return;
  set_name("gnafk");
  set_alt_name("bartender");
  set_alias("vendor");
  set_short("Gn"+hic("afk")+" the Shopkeeper");
  set_long("A boring shopkeeper.\n");
  set_gender("male");
  set_race("human");
  set_level(20);
  set_wc(30);
  set_ac(17);
  set_hp(500);
  set_al(500);
  add_money(4000);  
}
