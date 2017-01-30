
inherit"obj/monster";
reset(arg) {
object money;
object armor;
object weapon;
::reset(arg);
if(arg) return;
set_name("wraith");
set_alias("wraith");
set_short("wraith");
set_long(
"A shadowy outline that seems to morph as you look at it.\n");
set_level(19);
set_race("undead");
set_hp(800);
set_wc(30);
set_ac(17);
set_chance(50);
set_spell_dam(30);
set_spell_mess1("The wraith drifts to you and it's chill hands reach into ");
set_spell_mess2("Soul Sucked!");
money = clone_object("obj/money");
money->set_money(1500);
move_object(money, this_object());
armor = clone_object("/players/zone/obj/deadring.c");
if(armor) {
move_object(armor,this_object());
  }
weapon = clone_object("/players/zone/obj/dirk.c");
if(weapon) {
move_object(weapon,this_object());
   }
}
