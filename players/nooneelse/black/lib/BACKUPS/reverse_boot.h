/*
  reverse_boot.h
*/

#include "defs.h"

/* ---- Allow guild master & assistant to give fangs back to players ---- */
reverse_boot(str) {
  int i, exp, plus, player_level;
  object obj, target_obj, vampire_training_obj, new_fangs;
  string new_title, player_gender;
  if (!str) {
    write("Use: reverse <who>\n");
    return 1;
  }
  if (GUILD_OFFICE_FLOOR_TOP->find_officer(MY_NAME)!=GUILD_MASTER &&
      GUILD_OFFICE_FLOOR_TOP->find_officer(MY_NAME)!=GUILD_ASSISTANT) {
    write("You can't use that abilitiy.\n");
    return 1;
  }
  target_obj=find_player(str);
  if (!target_obj) {
    write("Can't find '"+str+"'\n");
    return 1;
  }
  /* add them to the member list */
  call_other(GUILD_MEMBER, "???");
  call_other(GUILD_MEMBER, "add_player", target_obj->query_real_name());
  /* remove them from the traitor list */
  call_other(GUILD_PROHIBIT, "???");
  call_other(GUILD_PROHIBIT, "delete_player", target_obj->query_real_name());
  /* fix their title */
  call_other(GUILD_TRAINING, "???");
  vampire_training_obj = find_object(GUILD_TRAINING);
  player_level = target_obj->query_level();
  player_gender = target_obj->query_gender();
  new_title=vampire_training_obj->remote_get_title(player_level, player_gender);
  if (!new_title) {
    write("There's something wrong with the title command.\n"+
          "Leave mail for Nooneelse.\n");
    return 1;
  }
  target_obj->set_title(new_title);
  /* set their guild experience to new member status */
  i = target_obj->query_guild_exp();
  target_obj->add_guild_exp(-i);
  target_obj->add_guild_exp(666);
  /* set up their guild name and file */
  target_obj->set_guild_name("vampire");
  target_obj->set_guild_file(0);
  /* fix their experience */
  exp = target_obj->query_exp();
  plus = exp / 6;
  target_obj->add_exp(plus);
  /* now give em the new fangs */
  new_fangs = clone_object(VAMPIRE_FANGS);
  move_object(new_fangs, target_obj);
  write(capitalize(str)+" now has a set of fangs.\n");
  return 1;
}
