#include "/players/khrell/define.h"
#include <ansi.h>

inherit "/players/vertebraker/closed/std/monster.c";

reset(arg) {
object gold;
  ::reset(arg);
  if(arg) return;
  set_name("Plaguepriest");
  set_alt_name("priest");
  set_alias("skab");
  set_short(YEL+"Plague"+MAG+"priest"+NORM+" Skab");
  set_long(
"   Plaguepriest Skab is the right paw of the Plaguelord Nurglitch of\n"+
"clan Pestilens.  He is a fanatical devotee of the Horned God and to\n"+
"his blighted clan.  His Leprous skin drips from his diseased frame,\n"+
"and he chitters constantly to his favored boils as if a pet.\n");
  set_gender("male");
  set_race("skaven");
  set_level(25);
  set_wc(44);
  set_ac(23);
  set_hp(1000);
  set_heal(20,3);
  set_al(-1000);
  set_assist("/players/khrell/monster/skaven/plrat", 5, 5, 15);
  set_aggro(1, 50, 50);
move_object(clone_object("/players/khrell/heals/skaven/plaguescroll.c"));

gold = clone_object("obj/money");
gold->set_money(6000);
move_object(gold,this_object());
}
