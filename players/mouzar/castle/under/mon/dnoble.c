inherit "obj/monster.c";
reset(arg) {
object gold;
object armor;
object weapon;
string chat_str;
string a_chat_str;
::reset(arg);
if(arg) return;
set_chat_chance(50);
set_a_chat_chance(30);
load_chat("Drow says:  Those who watch their backs meet death from the front.\n");
load_chat("Drow says:  All non-drow must die!\n");
load_a_chat("The drow blocks what would have been deadly blow.\n");
load_a_chat("Drow shouts:  How dare you attack a son of the 4th house!\n");
set_name("noble");
set_short("Drow Noble");
set_long(
"This drow noble is dressed in bright clothing.  He has fire in his eyes as\n"
+ "he looks at a nondrow walking through the spider queen's city.  He gives\n"
+ "you a look that puts fear into you.\n");
set_level(18);
set_al(-400);
set_race("drow");
set_hp(450);
set_wc(28);
set_ac(17);
set_aggressive(1);
/*
set_chance(35);
set_spell_dam(30);
set_spell_mess1("The noble strikes you with a deadly poisoned dart!\n");
*/
add_spell("spellattack",
  "The Noble Drow strikes you with a deadly poisoned dart!\n",
  "The Noble Drow strikes #CTN# with a deadly poisoned dart!\n",
  35, "30", "physical", 0);
gold = clone_object("obj/money");
   gold->set_money(random(300)+100);
   move_object(gold,this_object());
armor = clone_object("/players/mouzar/castle/under/obj/dchain");
   move_object(armor,this_object());
weapon = clone_object("/players/mouzar/castle/under/obj/crossbow");
   move_object(weapon,this_object());
}
