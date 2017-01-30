/*
 * Gput
 * Put stuff into the guild community locker room (not saved)
 */

status main(string str) {
  object obj;

  if (this_player()->query_guild_rank() < 3) {
    write("You are not high enough level to do that.\n");
    return 1;
  }
  if (this_player()->query_sp() < 5) {
    write("You do not have enough spell points to do that.\n");
    return 1;
  }
  if (!str) {
    write("What do you want to put in the locker?\n");
    return 1;
  }
  obj = present(str, this_player());
  if (!obj) {
    write("You do not have one of those.\n");
    return 1;
  }
  if (obj->query_auto_load()) {
    write("You cannot put that into the locker.\n");
    return 1;
  }
  if (obj->drop()) {
    write("That item cannot be dropped.\n");
    return 1;
  }
  if (obj->armor_class()) obj->remove(str);
  if (obj->weapon_class()) obj->stopwield(str);
  move_object(obj, "/players/guilds/dopplegangers/room/locker");
  write("You send your " + obj->short() + " to the guild locker.\n");
  say(this_player()->query_name() + " sends an item to " +
      this_player()->query_possessive() + " guild locker.\n");
  this_player()->add_spell_point(-5);
  return 1;
}
