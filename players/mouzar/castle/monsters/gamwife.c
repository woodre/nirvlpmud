inherit "obj/monster.c";
object coins;
reset(arg) {
::reset(arg);
if(arg) return;
set_name("wife");
set_short("Gammer's wife");
set_long("Poor woman hasn't seen jewlery in ages.\n");
set_al(0);
set_level(3);
set_wc(7);
set_ac(4);
set_hp(45);
set_aggressive(0);
}
 
