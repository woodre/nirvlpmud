#include "/players/fred/closed/bloodfist/defs.h"

status main(string str, object PO, object User)
{
  int cost;
  if(User->query_ghost()) return 0;
  if(!PO->level_check(3)) return 0;
  if(!HONOR_DAEMON->honor_check(200))
  {
    TOU "Your Blood Honor is not high enough.\n");
    return 1;
  }

  cost = 40 - (WIS / 20) - (FAI / 20);

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

  if(PO->query_heal_time() > 3)
    return (notify_fail("You can not cast this again yet.\n"), 0);

  TOU RED+"\n ~-~ -~// ~> "+NORM+"You beckon with your hands"+RED+
    " --~//.~-`\n//-~ ~ .~ "+NORM+
    "The blood crystal begins to glow"+RED+
    "~ - - ~ //.\n* //..-~"+NORM+
    "A warmth flows over you and then passes"+RED+" ~- -~./-\n\n"+NORM);

  TRU Name+" beckons with "+User->POS+" hands as "+User->POS+
    " blood crystal glows.\n", ({ User }));

  PO->add_endurance(((int)PO->query_max_endurance()
    * (2 + (WIS / 34))) / 100); /* 2-4% */
  User->add_sp(-cost);
  User->add_hit_point(30);
  PO->add_heal_time(2);
  return 1;
}
