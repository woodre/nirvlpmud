inherit "/obj/monster.c"; /* monster.talk no longer loads for some reason -Feldegast 8/19/00 */

object gold;
reset(arg) {
::reset(arg);
if(!arg) {
    set_name("gamemaster");
set_alias("angst");
set_short("Angst the biomech");
    set_race("biomech");
    set_long(
"Angst is the Grand Champion of the hunt.  He is a biomech,\n"+
"(a biological machine).  He reigned as supreme hunter for 4 centuries\n"+
"before the masters decided to retire him. Now he serves as\n"+
"guardian and guide to the hunt.  As long as blood remains to \n"+
"be spilled..The GameMaster shall remain at his post with his\n"+
"trusted dog, Henry.  The only thing Angst loves more than \n"+
"spilling blood is his only friend Henry <HINT>.\n"+
"If one is brave enough ..join the hunt..Angst is always willing \n"+
"to help the initiate.\n");
gold = clone_object("obj/money");
gold -> set_money (random (10000) + 2000);
move_object(gold, this_object());
   set_level(20);
call_other(this_object(),"set_heal",0,0);
   set_ac(30);
   set_wc(30);
   set_hp(10000);
   set_al(-300);
 /* changed to two different spells and damage upped by illarion May 2005
set_chance(20);
set_spell_dam(30);
set_spell_mess1("Gamemaster begins to remove your spine.");
set_spell_mess2("GameMaster helps you lose weight by removing your head!?!.");
*/
   add_spell("spinal tap",
"The GameMaster moves behind you with blinding speed, and plunges his hand\n"+
"into your back with bone-shattering force.  $HR$Blood$N$ spurts from the wound!\n",
"The GameMaster moves behind #TN# with blinding speed, and plunges his hand\n"+
"into #TN#'s back!  $HR$Blood$N$ spurts from the wound!\n",10,"50-150");
  set_aggressive(0);
    set_a_chat_chance(10);
   set_chat_chance(10);
load_chat("Angst says: The hunter equals the HUNTED..\n");
load_chat("Angst says: That which does not kill you only makes you stronger\n");
load_chat("Angst States: Be warned killing attracts other hunters.\n");
load_chat("Angst rubs Henry's head calmly.\n");
load_a_chat("Angst smiles-You really are dumb, arent ya?\n");
load_a_chat("Angst shakes his head..he thinks its a shame youll never survive.\n");
load_a_chat("Oh well, I can always use another trophy<sigh>\n");
}
}
