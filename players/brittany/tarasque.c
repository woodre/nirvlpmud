#include "/players/brittany/ansi"
inherit "obj/monster.c";

reset(arg)  {
object gold;
  ::reset(arg);
  if(arg) return;

set_name("tarasque");
set_alias("dragon");
set_alt_name("beast");
set_race("monster");
set_short("tarasque");
set_long("The tarasque was some sort of an unusual dragon.  It\n"+
"possessed certain nonreptilian attributes.  Its head was that\n"+
"of an ant-lion, it had six bearlike legs, a big spiked carapace,\n"+
"and an ugly reptilian tail.  His jaws were horrendous, with\n"+
"teeth like a forest of spikes, some narrowing to points, some\n"+
"splitting into multiple cutting ridges.  His eyes blazed and\n"+
"he looked fearsome.\n");

set_level(20);
set_hp(550);
set_al(0);
set_wc(30);
set_ac(15);
set_aggressive(0);
set_dead_ob(this_object());

set_chat_chance(15);
load_chat("The dragon eyes blazed.\n");
set_a_chat_chance(15);
load_a_chat("The dragon roars loudly.\n");

set_chance(10);
set_spell_dam(30);

set_spell_mess1(
"The dragon swipes at you with a massive paw, gouging out some skin.\n"+);
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
