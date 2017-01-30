inherit "obj/monster.c";
object coins;
reset(arg) {
::reset(arg);
if(arg) return;
set_name("mouse");
set_short("A mouse");
set_long("A pesky little mouse.\n");
set_al(0);
set_level(1);
set_wc(5);
set_ac(3);
set_hp(15);
set_aggressive(0);
}
 
