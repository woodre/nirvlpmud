/*
 * new_title
 * Doppleganger command to set their own title
 */

status main(string str) {
  if (this_player()->query_guild_rank() < 3) {
    write("You are not high enough level to do that.\n");
    return 1;
  }
  if (this_player()->query_sp() < 5) {
    write("You do not have enough spell points to do that.\n");
    return 1;
  }
  if (!str) {
    write("What do you want your new title to be?\n");
    write("You can type \"new_title clear\" to clear it.\n");
    return 1;
  }
  if (str == "clear") this_player()->set_title("|");
  else
  if (this_player()->query_level() > 19)
    this_player()->set_title(str);
  else
      this_player()->set_title(str + " (p)");
  write("Your title has been changed, you are now: \n");
  write(this_player()->short());
  write("\n");
  this_player()->add_spell_point(-5);
  return 1;
}
