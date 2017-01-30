#include "/players/fred/closed/bloodfist/defs.h"

status main(string str, object PO, object User)
{
  int cost;
  if(User->query_ghost()) return 0;
  if(!PO->level_check(6)) return 0;
  if(!HONOR_DAEMON->honor_check(800))
  {
    TOU "Your Blood Honor is not high enough.\n");
    return 1;
  }

  cost = 60 - (WIS / 20) - (FAI / 20);

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
  if(PO->query_heal_time() > 5)
    return (notify_fail("You can not cast this again yet.\n"), 0);

  TOU RED+"\n ~-~ -~//- ~> "+NORM+"You beckon with your hands"+RED+
    " --~//.~-`\n//-~ ~ -.~ "+NORM+
    "The blood crystal pours red light"+RED+
    "~ - - ~ //.\n* //..-~"+NORM+
    "A wave of healing envelops you then passes"+RED+" ~- -~./-\n\n"+NORM);

  TRU Name+" beckons with "+User->POS+" hands as "+User->POS+
    " blood crystal glows.\n", ({ User }));

  PO->add_endurance(((int)PO->query_max_endurance()
    * (4 + (WIS / 22))) / 100); /* 4-8% */
  User->add_sp(-cost);
  User->add_hit_point(80);
  PO->add_heal_time(5);
  return 1;
}
