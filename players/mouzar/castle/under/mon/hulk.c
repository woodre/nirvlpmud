
inherit"obj/monster";
object weapon;
reset(arg) {
::reset(arg);
if(arg) return;
set_name("umberhulk");
set_alias("hulk");
set_short("Umber Hulk");
set_long(
"This guy is about 8 feet tall and about 6 feet wide!  Muscles bulge\n"
+ "beneath their thick, scaly hides.  Extending from their fingers and toes\n"
+ "are great claws.\n");
set_level(20);
set_al(-500);
set_race("monster");
set_hp(740);
set_wc(28);
set_ac(28);
set_aggressive(1);
set_chance(20);
set_spell_dam(40);
set_spell_mess1("The umber hulk tears into his opponet with it's massive claws!");
set_spell_mess2("the umber hulk tears into your flesh with it's massive claws!");
weapon = clone_object("/players/mouzar/castle/under/obj/claws");
 move_object(weapon,this_object());
}
