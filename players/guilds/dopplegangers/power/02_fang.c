/*
 * Fang - Damage spell for Dopplegangers
 *        MAX damage - 5 * Guild Level
 */

status main(string str) {
  object badge, target;
  string tname;
  int fang_damage;

  badge = present("V-GUILD", this_player());
  fang_damage = (int)badge->query_fang_hit();
  if (this_player()->query_guild_rank() < 2) {
    write("You are not high enough level to do that yet.\n");
    return 1;
  }
  if (this_player()->query_sp() < fang_damage) {
    write("You do not have enough spell points to do that.\n");
    return 1;
  }
  if (badge->query_fang_casting()) {
    write("You're still swallowing the blood!\n");
    return 1;
  }
  if (!str && !this_player()->query_attack()) {
    write("Fang who?\n");
    return 1;
  }
  if (this_player()->query_attack())
    target = (object)this_player()->query_attack();
  else
    target = present(str, environment(this_player()));
  if (!target) {
    write("Fang who?\n");
    return 1;
  }
  if (!this_player()->valid_attack(target)) {
    write("Your body rejects the blood.\n");
    return 1;
  }
  tname = (string)target->query_name();

  if (this_player()->query_guild_rank() < 9)
    badge->set_fang_casting();
  if (!this_player()->query_attack())
    this_player()->attack_object(target);
  if (target->query_guild_name() &&
      (string)target->query_guild_name() != "doppleganger")
    fang_damage += 10;
  target->hit_player(fang_damage);
  this_player()->add_spell_point(-fang_damage);
  write("You sink your fangs into the neck of " + tname + ".\n");
  write("Your blood starts to boil as you drain the blood of your victim!\n");
  say(this_player()->query_name() + " fangs " + tname + " in the neck.\n");
  return 1;
}
