inherit "obj/monster";
object phblaster, flsuit, helmet, shield;
int items;
reset(arg) {
::reset(arg);
if(arg) return;
set_name("Rick Hunter");
set_alias("rick");
set_short("Rick Hunter");
set_long("The leader of Skull Squadron..and he is in love with Lisa Hayes.\n");
set_level(22);
set_hp(1000);
set_al(1200);
set_aggressive(0);
set_chat_chance(10);
load_chat("Rick says: I'm in love with Lisa!!\n");
load_chat("Rick says: What are you doing here!!??\n");
set_a_chat_chance(10);
load_a_chat("Rick says: You're going to regret this! You slime!\n");
load_a_chat("Rick says: I'm going to melt you into nothing with my blaster!\n");
phblaster=clone_object("players/cyrex/phblaster");
move_object(phblaster, this_object());
command("wield blaster");
flsuit=clone_object("players/cyrex/flsuit");
move_object(flsuit, this_object());
command("wear suit");
helmet=clone_object("players/cyrex/helmet");
move_object(helmet, this_object());
command("wear helmet");
shield=clone_object("players/cyrex/shield");
move_object(shield, this_object());
command("wear shield");
/* Setting wc/ac after wield and wear.. -Snow */
set_wc(25);
set_ac(15);
}
