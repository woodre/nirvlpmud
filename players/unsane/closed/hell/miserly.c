object gold;
inherit "obj/monster";

object mane;
reset(arg) {
::reset(arg);
if(!arg) {
set_alias("the miserly");
set_alt_name("masses");
    set_name("miserly");
set_short("The Miserly");
    set_race("demon");
set_long(
"  These are the misers of the world.  When they were living souls, they were\n"+
"obsessed with hanging on to their money.  They valued money above all else\n"+
"and now they are paying dearly for it.  They are busy at this moment\n"+
"trying to smash the prodigal to death with a giant bolder.\n");
move_object(clone_object("players/unsane/closed/hell/boulder.c"),this_object());
init_command("wield boulder");
gold =  clone_object("obj/money");
gold->set_money(random(500)+150);
move_object(gold, this_object());
set_chance(15);
set_spell_mess1("The Miserly ram their foe with a giant bolder!\n");
set_chat_chance(10);
load_chat("The Miserly ram the Prodigal with their bolder.\n");
load_chat("Bolders collide!\n");
set_a_chat_chance(10);
load_a_chat("The Miserly chant in unison: Kill Kill Kill!\n");
set_spell_mess2("The Miserly ram you with a boulder!\n");
   set_level(15);
   set_ac(15);
   set_wc(25);
   set_al(-500);
  set_hp(250);
  set_aggressive(0);
}
}
