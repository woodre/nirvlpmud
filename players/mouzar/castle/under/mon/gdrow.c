inherit"obj/monster";
reset(arg) {
object gold;
object armor;
object weapon;
::reset(arg);
if(arg) return;
set_name("drow");
set_alias("guard");
set_short("Drow Guard");
set_long(
"This is a drow guard.  He is amoungst the best trained fighters.  \n"
+ "He is a deadly and silent killer.  You can see hatred and the burning\n"
+ "lust for battle in his glowing eyes.\n");
set_level(15);
set_al(-325);
set_race("drow");
set_hp(225);
set_wc(25);
set_ac(12);
set_aggressive(1);
gold = clone_object("obj/money");
 gold->set_money(random(500)+300);
 move_object(gold,this_object());
armor = clone_object("/players/mouzar/castle/under/obj/dchain");
 move_object(armor,this_object());
weapon = clone_object("/players/mouzar/castle/under/obj/dsword");
 move_object(weapon,this_object());
}
