inherit "obj/monster";
reset(arg) {
::reset(arg);
if(arg) return;
set_name("rothe");
set_short("Rothe");
set_long("A creature looking like a goat. One of the few gentle inhabitants of the Underdark.\n");
set_level(7);
set_hp(105);
set_ac(6);
set_wc(11);
}
