inherit "obj/monster.c";
reset(arg) {
::reset(arg);
if(arg) return;
set_name("snake");
set_short("Flying Snake");
set_long("It is a snake with wings.");
set_al(0);
set_level(4);
set_wc(8);
set_ac(4);
set_hp(60);
set_aggressive(1);
}
 
