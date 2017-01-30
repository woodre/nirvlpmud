#include "/players/wocket/closed/ansi.h"
#define tpn this_player()->query_name()
inherit "/obj/monster.c";

object staff;
object gold;
reset(arg)  {
  ::reset(arg);
  if(arg) return;
  
  set_name("manager");
  set_race("human");
  set_alias("mage");
  set_short(BOLD+HIM+"Sariun Firestarter"+NORM);
  set_long(
    "  A powerful mage by the looks of him. He wears Red robes\n"+
    "and carries a mighty staff. He doesn't look happy.\n");
  
  set_level(21);
  set_hp(1500 + random(1500));
  set_al(0);
  set_ac(30);
  set_wc(41 + random(10));
  set_aggressive(0);
  set_armor_params("other|magic",0,20,0);
  set_armor_params("other|fire",0,10,0);
  set_armor_params("other|mental",0,10,0);
  
  add_spell("fireball",
  "#MN# casts a massive $HR$F I R E B A L L!!!!!!!$N$ at you.\n",
  "#MN# casts a massive $HR$F I R E B A L L!!!!!!!$N$ at you.\n",
  25,140,"other|fire");

  staff = clone_object("/players/tallos/7tigers/objects/mspellstaff.c");
  move_object(staff, this_object());
  
  gold = clone_object("obj/money");
  gold->set_money(random(1500) + 2000);
  move_object(gold,this_object());
}
