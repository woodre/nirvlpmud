/*
  call_wolf.h
*/

#include "defs.h"

/* -------- Call a wolf to help fight ---------- */
call_wolf(str) {
  string wolf_name, str1, str2;
  object wolf_obj;
  if (!str) return 0;
  wolf_name=0;
  sscanf(str, "wolf %s", wolf_name);
  if (!wolf_name) {
    write("You must supply the wolf's name.  (call wolf <name>)\n");
    return 1;
  }
  if (MY_LEVEL < 10 || MY_GUILD_EXP < 669) {
    write("You can't use that abilitiy yet.\n");
    return 1;
  }
  if (MY_SPELL_POINTS < 50) {
    write("You don't have enough spell points.\n");
    return 1;
  }
  if (MY_FANGS->query_wolf_obj()) {
    write("You can only have one wolf at a time.\n");
    return 1;
  }

  str1=file_name(MY_ROOM);
  sscanf(str1, "%s.c", str2);
  if (!str2) str2=str1;
/*
  if (str2 != "players/nooneelse/entryforest/e_forest8") {
*/
  if(str2 != "players/eurale/VAMPIRES/RMS/wolf_summon") {
    write("A wolf may only be summoned from the wolf rock.\n");
    return 1;
  }
  MY_PLAYER->add_spell_point(- 50);
  wolf_obj = clone_object("/players/eurale/VAMPIRES/NPC/vamp_wolf.c");
  wolf_obj->set_master(MY_NAME);
  wolf_obj->set_name(wolf_name);
/*
  move_object(wolf_obj, MY_ROOM);
*/
  move_object(wolf_obj,str1);
  MY_FANGS->set_wolf_obj(wolf_obj);
  MY_FANGS->tell_my_room(
  "A "+BOLD+"large black wolf"+NORM+" pads into the room and stands at "+
               MY_NAME_CAP+"'s left side.");
  write("A "+BOLD+"large black wolf"+NORM+" pads into the room and "+
        "stands at your left side.\n");
  return 1;
}
