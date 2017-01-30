
inherit"obj/monster";
reset(arg) {
object money;
object armor;
object weapon;
::reset(arg);
if(arg) return;
set_name("guardian");
set_alias("guardian");
set_short("Guardian");
set_long(
"A guardian set over the door of the tomb.\n");
set_level(25);
set_race("undead");
set_hp(1500);
set_aggressive(1);
set_wc(40);
set_ac(25);
set_chance(25);
set_spell_dam(100);
set_spell_mess1("The guardian's eyes flash and lightning strikes you!");
set_spell_mess2("The Guardian's eyes flash and lightning strikes you!");
money = clone_object("obj/money");
money->set_money(500);
move_object(money, this_object());
armor = clone_object("/players/zone/obj/loincloth.c");
if(armor) {
move_object(armor,this_object());
  }
weapon = clone_object("/players/zone/obj/dancingsword.c");
if(weapon) {
move_object(weapon,this_object());
   }
}
