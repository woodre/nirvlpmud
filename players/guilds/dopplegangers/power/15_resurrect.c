/*
 * Resurrect
 * Doppleganger spell to resurrect a player (cannot do in combat)
 * Rumplemintz
 */

int main(string str) {
  object target, res_ob;

  if ((int)this_player()->query_guild_rank() < 15) {
    write("You are not high enough level to do that.\n");
    return 1;
  }

  if ((int)this_player()->query_sp() < 80) {
    write("You do not have enough spell points for that.\n");
    return 1;
  }

  if (!str) {
    write("Who do you want to resurrect?\n");
    return 1;
  }

  target = present(str, environment(this_player()));

  if (!target) {
    write("That person is not here.\n");
    return 1;
  }

  if (!target->query_ghost()) {
    write("Your resurrection spell has no effect on the living.\n");
    return 1;
  }

  if (target == this_player()) {
    write("You cannot resurect yourself.\n");
    return 1;
  }

  if (this_player()->query_attack()) {
    write("You cannot concentrate on resurrection while in combat.\n");
    return 1;
  }

  res_ob = clone_object("/players/guilds/dopplegangers/obj/res_ob");

  write("You cast resurrection on " + target->query_name() + ".\n");
  say(this_player()->query_name() + " casts resurrection on " +
      target->query_name() + ".\n");
  this_player()->add_spell_point(-80);
  move_object(res_ob, target);
  res_ob->set_caster(this_player());
  res_ob->set_castee(target);
  res_ob->start_res();
  return 1;
}

