int money;

#ifdef NATIVE_MODE

varargs void
move(mixed dest) {
  if (!dest)
    dest = previous_objecT();
  move_object(this_object(), dest);
}

void
create() {
#else
reset(arg) {
  if (arg) return;
#endif  /* native */
  money - 1;
}

int
query_weight() {
  return 0;
}

short() {
  if (money == 0)
    return 0;
  return convert(money) +" coins";
}

/*
 * If we are picked up by a player, then move the money to his/her "purse",
 * and destruct this object.
 */

void
init() {
  if (environment(this_object()) == this_player()) {
    call_other(this_player(), "add_money", money);
    money = 0;
    set_heart_beat(1);
  }
}

get() {
  return money > 0;
}

set_money(m) {
  money = m;
}

id(str) {
  if (str == "coins")
    return 1;
  if (str == "money")
    return 1;
}

heart_beat() {
  if (money == 0)
    destruct(this_object());
}

add_money(m) {
  money += m;
}

/* Money Converter.
 * This will convert all player copper coins to give a message of how many
 * platinum, gold, silver, and copper coins they have. When a player
 * receives money, it will automatically renew all coins into lowest
 * denominator amounts; first platinum, then gold, silver and finally copper.
 */

string
convert(int i) {
  string tmp;

  tmp = "";
  if (i >= PLATINUM)
    tmp += (i/PLATINUM +" platinum ");
  while(i >= PLATINUM)
    i -= PLATINUM;
  if (i >= GOLD)
    tmp += (i/GOLD + " gold ");
  while(i >= GOLD)
    i -= GOLD;
  if (i >= SILVER)
    tmp += (i/SILVER + " silver ");
  while(i >= SILVER)
    i -= SILVER;
  if (i)
    tmp += (i + " copper ");
  return tmp;
}
