inherit "obj/monster";
object weap,ob,fart;
reset(arg)
{
::reset(arg);
if(arg) return;
set_name("fighter");
set_short("Practicing Fighter");
set_alias("fighter");
set_alias("count");
set_long(
"This is a brute of a man who hasnt had much training, but knows enough to kick some butt.\n");
set_level(10);
set_hp(150);
/* Fighter has good wc now  -Snow */
set_wc(24);
set_ac(8);
ob=clone_object("players/nightshade/misc/wood_shield");
move_object(ob, this_object());
fart=clone_object("players/nightshade/misc/wood_sword");
move_object(fart, this_object());
}
