#include "/players/fred/closed/bloodfist/defs.h"

status main(string str, object PO, object User)
{
  int cost;
  if(User->query_ghost()) return 0;
  if(!PO->level_check(2)) return 0;
  if(!HONOR_DAEMON->honor_check(100))
  {
    TOU "Your Blood Honor is not high enough.\n");
    return 1;
  }

 cost = 30 - (WIS / 10) - (FAI / 20);

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

  if(PO->query_bloodcloak())
  {
    TOU "You step out from behind your bloodcloak.\n");
    TRU Name+" steps out from behind "+User->POS+" bloodcloak.\n",
      ({ User }));
    PO->set_bloodcloak(0);
    User->unset_invs_sp();
    return 1;
  }

  TOU RED+"\n ~ - >/ ~~ "+NORM+"You beckon with your hands"+RED+
    " -/ ~~ -- ~> /\n -//~ <. "+NORM+
    "The blood crystal begins to glow"+RED+" -~ ..> ~ -\n~  ~- /"+NORM+
    "A reddish glow swirls around your body"+RED+
    " - -/ ~>\n -~ > ~--.< "+NORM+
    "You vanish in an instant"+RED+" ~>-. ~-~./ /- `\n\n"+NORM);

  TRU Name+" vanishes in a red swirl of light.\n", ({ User }));

  User->add_sp(-cost);
  User->set_invs_sp();
  PO->set_bloodcloak(1);
  return 1;
}
