
inherit"obj/monster";
reset(arg) {
::reset(arg);
if(arg) return;
set_name("slime");
set_short("slime");
set_level(10);
set_race("slime");
set_hp(120);
set_al(-50);
set_wc(15);
set_ac(12);
set_random_pick(20);
}
