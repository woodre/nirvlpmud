/*
Created by: Feldegast
Date: 1-1-01
Description:
  A defensive field for the Healer shield spell.  The
old shield spell was...problematic and this version is
less likely to have conflicts.
Added a Resistance to be shown on the short() - Maledicta
 4-23-01
*/
#include "/players/feldegast/closed/ansi.h"

object target;
int heh;
int id(string str) {
  return str=="shield_spell" ||
         str=="shielding" ||
         str=="field";
}

string short() { 
if(this_player())
if(this_player()->query_level() > 19) return "A Shield of Light RES("+heh+"%)";
return "A Shield of Light"; }

int query_weight() { return 0; }
int drop() { return 1; }
int get() { return 0; }

void start(object targ, int strength, int duration) {
  mixed *parms;
  target = targ;
  heh = strength;
  parms = ({ "physical", 0, strength, "do_special" });
  move_object(this_object(),targ);
  targ->RegisterArmor(this_object(), parms);
  call_out("stop", duration);
}

void charge(int duration) {
  int time_left;
  time_left = find_call_out("stop");
  remove_call_out("stop");
  time_left += duration;
  call_out("stop", duration);
}

void stop() {
  tell_object(target,"The Shield of Light vanishes.\n");
  if(environment(target))
     tell_room(environment(target),"The Shield of Light vanishes from around "+target->query_name()+".\n", ({ target }));
  target->RemoveArmor(this_object());
  destruct(this_object());
}

int do_special(object owner) {
  if(!random(10)) {
    tell_object(owner,HIC+"The shield of light absorbs some of the blow.\n"+NORM);
    if(this_player() && this_player()!=owner)
      write(HIC+"The shield of light absorbs some of your blow.\n"+NORM);
  }
  return 0;
}

void remove_object(object ob) {
  target->RemoveArmor(this_object());
}


