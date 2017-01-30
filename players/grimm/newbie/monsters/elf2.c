inherit "obj/monster";
reset(arg) {
::reset(arg);
if(arg) return;
set_name("elf");
set_short("An Elf");
set_long("Here stands a character that is willing to test his skill...\n");
set_al(30);
set_level(2);
set_wc(2);
set_hp(10);
set_ac(0);
set_aggressive(0);
}
