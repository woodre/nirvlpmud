inherit "obj/monster";
reset(arg) {
::reset(arg);
if(arg) return;
set_name("orc");
set_short("An Small Orc");
set_long("Here stands a character that is willing to test his skill...\n");
set_al(-30);
set_level(2);
set_wc(4);
set_hp(10);
set_ac(2);
set_aggressive(0);
}
