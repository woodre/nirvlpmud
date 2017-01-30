inherit "obj/monster";
reset(arg) {
::reset(arg);
if(arg) return;
set_name("big rat");
set_alias("rat");
set_short("A Large Rat");
set_long("He looks underfed, malnourished, and has had a bad day.\n");
set_al(50);
set_level(3);
set_wc(3);
set_hp(15);
set_ac(0);
set_aggressive(0);
}
