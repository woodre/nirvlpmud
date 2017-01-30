#include "/players/laera/closed/ansi.h"
inherit "obj/monster.c";

reset(arg)  {
object gold;
  ::reset(arg);
  if(arg) return;

set_name("monster");
set_alias("ale");
set_alt_name("nm2");
set_race("creature");
set_short("monster");
set_long(
  "desc \n");

set_level(20);
set_hp(550);
set_al(0);
set_wc(30);
set_ac(15);
set_heal(1,1);
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
gold->set_money(100);
move_object(gold,this_object());
}

monster_died() {
tell_room(environment(this_object()),
  "The monster sticks its tongue out at you as it dies...\n");
return 0; }
