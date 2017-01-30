/*
 * Summon
 * Teleport a guild member to you (if that member is allowing it)
 * 65 spell points - cannot summon wizards
 */

status main(string str) {
  object target;
  object badge;
  object prior_environment;

  if (this_player()->query_guild_rank() < 7) {
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
    write("You cannot summon a wizard.\n");
    return 1;
  }
  if ((string)target->query_guild_name() != "dopplegangers") {
    write("That is not a Doppleganger!\n");
    return 1;
  }
  if (!badge->query_allowem()) {
    write("That Doppleganger is not allowing summons.\n");
    return 1;
  }
  if ((string)environment(target)->realm() == "NT" ||
      (string)environment(this_player())->realm() == "NT") {
    write("A magical force is preventing your summons.\n");
    return 1;
  }
  this_player()->add_spell_point(-65);
  prior_environment = environment(target);
  write("You reach behind your shadow and pull " +
        target->query_name() + " from it.\n");
  move_object(target, environment(this_player()));
  tell_room(prior_environment, " A hand pops out from behind " +
            target->query_name() + " and pulls " +
            target->query_objective() + " through.\n");
  tell_object(target, "A hand pops out from behind your shadow and pulls " +
              "you through.\n");
  return 1;
}
