#include "/players/fred/closed/bloodfist/defs.h"

status main(string str, object PO, object User)
{
  int cost;
  object fury, att;
  if(User->query_ghost()) return 0;
  if(!PO->level_check(7)) return 0;
  if(!HONOR_DAEMON->honor_check(1000))
  {
    TOU "Your Blood Honor is not high enough.\n");
    return 1;
  }
  if(!User->query_attack())
  {
    TOU "You must be in combat to use this ability.\n");
    return 1;
  }

  cost = 120 - (WIS / 10) - (FAI / 10);

  if((string)environment(User)->realm() == "NM")
  {
    TOU"Your energy is being drained here.\n");
    return 1;
  }

  if(User->query_sp() < cost)
  {
    TOU "You are too weak to do this now.\n");
    return 1;
  }

  if(PO->query_bloodfury()) 
    return (notify_fail("Bloodfury is already active.\n"),0);   
  
  if(PO->query_dur() >= PO->query_max_dur())
    return (notify_fail("You can not handle another duration ability.\n"),0);

  TOU RED+"\n ~-~ -~ /- ~>- "+NORM+"You beckon with your hands"+RED+
    " --`~/ ~- /.~-`\n/~ ~ -. ~ "+NORM+
    "The blood crystal glows with red light"+RED+
    "~ - - /~-.\n /..-~"+NORM+
    "Your motions are fueled by a torturous bloodfury"+
    RED+" ~- ~\n\n"+NORM);  

  TRU RED+Name+" is engulfed by bloodfury!\n"+NORM, ({ User }));

  fury = clone_object(DIR+"NPC/fury.c");
  fury -> set_owner(User);
  fury -> set_name(User->query_real_name());
  fury -> set_alt_name("fred_bf_fury_"+User->query_real_name());
  fury -> class_set(User->query_wc());
  move_object(fury, environment(User));
  if((att = (object)User->query_attack()) && present(att, environment(User)))
    fury->attack_object(att);

  PO->set_bloodfury(1);
  User->add_sp(-cost);
  PO->add_dur();  
  return 1;
}

