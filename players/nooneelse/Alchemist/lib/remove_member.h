/*
  remove_member.h
*/

#include "/players/nooneelse/Alchemist/lib/defs.h"

/* ------ release a member without penalty ------ */
expell_traitor(player_name) {
  object target_obj;
  int i, minus, exp, is_an_alchemist;

  if(!player_name) {
    write(NORM+CYN+"use: release <who> "+NORM);
    return 1;
  }
  if (this_player()->query_real_name()!=ALCHEMIST_MASTER) {
    write(NORM+CYN+"You can't use that abilitiy.\n"+NORM);
    return 1;
  }
  target_obj=find_living(player_name);
  if (!target) {
    write(NORM+CYN+capitalize(player_name)+" is not in the mud right now.\n"+
          "...continuing...\n"+NORM);
  }
  call_other(ALCHEMIST_MEMBER, "???");
  is_an_alchemist=call_other(ALCHEMIST_MEMBER, "query_member", player_name);
  if (!is_an_alchemist) {
    write(NORM+CYN+capitalize(player_name)+" is nto an Alchemist!\n"+NORM);
    return 1;
  }
  if (!target_obj) {
    /* take them off the member list */
    call_other(ALCHEMIST_MEMBER, "???");
    call_other(ALCHEMIST_MEMBER, "delete_player", player_name);
    write(NORM+CYN+"Ok.  They're out!\n"+NORM);
    return 1;
  }
  /* get rid of any Alchemist stuff around */
  MY_POUCH->dismiss_elemental("air elemental");
  MY_POUCH->dismiss_elemental("fire elemental");
  MY_POUCH->forget_rooms();
  /* dismiss raven, if there is one */
  if (MY_POUCH->query_raven_obj()) destruct(MY_POUCH->query_raven_obj());





  /* fix their title */
  MY_PLAYER->set_title(NORM+GRN+"the wandering punster"+NORM);

  /* now clear the guild stuff that the alchemist guild uses */
  i = MY_PLAYER->query_guild_rank();
  MY_PLAYER->add_guild_rank(-i);
  MY_PLAYER->set_guild_name(0);
  MY_PLAYER->set_guild_file(0);
  if (MY_LEVEL<21) MY_PLAYER->set_home("");
  /* and we're done. they're out. */
  destruct(MY_POUCH);
  write(NORM+CYN+"Ok.  They're out!\n"+NORM);
  return 1;
}
