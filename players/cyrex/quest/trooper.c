inherit "obj/monster";
object flower;
int items;
reset(arg) {
::reset(arg);
if(arg) return;
set_name("Invid Trooper");
set_short("Invid trooper");
set_level(10);
set_long("The trooper glares at you and looks like he is about attack!\n");
set_wc(20);
set_ac(2);
set_hp(100);
set_chance(35);
set_spell_mess1("The Invid lunges forward and takes a bite out of you!\n");
set_spell_mess2("The Invid lunges forward and takes a bite out of you!\n");
set_spell_dam(5);
set_aggressive(1);
set_alias("trooper");
set_al(-100);
flower = clone_object("players/cyrex/quest/flower");
move_object(flower,this_object());
return 1;
}
