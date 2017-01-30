
inherit"obj/monster";
reset(arg) {
object money;
object armor;
object weapon;
::reset(arg);
if(arg) return;
set_name("gargantua");
set_alias("gargantua");
set_short("Gargantua");
set_long(
"You see an extremely large reptile.  Legends have it that in ancient times\n"
+ "kingdoms mustered mighty armies and wizards against this beast, and failed,\n"
+ "as its presence is testimony to.\n");
set_level(25);
set_race("monster");
set_hp(2000);
set_wc(50);
set_ac(25);
set_chance(25);
set_spell_dam(50);
set_spell_mess1("The Gargantual rears upon its hindquarters and stomps!");
set_spell_mess2("Enoumouse claws descend and nail you to the floor!");
money = clone_object("obj/money");
money->set_money(1000);
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
