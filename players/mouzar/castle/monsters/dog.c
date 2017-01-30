inherit "obj/monster.c";
object coins;
reset(arg) {
::reset(arg);
if(arg) return;
set_name("dog");
set_short("Pesty dog");
set_long("This is one of the pest dogs that keeps running around the village.\n");
set_al(0);
set_level(1);
set_wc(6);
set_ac(3);
set_hp(30);
set_aggressive(0);
}
 
