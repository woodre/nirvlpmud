inherit "obj/monster";
object flower;
int items;
reset(arg) {
::reset(arg);
if(arg) return;
set_name("Invid Shock Trooper");
set_short("Invid shock trooper");
set_level(15);
set_long("The trooper is standing guard. However, now he sees you...\n");
set_wc(28);
set_ac(2);
set_hp(150);
set_spell_mess1("The Invid shocks you!\n");
set_spell_dam(5);
set_chance(35);
set_aggressive(1);
set_alias("trooper");
set_al(-150);
flower = clone_object("players/cyrex/quest/flower");
move_object(flower,this_object());
return 1;
}
