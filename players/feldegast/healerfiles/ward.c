/*
Created by: Feldegast
Date: 8-29-01
Description:
  A 'ward' spell for healers.  Basicly, a typed defensive shield.
Based largely upon the shield spell(also designed by myself).
*/
#include "/players/feldegast/closed/ansi.h"

object target;
int heh;
string dmg_type;
int bonus;

int id(string str) {
  return str=="ward_spell" ||
         str=="ward";
}

string short() { 
  if(this_player())
    if(this_player()->query_level() > 19)
      return "Ward *(" + capitalize(dmg_type) + ")* RES("+heh+"% "+"+"+bonus+")";
  return "Ward *(" + capitalize(dmg_type) + ")*";
}

int query_weight() { return 0; }
int drop() { return 1; }
int get() { return 0; }

void start(object targ, string type, int strength, int duration) 
{
  mixed *parms;
  string dmg_string;
  target = targ;
  dmg_string = "other|"+type;
  /* +1 ac vs damage type for every ten levels after 19+15 */
  if(strength > 35)
  {
    bonus = (strength - 35) / 10;
    heh = 35;
  } 
  else
    heh = strength;

  dmg_type = type;
  parms = ({ "other|"+dmg_string, bonus, strength, "do_special" });
  move_object(this_object(),targ);
  targ->RegisterArmor(this_object(), parms);
  call_out("stop", duration);
}

void charge(int duration) 
{
  int time_left;
  time_left = find_call_out("stop");
  remove_call_out("stop");
  time_left += duration;
  call_out("stop", duration);
}

void stop() 
{
  tell_object(target, HIY+"The Ward vanishes.\n"+NORM);
  if(environment(target))
     tell_room(environment(target), HIY+"The Ward vanishes from around "+target->query_name()+".\n"+NORM, ({ target }));
  target->RemoveArmor(this_object());
  destruct(this_object());
}

int do_special(object owner) 
{
  if(!random(10)) {
    tell_object(owner, HIC+"The Ward against " + capitalize(dmg_type) + " absorbs some of the blow.\n"+NORM);
    if(this_player() && this_player() != owner)
      write(HIC + "The ward against " + dmg_type + " absorbs some of your blow.\n" + NORM);
  }
  return 0;
}

void remove_object(object ob) 
{
  target->RemoveArmor(this_object());
}


