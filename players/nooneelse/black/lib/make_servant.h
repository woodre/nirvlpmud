/*
  make_servant.h
*/

#include "defs.h"

/* -------- Make a servant from a corpse ---------- */
make_servant(str) {
  object target_obj, servant_obj;
  int i;
  if (MY_FANGS->query_servant_obj()) {
    write("You can only make one servant at a time.\n");
    return 1;
  }
  if (!str) {
    write("You must supply the servant's name.\n");
    return 1;
  }
  if (str==MY_NAME) {
    write("You cannot give the servant your own name!\n");
    return 1;
  }
  if (MY_LEVEL < 5 || MY_GUILD_EXP < 668) {
    write("You can't use that abilitiy yet.\n");
    return 1;
  }
  if (MY_SPELL_POINTS < 30) {
    write("You don't have enough spell points.\n");
    return 1;
  }
  MY_PLAYER->add_spell_point(- 30);
  target_obj = present("corpse", MY_ROOM);
  if (!target_obj) {
    write("A corpse must be present to do that.\n");
    return 1;
  }
  destruct(target_obj);
  servant_obj = clone_object(VAMPIRE_SERVANT);
  MY_FANGS->set_servant_obj(servant_obj);
  servant_obj->set_name(lower_case(str));
  servant_obj->set_master_name(MY_NAME);
  servant_obj->set_servant_name(lower_case(str));
  i = MY_LEVEL;
  servant_obj->set_level(i);
  servant_obj->set_hp(666666);
  servant_obj->set_ac(99);
  i = MY_LEVEL;
  if (i < 10) i = 4;
  servant_obj->set_wc(i);
  move_object(servant_obj, MY_ROOM);
  command("fix servant", MY_PLAYER);
  write("The corpse raises as a servant and says: 'My name is "+
        capitalize(str)+"'.\n");
  MY_FANGS->tell_my_room(
              "The corpse raises and says: 'My name is "+capitalize(str)+"'.");
  str = "bow "+MY_NAME;
  command(str, servant_obj);
  return 1;
}
