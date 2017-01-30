inherit "obj/monster.c";
reset(arg) {
::reset(arg);
if(arg) return;
set_name("duck");
set_short("Duck");
set_long("A fat duck.\n");
set_al(0);
set_level(2);
set_wc(7);
set_ac(4);
set_hp(45);
set_aggressive(0);
}
 
