
inherit"obj/monster";
reset(arg) {
object weapon;
::reset(arg);
if(arg) return;
set_name("elven guard");
set_alias("guard");
set_short("Elven Guard");
set_long(
"A nimble, strong looking guard. He grins at you.\n");
set_level(15);
set_race("elf");
set_hp(800);
set_al(-800);
set_wc(18);
set_ac(15);
set_spell_mess2("");
weapon = clone_object("/players/cyrex/aldera/aewsword");
if(weapon) {
move_object(weapon,this_object());
   }
}
