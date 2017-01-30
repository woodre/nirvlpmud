/*
Created by: Feldegast
Date: 1-1-01
Description:
  A defensive field for the Healer defend spell.  The old defend
spell didn't work with the new armor system.
Stolen By Jaraxle for Bards guild.
Date: 03-15-02
*/

#include "/players/mokri/ansi.h"

object target;
object source;

int id(string str) {
  return str=="bard_defend_spell";
}

extra_look(){
	return environment()->query_name()+"'s body is distorted by waves of "+HIB+"sound"+NORM;
}

int drop() { return 1; }
int get() { return 0; }

void start(object targ, int ac, int dtime, object caster) {
	int time;
    mixed *parms;
	time = dtime;
  target = targ;
  source = caster;
  parms = ({ "physical", ac, 0, "do_special" });
  move_object(this_object(),targ);
  targ->RegisterArmor(this_object(), parms);
  call_out("stop", time);
}

void stop() {
  object room;
  target->RemoveArmor(this_object());
  if(target) {
    room=environment(target);
    tell_object(target, HIB+"The distortion field surrounding you dissipates.\n"+NORM);
    if(room) tell_room(room,HIB+
"The distortion field around "+target->query_name()+" dissipates.\n"+NORM,
                       ({target}));
  }
  destruct(this_object());
}

int do_special(object owner) {
  if(!source) {
    object room;
    room=environment(owner);
    if(room) tell_room(room,
HIB+"A loud, high-pitched whine fills the area!\n"+NORM);
    tell_object(owner,HIB+
"The whine is coming from your distortion field.  Something seems to be\n"+
"interfering with it.\n"+NORM);
    remove_call_out("stop");
    stop();
  } else if(!random(10))
    tell_object(owner, HIB+"The air around you distorts.\n"+NORM);  
  return 0;
}

void remove_object(object ob) {
  target->RemoveArmor(this_object());
}
