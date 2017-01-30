/*
  emotions.h
*/

#include "defs.h"

vbow(str) {
if(!str) {
  say(MY_NAME_CAP+" bends slowly and bows with vampiric grace.\n");
  write("You bow with vampiric grace.\n");
  return 1; }
if(!present(str,environment(this_player()))) {
  write(capitalize(str)+" doesn't seem to be here.\n");
  return 1; }
say(MY_NAME_CAP+" bends slowly and bows with vampiric grace to "+
    capitalize(str)+".\n");
write("You bend slowly and bow with vampiric grace to "+
      capitalize(str)+".\n");
return 1;
}

vcurtsey(str) {
if(!str) {
  say(MY_NAME_CAP+" slowly curtseys with vampiric grace.\n");
  write("You curtsey with vampiric grace.\n");
  return 1; }
if(!present(str,environment(this_player()))) {
  write(capitalize(str)+" doesn't seem to be here.\n");
  return 1; }
say(MY_NAME_CAP+" slowly curtseys with vampiric grace to "+
  capitalize(str)+".\n");
write("You slowly curtsey with vampiric grace to "+
  capitalize(str)+".\n");
return 1;
}

vyawn() {
if(MY_FANGS->query_in_a_form()) return 0;
  say(MY_NAME_CAP+" yawns exposing "+MY_PLAYER->query_possessive()+
      " long, deadly fangs.\n");
  write("You yawn, exposing your long, deadly fangs.\n");
return 1; }

vchortle() {
  say(MY_NAME_CAP+"'s lips pull back in a snarl, "+
  MY_PLAYER->query_possessive()+" head tilts back and\n"+
  "    from deep down "+MY_PLAYER->query_pronoun()+" chortles demonically!\n");
  write("You snarl and from deep down you chortle demonically!\n");
return 1; }

vkhand(str) {
object who;
if(!str) { write("Whose hand?\n"); return 1; }
who = present(str,environment(this_player()));
if(!who) {
  write(capitalize(str)+" does not appear to be present.\n");
  return 1; }
say(MY_NAME_CAP+" galantly bows and tenderly kisses "+
    capitalize(str)+"'s hand.\n");
write("You gallantly bow and tenderly kiss "+capitalize(str)+"'s hand.\n");
return 1;
}

vhiss() {
say(MY_NAME_CAP+" snarls and emits a loud HISSSSSS...\n");
write("You snarl and emit a loud HISSSSSS...\n");
return 1; }
