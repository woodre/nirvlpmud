#include "/players/khrell/define.h"
#include <ansi.h>

inherit "/obj/monster.c";

reset(arg) {
object gold;
  ::reset(arg);
  if(arg) return;
  set_name("skaven slave");
  set_alt_name("skaven");
  set_alias("slave");
  set_short("Clanrat Slave");
  set_long(
"This wretched skaven has seen better days.\n"+
"It's fur is matted and mangey.\n");
  set_gender("male");
  set_race("skaven");
  set_level(15+random(5));
move_object(clone_object("/players/khrell/weapons/skaven/pickax.c"));
init_command("wield axe");  
  set_wc(20);
  set_ac(15);
  set_hp(200);
  set_al(-1000);
  set_aggressive(0);

set_chat_chance(10);
load_chat("The slave looks around sadly.\n");
load_chat("A pitiful moan escapes from the slave's mouth.\n");

gold = clone_object("obj/money");
gold->set_money(1);
move_object(gold,this_object());
}
