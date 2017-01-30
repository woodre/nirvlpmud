inherit "obj/monster.c";
object weapon;
reset(arg) {
::reset(arg);
if(arg) return;
set_name("snake");
set_alias("snake in the grass");
set_short("Snake");
set_long("An big, brownsh colored snake that you have just scared.\n");
set_al(0);
set_level(15);
set_wc(20);
set_ac(12);
set_hp(225);
set_aggressive(1);
}
 
