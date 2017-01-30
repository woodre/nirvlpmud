#include "/players/eurale/closed/ansi.h"
#define NAME "Eurale"
#define DEST "room/forest10"

id(str) { return str == "warp"; }

short() { return BOLD+"Time Warp"+NORM; }

long() { write(
  "This is a flaw in the fabric of time.  You may enter and explore\n"+
  "the various destinations by typing ["+BOLD+"warp"+NORM+"].\n");
}

init() {
  add_action("step", "warp");
}

step() {
  this_player()->move_player("warp#players/eurale/RMS/warp.c");
    return 1;
}

reset(arg) {
object qob;

  /*  Quests  */
if(!present("lost_rood",find_object("room/quest_room.c"))) {
  qob = clone_object("obj/quest_obj");
  qob->set_name("lost_rood");
  qob->set_hint("Ask the grimalkin in Drygulch\n");
  move_object(qob,"room/quest_room");
}

if(!present("phantasm_puzzle",find_object("room/quest_room.c"))) {
  qob = clone_object("obj/quest_obj");
  qob->set_name("phantasm_puzzle");
  qob->set_hint("Inquire of Drizella's stepsister.\n");
  move_object(qob,"room/quest_room");
}

if(!present("hooks_hand",find_object("room/quest_room.c"))) {
  qob = clone_object("obj/quest_obj");
  qob->set_name("hooks_hand");
  qob->set_hint(
	"A barker's price gets you through the gate..\n"+
	"Ask him for the clue and change your fate.....\n");
  move_object(qob,"room/quest_room");
}

if(!present("key_quest",find_object("room/quest_room.c"))) {
  qob = clone_object("obj/quest_obj");
  qob->set_name("key_quest");
  qob->set_hint(
    "To unlock the secret of the wanting well,\n"+
    "forage the sarcophagus glebe for the key.\n");
  move_object(qob,"room/quest_room");
}

if(!present("keep_dragons",find_object("room/quest_room.c"))) {
  qob = clone_object("obj/quest_obj");
  qob->set_name("keep_dragons");
  qob->set_hint(
	"Sit in the royal seat of the banneret who has\n"+
	"visited the Reaper and be very patient.\n");
  move_object(qob,"room/quest_room");
}

if(!present("t_rexs",find_object("room/quest_room.c"))) {
  qob = clone_object("obj/quest_obj");
  qob->set_name("t_rexs");
  qob->set_hint(
    "Visit the Park and ask the ranger for the 'problem'.\n");
  move_object(qob,"room/quest_room");
}

if(!present("despoina",find_object("room/quest_room.c"))) {
  qob = clone_object("obj/quest_obj");
  qob->set_name("despoina");
  qob->set_hint(
    "Despoina must die by the blade of the Holy Avenger wielded\n"+
    "by none other than the Guardian of the Paladins.\n");
  move_object(qob,"room/quest_room");
}
  if(arg) return;
    move_object(this_object(), DEST);

  /* Autoload Objects  */
/* 11/18/05 Earwax: switched these from clone_object() */
call_other("players/eurale/Keep/OBJ/poison.c", "???");
call_other("players/eurale/Keep/OBJ/poison2.c", "???");
call_other("players/eurale/Abyss/OBJ/mark.c", "???");
call_other("players/eurale/closed/VD.c", "???");
call_other("players/eurale/VAMPIRES/OBJ/batwings.c", "???");
call_other("players/eurale/OBJ/button.c", "???");
/* moved to init-file for ld -Bp
call_other("players/eurale/VAMPIRES/vampob.c", "???");
*/
call_other("players/eurale/VAMPIRES/changefangs.c", "???");
call_other("players/eurale/VAMPIRES/OBJ/vampire_bite.c", "???");
call_other("players/eurale/Lab/OBJ/acid.c", "???");
call_other("players/eurale/Lab/OBJ/scorptox.c", "???");
call_other("players/eurale/Lab/OBJ/toadtox.c", "???");
call_other("players/eurale/closed/shut_up.c", "???");
/* What exactly is this for?  Who's autoloading this?  Why does Mythos
 * and Eurale each need this?
 * 03/21/06 Earwax: just commented this out.  No need.
call_other("players/eurale/closed/garble.c", "???");
 */

}

is_castle(){return 1;}
