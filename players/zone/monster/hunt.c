
inherit"obj/monster";
reset(arg) {
::reset(arg);
if(arg) return;
set_name("hunt");
set_short("hunt");
set_level(21);
set_race("hunt");
set_hp(600);
set_al(100);
set_wc(35);
set_ac(20);
set_aggressive(1);
}
