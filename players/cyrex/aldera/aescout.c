
inherit"obj/monster";
reset(arg) {
object armor;
::reset(arg);
if(arg) return;
set_name("elven scout");
set_alias("scout");
set_short("Elven scout");
set_long(
"A nimble little fellow is here scouting the woods. He sees you!\n");
set_level(10);
set_race("elf");
set_hp(300);
set_al(-300);
set_wc(15);
set_ac(15);
set_chance(25);
set_spell_dam(20);
set_spell_mess1("The scout throws some magical powder!");
set_spell_mess2("The scout throws some magical powder in your face!");
armor = clone_object("/players/cyrex/aldera/aeboots");
if(armor) {
move_object(armor,this_object());
  }
}
