inherit "obj/monster.c";

reset(arg)  {
object gold;
  ::reset(arg);
  if(arg) return;

set_name("Tinker");
set_alias("tinker");
set_alt_name("Tuatha'am");
set_race("human");
set_short("A traveling Tinker");
set_long(
  "A wandering folk, also known as the Tuatha'am and as the Traveling People,\n"+
  "who live in brightly painted wagons and follow a totally pacifist philosophy\n"+
  "called the Way of the Leaf.  Things mended by Tinkers are oftain better than\n"+
  "new, but the Tuatha'an are shunned by many villages because of stories that\n"+
  "they steal children and try to convert them to their beliefs. \n");

set_level(10);
set_hp(150);
set_al(500);
set_wc(14);
set_ac(6);
set_aggressive(0);
set_dead_ob(this_object());

set_chat_chance(10);
  load_chat("Hello stranger!  Need something mended? \n");
set_a_chat_chance(15);
  load_a_chat("Please stop!  You need to learn the Way of the Leaf! \n");

set_chance(10);
set_spell_dam(10);

set_spell_mess1(
  "The tinker prays to the Way of the Leaf. \n");
set_spell_mess2(
  "The Tuatha'am prays to the Way of the Leaf and you feel pain. \n");

gold = clone_object("obj/money");
gold->set_money(450);
move_object(gold,this_object());
}

