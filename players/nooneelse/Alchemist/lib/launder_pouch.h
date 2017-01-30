/*
  launder_pouch.h
*/

#include "/players/nooneelse/Alchemist/lib/defs.h"

/* --------------- update pouch --------------- */
launder_pouch(str) {
  object new_pouch, old_pouch, next_obj;
  int i, n;

  if (!str || !str=="pouch") {
    write(NORM+CYN+"use: launder pouch\n"+NORM);
    return 1;
  }
  if (MY_PLAYER->query_ghost()) {
    write(NORM+CYN+"How can you launder anything? You are a ghost!\n"+NORM);
    return 1;
  }
  if (!str) return 0;
  if (MY_GUILD_RANK < 10) {
    write(NORM+CYN+"You can't use that abilitiy yet.\n"+NORM);
    return 1;
  }
  write(NORM+CYN+"Laundering your Alchemist pouch.\n"+NORM);
  this_player()->set_guild_name("Alchemist");
  if (this_player()->query_guild_rank()!=10 &&
      this_player()->query_guild_rank()!=20 &&
      this_player()->query_guild_rank()!=40 &&
      this_player()->query_guild_rank()!=50 &&
      this_player()->query_guild_rank()!=80 &&
      this_player()->query_guild_rank()!=100 &&
      this_player()->query_guild_rank()!=1000) {
    this_player()->add_guild_rank(- this_player()->query_guild_exp());
    this_player()->add_guild_rank(10);
  }
  new_pouch = clone_object(POUCH);
  old_pouch = present("Alchemist Pouch", this_player());

  new_pouch->set_loginmsg(old_pouch->query_loginmsg());
  new_pouch->set_logoutmsg(old_pouch->query_logoutmsg());
  new_pouch->set_call_time(old_pouch->query_call_time());
  new_pouch->set_last_time(old_pouch->query_last_time());
  new_pouch->set_guild_name(old_pouch->query_guild_name());
  new_pouch->set_guild_display(old_pouch->query_guild_display());
  new_pouch->set_target_name(old_pouch->query_target_name());
  new_pouch->set_alarm_elemental_obj(old_pouch->query_alarm_elemental_obj());
  for (i=0; i<old_pouch->query_nbr_remembered_rooms(); i++) {
    new_pouch->set_mapper_elemental_obj(old_pouch->query_mapper_elemental_obj(i), i);
  }
  new_pouch->set_nbr_remembered_rooms(old_pouch->query_nbr_remembered_rooms());
  if (old_pouch->query_servant_obj()) {
    old_pouch->query_servant_obj()->set_master_name(MY_NAME);
    new_pouch->set_servant_obj(old_pouch->query_servant_obj());
  }
  new_pouch->set_old_room(old_pouch->query_old_room());
  new_pouch->set_glowing_eyes(old_pouch->query_glowing_eyes());
  new_pouch->set_telepathy(old_pouch->query_telepathy());
  new_pouch->set_sanctuary_on(old_pouch->query_sanctuary_on());
  new_pouch->set_sanctuary_hp(old_pouch->query_sanctuary_hp());
  new_pouch->set_monitor_self(old_pouch->query_monitor_self());
  new_pouch->set_old_hp(old_pouch->query_old_hp());
  new_pouch->set_old_sp(old_pouch->query_old_sp());
  new_pouch->set_old_intox(old_pouch->query_old_intox());
  new_pouch->set_old_stuffed(old_pouch->query_old_stuffed());
  new_pouch->set_told_em_i_died(old_pouch->query_told_em_i_died());
  new_pouch->set_call_time(old_pouch->query_call_time());
  /* now get rid of any extra pouches they have */
  for (n=0; n<10; n++) {
    old_pouch = present("Alchemist Pouch", this_player());
    if (old_pouch) destruct(old_pouch);
  }
  move_object(new_pouch, this_player());
  write(NORM+CYN+"Done laundering pouch.\n"+NORM);
  return 1;
}
