/*
  sharpen_fangs.h
*/

#include "defs.h"

/* --------------- update fangs --------------- */
sharpen_fangs(str) {
  object new_fangs, old_fangs, next_obj;
  int i, n;
  if (!str || !str=="fangs") {
    write("use: sharpen fangs\n");
    return 1;
  }
  write("Sharpening your vampire's fangs.\n");
  this_player()->set_guild_name("vampire");
  if (this_player()->query_guild_exp() < 666 ||
      this_player()->query_guild_exp() > 672) {
    this_player()->add_guild_exp(- this_player()->query_guild_exp());
    this_player()->add_guild_exp(666);
  }
  new_fangs = clone_object(VAMPIRE_FANGS);
  old_fangs = present("nooneelse@vampire@fangs", this_player());
  new_fangs->set_loginmsg(old_fangs->query_loginmsg());
  new_fangs->set_logoutmsg(old_fangs->query_logoutmsg());
  new_fangs->set_call_time(old_fangs->query_call_time());
  new_fangs->set_last_time(old_fangs->query_last_time());
  new_fangs->set_form_description(old_fangs->query_form_description());
  new_fangs->set_new_form_description(old_fangs->query_new_form_description());
  new_fangs->set_form_owner_name(old_fangs->query_form_owner_name());
  new_fangs->set_following_name(old_fangs->query_following_name());
  new_fangs->set_guild_name(old_fangs->query_guild_name());
  new_fangs->set_guild_display(old_fangs->query_guild_display());
  new_fangs->set_target_name(old_fangs->query_target_name());
  new_fangs->set_alarm_bat_obj(old_fangs->query_alarm_bat_obj());
  new_fangs->set_wolf_obj(old_fangs->query_wolf_obj());
  new_fangs->set_new_form_obj(old_fangs->query_new_form_obj());
  new_fangs->set_form_obj(old_fangs->query_form_obj());
  for (i=0; i<old_fangs->query_nbr_remembered_rooms(); i++) {
    new_fangs->set_mapper_bat_obj(old_fangs->query_mapper_bat_obj(i), i);
  }
  new_fangs->set_nbr_remembered_rooms(old_fangs->query_nbr_remembered_rooms());
  new_fangs->set_following_obj(old_fangs->query_following_obj());
  if (old_fangs->query_servant_obj()) {
    old_fangs->query_servant_obj()->set_master_name(MY_NAME);
    new_fangs->set_servant_obj(old_fangs->query_servant_obj());
  }
  new_fangs->set_old_room(old_fangs->query_old_room());
  new_fangs->set_hell_fire_pause(old_fangs->query_hell_fire_pause());
  new_fangs->set_in_a_form(old_fangs->query_in_a_form());
  new_fangs->set_in_flight(old_fangs->query_in_flight());
  new_fangs->set_demon_wrath_pause(old_fangs->query_demon_wrath_pause());
  new_fangs->set_glowing_eyes(old_fangs->query_glowing_eyes());
  new_fangs->set_disguise_on(old_fangs->query_disguise_on());
  new_fangs->set_telepathy(old_fangs->query_telepathy());
  new_fangs->set_sanctuary_on(old_fangs->query_sanctuary_on());
  new_fangs->set_sanctuary_hp(old_fangs->query_sanctuary_hp());
  new_fangs->set_monitor_self(old_fangs->query_monitor_self());
  new_fangs->set_old_hp(old_fangs->query_old_hp());
  new_fangs->set_old_sp(old_fangs->query_old_sp());
  new_fangs->set_old_intox(old_fangs->query_old_intox());
  new_fangs->set_old_stuffed(old_fangs->query_old_stuffed());
  new_fangs->set_sneak_seconds(old_fangs->query_sneak_seconds());
  new_fangs->set_told_em_i_died(old_fangs->query_told_em_i_died());
  new_fangs->set_call_time(old_fangs->query_call_time());
  new_fangs->set_vampire_speed(old_fangs->query_vampire_speed());
  /* now get rid of any extra fangs they have */
  for (n=0; n<10; n++) {
    old_fangs = present("nooneelse@vampire@fangs", this_player());
    if (old_fangs) destruct(old_fangs);
  }
  move_object(new_fangs, this_player());
  write("Done sharpening fangs.\n");
  return 1;
}
