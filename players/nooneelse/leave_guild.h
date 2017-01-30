/*
  leave_guild.h
*/

#include "defs.h"

/* --------------- Leave the guild --------------- */
leave_guild(str) {
  string str, str1, str2;
  object stuff;
  int i,exp,minus;

  if (str!="guild") return 0;
  input_to("exit_guild");
  write("This removes you from the Vampire Guild!\n"+
        "You will NEVER be able to rejoin!\n"+
        "Do you really want to leave the guild? (yes or no) ");
  str="";
  return 1;
}

exit_guild(str) {
  if (str!="yes") {
    write("Aborting the 'leave guild' command.\n");
    return;
  }

  /* take them off the member's list */
  call_other(GUILD_MEMBER, "???", 0);
  call_other(GUILD_MEMBER, "delete_player", MY_NAME);
  /* add them to the traitor's list & indicate that they Quit*/
  call_other(GUILD_PROHIBIT, "???", 0);
  call_other(GUILD_PROHIBIT, "add_player", MY_NAME, "Q");
  /* get rid of any guild stuff around */
  MY_FANGS->dismiss_bat("bat");
  MY_FANGS->forget_rooms();
  /* destruct their coffin & everything in it */
  call_other(GUILD_COFFIN_ROOM, "???", 0);
  stuff=first_inventory(GUILD_COFFIN_ROOM);
  while (stuff) {
    if (stuff->query_coffin_owner_name()==MY_NAME) {
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
  if (present("vampire dagger", MY_PLAYER)) command("drop dagger", MY_PLAYER);
  if (present("vampire tuxedo", MY_PLAYER)) command("drop tuxedo", MY_PLAYER);
  if (present("vampire bag", MY_PLAYER)) command("drop bag", MY_PLAYER);
  /* fix their title */
  MY_PLAYER->set_title("-->Quitter from the vampire's guild");
  /* now throw them out if they're in a guild_room */
  str1 = file_name(MY_ROOM);
  sscanf(str1, "%s.c", str2);
  if (!str2) str2 = str1;
  if (str2==GUILD_HALL ||
      str2==GUILD_LOWER_HALL ||
      str2==GUILD_TRAINING ||
      str2==GUILD_EQUIP ||
      str2==GUILD_CHARITY ||
      str2==GUILD_SHOP ||
      str2==GUILD_COFFIN_ROOM ||
      str2==GUILD_COFFIN) {
    write("A flamming demon appears, beats you up (injuring you) "+
          "and tosses you out, saying:\n"+
          "     Members only!\n");
    MY_FANGS->tell_my_room(
                "A flamming demon appears, beats "+MY_NAME_CAP+
                " up and tosses "+MY_PLAYER->query_objective()+
                " out, saying:\n     Members only!");
    if (MY_HIT_POINTS > 10) MY_PLAYER->add_hit_point(- 5);
    call_other("/room/church", "???", 0);
    move_object(MY_PLAYER, "/room/church");
    command("look", MY_PLAYER);
  }
  i = MY_PLAYER->query_guild_exp();
  MY_PLAYER->add_guild_exp(-i);
  exp = this_player()->query_exp();
  minus = exp / 6;
  MY_PLAYER->add_exp(-minus);
  MY_PLAYER->set_guild_name(0);
  MY_PLAYER->set_guild_file(0);
  MY_PLAYER->set_guild_name(0);
  telepathy("I'M A QUITTER FROM THE VAMPIRE GUILD!  SO NANNY!");
  destruct(MY_FANGS);
  return 1;
}
