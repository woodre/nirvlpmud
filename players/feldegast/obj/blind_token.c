/*
File: blind_token.c
Author: Feldegast
Date: 3-17-02
Description:
  A counter for the blind spell.  It will reduce the player's
weapon class, and armor class.  It eventually wears off.
Based upon the web token.
*/
#include "/players/feldegast/defines.h"

object target;

void reset(int arg)
{
  if(arg) return;
  call_out("stumble", 10+random(20));
  call_out("end", 300 + random(300));
}

void start(object ob)
{

  target = ob;
  target->RegisterArmor(this_object(), ({ "physical", 0, -30, "do_special" }) );
}


int do_special(object owner)
{
  if(!random(5)) tell_object(owner, YEL+"You are completely blindsided by the attack.\n"+NORM);
}

string extra_look()
{
  return (string)environment()->query_name()+" is blind";
}

int id(string str)
{
  return str == "generic_wc_bonus" || str == "blind_token";
}

int gen_wc_bonus()
{
  if(!random(5))
  {
    tell_object(environment(), HIY+"You can't see your opponent!\n"+NORM);
  }
  return -5;
}

void stumble()
{
  if(target) 
  {
    tell_object(target, "You stumble about blindly.\n");
    tell_room(environment(target), (string)target->query_name()+" stumbles about blindly.\n",({target}));
    call_out("stumble", 10+random(20));
  }
}

void end()
{
  tell_object(target, BBLK+HIW+"\nYour vision begins to clear.\n\n"+NORM);
  target->RemoveArmor(this_object());
  destruct(this_object());
}

query_auto_load() { return "/players/feldegast/obj/blind_token.c:"; }

drop() {
  if(environment()->is_dieing()) destruct(this_object());
  else return 1;
}
