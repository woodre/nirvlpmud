inherit "obj/monster";
object blsword, tarmor, boots;
int items;
reset(arg) {
::reset(arg);
if(arg) return;
set_name("Roy Fokker");
set_alias("roy");
set_short("Roy Fokker");
set_long("A man that has seen all in the face of battle.\n");
set_level(22);
set_hp(1000);
set_al(250);
set_ac(19);
set_wc(24);
set_aggressive(0);
set_chat_chance(10);
load_chat("Roy says: Someday you will want to be like me.......a HERO!\n");
load_chat("Roy says: The veritech is a hard mech to beat!\n");
set_a_chat_chance(10);
load_a_chat("Roy says: Are you stupid or what?! You will lose!\n");
load_a_chat("Roy says: Just wait till I get into my veritech!\n");
blsword=clone_object("players/cyrex/blsword");
move_object(blsword, this_object());
command("wield sword");
tarmor=clone_object("players/cyrex/tarmor");
move_object(tarmor, this_object());
command("wear armor");
boots=clone_object("players/cyrex/boots");
move_object(boots, this_object());
command("wear boots");
/* Set wc.ac after wield.wear -Snow */
/* no longer needed - illarion
set_wc(35);
set_ac(20);
*/
}
