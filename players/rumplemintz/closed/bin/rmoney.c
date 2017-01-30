#include <ansi.h>

int rmoney(string str) {
  string who;
  int amount;
  object coins;
  if (!str || sscanf(str, "%s %s", who, amount) != 2) {
    notify_fail("Usage: rmoney <who> <amount>\n");
    return 0;
  }
  if(!find_player(who)){
    notify_fail("Cannot find "+who+" currently.\n");
    return 0;
  }
  coins = clone_object("/obj/money");
  coins->set_money(amount);
  move_object(coins, environment(find_player(who)));
  return 1;
}
