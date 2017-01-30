/*
  call a guild pet - wolf
  quick edit by Vital
    modified room check
    
*/

#include "/players/eurale/defs.h"

/* -------- Call a wolf to help fight ---------- */
call_wolf(str)
{
  string wolf_name, str1, str2;
  int boost, tmp;
  object wolf_obj;

  if(!str) return 0;
  wolf_name = 0;
  sscanf(str, "wolf %s", wolf_name);

  if(!wolf_name)
  {
    write("You must supply the wolf's name.  (call wolf <name>)\n");
    return 1;
  }

  if(TPL < 17 || TPGEXP < 669 || TP->query_attrib("luc") < 20)
  {
    write("You don't have the skills for that ability yet.\n");
    return 1;
  }

  if(TPSP < 50)
  {
    write("You don't have enough magic to do that.\n");
    return 1;
  }

  if(TPBPTS < 60)
  {
    write("You lack the blood energy to call a wolf.\n");
    return 1;
  }

  if(present("vampire fangs",TP)->query_wolf_obj())
  {
    write("You already command a wolf.\n");
    return 1;
  }

  str1 = file_name(ROOM);
  sscanf(str1, "%s.c", str2);
  if(!str2) str2 = str1;

  if(str2 != "players/eurale/VAMPIRES/RMS/wolf_summon")
  {
    write("A wolf may be stronger when summoned from the wolf rock.\n");
    boost = 2;
  }
  else
    boost = 10;

  TP->add_spell_point(-50+boost);
  PFANGS->add_BLOODPTS(-60+boost);
  wolf_obj = clone_object(VAMP_WOLF);
  wolf_obj->set_master(TPRN);
  wolf_obj->set_name(wolf_name);
  tmp = wolf_obj->query_level();
  wolf_obj->set_level(tmp + (boost/2));
  tmp = wolf_obj->query_wc();
  wolf_obj->set_wc(tmp + (boost/3));
  move_object(wolf_obj,str1);
  present("vampire fangs",TP)->set_wolf_obj(wolf_obj);
  FANGS->tell_my_room(
    "A "+BOLD+"large black wolf"+NORM+" pads into the room and stands at "+
    capitalize(TPRN)+"'s left side.");
  write("A "+BOLD+"large black wolf"+NORM+" pads into the room and "+
        "stands at your left side.\n");
  return 1;
}

