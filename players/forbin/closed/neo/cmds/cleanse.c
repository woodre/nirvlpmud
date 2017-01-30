#include "../defs.h"
#include "../specfuns.h"

status main(string str, object gob, object player)
{
  object ob1, ob2;
  string junk1,junk2;
  
  if((int)player->query_ghost()) 
    return 0;
  
  if((int)gob->query_skill("control") < 1) 
    return 0;

  if((int)player->query_sp() < 50)
  {
    tell_object(player,
      "You lack the energy to do that.\n");
    return 1;
  }
  tell_object(player,
    "A "+HIW+"Dark Matter Tentacle"+NORM+" dives beneath your skin.\n"+NORM);

  ob1 = first_inventory(player);
  
  while(ob1) 
  {
    ob2 = next_inventory(ob1);
    if(sscanf(file_name(ob1), "%spoison%s", junk1, junk2) == 2 ||
			ob1->id("poison")) 
    {
      tell_object(player,
        PGC+BOLD+"Poison is destroyed...\n"+NORM);
      destruct(ob1);
    }
    else if(sscanf(file_name(ob1), "%sdisease%s", junk1, junk2) == 2 ||
			ob1->id("disease")) 
    {
      tell_object(player,
        PGC+BOLD+"Disease is destroyed...\n"+NORM);
      destruct(ob1);
    }
    else if(sscanf(file_name(ob1), "%stoxin%s", junk1, junk2) == 2 ||
      sscanf(file_name(ob1), "%stox%s", junk1, junk2) == 2 ||
			ob1->id("toxin")) 
    {
      tell_object(player,
        PGC+BOLD+"Toxin is destroyed...\n"+NORM);
      destruct(ob1);
    }
    ob1 = ob2;
  }
  
  if((int)player->query_infuse())
  {
    tell_object(player,
      PGC+BOLD+"Infusion destroyed...\n"+NORM);   
    player->add_infuse(-1000);
    gob->sub_mp(25);
  }  

    player->add_spell_point(-50);
  return 1;
}

status help(object gob, object player)
{
	string title;
	
	title = "Cleanse";
  tell_object(player,"\n"+
	  HELPLINE+
	  HELPTITLE+
	  HELPLINE+"\n"+
    "    "+SGC+"Spell Point Cost:"+NORM+"      high\n"+
	  "    "+SGC+"Matter Point Cost:"+NORM+"     varies\n"+
	  "\n"+
	  help_wrap("If or when you become afflicted by one of various ailments: poisons, disease, and the like, "+
	  "you can use the cleanse ability to purge these aches and pains from your body.  Cleanse is also helpful "+
	  "in dealing with transfusion healing, as it can rid your system of deadly infusion.\n")+
    "\n"+
    "         Usage:  "+PGC+"cleanse"+NORM+"\n\n"+
	  HELPLINE);
  return 1;
}