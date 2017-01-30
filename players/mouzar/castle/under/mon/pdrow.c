inherit"obj/monster";
reset(arg) {
object gold;
object weapon;
::reset(arg);
if(arg) return;
set_a_chat_chance(25);
load_a_chat("Priestess shouts:  Kill these puny adventurers\n");
set_name("priestess");
set_alias("bitch");
set_short("Drow Priestess");
set_long(
"This is a drow priestess of the spider queen.  She is a bitch and a half.\n"
+ "She is pure evil.  Better not let her take you alive.\n");
set_level(20);
set_al(-800);
set_race("drow");
set_hp(500);
set_wc(30);
set_ac(17);
set_aggressive(1);
set_chance(50);
set_spell_dam(30);
set_spell_mess1("The priestess points at you and shoots a stream of acid.");
set_spell_mess2("You get blasted by a stream of acid.");
gold = clone_object("obj/money");
 gold->set_money(random(2000)+3000);
 move_object(gold,this_object());
weapon = clone_object("/players/mouzar/castle/under/obj/dwhip");
  move_object(weapon,this_object());
}
