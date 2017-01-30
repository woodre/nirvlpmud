inherit "obj/monster";
reset(arg) {
::reset(arg);
if(arg) return;
set_name("doppleganger");
set_short("A Doppleganger");
set_long("This looks like another person.\n");
set_al(0);
set_level(0);
set_wc(0);
set_hp(1);
set_ac(0);
set_aggressive(0);
}
