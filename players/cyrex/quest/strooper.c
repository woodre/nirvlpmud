inherit "obj/monster";
object flower, armor;
int items;
reset(arg) {
::reset(arg);
if(arg) return;
set_name("Invid Shock Trooper");
set_short("Invid shock trooper");
set_level(15);
set_long("The trooper is standing guard. However, now he sees you...\n");
set_wc(30);
set_ac(2);
set_hp(250);
set_spell_mess1("The Invid shocks you!\n");
set_spell_mess2("The Invid shocks with a hit!\n");
set_spell_dam(5);
set_chance(35);
set_aggressive(1);
set_alias("trooper");
set_al(-150);
flower = clone_object("players/cyrex/quest/flower");
move_object(flower,this_object());
armor = clone_object("players/cyrex/quest/shockplate");
move_object(armor,this_object());
init_command("wear armor");
return 1;
}
