
inherit"obj/monster";
reset(arg) {
object armor;
::reset(arg);
if(arg) return;
set_name("elven scout");
set_alias("scout");
set_short("Elven scout");
set_long(
"A nimble little fellow scouting the woods. He grins at you!\n");
set_level(10);
set_race("elf");
set_hp(300);
set_al(-300);
set_wc(10);
set_ac(15);
set_chance(25);
set_spell_dam(20);
set_spell_mess1("The scout castes a magical spell!");
set_spell_mess2("The scout parries your blow and kicks you hard!");
armor = clone_object("/players/cyrex/aldera/aegloves");
if(armor) {
move_object(armor,this_object());
  }
}
