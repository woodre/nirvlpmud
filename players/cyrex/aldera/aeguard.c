
inherit"obj/monster";
reset(arg) {
object armor;
::reset(arg);
if(arg) return;
set_name("elven guard");
set_alias("guard");
set_short("Elven Guard");
set_long(
"A nimble, strong looking guard. He stares at you.\n");
set_level(15);
set_race("elf");
set_hp(800);
set_al(-800);
set_wc(18);
set_ac(15);
set_spell_mess2("");
armor = clone_object("/players/cyrex/aldera/aearmor");
if(armor) {
move_object(armor,this_object());
  }
}
