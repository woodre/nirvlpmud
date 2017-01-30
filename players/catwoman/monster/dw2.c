inherit "obj/monster.talk";
object coins;
reset(arg) {
::reset(arg);
if(arg) return;
set_name("missionary");
set_short("demon missionary");
set_al(-1000);
set_race("duck");
set_level(20);
set_wc(1);
set_hp(5);
set_ac(1);
set_aggressive(0);
}

