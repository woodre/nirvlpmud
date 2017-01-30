inherit "obj/monster";
object weap,ob,fart;
reset(arg)
{
::reset(arg);
if(arg) return;
set_name("thief");
set_short("Practicing Thief");
set_alias("thief");
set_alias("count");
set_long(
"This guy is a thief who aspires to become the guildmaster of the thieves guild. Dont let him.\n");
set_level(10);
set_hp(150);
set_wc(14);
set_ac(8);
ob=clone_object("players/nightshade/misc/picks");
move_object(ob, this_object());
}
