/*
  call a guild pet - wolf [regular/dire/shadow/spirit]
  recode to allow for 4 wolf variations
*/

#include "/players/eurale/defs.h"

/* -------- Call a wolf to help fight ---------- */
main(str)
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

  if(TPL < 17 || TPGEXP < 669 || TP->query_attrib("luc") < 20)
  {
    notify_fail("You don't have the skills for that ability yet.\n");
    return 0;
  }

  if( (wolf_type != "wolf") &&
      (wolf_type != "dire") &&
      (wolf_type != "shadow") &&
      (wolf_type != "spirit") )
  {
    string types;
    write("Enter type: " + wolf_type + "\n");
    types = "That is not a pet that you can call.\n You can call a ";
    switch(TPTL)
    {
      case 17..23: types += "\<wolf\>.\n"; break;
      case 24..38: types += "\<wolf\> or \<dire\> wolf.\n"; break;
      case 39..53: types += "\<wolf\>, \<dire\> wolf or \<shadow\> wolf.\n"; break;
      case 54..10000: types += "\<wolf\>, \<dire\> wolf, \<shadow\> wolf or \<spirit\> wolf.\n"; break;
    }
    notify_fail(types);
    return 0;
  }

  if(TPSP < 50)
  {
    notify_fail("You don't have enough magic to do that.\n");
    return 0;
  }

  str1 = file_name(ROOM);
  sscanf(str1, "%s.c", str2);
  if(!str2) str2 = str1;

  if(str2 != "players/eurale/VAMPIRES/RMS/wolf_summon")
  {
    write("A wolf may be stronger \(and cheaper\) when summoned from the wolf rock.\n");
    boost = 2;
  }
  else
    boost = TPL - random(10);

  TP->add_spell_point(-50+(40/boost));
  wolf_obj = clone_object("/players/vital/misc/v/vamp_wolf.c");
  wolf_obj->setup_type(wolf_type);
  wolf_obj->set_master(TPRN);
  wolf_obj->set_name(wolf_name);
  tmp = wolf_obj->query_level();
  wolf_obj->set_level(tmp + (boost/2));
  tmp = wolf_obj->query_wc();
  wolf_obj->set_wc(tmp + (boost/3));
  tmp = wolf_obj->query_ac();
  wolf_obj->set_ac(tmp + (boost/4));
  move_object(wolf_obj,str1);
  write("A "+BOLD+wolf_obj->query_type()+NORM+" pads into the room and "+
        "stands at your left side.\n");
  return 1;
}

