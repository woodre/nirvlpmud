
inherit"obj/monster";
reset(arg) {
object money;
object armour;
object weapon;
object treasure;
::reset(arg);
if(arg) return;
set_name("royal castle guard");
set_alias("guard");
set_short("Royal Castle Guard");
set_long(
"One of the King's many guards. He has a face full of guilt for\n"+
"not protecting the King. He will seek his revenge on you!\n");
set_level(19);
set_race("human");
set_hp(500);
set_al(-500);
set_wc(25);
set_ac(15);
set_aggressive(1);
}
