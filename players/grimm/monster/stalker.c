inherit "obj/monster";
reset(arg) {
::reset(arg);
if(arg) return;
set_name("stalker");
set_al(-200);
set_short("An undead stalker");
set_long("This is the final guardian of Malachi\n");
set_alias("stalker");
set_level(20);
set_hp(500);
set_ac(17);
set_wc(30);
set_aggressive(1);
}
