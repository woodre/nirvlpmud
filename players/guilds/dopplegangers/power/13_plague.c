/*
 * Plague
 * Doppleganger DoT spell, 30sp for 5 heart_beat random(10) damage each hb
 * Rumplemintz
 */

int main(string str) {
  object target, plagueob, badge;

  if ((int)this_player()->query_guild_rank() < 13) {
    write("You are not high enough level to do that.\n");
    return 1;
  }

  if ((int)this_player()->query_sp() < 30) {
    write("You do not have enough spell points for that.\n");
    return 1;
  }

  badge = present("V-GUILD", this_player());
  if (badge->query_plagued()) {
    write("You are already concentrating on plagueing something.\n");
    return 1;
  }

  if (!str && !this_player()->query_attack()) {
    write("Send the plague against who?\n");
    return 1;
  }

  if (this_player()->query_attack())
    target = (object)this_player()->query_attack();
  else
    target = present(str, environment(this_player()));
  if (!target) {
    write("Send the plague against who?\n");
    return 1;
  }

  if (!this_player()->query_attack())
    this_player()->attack_object(target);

  this_player()->add_spell_point(-30);
  plagueob = clone_object("/players/guilds/dopplegangers/obj/plagueob");
  plagueob->set_owner(this_player());
  move_object(plagueob, target);
  plagueob->start_me();
  write("You cast a plague on " + target->short() + ".\n");
  say(this_player()->query_name() + " plagues " + target->short() + ".\n");
  badge->set_plagued(1);
  return 1;
}

