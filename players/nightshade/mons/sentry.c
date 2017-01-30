inherit "obj/monster";
object weap,ob,fart;
reset(arg)
{
::reset(arg);
if(arg) return;
set_name("sentry");
set_short("Town Sentry");
set_alias("sentry");
set_alias("count");
set_long(
"A member of the town watch. A kool looking dood.\n");
set_level(13);
set_hp(250);
set_wc(17);
set_ac(10);
ob=clone_object("players/nightshade/weap/sentry_sword");
move_object(ob, this_object());
weap=clone_object("players/nightshade/armor/sentry_armor");
move_object(weap, this_object());
}
