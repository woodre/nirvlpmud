/*
 * Jerky
 * Make jerky out of a corpse for use later
 */

status main(string str) {
  object corpse;
  string cname;

  if (this_player()->query_guild_rank() < 6) {
    write("You are not high enough level to do that.\n");
    return 1;
  }
  if (this_player()->query_sp() < 5) {
    write("You do not have enough spell points for that.\n");
    return 1;
  }
  corpse = present("corpse", this_player());
  if (!corpse)
    corpse = present("corpse", environment(this_player()));
  if (!corpse) {
    write("There is no corpse present.\n");
    return 1;
  }
  if (sscanf(corpse->short(), "corpse of %s", cname) != 1) {
    write("The name of the corpse was not found.. aborting...\n");
    return 1;
  }
  this_player()->add_spell_point(-5);
  environment(corpse)->add_weight(- ((int)corpse->query_weight()));
  destruct(corpse);
  corpse = clone_object("/players/guilds/dopplegangers/obj/jerky");
  corpse->set_nme(cname);
  move_object(corpse, this_player());
  write("You make jerky out of the corpse of " + capitalize(cname) + ".\n");
  say(this_player()->query_name() + " makes jerky out of the corpse of " +
      capitalize(cname) + ".\n");
  return 1;
}
