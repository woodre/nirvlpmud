/*
 * Ginv
 * Inventory command for the Doppleganger guild locker room
 */

status main(string str) {
  object locker_room;
  object obj;
  int i;

  if (this_player()->query_guild_rank() < 4) {
    write("You are not high enough level to do that.\n");
    return 1;
  }
  locker_room = find_object("/players/guilds/dopplegangers/room/locker");
  if (!locker_room) {
    write("The locker currently contains:\n  Nothing.\n");
    return 1;
  }
  obj = first_inventory(locker_room);
  write("The locker currently contains:\n");
  say(this_player()->query_name() + " looks in " +
      this_player()->query_possessive() + " guild locker.\n");
  i = 0;
  while (obj) {
    if (obj->id(str) || !str ||
        (obj->weapon_class() && str == "weapons") ||
        (obj->query_type() && str == "armors")) {
      i++;
      write(obj->short() + "\n");
    }
    obj = next_inventory(obj);
  }
  if (i == 0) write("  Nothing.\n");
  write("\n");
  return 1;
}
