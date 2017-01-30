#define ROOT "/players/daranath/qualtor/newstuff/"

inherit "/players/daranath/closed/monster1.c";
int a;

reset(arg) {
   ::reset(arg);
   if (!arg) {
object ob, ob2, ob3;
a = random(3);

 ob = clone_object("obj/money");
 ob->set_money(random(1000) + 500);
  move_object(ob, this_object());
 ob2 = clone_object(ROOT+"obj/mino_leather.c");
  move_object(ob2, this_object());
if(a == 0) {ob3 = clone_object(ROOT+"weps/mino_axe.c"); }
if(a == 1) {ob3 = clone_object(ROOT+"weps/mino_axe.c"); }
if(a == 2) {ob3 = clone_object(ROOT+"weps/mino_blade.c"); }
  move_object(ob3, this_object());

set_name("Minotaur Gladiator");
set_short("A large minotaur");
set_alias("mino");
set_alt_name("gladiator");
set_race("minotaur");
set_gender("male");
set_long("Standing nearly seven feet tall, the minotaur race is one of the most\n"+
         "powerful to ever walk upon Nirvana. A cross between a man\n"+
         "and a bull, the Minotaur Gladiator is not too be underestimated.\n");
set_level(19);

init_command("wear armor");
init_command("wield weapon");

set_ac(16);
set_wc(26 + random(6));
set_hp(400 + random(100));
set_al(-1000);
set_aggressive(0);
set_chat_chance(3);
load_chat("Minotaur tightens his grip on his weapon, ready for a fight.\n");
load_chat("Minotaur Gladiator looks at you and smirks confidently.\n");
load_chat("Minotaur snorts: 'Get lost, Whimp'\n");

set_chance(10);
set_spell_dam(20+random(40));
set_spell_mess1("Minotaur lowers his head and charges!\n");
set_spell_mess2("Minotaur Gladiator charges you, striking with its deadly horns.\n");
   }
}

