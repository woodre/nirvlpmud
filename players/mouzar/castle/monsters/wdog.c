inherit "obj/monster.c";
reset(arg) {
::reset(arg);
if(arg) return;
set_name("dog");
set_alias("animal");
set_short("Wild Dog");
set_long("This is a wild dog.  It is ready for FOOD and you are on it's main course!\n");
set_al(0);
set_level(15);
set_wc(20);
set_ac(12);
set_hp(225);
set_aggressive(1);
}
 
