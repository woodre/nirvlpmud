/*
 * Death
 * Doppleganger damage spell - 80sp for 80 damage, in increments of 20
 * Rumplemintz
 */

status main(string str) {
  object target, cost;
  int times, i;
  string tname;

  if ((int)this_player()->query_guild_rank() < 15) {
    write("You are not high enough level to do that.\n");
    return 1;
  }

  if (!str && !this_player()->query_attack()) {
    write("Summon Death against who?\n");
    return 1;
  }

  if (this_player()->query_attack())
    target = (object)this_player()->query_attack();
  else
    target = present(str, environment(this_player()));

  if (!target) {
    write("Summon Death against who?\n");
    return 1;
  }
  tname = (string)target->query_name();

  switch (target->query_hp()) {
  case 41..60: times = 3; break;
  case 21..40: times = 2; break;
  case 0..20: times = 1; break;
  default: times = 4; break;
  }

  if ((int)this_player()->query_sp() < (times * 20)) {
    write("You do not have enough spell points for that.\n");
    return 1;
  }

  if (!this_player()->query_attack())
    this_player()->attack_object(target);

  write("You summon Death, and point your finger towards " +
        tname + ".\n");
  say(this_player()->query_name() + " summons Death, and points " +
      this_player()->query_possessive() + " finger towards " +
      tname + ".\n");

  for (i=0; i < times; i++) {
/*
    tell_object(this_player(), "i = " + i + ".\n");
    tell_object(this_player(), "times = " + times + ".\n");
*/
    target->hit_player(20);
    this_player()->add_spell_point(-20);
    tell_room(environment(this_player()),
              "Death massacres " + tname + " to small fragments.\n");
  }
  return 1;
}

