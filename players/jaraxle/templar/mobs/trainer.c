#include "/players/jaraxle/ansi.h"
inherit "obj/monster.c";

reset(arg)  {
object gold;
  ::reset(arg);
  if(arg) return;

set_name("urhandrek");
set_alt_name("templar_trainer");
set_alias("trainer");
set_race("human");
set_gender("male");
set_short("Urhandrek, the Templar Trainer");
set_long(
"  This man is dressed in a simple brown robe and a sword is sheathed\n"+
"at his hip. He has jet black hair and a well-trimmed beard. His nose\n"+
"is hawk-like and his sharply accentuated eyebrows seem predatory. If\n"+
"you are a Knight, you can "+GRN+"advance"+NORM+" your guild levels, and "+GRN+"train"+NORM+" your\n"+
"weapon skills with this man.\n");

set_level(20);
set_hp(225);
set_al(800);
set_wc(35);
set_ac(14);
set_aggressive(0);
gold = clone_object("obj/money");
gold->set_money(500);
move_object(gold,this_object());
}
