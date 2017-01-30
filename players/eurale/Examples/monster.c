#include "/players/eurale/closed/ansi.h"
inherit "obj/monster.c";
#define ETO environment(this_object())

reset(arg)  {
object gold;
  ::reset(arg);
  if(arg) return;

set_name("N");
set_alias("A");
set_alt_name("N2");
set_short("Name");
set_long(
  "desc \n");

set_race("creature");
set_level(20);
set_hp(550);
set_al(0);
set_wc(30);
set_ac(15);
set_heal(amt,rate);
set_aggressive(0);
set_dead_ob(this_object());

set_chat_chance(15);
  load_chat("not fighting \n");
set_a_chat_chance(15);
  load_a_chat("attack chat \n");

set_chance(10);
set_spell_dam(30);
set_spell_mess1(
  "others \n");
set_spell_mess2(
  "figher \n");

gold = clone_object("obj/money");
gold->set_money(amt);
move_object(gold,this_object());
}

monster_died() {
move_object(clone_object("/players/eurale/area/OBJ/item.c"),ETO);
tell_room(ETO,"msg\n");
return 0; }
