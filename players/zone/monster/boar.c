
inherit"obj/monster";
reset(arg) {
object treasure;
::reset(arg);
if(arg) return;
set_name("boar");
set_short("boar");
set_aggressive(1);
set_level(17);
set_race("boar");
set_hp(500);
set_al(1);
set_wc(26);
set_ac(14);
}
