inherit"obj/monster";
reset(arg) {
object armor;
object weapon;
object treasure;
::reset(arg);
if(arg) return;
set_chat_chance(50);
load_chat("Healer says:  Please spare me.  I must heal the wounded.\n");
set_name("healer");
set_alias("duergar");
set_short("Duergar Healer");
set_long(
"This Duergar is dressed in funny clothing.  This guy is very fat and has\n"
+ "stains of all kinds on his colorful robes.  He is very calm and happy.\n");
set_level(18);
set_al(-200);
set_race("dwarf");
set_hp(450);
set_wc(26);
set_ac(15);
set_chance(35);
set_spell_dam(75);
set_spell_mess1("Healer calls upon his God for help!\n");
set_spell_mess2("Wounds form on you!\n");
armor = clone_object("/players/mouzar/castle/under/obj/durobe");
  move_object(armor,this_object());
weapon = clone_object("/players/mouzar/castle/under/obj/dumace");
  move_object(weapon,this_object());
treasure = clone_object("/players/mouzar/castle/under/obj/heal");
  move_object(treasure,this_object());
}
