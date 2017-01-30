/* Took out whiskey (11-shot heal20) and cut coins by 600 -Snow */

inherit "obj/monster";
object gold, microphone, bikini, whiskey;
int items;
reset(arg) {
::reset(arg);
if(arg) return;
set_name("Lynn Minmei");
set_alias("lynn");
set_alt_name("minmei");
set_short("Lynn Minmei");
set_long("A beautiful young singing star that captures your heart!!\n");
set_level(10);
set_hp(300);
set_al(500);
set_whimpy();
set_aggressive(0);
set_chat_chance(10);
load_chat("Minmei sings: You want me...and I want you...together forever...\n");
load_chat("Minmei sings: Promise me..that this love will never end...\n");
load_chat("Minmei sings: Our love...it will never end....please believe me...\n");
set_a_chat_chance(15);
load_a_chat("Minmei screams: How could you do this to me?!?!..\n");
load_a_chat("Minmei cries: Oh dear!...Is this the end of me singing career??\n");
load_a_chat("Minmei yells: RICK!!..where are you??....HELP ME!!\n");
gold=clone_object("obj/money");
gold->set_money(random(300)+50);
move_object(gold, this_object());
microphone=clone_object("players/cyrex/microphone");
move_object(microphone, this_object());
command("wield microphone");
bikini=clone_object("players/cyrex/bikini");
move_object(bikini, this_object());
command("wear bikini");
/* Setting ac/wc after wield and wear...  -Snow */
set_ac(10);
set_wc(12);
}
