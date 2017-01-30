inherit "obj/monster.c";
reset(arg) {
::reset(arg);
if(arg) return;
set_name("cow");
set_short("Cow");
set_long("An everyday old farm cow\n");
set_al(0);
set_level(2);
set_wc(6);
set_ac(3);
set_hp(30);
set_aggressive(0);
}
 
