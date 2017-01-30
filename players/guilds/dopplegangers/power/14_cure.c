/*
 * Cure
 * Doppleganger heal spell - 70sps/35 hp heal (Changed from 40sp/heal_self(35))
 * Rumplemintz
 */

int main(string str) {
  object target;

  if ((int)this_player()->query_guild_rank() < 14) {
    write("You are not high enough level for that.\n");
    return 1;
  }

  if ((int)this_player()->query_sp() < 70) {
    write("You do not have enough spell points for that.\n");
    return 1;
  }

  if (!str) {
    write("Who do you want to cure?\n");
    return 1;
  }

  target = present(str, environment(this_player()));
  if (!target) {
    write("That player is not here.\n");
    return 1;
  }

  if (!target->is_player()) {
    write("That is not a player.\n");
    return 1;
  }

  this_player()->add_spell_point(-70);
  target->add_hit_point( ((int)target->query_mhp() - (int)target->query_hp() >
                          35) ? 35 :
                          (int)target->query_mhp() - (int)target->query_hp());
  write("You apply cures to " + target->query_name() + ".\n");
  say(this_player()->query_name() + " applies cures to " +
      target->query_name() + ".\n");
  return 1;
}

