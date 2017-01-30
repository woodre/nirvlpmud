/* needs to be hard because he guards a very needed quest item */
inherit "obj/monster";
object cross;
reset(arg) {
::reset(arg);
if(arg) return;
set_name("demon");
set_al(200);
set_short("Blood Demon");
set_long("This is one of the guardians of Malachi\n");
set_alias("demon");
set_level(20);
set_hp(800);
set_ac(17);
set_wc(30);
set_aggressive(1);
cross = clone_object("/players/grimm/object/cross");
move_object(cross, this_object());
}
