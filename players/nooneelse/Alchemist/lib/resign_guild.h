/*
  resign.h
*/

#include "/players/nooneelse/Alchemist/lib/defs.h"

/* --------------- Leave the guild --------------- */
resign(str) {
  string str, str1, str2;
  object stuff;
  int i,exp;

  if (str!="guild") return 0;
  input_to("exit_guild");
  write(NORM+CYN+"This removes you from the Alchemist Guild!\n"+
        "Do you really want to leave the guild? (yes or no) "+NORM);
  str="";
  return 1;
}

exit_guild(str) {
  if (str!="yes") {
    write(NORM+CYN+"Aborting the 'leave guild' command.\n"+NORM);
    return;
  }

  /* take them off the member's list */
  call_other(ALCHEMIST_MEMBER, "???", 0);
  call_other(ALCHEMIST_MEMBER, "delete_player", MY_NAME);
  /* add them to the traitor's list & indicate that they Quit*/
  call_other(ALCHEMIST_PROHIBIT, "???", 0);
  call_other(ALCHEMIST_PROHIBIT, "add_player", MY_NAME, "Q");
  /* get rid of any guild stuff around */
  MY_POUCH->dismiss_elemental("air elemental");
  MY_POUCH->dismiss_elemental("fire elemental");
  MY_POUCH->forget_rooms();
  /* dismiss raven, if there is one */
  if (MY_POUCH->query_raven_obj()) destruct(MY_POUCH->query_raven_obj());
/* @@@@@@@@@@@ */



  /* fix their title */
  MY_PLAYER->set_title(NORM+GRN+"-->Quitter from the Alchemist guild"+NORM);

  /* now zap some experience */
  i = MY_PLAYER->query_exp() / 6;
  MY_PLAYER->add_exp(-i);
  i = MY_PLAYER->query_guild_exp();
  MY_PLAYER->add_guild_exp(-i);

  /* now clear the guild stuff that the alchemist guild uses */
  i = MY_PLAYER->query_guild_rank();
  MY_PLAYER->add_guild_rank(-i);
  MY_PLAYER->set_guild_name(0);
  MY_PLAYER->set_guild_file(0);
  if (MY_LEVEL<21) MY_PLAYER->set_home("");
  think(NORM+GRN+"I'M A QUITTER FROM THE ALCHEMIST GUILD!"+NORM);
  /* and we're done. they're out. */
  destruct(MY_POUCH);
  return 1;
}
