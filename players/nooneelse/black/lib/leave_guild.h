/*
  leave_guild.h
*/

#include "defs.h"

/* --------------- Leave the guild --------------- */
leave_guild(str) {
  string str1, str2;
  object stuff;
  int i,exp,minus;
  if (str!="guild") return 0;

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
if(
  str2 == "/players/eurale/Vamp/RMS/vguild_hall.c" ||
  str2 == "/players/eurale/Vamp/RMS/boardroom.c" ||
  str2 == "/players/eurale/Vamp/RMS/titles.c" ||
  str2 == "/players/eurale/Vamp/RMS/equip.c" ||
  str2 == "/players/eurale/Vamp/RMS/mirrors.c" ||
  str2 == "/players/eurale/Vamp/RMS/shop.c" ||
  str2 == "/players/eurale/Vamp/RMS/wolf_path.c" ||
  str2 == "/players/eurale/Vamp/RMS/wolf_summon.c" ||
  str2 == "/players/eurale/Vamp/RMS/wing_room.c" ||
  str2 == "/players/eurale/Vamp/RMS/cafe.c" ||
  str2 == "/players/eurale/Vamp/RMS/init_room.c" ||
  str == "/players/nooneelse/black/guild_history_hall.c" ||
  str == "/players/nooneelse/black/guild_prohibit.c" ||
  str2 == GUILD_CHARITY ||
  str2 == GUILD_MEMBER ||
  str2 == GUILD_COFFIN_ROOM ||
  str2 == GUILD_COFFIN) {
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
  minus = exp / 4;
  MY_PLAYER->add_exp(-minus);
  MY_PLAYER->set_guild_name(0);
  MY_PLAYER->set_guild_file(0);
  MY_PLAYER->set_guild_name(0);
    MY_PLAYER->raise_strength(-5);
    MY_PLAYER->raise_magic_aptitude(-5);
    MY_PLAYER->raise_stamina(-5);
    MY_PLAYER->raise_will_power(-5);
    MY_PLAYER->raise_stealth(-4);
    MY_PLAYER->raise_luck(-3);
    MY_PLAYER->raise_intelligence(-3);
    MY_PLAYER->raise_piety(-2);
  telepathy("I'M A QUITTER FROM THE VAMPIRE GUILD!");
  destruct(MY_FANGS);
  return 1;
}
