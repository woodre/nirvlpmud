inherit "obj/monster";

object gold;
reset(arg) {
::reset(arg);
if (!arg) {
set_name ("plug");
set_alias ("  ");
set_short("");
set_race("");
   set_long(
"This is a normal indoor extension cord.  However, since its been\n"+
"plugged in outdoors, It has come alive-You better kill it before it kills\n"+
"you!  You think to youself: I wish people would be more responsible\n"+
"with electricity\n");
gold = clone_object("obj/money");
gold -> set_money (random(10)+20);
set_level(10);
set_ac(5);
set_wc(15);
set_hp(random(100)+200);
set_al(-100);
set_chance(20);
set_spell_dam(15);
set_aggressive(1);
}
}
