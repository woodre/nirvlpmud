inherit "obj/monster.talk";
object coins;
reset(arg) {
::reset(arg);
if(arg) return;
set_name("eel");
set_short("a shreeking eel");
set_long("He looks hungry.\n");
set_al(-1000);
set_race("eel");
set_level(17);
set_wc(24);
set_hp(400 + random(75));
set_ac(17);
set_spell_mess1("The EEL Screems\n");
set_spell_mess2("The EEL hits you again\n");
set_chance(15);
set_spell_dam(25);
set_aggressive(1);
}

