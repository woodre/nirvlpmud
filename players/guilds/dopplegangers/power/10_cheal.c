/*
 * Coin Heal (cheal)
 * Doppleganger heal spell - cost is 20 coins per hp/sp
 */

status main(string str) {
  int amt;

  if (!str || (sscanf(str, "%d", amt) != 1)) {
    write("How many coins do you want to spend?\n");
    return 1;
  }
  if (this_player()->query_guild_rank() < 10) {
    write("You are not high enough level to do that yet.\n");
    return 1;
  }
  if (amt <= 0) {
    write("You must use a positive number.\n");
    return 1;
  }
  if (this_player()->query_money() < amt) {
    write("You do not have enough coins for that.\n");
    return 1;
  }
  write("You healed yourself for " + (amt / 20) + " points.\n");
  say(this_player()->query_name() + " healed " +
      this_player()->query_possessive() + "self.\n");
  this_player()->add_money( - amt );
  this_player()->heal_self( (amt / 20) );
  return 1;
}
