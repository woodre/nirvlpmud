/*
Vampire emotions:
  cackle  emote  glare  grin  kiss  laugh  smile
*/

#include "/players/eurale/defs.h"

vemote(str) {
tell_room(environment(TP),
  BOLD+"~o~ "+NORM+capitalize(TPRN)+" "+str+"\n");
  return 1; }

vlaugh(str) {
  object target;
if(!str) {
  FANGS->tell_my_room(
    capitalize(TPRN)+" laughs a hearty belly-laugh, exposing the tips "+
    "of "+TP->query_possessive()+" fangs.\n");
  write("You laugh a hearty belly-laugh, exposing the tips of your "+
        "fangs.\n");
  return 1; }
target = find_player(str);
if(!target) {
  write(capitalize(str)+" isn't logged on.\n");
  return 1; }
if(target->query_level() > 20 && target->query_invis() > 0) return 0;
if(!present(target,ROOM)) {
  tell_object(target,
   capitalize(TPRN)+" laughs a hearty belly-laugh at you from far away,\n"+
   "    exposing the tips of "+TP->query_possessive()+" fangs.\n");
  write("You laugh a hearty belly-laugh at "+capitalize(str)+" in the\n"+
        "    distance, exposing just the tips of your fangs.\n");
  return 1; }
FANGS->tell_my_room(
  capitalize(TPRN)+" laughs a hearty belly-laugh at "+capitalize(str)+
  " exposing the tips of "+TP->query_possessive()+" fangs.");
write("You laugh a hearty belly-laugh at "+capitalize(str)+
      " exposing the tips of your fangs.\n");
return 1;
}

vglare(str) {
object target_obj;

if(!str) {
  say(capitalize(TPRN)+" glares about the room in disgust.\n");
  write("You glare about the room in disgust.\n");
  return 1; }
target_obj = find_player(str);
if(!target_obj) {
  write(capitalize(str)+" doesn't seem to be logged on.\n");
  return 1; }
if (target_obj->query_level() > 20 && target_obj->query_invis() > 0)
    return 0;
tell_object(target_obj,
    "You feel a chill run down your spine as "+capitalize(TPRN)+
    "'s eyes glow\n"+
    HIR+"a bloody red"+NORM+" and "+TP->query_pronoun() +
    " glares balefully at you.\n");
write("You see "+capitalize(target_obj->query_name())+
        " shiver as you glare balefully at "+
        target_obj->query_objective()+".\n");
return 1;
}

vkiss(str) {
object who;

if(!str) { write("Kiss who?\n"); return 1; }
who = find_player(str);
if(!who) { write("Not logged on...\n"); return 1; }
if(who->query_level() > 20 && who->query_invis() > 0) return 0;

if(present(who,ROOM)) {
  tell_object(who,
    capitalize(TPRN)+" runs "+TP->query_possessive()+" tongue across "+
    TP->query_possessive()+" fangs with anticipation.\n"+
    capitalize(TPRN)+" mesmerises you with "+TP->query_possessive()+
    " eyes and pulls you in close.\n"+
    "Before you can do anything, "+TP->query_possessive()+
    " lips slide back, exposing "+TP->query_possessive()+" fangs.\n"+
    capitalize(TP->query_pronoun())+
    " kisses you deeply, and you feel "+TP->query_possessive()+
    " fangs nip your lower lip.\n");
  write("You run your tongue across your fangs with anticipation.\n"+
        "You focus your eyes on "+capitalize(str)+
        " and pull "+who->query_objective()+" in close.\n"+
        "Before "+who->query_pronoun()+" can do anything, "+
        "your lips slide back, exposing your fangs.\n"+
        "You kiss "+capitalize(str)+" deeply, and you feel your "+
        "fangs nip "+who->query_possessive()+" lower lip.\n");
  return 1; }
tell_object(who,
  capitalize(TPRN)+" blows you a "+HIR+"BIG JUICY KISS"+NORM+
  " from far away!\n");
write("You blow a "+HIR+"BIG JUICY KISS"+NORM+" to "+capitalize(str)+
      " far off in the distance.\n");
return 1;
}

vgrin(str) {
  object target_obj;

if(!str) {
FANGS->tell_my_room(
  capitalize(TPRN)+" grins evilly, exposing "+
  TP->query_possessive()+" fangs.");
  write("You grin widely, exposing your fangs.\n");
  return 1; }

target_obj = present(lower_case(str), ROOM);
if(!target_obj) {
  target_obj = find_player(str);
  if(!target_obj) return 0;
  if(target_obj->query_level() > 20 && target_obj->query_invis() > 0)
      return 0;

  tell_object(target_obj,
    capitalize(TPRN)+" grins at you from afar, exposing "+
        TP->query_possessive()+" fangs.\n");
    write("You grin widely at "+target_obj->query_name()+
          " in the distance, exposing your fangs.\n");
    return 1; }

if(!target_obj || !living(target_obj) || target_obj == TP) return 0;

FANGS->tell_my_room(
  capitalize(TPRN)+" grins at "+capitalize(str)+", exposing "+
    TP->query_possessive()+" fangs.", str);
  write("You grin widely at "+target_obj->query_name()+
        ", exposing your fangs.\n");
  return 1;
}

vsmile(str) {
object who;
if(!str) {
  say(capitalize(TPRN)+" smiles at you, exposing "+
      TP->query_possessive()+" sharp fangs.\n");
  write("You smile, exposing your sharp fangs.\n");
  return 1; }
who = find_player(str);
/* query_invis() and query_level() checks by verte [6.24.01] */
if(!who || (who->query_invis() && who->query_level() > 20)) { write("Not logged on!\n"); return 1; }
if(!present(str,environment(this_player())) && who) {
  tell_object(who,capitalize(TPRN)+" smiles at you from afar, exposing "+
    TP->query_possessive()+" sharp fangs.\n");
  write("You smile at "+capitalize(str)+" off in the distance, exposing"+
    " your fangs.\n");
  return 1; }
if(present(str,environment(this_player()))) {
  say(capitalize(TPRN)+" smiles at "+capitalize(str)+", exposing "+
      TP->query_possessive()+" sharp fangs.\n");
  write("You smile at "+capitalize(str)+", exposing your sharp fangs.\n");
  return 1; }
else {
  write("You don't see "+capitalize(str)+" here.\n");
  return 1; }
}

vcackle(str) {
object who;
if(!str) {
  FANGS->tell_my_room(
    "With a glint off "+TP->query_possessive()+" fang tip, \n"+
    "    "+capitalize(TPRN)+" throws back "+TP->query_possessive()+
    " head and cackles gleefully.\n");
  write(
    "With a glint off the tip of a long fang,\n"+
    "    you throw back your head and cackle gleefully.\n");
  return 1; }
}
