/*
 * Step
 * Teleport to a guild member (if that member is allowing it)
 * 65 spell points - cannot step to wizards
 */

status main(string str) {
  object target;
  object badge;

  if (this_player()->query_guild_rank() < 5) {
    write("You are not high enough level to do that.\n");
    return 1;
  }
  if (this_player()->query_sp() < 65) {
    write("You do not have enough spell points for that.\n");
    return 1;
  }
  target = find_player(str);
  if (!str || !target) {
    write("That person is not playing right now.\n");
    return 1;
  }
  badge = present("V-GUILD", target);
  if(target->query_level() > 19) {
    write("You cannot use step to teleport to a wizard.\n");
    return 1;
  }
  if ((string)target->query_guild_name() != "dopplegangers") {
    write("That is not a Doppleganger!\n");
    return 1;
  }
  if (!badge->query_allowem()) {
    write("That Doppleganger is not allowing steps.\n");
    return 1;
  }
  if ((string)environment(target)->realm() == "NT" ||
      (string)environment(this_player())->realm() == "NT") {
    write("A magical force is preventing your step.\n");
    return 1;
  }
  this_player()->add_spell_point(-65);
  write("You step behind your shadow and arrive next to " +
        target->query_name() + ".\n");
  tell_room(environment(target), this_player()->query_name() +
            " steps out from behind " + target->query_name() +
            "'s shadow.\n");
  move_object(this_player(), environment(target));
  return 1;
}
