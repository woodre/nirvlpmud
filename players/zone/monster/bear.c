
inherit"obj/monster";
reset(arg) {
::reset(arg);
if(arg) return;
set_name("bear");
set_short("bear");
set_level(10);
set_race("bear");
set_hp(250);
set_al(1);
set_wc(15);
set_ac(10);
set_random_pick(20);
}
