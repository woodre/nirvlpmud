#include "/players/brittany/ansi"
inherit "obj/monster.c";

reset(arg)  {
object gold;
  ::reset(arg);
  if(arg) return;

set_name("callicantzari");
set_alias("calli");
set_alt_name("cantzari");
set_race("monster");
set_short("callicantzari");
set_long("The calli has arms with hairy extremities on\n"+
"the muscles which are attached backwards, with several\n"+
"bones in the wrong place.  He looks like an unusually\n"+
"large and grotesque goblin.  His breath smells of foul\n"+
"decay when he exhales.\n");

set_level(20);
set_hp(550);
set_al(0);
set_wc(30);
set_ac(15);
set_aggressive(0);
set_dead_ob(this_object());

set_chat_chance(15);
load_chat("The calli trampled as he moved.\n");
set_a_chat_chance(15);
load_a_chat("The calli suffocates you with the stench of his breath.\n");

set_chance(10);
set_spell_dam(30);

set_spell_mess1(
"Calli knocks you silly with a hammy fist on the head.\n");
set_spell_mess2(
"Calli claws at you, tearing flesh from the skin.\n");

gold = clone_object("obj/money");
gold->set_money(0);
move_object(gold,this_object());
}

monster_died() {
  tell_room(environment(this_object()),
"The calli lumbered staggerly, then plummented to the ground.\n");
return 0; }
