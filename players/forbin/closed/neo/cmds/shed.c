#include "../defs.h"

status main(string str, object gob, object player)
{
	int key;
  string *validshapes;
  
  validshapes = ({ "main", "boots", "helmet", "neckguard", "greaves",
                   "cloak", "bracers", "earring", "gloves", "belt",
                   "amulet", "necklace", "ring", "chestplate", "all", });

  if((int)player->query_ghost()) return 0;
  
  if((int)gob->query_skill("creation") < 1) return 0;
	
	if(!str)
	{
		tell_object(player,
		  "Shed which shaped armor?\n"+
		  "You may 'shed <type>' or 'shed all'.\n");
		return 1;
	}

  if(member_array(str, validshapes) < 0)
  {
    tell_object(player,
      "That is not a valid choice.  You may shed <type>.\n"+
	    "You may 'shed <type>' or 'shed all'\n");
    return 1;	
  }
  if(str == "all")
  {
    command("shed main", player);
    command("shed boots", player);
    command("shed helmet", player);
    command("shed neckguard", player);
    command("shed greaves", player);
    command("shed cloak", player);
    command("shed bracers", player);
    command("shed earring", player);
    command("shed gloves", player);
    command("shed belt", player);
    command("shed amulet", player);
    command("shed necklace", player);
    command("shed ring", player);
    command("shed chestplate", player); 
    return 1;	
  }
  if(str != "all")
  {
    switch(str)
    {
      case "main": key = 0; break;
      case "boots": key = 1; break;
      case "helmet": key = 2; break;
      case "neckguard": key = 3; break;
      case "greaves": key = 4; break;
      case "cloak": key = 5; break;
      case "bracers": key = 6; break;
      case "earring": key = 7; break;
      case "gloves": key = 8; break;
      case "belt": key = 9; break;
      case "amulet": key = 10; break;
      case "necklace": key = 11; break;
      case "ring": key = 12; break;
      case "chestplate": key = 13; break;
    }
    if((int)gob->query_shaped_armors(key))
    {
    	if(str == "main")
    	  tell_object(player,
    	    "You will your symbiotic self to shed the "+HIW+"Dark Matter"+NORM+" main armor.\n");
    	else 
        tell_object(player,
          "You will your symbiotic self to shed the "+HIW+"Dark Matter"+NORM+" "+str+".\n"); 
      if(str == "main")
        tell_room(environment(player),
          (string)player->QN+" struggles as "+
          (string)player->PRO+" sheds his symbiotic main armor.\n", ({ player }) );          
      else 
        tell_room(environment(player),
          (string)player->QN+" struggles as "+
          (string)player->PRO+" sheds his symbiotic "+str+".\n", ({ player }) );
      gob->remove_shaped_armor(str);
      return 1;
    }
    else 
    {
    	if(str == "main")
    	  tell_object(player,
          "You are not wearing a "+HIW+"Dark Matter"+NORM+" main armor.\n");
    	else
        tell_object(player,
          "You are not wearing a "+HIW+"Dark Matter"+NORM+" "+str+".\n");
      return 1;	
    }
  }
	else
	{
    tell_object(player,
      "That is not a valid choice.  You may shed <type>.\n"+
      "You may 'shed <type>' or 'shed all'\n");
		return 1; 		
  }
}

