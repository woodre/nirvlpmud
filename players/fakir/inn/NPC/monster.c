#include "/players/fakir/color.h"
inherit "obj/monster.c";

reset(arg)  {
object gold;
  ::reset(arg);
  if(arg) return;

set_name("nm");
set_alias("ale");
set_alt_name("nm2");
set_race("creature");
set_short("Name");
set_long(
  "desc \n");

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

treasure=clone_object("path of treasure");
move_object(treasure,this_object());
armor=clone_object("path of armor");
move_object(armor,this_object());
weapon=clone_object("path of weapon");
move_object(weapon,this_object());
}

monster_died() {
  move_object(clone_object("obj"),
      environment(this_object()));
  tell_room(environment(this_object()),
	"msg \n");
return 0; }
