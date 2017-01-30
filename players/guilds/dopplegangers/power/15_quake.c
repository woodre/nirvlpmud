/*
 * Quake
 * Doppleganger AoE damage spell 30sp / mob in room, up to 5
 * Rumplemintz
 */

int main(string str) {
  object *targets;
  int i, j;

  if (str) return 0;

  if ((int)this_player()->query_guild_rank() < 15) {
    write("You are not high enough level to do that.\n");
    return 1;
  }

  targets = all_inventory(environment(this_player()));
  j = sizeof(targets);

  for (i=0; i<sizeof(targets); i++) {
    if (!targets[i]->is_npc()) {
      targets -= ({ targets[i] });
      j--;
    }
  }

  if (j > 5) j = 5;

  if (this_player()->query_spell_point() < (30 * j)) {
    write("You do not have enough spell points for that.\n");
    return 1;
  }

  for (i=0; i<j; i++) {
    targets[i]->hit_player(30);
    write("You pound the ground and make the earth quake, staggering " +
          targets[i]->query_name()+ ".\n");
    say(this_player()->query_name() + " pounds the ground.\n" +
        "The earth quakes, staggering " + targets[i]->query_name() + ".\n");
    this_player()->add_spell_point(-30);
    targets[i]->attack_object(this_player());
  }
  return 1;
}

