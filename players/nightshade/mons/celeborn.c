inherit "obj/monster";
object wep,arm;
reset(arg)
{
::reset(arg);
if(arg) return;
set_name("celeborn");
set_short("Celeborn");
set_long("Elronds favorite and most fierce guard.\n");
set_level(15);
set_hp(225);
set_ac(12);
set_wc(20);
wep = clone_object("players/nightshade/weap/lswd");
move_object(wep, this_object());
arm=clone_object("players/nightshade/armor/sentry_armor");
move_object(arm, this_object());
}
