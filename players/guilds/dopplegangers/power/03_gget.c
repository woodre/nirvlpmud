/*
 * Gget
 * Get an item from the guild locker room
 */

status main(string str) {
  object obj, locker_room;

  if (this_player()->query_guild_rank() < 3) {
    write("You are not high enough level to do that yet.\n");
    return 1;
  }
  if (this_player()->query_sp() < 5) {
    write("You do not have enough spell points to do that.\n");
    return 1;
  }
  if (!str) {
    write("What do you want to get from the guild locker?\n");
    return 1;
  }
  locker_room = find_object("/players/guilds/dopplegangers/room/locker");
  obj = present(str, locker_room);
  if (!obj) {
    write("Cannot find  " + str + " in the locker.\n");
    return 1;
  }
  move_object(obj, this_player());
  write("You retrieve " + obj->short() + " from the guild locker.\n");
  say(this_player()->query_name() + " pulls an item from " +
      this_player()->query_possessive() + " guild locker.\n");
  this_player()->add_spell_point(-5);
  this_player()->recalc_carry();
  return 1;
}
