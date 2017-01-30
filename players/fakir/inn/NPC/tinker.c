inherit "obj/monster.c";

reset(arg)  {
  ::reset(arg);
  if(arg) return;
add_money(400);
set_name("Tinker");
set_alias("tinker");
set_alt_name("Tuatha'am");
set_race("human");
set_short("A traveling Tinker");
set_long(
  "A wandering folk, also known as the Tuatha'am and as the Traveling People,\n"+
  "who live in brightly painted wagons and follow a totally pacifist philosophy\n"+
  "called the Way of the Leaf.  Things mended by Tinkers are often better than\n"+
  "new, but the Tuatha'an are shunned by many villages because of stories that\n"+
  "they steal children and try to convert them to their beliefs. \n");

set_level(10);
set_hp(150);
set_al(-700);
set_wc(14);
set_ac(6);
set_aggressive(0);
set_dead_ob(this_object());

set_chat_chance(10);
  load_chat("Hello stranger!  Need something mended? \n");
  load_chat("Tinker says: My gosh its certainly a wonderful day. \n");
  load_chat("Say, you don't happen to have any children around here? \n");
  load_chat("Times are tough in the borderlands these days. \n");
  load_chat("The tinker raps on the bartop and asks for another mug of ale. \n");
  load_chat("Tinker says: Could you spare a few coins for a poor traveling man? \n");
set_a_chat_chance(15);
  load_a_chat("The tinker yells: Please stop!  You need to learn the Way of the Leaf! \n");
  load_a_chat("The tinker cries: I am a lover, not a fighter! \n");

set_chance(10);
set_spell_dam(10);

set_spell_mess1(
  "The tinker prays to the Way of the Leaf. \n");
set_spell_mess2(
  "The Tuatha'am prays to the Way of the Leaf and you feel pain. \n");


}

