/*
 * First Aid
 * Doppleganger heal spell - 30sp for 25hp heal
 * Rumplemintz
 */

int main(string str) {
  object target;

  if ((int)this_player()->query_guild_rank() < 12) {
    write("You are not high enough level to do that.\n");
    return 1;
  }

  if ((int)this_player()->query_sp() < 30) {
    write("You do not have enough spell points for that.\n");
    return 1;
  }

  if (!str) {
    write("Who do you want to apply first aid to?\n");
    return 1;
  }

  target = find_player(str);

  if (!target || !present(target, environment(this_player()))) {
    write("That player is not here.\n");
    return 1;
  }

  write("You apply first-aid to " + target->query_name() + ".\n");
  say(this_player()->query_name() + " applies first-aid to " +
      target->query_name() + ".\n", ({ target, this_player() }));
  tell_object(target, this_player()->query_name() +
              " applies first-aid to you.\n");
  this_player()->add_spell_point(-30);
  target->heal_self(25);
  return 1;
}
