/*
 * Smelt
 * Doppleganger command for remote selling
 */

status main(string str) {
  object obj;
  int amount;

  if (this_player()->query_guild_rank() < 3) {
    write("You are not high enough level to do that.\n");
    return 1;
  }
  if (this_player()->query_sp() < 20) {
    write("You do not have enough spell points for that.\n");
    return 1;
  }
  if (!str) {
    write("What do you want to smelt?\n");
    return 1;
  }
  obj = present(str, this_player());
  if (!obj) {
    write("You do not have one of those.\n");
    return 1;
  }
  amount = (int)obj->query_value();
  if (amount > 1000) amount = 1000;
  amount = amount*80 / 100;
  destruct(obj);
  write("A small 'ganger comes and takes the item from you.  After looking \n"+
        "it over, he flips you " + amount + " coins.\n");
  say("A small 'ganger comes and takes an item away from " +
      this_player()->query_name() + " and flips " +
      this_player()->query_objective() + " some coins.\n");
  this_player()->add_spell_point(-20);
  if ((int)this_player()->query_money() >= 80000) {
    obj = clone_object("obj/money");
    obj->set_money(amount);
    move_object(obj, this_player());
    write("You have the maximum amount of money, so the coins are placed in "+
          "your inventory.\n");
    return 1;
  }
  this_player()->add_money(amount);
  return 1;
}
