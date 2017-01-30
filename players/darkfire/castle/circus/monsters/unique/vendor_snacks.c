#include "/players/feldegast/defines.h"

inherit "/obj/monster.c";
inherit "/players/darkfire/obj/color.c";

reset(arg) {
  ::reset(arg);
  if(arg) return;
  set_name("drafk");
  set_alt_name("snack vendor");
  set_alias("vendor");
  set_short("Dr"+hib("afk")+" the Snack Vendor");
  set_long("A boring snack shop vendor.\n");
  set_gender("male");
  set_race("human");
  set_level(20);
  set_wc(30);
  set_ac(17);
  set_hp(500);
  set_al(500);
  add_money(4000);  
}
