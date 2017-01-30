inherit "obj/monster.c";
object coins;
reset(arg) {
::reset(arg);
if(arg) return;
set_name("kid");
set_short("A halfling kid (spoiled)");
set_long("This is one of the Sheriff's many kids.  It is very spoiled");
set_al(0);
set_level(2);
set_wc(6);
set_ac(3);
set_hp(30);
set_aggressive(0);
}
 
