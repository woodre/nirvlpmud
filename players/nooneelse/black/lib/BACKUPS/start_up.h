/*
  start_up.h
*/

#include "defs.h"

/* --------------- Transfer a member to the guild at startup --------------- */
start_up() {
  string str1, str2, str3;
  object amulet;
  str1 = file_name(MY_ROOM);
  sscanf(str1, "%s.c", str2);
  if (!str2) str2 = str1;
  /* only from the church */
  if (str2 != "room/church") {
    write("You can only do that from the church.\n");
    return 1;
  }
  if (!present("nooneelseamulet", MY_PLAYER)) {
    amulet = clone_object(AMULET);
    amulet->set_amulet_color("black");
    transfer(amulet, MY_PLAYER);
    write("As you arive, you receive a black amulet.\n");
    command("wear amulet", MY_PLAYER);
  }
  MY_FANGS->tell_my_room(
              "A mist envelops "+MY_NAME_CAP+
              ".  When it clears, you see a small bat flying away.");
  call_other(GUILD_LOWER_HALL, "???", 0);
  move_object(MY_PLAYER, GUILD_LOWER_HALL);
  write("You fly to the northwest over the landscape, then into the mouth\n"+
        "of a mine at the base of a mountain.  After a moment you emerge\n"+
        "from the tunnel to soar over some low mountains, then down into\n"+
        "a violet mist and into some secret rooms.\n\n");
  if (MY_PLAYER->query_brief())
    tell_object(MY_PLAYER, MY_ROOM->short()+"\n");
  else
    command("look", MY_PLAYER);
  return 1;
}
