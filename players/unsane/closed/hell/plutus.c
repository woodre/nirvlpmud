#include <ansi.h>

object gold;
inherit "obj/monster";

object mane;
reset(arg) {
::reset(arg);
if(!arg) {
set_alias("plutus");
set_alt_name("god");
    set_name("god of wealth");
set_short("Plutus, God of Wealth");
    set_race("demon");
set_long(
"This babbling stupid creature is Plutus, the God of wealth.  He seems to\n"+
"have been driven insane by being in such close proximity to Satan,\n"+
"his master.  He is the guardian of the Fourth Circle and, though he\n"+
"is mindless, he seems to be quite formidable.  You seem to remember\n"+
"hearing a story about two travellers who managed to pass by him without\n"+
"a scratch.  If only you could remember how they did it?  Plutus notices you are\n"+
"staring at him and he begins clucking to you.  His mouth froths foamy blood.\n"+
"He is disgusting.\n");
/*
set_chance(20);
set_spell_mess1("Plutus begins chanting at his foe.");
set_spell_dam(50);
*/
set_chat_chance(10);
load_chat("Plutus clucks at you.\n");
load_chat("Plutus appears to be afraid you might say something.\n");
load_chat("Plutus slobbers.\n");
load_chat("Plutus begins babbling to himself.\n");
load_chat("Plutus cries out: Father Satan!  Father Satan!\n");
set_a_chat_chance(10);
load_a_chat("Plutus cries like a baby.\n");
load_a_chat("Plutus cries to Satan for help!\n");
load_a_chat("Plutus says:  Father Satan, Help me!\n");
/*
set_spell_mess2("Plutus casts a black spell at you!");
*/
   set_level(21);
   set_ac(25);
  set_wc_bonus(7); /* 25 avg * .2 * 1.25 ~ 7 */
   set_wc(50);
   set_al(-3000);
set_hp(2000);
  set_aggressive(0);
  add_money(5555 + random(3333));
}
}

heart_beat()
{
    ::heart_beat();
     if(!random(5) && attacker_ob) black_spell();
}

black_spell()
{
     tell_object(attacker_ob, "Plutus casts a " + HIK + "black spell" + NORM + " at you!\n");
     tell_room(environment(), "Plutus casts a " + HIK + "black spell" + NORM + " at " + attacker_ob->query_name() + "!\n", ({ attacker_ob }));
     attacker_ob->hit_player(random(50), "other|evil");
}
