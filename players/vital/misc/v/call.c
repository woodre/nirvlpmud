/******************************************************************************
 *
 *  File:         call.c
 *
 *  Function:     Call a guild pet - wolf [wolf/dire/shadow/spirit]
 *
 *  Author(s):    Vital
 *
 *  Copyright:    Copyright (c) 2007 Vital-Dev
 *                All Rights Reserved.
 *
 *  Source:       Adapted from NOE code
 *
 *  Notes:        
 *
 *  Change History:
 *      2007-05-26    Added 4 types in the new vamp_wolf.c
 *      2007-05-29    Added Header, typed, began debugging
 *      2007-06-13    Adapted for new guild object
 *      
 *****************************************************************************/

#pragma strict_types

#include <ansi.h>
#include "../headers/player_object.h"
#include "../headers/guild.h"

/******************************************************************************
 *
 *  main
 *
 *  Function:       Initiates the call for a wolf
 *  Arguments:      string
 *  Returns:        int
 *
 *  Change History:
 *      2007-06-13  added ranked calls for types
 *****************************************************************************/

int
main(string str)
{
  string wolf_type, wolf_name, str1, str2;
  int boost, tmp;
  object wolf_obj;

  wolf_name = "";
  wolf_type = "";

  if(!str || (sscanf(str, "%s %s", wolf_type, wolf_name) != 2)) 
  {
    notify_fail("The format for the spell is \(call \<pet_type\> \<pet_name\>\)\n");
    return 0;
  }
  
  if((int)TPL < 17 || (int)TPGEXP < 0 || (int)TPLUC < 20)
  {
    notify_fail("You don't have the skills for that ability yet.\n");
    return 0;
  }

  if( (wolf_type != "wolf") ||
      (wolf_type != "dire") ||
      (wolf_type != "shadow") ||
      (wolf_type != "spirit") )
  {
    string types;
    types = "That is not a pet that you can call.\n You can call a ";
    switch(GRANK)
    {
      case BLOOD_RANK :
        types += "\<wolf\>.\n"; break;
      case DIRE_RANK  :
        types += "\<wolf\> or \<dire\> wolf.\n"; break;
      case SHADOW_RANK:
        types += "\<wolf\>, \<dire\> wolf or \<shadow\> wolf.\n"; break;
      case SPIRIT_RANK: 
        types +=
        "\<wolf\>, \<dire\> wolf, \<shadow\> wolf or \<spirit\> wolf.\n";
        break;
    }
    notify_fail(types);
    return 0;
  }

  if((int)TPSP < 50)
  {
    notify_fail("You don't have enough magic to do that.\n");
    return 0;
  }

  if((int)TPBPTS < 60)
  {
    notify_fail("You lack the blood energy to call a wolf.\n");
    return 0;
  }

  if(PFANGS->query("wolf_obj"))
  {
    notify_fail("You already command a wolf.\n");
    return 0;
  }

  str1 = file_name(ETP);
  sscanf(str1, "%s.c", str2);
  if(!str2) str2 = str1;

  if(str2 != "players/eurale/VAMPIRES/RMS/wolf_summon")
  {
    write("A wolf may be stronger \(and cheaper\) when summoned from the wolf rock.\n");
    boost = 2;
  }
  else
    boost = ((int)TPL - random(10));

  TP->add_spell_point(-50+(40/boost));
  PFANGS->add("blood_points", -60+(40/boost));
  wolf_obj = clone_object(VAMP_WOLF);
  wolf_obj->set_type(wolf_type);
  wolf_obj->set_master(TPRN);
  wolf_obj->set_name(wolf_name);
  tmp = (int)wolf_obj->query_level();
  wolf_obj->set_level(tmp + (boost/2));
  tmp = (int)wolf_obj->query_wc();
  wolf_obj->set_wc(tmp + (boost/3));
  tmp = (int)wolf_obj->query_ac();
  wolf_obj->set_ac(tmp + (boost/4));
  move_object(wolf_obj,str1);
  PFANGS->set("wolf_obj", wolf_obj);
  PFANGS->tell_my_room(
    "A "+BOLD+wolf_obj->query_type()+NORM+" pads into the room and stands at "+
    capitalize((string)TPRN)+"'s left side.");
  write("A "+BOLD+wolf_obj->query_type()+NORM+" pads into the room and "+
        "stands at your left side.\n");
  return 1;
}

