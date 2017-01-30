#include "../defs.h"

status main(string str, object gob, object player)
{
	string one, two;
  string *validshapes;
  int spcost, mpcost;
  
  validshapes = ({ "main", "boots", "helmet", "neckguard", "greaves",
                   "cloak", "bracers", "earring", "gloves", "belt",
                   "amulet", "necklace", "ring", "chestplate", "all", });

  if((int)player->query_ghost()) return 0;
  
  if((int)gob->query_skill("creation") < 1) return 0;
	
	if(!str)
	{
		tell_object(player,
		  "You may shape armor <type>.\n"+
		  "Valid types are: main, boots, helmet, neckguard, greaves, cloak, bracers,\n"+
		  "                 earring, gloves, belt, amulet, necklace, ring, chestplate.\n"+
		  "You may also shape armor all to shape a full set.\n");
		return 1;
	}
	
	else if(sscanf(str, "%s %s", one, two) == 2)             
  {
  	if(one == "armor")
  	{
      if(member_array(two, validshapes) < 0)
      {
        tell_object(player,
          "That is not a valid choice.  You may shape armor <type>.\n"+
		      "Valid types are: main, boots, helmet, neckguard, greaves, cloak, bracers,\n"+
		      "                 earring, gloves, belt, amulet, necklace, ring, chestplate.\n"+
		      "You may also shape armor all to shape a full set.\n");
        return 1;	
      }
      if(two == "all")
      {
        command("shape armor main", player);
        command("shape armor boots", player);
        command("shape armor helmet", player);
        command("shape armor neckguard", player);
        command("shape armor greaves", player);
        command("shape armor cloak", player);
        command("shape armor bracers", player);
        command("shape armor earring", player);
        command("shape armor gloves", player);
        command("shape armor belt", player);
        command("shape armor amulet", player);
        command("shape armor necklace", player);
        command("shape armor ring", player);
        command("shape armor chestplate", player); 
        return 1;	
      }
      if(two != "all")  
      {
        if((int)gob->check_armors(two))
        {
          tell_object(player,
            "You are already wearing an armor of that type!\n");
          return 1;
        }
      }
      if(two == "main")
      {
        mpcost = 50;
        spcost = 30;
      }
      else if(two == "boots" || two == "helmet" || two == "neckguard" ||
              two == "greaves" || two == "cloak" || two == "chestplate")
      {
      	mpcost = 30;
      	spcost = 20;
      }
      else 
      {
      	mpcost = 20;
      	spcost = 10;
      }
      if((int)gob->query_mp() < mpcost)
      {
      	tell_object(player,
      	  "You lack the "+HIW+"Dark Matter"+NORM+" to do that.\n");
      	return 1;
      }
      if((int)player->query_sp() < spcost)
      {
      	tell_object(player,
      	  "You lack the energy to do that.\n");
      	return 1;
      }
      if(two == "boots" || two == "greaves" || two == "gloves" || two == "bracers")
        tell_object(player,
          "You concentrate and force your inner symbiote to form "+two+" from its "+HIW+"Dark Matter"+NORM+".\n");
      else if(two == "amulet" || two == "earring")
        tell_object(player,
          "You concentrate and force your inner symbiote to form an "+two+" from its "+HIW+"Dark Matter"+NORM+".\n");
      else
        tell_object(player,
          "You concentrate and force your inner symbiote to form a "+two+" from its "+HIW+"Dark Matter"+NORM+".\n");          
      tell_room(environment(player),
        "Glistening "+HIW+"Dark Matter"+NORM+" armor forms on "+(string)player->QN+".\n", ({ player }) );
      gob->add_shaped_armor(two);
      gob->sub_mp(mpcost);
      player->add_spell_point(-spcost);
      return 1;
    }
  	else
  	{
      tell_object(player,
        "That is not a valid choice.  You may shape armor <type>.\n"+
      "Valid types are: main, boots, helmet, neckguard, greaves, cloak, bracers,\n"+
      "                 earring, gloves, belt, amulet, necklace, ring, chestplate.\n"+
      "You may also shape armor all to shape a full set.\n");
      return 1;	  		
  	}
  }
  else if(sscanf(str, "%s", one) == 1)
  {
    if(one == "armor")
    {
		  tell_object(player,
		    "You may shape armor <type>.\n"+
		    "Valid types are: main, boots, helmet, neckguard, greaves, cloak, bracers,\n"+
		    "                 earring, gloves, belt, amulet, necklace, ring, chestplate.\n"+
		    "You may also shape armor all to shape a full set.\n");
		  return 1;
    }
  }
}
