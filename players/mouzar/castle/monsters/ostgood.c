inherit "obj/monster.c";
object coins;
reset(arg) {
::reset(arg);
if(arg) return;
set_name("ostgood");
set_short("Miss Ostgood");
set_long("This is a very naughty woman.  She should be killed!\n");
set_level(3);
set_wc(7);
set_ac(4);
set_hp(45);
set_aggressive(0);
add_money(100);
}
 
