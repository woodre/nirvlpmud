inherit "obj/monster";
object weap,ob,fart;
reset(arg)
{
::reset(arg);
if(arg) return;
set_name("cleric");
set_short("Practicing Cleric");
set_alias("cleric");
set_alias("count");
set_long(
"A humble individual who wants to someday inspire hope and peace among his people.\n");
set_level(10);
set_hp(150);
set_wc(14);
set_ac(8);
ob=clone_object("players/nightshade/misc/symbol");
move_object(ob, this_object());
}
