#include "../defs.h"
#include "../specfuns.h"

status main(string str, object gob, object player)
{
  if((int)player->query_ghost()) 
    return 0;
  
  if((int)gob->query_skill("control") < 6) 
    return 0;

  if((int)gob->query_burnoff())
  {
    tell_object(player,
      "You will yourself to stop the burnoff process.\n");
    gob->set_burnoff(1);
    return 1; 
  }
  if((int)player->query_sp() < 20)
  {
    tell_object(player,
      "You lack the energy to do that.\n");
    return 1;
  }
  if((int)gob->query_mp() < 15)
  {
    tell_object(player,
      "You lack the dark "+PGC+"Dark Matter"+NORM+" to do that.\n");
    return 1;
  }
  if((int)player->query_hp() < 50)
  {
    tell_object(player,
      "Your body is too weak to begin the burnoff process.\n");
    return 1;
  }

  tell_object(player,
    "You concentrate and force your inner symbiote to burnoff the\n"+
    "toxins present in your system.\n"+NORM);

  gob->set_burnoff(1);
  player->add_spell_point(-20);
  gob->sub_mp(15);
  return 1;
}

status help(object gob, object player)
{
	string title;
	
	title = "Burnoff";
  tell_object(player,"\n"+
	  HELPLINE+
	  HELPTITLE+
	  HELPLINE+"\n"+
    "    "+SGC+"Spell Point Cost:"+NORM+"      low\n"+
	  "    "+SGC+"Matter Point Cost:"+NORM+"     low\n"+
	  "\n"+
	  help_wrap("Burnoff allows you to eliminate toxins from your system at an increased pace.  In order "+
	  "for burnoff to funciton, you must assign tentacles to burnoff.  Of course, the greater the number "+
	  "of tentacles assigned, the more effective this ability can be.\n")+
    "\n"+
    "         Usage:  "+PGC+"burnoff"+NORM+"\n\n"+
	  HELPLINE);
  return 1;
}