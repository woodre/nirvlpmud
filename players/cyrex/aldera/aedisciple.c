
inherit"obj/monster";
reset(arg) {
::reset(arg);
if(arg) return;
set_name("elven disciple");
set_alias("disciple");
set_short("Elven Disciple");
set_long(
"He is one of the many fortunate elves to be taught by the old wise sage.\n"
+ "Right now, All he wants to do is seek revenge upon you for killing his\n"
+ "teacher.\n");
set_level(15);
set_race("elf");
set_hp(650);
set_al(-650);
set_wc(25);
set_ac(20);
set_aggressive(1);
set_chance(15);
set_spell_dam(20);
set_spell_mess1("The Elven Disciple casts a magic spell.");
set_spell_mess2("The Elven Disciple casts a spell on you!");
set_random_pick(20);
}
