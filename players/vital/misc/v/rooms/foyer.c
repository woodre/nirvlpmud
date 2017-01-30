inherit "room/room";
#include "check.h"
#include "/players/eurale/defs.h"
int ONE;  /*  only one person  */
object note;

reset(arg) {
  if(arg) return;
set_light(-1);
ONE = 0;  /* nobody in space  */

short_desc = BOLD+"A rocky foyer"+NORM;
long_desc =
  "This is the foyer to the trials room.  It is a small, circular room\n"+
  "with a curved stairway, cut right into the solid rock, leading up to\n"+
  "the Vampire Guild Hall.  An ominous black opening leads into the\n"+
  "trials room where the Vampire Elders test the aspiring new vampires.\n"+
  "The whole area has been chiseled out of solid rock so that no noise\n"+
  "can penetrate or leave the area.\n";

items = ({
  "stairway","Narrow and curved sharply, the steps have been worn\n"+
             "smooth by the shoes of countless Vampires who have\n"+
             "traveled them when facing their trials",
  "rock","Granite like, very grey and extremely dense",
  "opening","A black hole in the wall that seems to shimmer as if it\n"+
            "was imaginary.  It is too dark to see where it leads",
});

dest_dir = ({
  "players/eurale/VAMPIRES/RMS/titles.c","up",
  "players/eurale/VAMPIRES/RMS/trial_room.c","enter",
});

}

set_ONE(i) { ONE = i; }
query_ONE() { return ONE; }

init() {
  ::init();
  add_action("enter","enter");
  add_action("listen","listen");
}

enter() {
object vamp,ob;
  ob = present("tpass",TP);

if(!present("vampire fangs",TP)) {
  write("\nYou hear a high-pitched noise and then a "+BOLD+
        "swarm of bats"+NORM+" swoops\n"+
        "in and picks you up and carries you away.... "+
        "then "+BOLD+"DROPS"+NORM+" you...\n\n");
  call_other("/room/lanceroad1", "???", 0);
  move_object(TP, "/room/lanceroad1.c");
  command("look",TP);
  return 1; }

if(!ob) {
  write("As you try to enter the trials room, a whisper from the\n"+
        "darkness stops you in your tracks....  It says, 'Only the\n"+
        "darkest of heart may enter this sacred place, be gone!'\n");
  return 1; }

if(TPGEXP == 666 && ONE == 0) {
  if(TPL < 7) {
    write("A voice tells you, 'Too small for the first trial'.\n");
    return 1; }
  vamp = clone_object("/players/eurale/VAMPIRES/NPC/vampire1.c");
  move_object(vamp, TRIAL_ROOM);
  TP->move_player("opening#players/eurale/VAMPIRES/RMS/trial_room.c");
  destruct(ob);
  ONE = 1;
  return 1; }

if(TPGEXP == 667 && ONE == 0) {
  if(TPL < 12) {
    write("You hear, 'You'll have to be bigger for the second trial'.\n");
    return 1; }
  vamp = clone_object("/players/eurale/VAMPIRES/NPC/vampire2.c");
  move_object(vamp, TRIAL_ROOM);
  TP->move_player("opening#players/eurale/VAMPIRES/RMS/trial_room");
  destruct(ob);
  ONE = 1;
  return 1; }

if(TPGEXP == 668 && ONE == 0) {
  if(TPL < 17) {
  write("A whisper, 'You lack the levels for the third trial'.\n");
    return 1; }
  vamp = clone_object("/players/eurale/VAMPIRES/NPC/vampire3.c");
  move_object(vamp, TRIAL_ROOM);
  TP->move_player("opening#players/eurale/VAMPIRES/RMS/trial_room");
  destruct(ob);
  ONE = 1;
  return 1; }

if(TPGEXP == 669 && ONE == 0) {
  if(TPL < 19) {
    write("A voice whispers, 'You are too small for the final trial'.\n");
    return 1; }
  vamp = clone_object("/players/eurale/VAMPIRES/NPC/vampire4.c");
  move_object(vamp, TRIAL_ROOM);
  TP->move_player("opening#players/eurale/VAMPIRES/RMS/trial_room");
  destruct(ob);
  ONE = 1;
  return 1; }

if(TPGEXP > 669 && ONE == 0) {
  write("A ghostly vampire appears from the darkness and whispers, \n"+
    BOLD+"'You have finished all the trials, "+HIR+"NOSFERATU"+NORM+
    BOLD+"... be gone and\n"+
    "quit wasting our time'"+NORM+"... Then he steps back into the\n"+
        "darkness from which he came and disappears.....\n");
  destruct(ob);
  return 1; }

write("A dark figure appears beside you and whispers, 'The trial\n"+
      "arena is in use, please come back a bit later.'  And as\n"+
      "quickly as he appeared, he is gone...\n");
return 1;
}

listen(str) {
if(!str || str == "noise" || str == "sounds") {
  write("You listen intently.... it's so quiet it's eerie..\n");
  say(capitalize(TPRN)+" listens for noises...\n");
  return 1; }
}
