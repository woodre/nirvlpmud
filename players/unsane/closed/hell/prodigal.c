object gold;
inherit "obj/monster";

object mane;
reset(arg) {
::reset(arg);
if(!arg) {
set_alias("the prodigal");
set_alt_name("masses");
    set_name("prodigal");
set_short("The Prodigal");
    set_race("demon");
set_long(
"This mass of people are the prodigal.  Like the others who were condemmed to\n"+
"this circle, they were overly concerned with money.  Right now they are busy\n"+
"smashing a giant bolder against the miserly.  It appears these two groups will\n"+
"never stop clashing with one another.  Even though they are dying from\n"+
"exhaustion.\n");
move_object(clone_object("players/unsane/closed/hell/boulder.c"),this_object());
init_command("wield boulder");
gold =  clone_object("obj/money");
gold->set_money(random(500)+150);
move_object(gold, this_object());
set_chance(15);
set_spell_mess1("Plutus begins chanting at his foe.\n");
set_spell_mess1("The Prodigal ram their foe with a giant bolder!\n");
set_chat_chance(10);
load_chat("The Prodigal ram the Miserly with their bolder.\n");
load_chat("Bolders collide!\n");
set_a_chat_chance(10);
load_a_chat("The Prodigal chant in unison: Die Die Die!\n");
set_spell_mess2("The Prodigal ram you with a boulder!\n");
   set_level(15);
   set_ac(19);
   set_wc(25);
  set_hp(250);
   set_al(-500);
  set_aggressive(0);
}
}
