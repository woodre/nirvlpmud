inherit "obj/monster";
reset(arg) {
::reset(arg);
if(arg) return;
set_name("rat");
set_short("A Rat");
set_long("Squeek!  Squeek!  Squeek!\n");
set_al(15);
set_level(1);
set_wc(4);
set_hp(10);
set_ac(2);
set_aggressive(0);
}
