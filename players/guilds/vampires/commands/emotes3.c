/*
Vampire emotions
     faint
*/

#include "/players/eurale/defs.h"

vfaint(str) {
object who;
if(!str || present(str,ETP)) {
  say(capitalize(TPRN)+" raises the back of "+TPPOS+" hand to "+TPPOS+
    " forehead and faints.\n");
  write("You raise the back of your hand to your forehead and faint.\n");
  return 1; }
who = find_player(str);
if(!who) {
  write(capitalize(str)+" doesn't seem to be here.\n");
  return 1; }
tell_object(who,
capitalize(TPRN)+" falls in a dead faint far off in the distance.\n");
write("You faint for "+capitalize(str)+" far off in the distance.\n");
return 1;
}

vbird(str) {
object who;
if(!str) { write("You give yourself the finger!\n"); return 1; }
who = find_player(str);
if(!who) {
  write("They don't seem to be logged on right now....\n");
  return 1; }
if(present(str,ETP)) {
  say(capitalize(TPRN)+" gives "+capitalize(str)+" the finger!\n");
  write("You give "+capitalize(str)+" the finger!\n");
  return 1; }
tell_object(who,
  capitalize(TPRN)+" gives you the finger from far off!\n");
write("You give "+capitalize(str)+" the finger way over there!\n");
return 1;
}
