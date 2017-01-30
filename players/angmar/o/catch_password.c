#pragma strong_types

#include <living.h>

/*
 * This is a listener. It listen to the players an communicate
 * with the environment
 */

string callfunc,callroom;
string next_out;
object next_dest,callobject;

string short() { return 0; }
status get() { return 0; }
void long() { }
mixed id(string str) { return 0; }

void
reset(status arg) {
  if (arg)
    return;
  msgout = "leaves";
  msgin = "enters";
  name = "listener";
  next_out = 0;
  is_npc = 1;
  level = 40;
  alignment = 0;
  weapon_class = WEAPON_CLASS_OF_HANDS;
  max_hp = 300;
  hit_point = 300;
  experience = 100000;
  enable_commands();
  spell_points = 300;
  is_invis = 1; 
}

void set_object(object obj) { callobject = obj; }
void set_room(string str) { callroom = str; }

void
catch_tell(string str) {
  object from;

  from = this_player();
  if (!from)
    return;  /* Not from a real player. */
  if (callobject)
    call_other(callobject, callfunc , str);
  else if (callroom)
    call_other(callroom, callfunc , str);
  else {
    set_heart_beat(0);
    destruct(this_object());
  }
}

/*
 * Always let the heart_beat do the talking, to simulate delay.
 */

void
heart_beat() {
  if (next_out) {
    tell_object(next_dest, next_out);
    next_out = 0;
  }
  set_heart_beat(0);
}

void set_call(string str) { callfunc = str; }
