/*
 * Curse
 * Doppleganger spell to curse a mob - changes heal_rate / heal_interval
 *              to slow it's auto healing
 * Rumplemintz
 */

int main(string str) {
  object target, curseob, badge;

  if ((int)this_player()->query_guild_rank() < 14) {
    write("You are not high enough level to do that.\n");
    return 1;
  }

  if ((int)this_player()->query_sp() < 40) {
    write("You do not have enough spell points for that.\n");
    return 1;
  }

  if (!str) {
    write("What do you want to curse?\n");
    return 1;
  }

  target = (object)this_player()->query_attack();

  if (!target)
    target = present(str, environment(this_player()));

  if (!target) {
    write("What do you want to curse?\n");
    return 1;
  }

  if (!target->is_npc()) {
    write("You cannot curse " + target->short() + ".\n");
    return 1;
  }

  badge = present("V-GUILD", this_player());
  if (badge->query_cursed()) {
    write("You are already concentrating on a curse.\n");
    return 1;
  }

  if (present("doppleganger_curse_object", target)) {
    write(target->short() + " is already being cursed.\n");
    return 1;
  }

  badge->set_cursed(1);

  curseob = clone_object("/players/guilds/dopplegangers/obj/curseob");
  curseob->set_owner(this_player());
  curseob->set_orgs(target->query_heal_rate(), target->query_heal_intv());
  move_object(curseob, target);
  curseob->start_me();

  this_player()->add_spell_point(-40);
  write("You put a curse on " + target->short() + ", and " +
        target->query_pronoun() + " clutches " +
        target->query_possessive() + " heart in agony.\n");
  say(this_player()->query_name() + " puts a curse on " +
      target->short() + ", and " + target->query_pronoun() + " clutches " +
      target->query_possessive() + " heart in agony.\n");
  return 1;
}

