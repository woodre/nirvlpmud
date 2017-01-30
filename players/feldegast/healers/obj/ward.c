/*
Created by: Feldegast
Date: 8-29-01
Mods: 11-26-01 Refitting for new healers.
Description:
  A 'ward' spell for healers.  Basicly, a typed defensive shield.
Based largely upon the shield spell(also designed by myself).
*/
#include "/players/feldegast/closed/ansi.h"

object target;
string dmg_type;
string color;
int ac;
int res;

int id(string str) {
  return str=="ward_spell" ||
         str=="ward" ||
         str==dmg_type+"_ward_spell";
}

string short() { 
  if(this_player())
    if(this_player()->query_level() > 19)
      return "Ward "+BOLD+"*(" + color + capitalize(dmg_type) + NORM + BOLD + ")* "+NORM+"RES("+res+"% "+"+"+ac+")";
  return "Ward "+BOLD+"*(" + color + capitalize(dmg_type) + NORM + BOLD + ")*"+NORM;
}

int query_weight() { return 0; }
int drop() { return 1; }
int get() { return 0; }

void start(object targ, string type, string lcolor, int lac, int lres, int duration) 
{
  mixed *parms;
  string dmg_string;

  target = targ;
  dmg_string = "other|"+type;
  dmg_type = type;
  color = lcolor;
  ac = lac;
  res = lres;

  parms = ({ dmg_string, ac, res, "ward_spell" });
  targ->RegisterArmor(this_object(), parms);

  move_object(this_object(),targ);

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
     tell_room(environment(target), HIY+"The "+capitalize(dmg_type)+" Ward vanishes from around "+target->query_name()+".\n"+NORM, ({ target }));
  target->RemoveArmor(this_object());
  destruct(this_object());
}

int ward_spell(object owner) 
{
  if(!random(10)) {
    tell_object(owner, HIC+"The Ward against " + capitalize(dmg_type) + " absorbs some of the blow.\n"+NORM);
    if(this_player() && this_player() != owner)
      write(HIC + (string)owner->query_name()+"'s ward against " + 
                  capitalize(dmg_type) + " absorbs some of your blow.\n" + NORM);
  }
  return 0;
}

void remove_object(object ob) 
{
  target->RemoveArmor(this_object());
}


