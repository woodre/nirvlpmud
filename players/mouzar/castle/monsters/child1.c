inherit "obj/monster";
reset(arg) {
::reset(arg);
if(arg) return;
set_name("child");
set_short("Halfling child");
set_long("One of Dottery's grandkids.\n");
set_al(0);
set_level(1);
set_wc(5);
set_ac(3);
set_hp(6);
set_aggressive(0);
}
 
