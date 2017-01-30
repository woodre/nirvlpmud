/*
 * Vandalize
 * Doppleganger spell to add grafitti to room, wears off
 */

status main(string str) {
  object obj;

  if (str) return 0;
  if (this_player()->query_guild_rank() < 9) {
    write("You are not high enough level to do that.\n");
    return 1;
  }
  if (this_player()->query_sp() < 20) {
    write("You do not have enough spell points for that.\n");
    return 1;
  }
  obj = clone_object("/players/grimm/closed/obj/badge_stuff/vandal");
  obj->set_nme(this_player()->query_real_name());
  obj->reset();
  move_object(obj, environment(this_player()));
  write("You spray your name all over the walls.\n");
  say(this_player()->query_name() + " sprays " +
      this_player()->query_name() + " name all over the walls.\n");
  this_player()->add_spell_point(-20);
  return 1;
}
