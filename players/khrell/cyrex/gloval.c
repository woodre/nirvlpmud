inherit "obj/monster";
object caphat, medal, pipe;
int items;
reset(arg) {
::reset(arg);
if(arg) return;
set_name("Captain Gloval");
set_alias("captain");
set_short("Captain Gloval");
set_long("Captain of the famed SDF-1. He commands it with all his pride.\n");
set_level(18);
set_hp(460);
set_al(400);
set_aggressive(0);
set_chat_chance(40);
load_chat("Gloval says: Please don't disturb me....I'm very busy!\n");
load_chat("Gloval says: Where are those veritech squadrons??\n");
set_a_chat_chance(40);
load_a_chat("Gloval says: Security!! Where are those damn people?!?!\n");
load_a_chat("Gloval says: I do not have time for this nonsense!\n");
caphat=clone_object("players/cyrex/caphat");
move_object(caphat, this_object());
command("wear hat");
medal=clone_object("players/cyrex/medal");
move_object(medal, this_object());
command("wear medal");
pipe=clone_object("players/cyrex/pipe");
move_object(pipe, this_object());
command("wield pipe");
/* Moved ac/wc set here. -Snow */
set_ac(15);
set_wc(27);
}
