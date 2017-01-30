inherit"obj/monster";
reset(arg) {
object armor;
object weapon;
object gold;
::reset(arg);
if(arg) return;
set_name("husband");
set_alias("duergar");
set_short("Dying Husband");
set_long(
"This Duergar has seen better days.  He has several clean cuts on his\n"
+ "chest and one on his neck.  He is a dying husband.  He is soaked in \n"
+ "blood from head to toe. \n");
set_level(15);
set_al(-400);
set_race("dwarf");
set_hp(150);
set_wc(10);
set_ac(10);
gold = clone_object("obj/money");
  gold->set_money(100+random(100));
  move_object(gold,this_object());
armor = clone_object("/players/mouzar/castle/under/obj/duscale");
  move_object(armor,this_object());
weapon = clone_object("/players/mouzar/castle/under/obj/dusword");
  move_object(weapon,this_object());
}
