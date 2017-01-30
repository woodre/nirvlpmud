/*
File: reinstate_spell.c
Creator: Feldegast @ Nirvana
Date: 1/2/00
Description:
  This is a token for the reinstate spell that stays in a
player's inventory.  It raises one attribute, and then 
removes it after 1200 heartbeats.  This object autoloads.
*/

#include "../def.h"
#define DURATION 600

object targ;
int time;
string attrib;
int amount;
int time_left;

int drop() { return 1; }
int get() { return 0; }

id(str) {
  return str=="reinstate_spell";
}

short() {
  if(this_player() && this_player()->query_level() > 20)
    return "Attribute bonus: "+attrib+":"+amount+" "+time_left+" hbs remaining";
}

extra_look() {
  return targ->query_name()+" looks energized";
}

query_auto_load() {
  return root+"obj/reinstate_spell:"+time_left+"/"+attrib+"/"+amount;
}

init_arg(str) {
  if(sscanf(str,"%d/%s/%d",time_left,attrib,amount)!=3)
    destruct(this_object());
  call_out("delayed_reset",1);
}

/* Blah! */
delayed_reset() { 
  targ = environment();
  if(!targ->is_player())
    destruct(this_object());
}

start(target, atrb, amt) {
  targ=target;
  if(!targ) return;
  attrib=atrb;
  amount=amt;
  time_left = DURATION;
  targ->set_attrib(attrib,targ->query_attrib(attrib)+amt);
  move_object(this_object(),targ);
  command("save",target);
}  

stop() {
  if(!targ) return;
  tell_object(targ, "You no longer feel energized.\n");
  targ->set_attrib(attrib,targ->query_attrib(attrib)-amount);
  destruct(this_object());
}

reset(arg) {
  if(arg) return;
  set_heart_beat(1);
}

remove_object() {
  stop();
}

heart_beat() {
  time_left--;
  if(time_left <= 0)
    stop();
}
