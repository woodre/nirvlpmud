/*
  release_member.h
*/

#include "defs.h"

/* ------ release a member from guild without penalties ------ */
release_member(str) {
  object stuff, target_obj;
  int i;
  if (GUILD_OFFICE_FLOOR_TOP->find_officer(MY_NAME)!=GUILD_MASTER) return 0;
  if(!str) {
    write("Use: release <who>\n");
    return 1;
  }
  target_obj=find_living(str);
  if (!target_obj) {
    write("Can't find that player.\n");
    return 1;
  }
  stuff = present("nooneelse@vampire@fangs", target_obj);
  if (!stuff) {
    write("That player is not a member of the vampire guild.\n");
    return 1;
  }
  /* get rid of any guild stuff around */
  target_obj->dismiss_bat("bat");
  target_obj->forget_rooms();
  /* destruct their coffin & everything in it */
  call_other(GUILD_COFFIN_ROOM, "???", 0);
  stuff=first_inventory(GUILD_COFFIN_ROOM);
  while (stuff) {
    if (stuff->query_coffin_owner_name()==str) {
      destruct(stuff);
      break;
    }
    stuff=next_inventory(stuff);
  }
  /* dismiss wolf, if there is one */
  if (MY_FANGS->query_wolf_obj()) destruct(MY_FANGS->query_wolf_obj());
  /* dismiss servant, if there is one */
  if (MY_FANGS->query_servant_obj()) destruct(MY_FANGS->query_servant_obj());
  /* now drop any vampire equipment they have */
  if (present("vampire dagger", target_obj)) command("drop dagger", target_obj);
  if (present("vampire tuxedo", target_obj)) command("drop tuxedo", target_obj);
  if (present("vampire bag", target_obj))    command("drop bag", target_obj);
  call_other(GUILD_MEMBER, "???", 0);
  call_other(GUILD_MEMBER, "delete_player", str);
  i = target_obj->query_guild_exp();
  target_obj->add_guild_exp(-i);
  target_obj->set_guild_name(0);
  target_obj->set_guild_file(0);
  tell_object(target_obj, "You've been released from the Vampire Guild.\n");
  write(capitalize(str)+" has been released from the Vampire Guild.\n");
  stuff = present("nooneelse@vampire@fangs", target_obj);
  destruct(stuff);
  return 1;
}
