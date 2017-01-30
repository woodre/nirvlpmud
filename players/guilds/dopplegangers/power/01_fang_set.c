/*
 * Fang set (fs)
 * Set the damage that the spell 'Fang' does for the Dopples
 *
 * MAX is 5* Guild level
 *
 * Rumplemintz
 */

status main(string str) {
  int damage, MAX;
  object badge;

  MAX = (int)this_player()->query_guild_rank() * 5;
  badge = present("V-GUILD", this_player());

  if (!str) {
    write("What do you want your fang to be set at? (MAX: " + MAX + ")\n");
    return 1;
  }
  if (! (sscanf(str, "%d", damage))) {
    write("You must use a number to set your Fang damage to.\n");
    return 1;
  }
  if (damage > MAX) damage = MAX;
  if (damage < 1) damage = 1;
  badge->set_fang_hit(damage);
  write("Fang is now set to do " + badge->query_fang_hit() + " damage.\n");
  return 1;
}
