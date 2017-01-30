/*
  fix_guild_object.h
*/

#include "/players/nooneelse/Alchemist/lib/defs.h"

/* --------------- update pouch --------------- */
fix_guild_object(str) {
  object new_pouch, old_pouch, next_obj;
  int i, n;

  if (!str || !str=="pouch") {
    write(NORM+CYN+"use: launder pouch\n"+NORM);
    return 1;
  }
  write(NORM+CYN+"Repairing your Alchemist pouch.\n"+NORM);
  this_player()->set_guild_name("alchemist");
  if (this_player()->query_guild_rank() < 1 ||
      this_player()->query_guild_rank() > 80) {
    this_player()->add_guild_rank(- this_player()->query_guild_rank());
    this_player()->add_guild_rank(1);
  }
  new_pouch = clone_object(ALCHEMIST_POUCH);
  old_pouch = present("Alchemist Pouch", this_player());
  new_pouch->set_loginmsg(old_pouch->query_loginmsg());
  new_pouch->set_logoutmsg(old_pouch->query_logoutmsg());

  new_pouch->set_nbr_remembered_rooms(old_pouch->query_nbr_remembered_rooms());
  new_pouch->set_following_obj(old_pouch->query_following_obj());

  if (old_pouch->query_servant_obj()) {
    old_pouch->query_servant_obj()->set_master_name(MY_NAME);
    new_pouch->set_servant_obj(old_pouch->query_servant_obj());
  }


  /* now get rid of any extra pouch they have */
  for (n=0; n<10; n++) {
    old_pouch = present("Alchemist Pouch", this_player());
    if (old_pouch) destruct(old_pouch);
  }
  move_object(new_pouch, this_player());
  write(NORM+CYN+"Done repairing pouch.\n"+NORM);
  return 1;
}
