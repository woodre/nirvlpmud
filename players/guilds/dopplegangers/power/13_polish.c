/*
 * Polish
 * Doppleganger spell to add 10 percent value to an item
 * Rumplemintz
 */

int main(string str) {
  object ob;

  if ((int)this_player()->query_guild_rank() < 13) {
    write("You are not high enough level to do that.\n");
    return 1;
  }
  if ((int)this_player()->query_sp() < 15) {
    write("You do not have enough spell points for that.\n");
    return 1;
  }
  if (!str) {
    write("Polish what?\n");
    return 1;
  }
  ob = present(str, this_player());
  if (!ob) {
    write("You do not have one of those.\n");
    return 1;
  }
  if ((int)ob->query_value() <= 0) {
    write(ob->short() + " has no value.\n");
    return 1;
  }
  if ((int)ob->query_value() >= 1200) {
    write(ob->short() + " cannot be polished anymore.\n");
    return 1;
  }
  ob->set_value( ((int)ob->query_value() + ((int)ob->query_value() / 10)));
  this_player()->add_spell_point(-15);
  write("You polish " + ob->short() + ".\n");
  say(this_player()->query_name() + " polishes " +
      this_player()->query_possessive() + " " + ob->short() + ".\n");
  return 1;
}

