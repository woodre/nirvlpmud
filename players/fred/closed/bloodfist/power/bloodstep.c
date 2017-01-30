#include "/players/fred/closed/bloodfist/defs.h"

status main(string str, object PO, object User)
{
  int cost, a, sa, b;
  object portal, *home;
  if(User->query_ghost()) return 0;
  if(!PO->level_check(5)) return 0;
  if(!HONOR_DAEMON->honor_check(600))
  {
    TOU "Your Blood Honor is not high enough.\n");
    return 1;
  }

  cost = 65 - (WIS / 10) - (FAI / 20);
  b = 0; /* no portal */

  if((string)environment(User)->realm() == "NM")
  {
    TOU"Your energy is being drained here.\n");
    return 1;
  }

  if((string)environment(User)->realm() == "NT")
  {
    TOU"You cannot teleport from here.\n");
    return 1;
  }

  if(User->query_sp() < cost)
  {
    TOU "You are too weak to do this now.\n");
    return 1;
  }

  TOU RED+"\n ~ - >/ ~ ~ "+NORM+"You beckon with your hands"+RED+
    " -/ ~~ -- ~> /\n -/ /~ <. "+NORM+
    "The blood crystal begins to glow"+RED+" -~ ..> ~ -\n ~  ~- /"+NORM+
    "A red portal appears in front of you"+RED+
    " - -/ ~>\n-~ ~/ "+NORM+
    "You step through the portal and disappear"+RED+
    " ~>- .~\n\n\n"+NORM);

  home = all_inventory(find_object(DIR+"r/courtyard.c"));
  sa = sizeof(home);
  for(a = 0; a < sa; a++)
  {
    if(home[a]->query_z_bf_sportal() && (object)home[a]->query_owner() == User)
    {
      b = 1;
      break;
    }
  }

  if(!b)
  {
    portal = clone_object("/players/fred/closed/bloodfist/obj/portal.c");
    portal->set_owner(User);
    portal->set_loc(file_name(environment(User)));
    portal->cloned(80 + ((WIS + FAI) / 10));
    move_object(portal, DIR+"r/courtyard.c");
  }
  else
    home[a]->rcloned(80 + ((WIS + FAI) / 10));

  TRU Name+" leaves through a portal of red swirling light\n.", ({ User }));
  move_object(User, DIR+"r/courtyard.c");    
  TRU "A portal of red light suddenly appears in the courtyard.\n"+
    Name+" steps out of a portal in a flash of red light.\n", ({ User }));
  command("look", User);
  User->add_sp(-cost);
  return 1;
}
