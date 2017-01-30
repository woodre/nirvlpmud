/*
Created by: Feldegast
Date: 1-1-01
Description:
  A defensive field for the Healer defend spell.  The old defend
spell didn't work with the new armor system.
*/
#include "/players/feldegast/closed/ansi.h"

object target;

int id(string str) {
  return str=="defend_spell";
}

int drop() { return 1; }
int get() { return 0; }

void start(object targ, int ac) {
  mixed *parms;
  target = targ;
  parms = ({ "physical", ac, 0, "do_special" });
  move_object(this_object(),targ);
  targ->RegisterArmor(this_object(), parms);
}

void stop() {
  target->RemoveArmor(this_object());
  destruct(this_object());
}

int do_special(object owner) {
  if(!random(10))
    tell_object(owner, HIC+"Your defensive field softens the blow.\n"+NORM);  
  return 0;
}

void remove_object(object ob) {
  target->RemoveArmor(this_object());
}
