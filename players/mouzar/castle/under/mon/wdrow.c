inherit"obj/monster";
reset(arg) {
object gold;
object armor;
object treasure;
::reset(arg);
if(arg) return;
set_chat_chance(25);
set_a_chat_chance(2);
load_chat("Drow Wizard says:  No female can tell me what to do!\n");
load_chat("Drow Wizard says:  No one can touch me!\n");
load_a_chat("Drow Wizard says calmly:  Someone stupid enough to attack me.\n");
load_a_chat("Drow Wizard laughs at you.\n");
set_name("wizard");
set_alias("punk");
set_short("Drow Wizard");
set_long(
"This wizard is dressed in black robes.  He make you cringe in fear cause \n"
+ "everthing on him is black execpt for his white hair and red eyes.  He\n"
+ "keeps an evil grin on his face at all times.  From what you see of his\n"
+ "body he is smaller than most drow but wizards do not need size to kick\n"
+ "ass.\n"
+ "\n");
set_level(20);
set_al(-500);
set_race("drow");
set_hp(600);
set_wc(30);
set_ac(20);
set_aggressive(1);
set_chance(50);
set_spell_dam(60);
set_spell_mess1("The Drow Wizard steps back and shoot some grey stuff his his opponent!");
set_spell_mess2("The Drow Wizard steps back and shoot some grey stuff at you!");
armor = clone_object("/players/mouzar/castle/under/obj/drobe");
 move_object(armor,this_object());
treasure = clone_object("/players/mouzar/castle/under/obj/cball");
 move_object(treasure,this_object());
}
