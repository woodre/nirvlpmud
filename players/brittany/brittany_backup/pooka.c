#include "/players/brittany/ansi"
inherit "obj/monster.c";

reset(arg)  {
object gold;
  ::reset(arg);
  if(arg) return;

set_name("pooka");
set_alias("monster");
set_alt_name("horse");
set_race("creature");
set_short("A ghost horse");
set_long("A white ghost horse with chains wrapped about\n"+
"its body.  It looks transparent if it were not for the\n"+
"chains, since they stayed wrapped.\n");

set_level(15);
set_hp(225);
set_al(0);
set_wc(20);
set_ac(12);
set_aggressive(0);
set_dead_ob(this_object());
set_chat_chance(8);
load_chat("The pooka sniffs.\n");
load_chat("The pooka's chain rattles as he moves toward you.\n");
set_a_chat_chance(10);

set_chance(10);
set_spell_dam(30);

set_spell_mess1(
);
set_spell_mess2(

);

gold = clone_object("obj/money");
gold->set_money(0);
move_object(gold,this_object());
}
monster_died() {
return 0; }
