/*
File: blur.c
Creator: Feldegast
Date: 4/27/01
Description:
  A spell cast by a crystal mage to create a blur field.  It acts as
an armor, and disappears after 15 minutes.
*/

#include "../defs.h"

object owner;

string short()
{
  if((int)TP->query_level() > 20)
    return "Blur: "+find_call_out("stop");
  else
    return 0;
}

string extra_look()
{
  return HIC+(string)owner->query_name()+" appears blurry and distorted"+NORM;
}

void start(object targ)
{
  mixed *parms;
  owner = targ;
  parms = ({ "physical", 1, 0, "do_special" });
  owner->RegisterArmor(this_object(), parms);
  call_out("stop", 900);
}

void stop()
{
  owner->RemoveArmor(this_object());
  destruct(this_object());
}

int do_special(object targ)
{
  if( (int)targ->query_attrib("wil") < random(80) )
  {
    if( (int)targ->query_sp() > 1 )
    {
      if(!random(3)) {
        tell_object(targ, CYN+"Your field of blurriness protects you!\n"+NORM); 
        write(CYN+(string)targ->query_name()+" blurs before your eyes!\n"+NORM);
      }
      targ->add_spell_point(-1);
      return 4;
    }
  }
}

void remove_object(object ob)
{
  stop();
}
