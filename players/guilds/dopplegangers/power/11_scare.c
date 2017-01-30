/*
 * Scare
 * Doppleganger spell to scare wimpy players (checks whimpy)
 * Rumplemintz
 */

int main(string str) {
  object who, badge;
  int required;

  if (!str) return 0;

  badge = present("V-GUILD", this_player());

  if (badge->query_faction("barbarian"))
    required = 11;
  else
    required = 15;

  if (this_player()->query_guild_rank() < required) {
    write("You are not high enough level to do that.\n");
    return 1;
  }

  if (this_player()->query_spell_point() < 15) {
    write("You do not have enough spell points for that.\n");
    return 1;
  }

  if ((string)environment(this_player())->realm() == "NT") {
    write("That is not allowed in this room.\n");
    return 1;
  }

  who = find_player(str);

  if (!who || !present(who, environment(this_player()))) {
    write("That person is not here.\n");
    return 1;
  }

  if ( (random(100) < 21) || (!who->query_wimpy()) ) {
    write("You try to scare " + who->query_name() + ", but fail!\n");
    say(this_player()->query_name() + " tris to scare " + who->query_name() +
        ", but fails!\n");
    this_player()->add_spell_point(-15);
    return 1;
  }
  write("You scare " + who->query_name() + ", and " + who->query_pronoun() +
        " runs away!\n");
  say(this_player()->query_name() + " waves " +
      this_player()->query_possessive() + " arms in the air.\n");
  say(who->query_name() + " freaks out and runs away!\n");
  who->run_away();
  this_player()->add_spell_point(-15);
  return 1;
}
