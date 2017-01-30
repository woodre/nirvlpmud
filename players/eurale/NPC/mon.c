/* a generic monster set-up */

inherit "obj/monster";
reset(arg) {

object gold;
::reset(arg);
if(arg) return;
set_name("name1");
set_race("creature");
set_short("Name");
set_alias("name2");
set_long(
	"  long description \n");
set_level(21);
set_hp(975);
set_al(-1000);
set_aggressive(1);
set_dead_ob(this_object());

set_wc(30);
set_ac(17);


set_chat_chance(15);
  load_chat("message \n");
set_a_chat_chance(15);
  load_a_chat("message \n");


set_chance(16);
set_spell_dam(random(50)+50);
set_spell_mess1(
  "others \n");
set_spell_mess2(
  "fighter \n");

gold = clone_object("obj/money");
gold->set_money(random(200)+4000);
move_object(gold,this_object());
}

monster_died() {
  tell_room(environment(this_object()),
  "dying \n");
return 0; }
