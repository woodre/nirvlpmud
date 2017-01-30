inherit "obj/monster.c";
reset(arg) {
::reset(arg);
if(arg) return;
set_name("jackle");
set_alias("animal");
set_short("Jackle");
set_long("A very wild and hungry animal.\n");
set_al(0);
set_level(15);
set_wc(20);
set_ac(12);
set_hp(300);
set_aggressive(0);
}
 
