inherit "obj/monster";
object gold, weap;
reset(arg) {
::reset(arg);
if(arg) return;
set_name("sprite");
set_short("Sprite");
set_long(
"A spritely little sprite. Not to hard to kill.\n");
set_level(2);
set_hp(30);
set_wc(6);
set_ac(3);
weap=clone_object("players/nightshade/weap/sprite_dagger");
move_object(weap, this_object());
}
