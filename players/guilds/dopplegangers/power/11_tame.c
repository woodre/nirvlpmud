/*
 * Tame
 * Doppleganger spell to change an aggressive monster into being non-aggressive
 * Rumplemintz
 */

int main(string str) {
  object tameob;

  if (this_player()->query_guild_rank() < 11) {
    write("You are not high enough level for that.\n");
    return 1;
  }

  if (!str) {
    write("What do you want to tame?\n");
    return 1;
  }

  if (this_player()->query_sp() < 20) {
    write("You do not have enough spell points for that.\n");
    return 1;
  }

  tameob = present(str, environment(this_player()));

  if (!tameob) {
    write("There is no " + str + " here!\n");
    return 1;
  }

  if (random(100) < 21) {
    write("The attempt failed!\n");
    tameob->attack_object(this_player());
    say(this_player()->query_name() + " tried to tame " +
        tameob->query_name() + ", but failed!\n");
    this_player()->add_spell_point(-20);
    return 1;
  }
  tameob->set_aggressive(0);
  this_player()->add_spell_point(-20);
  write("You tame the beast.\n");
  say(this_player()->query_name() + " tames " +
      tameob->query_name() + ".\n");
  return 1;
}
