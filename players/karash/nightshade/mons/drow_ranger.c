inherit "obj/monster";
object weap,gold,glo,sh,arm;
reset(arg) {
::reset(arg);
if(arg) return;
set_name("ranger");
set_short("Drow Ranger");
set_long("A drow ranger who has perfected the art of tracking people.\n");
set_level(10);
set_hp(200);
set_ac(12);
set_wc(15);
set_al(-1000);
weap=clone_object("players/nightshade/weap/rang_scimitar");
move_object(weap, this_object());
arm=clone_object("players/nightshade/armor/rang_leather");
move_object(arm, this_object());
glo=clone_object("players/nightshade/armor/rang_gloves");
sh=clone_object("players/nightshade/armor/shield_health");
move_object(sh, this_object());
move_object(glo, this_object());
}
