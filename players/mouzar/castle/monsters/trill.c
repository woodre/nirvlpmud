inherit "obj/monster.c";
object coins;
reset(arg) {
::reset(arg);
if(arg) return;
set_name("trill");
set_short("Poor Trill");
set_long("You have to take pitty on this poor man as you look at him.\n");
set_al(0);
set_level(2);
set_wc(6);
set_ac(3);
set_hp(30);
set_aggressive(0);
}
 
