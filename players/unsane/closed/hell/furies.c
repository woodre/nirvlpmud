object gold;
inherit "obj/monster";

object mane;
reset(arg) {
::reset(arg);
if(!arg) {
set_alias("three furies");
set_alt_name("furies");
    set_name("the Three Furies");
set_short("The Three Furies");
    set_race("demon");
set_long(
"  These are three terrible and hideous women, who work together as one.  They\n"+
"immediately begin screaming and tearing chunks of their own flesh out\n"+
"in a disgusting disply.  They have a pale color and are greenish around\n"+
"the edges of the mouth.  Perhaps that is mold?  They also spit blood\n"+
"with every breath.  You are very afraid of them.\n");
gold = clone_object("obj/money");
gold->set_money(random(900));
move_object(gold, this_object());
set_chance(20);
set_spell_mess1("The furies lunge forward and bite their foe!");
set_spell_dam(20);
set_chat_chance(10);
load_chat("The Furies wail together in unison.\n");
load_chat("The Furies scream: Blood!!\n");
set_a_chat_chance(10);
load_a_chat("The Furies say: Medusa will feast on your blood.\n");
load_a_chat("The Furies scream: I want to taste flesh.\n");
load_a_chat("The Furies Scream: Sister come help us!\n");
set_spell_mess2("The Furies bite your flesh!");
   set_level(18);
   set_ac(15);
   set_wc(30);
set_hp(666);
   set_al(-3000);
  set_aggressive(1);
}
}
