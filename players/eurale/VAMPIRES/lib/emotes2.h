/*
Vampire emotions
    bow  chortle  curtsey  hiss  khand  kneck  knipple yawn
*/

#include "/players/eurale/defs.h"

vbow(str) {
  object target;
if(!str) {
  FANGS->tell_my_room(
    capitalize(TPRN)+" bends slowly and bows with vampiric grace.\n");
  write("You bow with vampiric grace.\n");
  return 1; }
target = find_player(str);
if(!target) {
  write(capitalize(str)+" doesn't seem to be here.\n");
  return 1; }
if(target->query_level() > 20 && target->query_invis() > 0) return 0;
if(present(str,ROOM)) {
  FANGS->tell_my_room(
    capitalize(TPRN)+" bows with vampiric grace to "+capitalize(str)+
    ".\n");
  write("You bow with vampiric grace to "+capitalize(str)+".\n");
  return 1; }
tell_object(target,
  capitalize(TPRN)+" bows with vampiric grace to you "+
  "from far off in the distance.\n");
write("You bow with vampiric grace to "+
      capitalize(str)+", far off in the distance.\n");
return 1;
}

vcurtsey(str) {
  object target;
if(!str) {
  say(capitalize(TPRN)+" slowly curtseys with vampiric grace.\n");
  write("You curtsey with vampiric grace.\n");
  return 1; }
target = find_player(str);
if(!target) {
  write(capitalize(str)+" doesn't seem to be here.\n");
  return 1; }
if(present(str,ROOM)) {
  FANGS->tell_my_room(
    capitalize(TPRN)+" slowly curtseys with vampiric grace to "+
      capitalize(str)+".\n");
    write("You slowly curtsey with vampiric grace to "+
      capitalize(str)+".\n");
    return 1; }
tell_object(target,
  capitalize(TPRN)+" curtseys with vampiric grace to you from far off.\n");
write("You curtsey with vampiric grace to "+capitalize(str)+
      " in the distance.\n");
return 1;
}

vyawn() {
  say(capitalize(TPRN)+" yawns exposing "+TP->query_possessive()+
      " long, deadly fangs.\n");
  write("You yawn, exposing your long, deadly fangs.\n");
return 1; }

vchortle() {
  say(capitalize(TPRN)+"'s lips pull back in a snarl, "+
  TP->query_possessive()+" head tilts back and\n"+
  "    from deep down "+TP->query_pronoun()+" chortles demonically!\n");
  write("You snarl and from deep down you chortle demonically!\n");
return 1; }

vkhand(str) {
object who;
if(!str) { write("Whose hand?\n"); return 1; }
who = present(str,environment(this_player()));
if(!who) {
  write(capitalize(str)+" does not appear to be present.\n");
  return 1; }
say(capitalize(TPRN)+" galantly bows and tenderly kisses "+
    capitalize(str)+"'s hand.\n");
write("You gallantly bow and tenderly kiss "+capitalize(str)+"'s hand.\n");
return 1;
}

vhiss() {
say(capitalize(TPRN)+" snarls and emits a loud HISSSSSS...\n");
write("You snarl and emit a loud HISSSSSS...\n");
return 1; }

vneck(str) {
object who;
if(!str) { write("Whose neck?\n"); return 1; }
who = present(str,environment(this_player()));
if(!who) {
  write(capitalize(str)+" is not present.\n");
  return 1; }
say(capitalize(TPRN)+" pushes "+capitalize(str)+"'s hair back exposing "+
  who->query_possessive()+" neck.\n"+
  capitalize(TP->query_pronoun())+" licks a small spot over a "+
    "throbbing artery and kisses it gently.\n");
write("You push "+capitalize(str)+"'s hair back exposing "+
  who->query_possessive()+" neck.\n"+
  "You lick a small spot over a throbbing artery and kiss it gently.\n");
return 1; }

knipple(str) {
object who;
if(!str) { write("What are you up to?\n"); return 1; }
who = present(str,environment(this_player()));
if(!who) {
  write("Sorry, but they're not here!\n");
  return 1; }
say(capitalize(TPRN)+" gently and ever so lightly kisses "+
  capitalize(str)+"'s erect nipples.\n");
write("You gently and ever so lightly kiss "+capitalize(str)+"'s erect "+
  "nipples.\n");
return 1; }
