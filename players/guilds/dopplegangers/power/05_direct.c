/*
 * Direct
 * Direct sps to another player - 10% loss in transfer
 */

status main(string str) {
  string person;
  object target;
  int amount;

  if (sscanf(str, "%d %s", amount, person) != 2) {
    write("Usage is 'direct <amount> <player>'\n");
    return 1;
  }
  if (amount < 0) {
    write("You cannot direct a negative amount.\n");
    return 1;
  }
  if (this_player()->query_sp() < amount) {
    write("You do not have enough spell points for that.\n");
    return 1;
  }
  target = find_player(person);
  if (!target) {
    write("That person is not on right now.\n");
    return 1;
  }
  if ((string)target->query_guild_name() != "dopplegangers") {
    write("That person is not a Doppleganger!\n");
    return 1;
  }
  this_player()->add_spell_point(-amount);
  write("You direct " + amount + " of your spell points to " +
        target->query_name() + ".\n");
  write("Some magic is lost in the transfer.\n");
  amount = amount - (amount/10);
  tell_object(target, this_player()->query_name() + " directs " + amount +
              " spell points to you.\n");
  target->add_spell_point(amount);
  return 1;
}
