inherit "obj/monster.c";
reset(arg) {
::reset(arg);
if(arg) return;
set_name("goat");
set_short("Mountain goat");
set_long("This is an everyday mountain goat. It is looking at you.\n");
set_al(-34);
set_level(5);
set_wc(9);
set_ac(5);
set_hp(75);
set_aggressive(0);
}
 
