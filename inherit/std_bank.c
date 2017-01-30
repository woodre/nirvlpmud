/* A bank */

#include <mudlib.h>

inherit ROOM;

#define OWNER (string)owner_ob->query_name()

string owner, owner_name;
object owner_ob;

mixed calc_value(int i);
void set_owner(string str);

void reset(status arg) {
  set_no_fight(1);
  if (arg) return;

  set_short("the city vault");
  set_long(
   "A long counter of brown polished wood shines with the light from \n" +
   "several lanterns hanging on the wall.  Across the room a large gate\n" +
   "of iron leads to the strong room, where all the valuables are kept.\n" +
   "On the wall, behind the counter, is a golden plaque.\n");

  set_items(({
    "wood#counter", "It appears to be very old",
    "light#lantern#lanterns", "They shed light into the small banking chamber",
    "plaque", "Perhaps you could read it?",
    "gate#iron#strong room", "It looks very protected, and difficult to " +
                             "break into"
  }));

  set_weather(2, 0, 0);

  set_exits(({
    "room/city/town_hall3", "south"
  }));

  set_smell("The strong smell of old wood permiates the air\n");
  set_listen("Behind the iron gate you can hear money being counted...\n");
}

void init() {
  ::init();
  if (!owner) set_owner(0);
  add_action("read", "read");
  add_action("withdraw", "withdraw");
  add_action("deposit", "deposit");
  add_action("balance", "balance");
}

status read(string str) {
  if (str == "plaque") {
    say(this_player()->query_name() + " reads the plaque on the wall.\n");
    write(
    "The plaque reads:                                             \n" +
    "       The " + short(0) + "                                   \n" +
    " Banking commands are:                                        \n" +
    " Deposit <amount> ..............Add money to your balance     \n" +
    " Withdraw <amount> .............Take money from your balance  \n" +
    " Balance .......................Find out your current balance \n" +
    "\nValid amounts are in gold, silver, default is copper        \n" +
    "1 gold = 10 silver, 1 silver = 100 copper coins.              \n" +
    "Amount of transaction subject to 10% fee.                     \n");
    return 1;
  }
  return 0;
}

status withdraw(string str) {
  string tmp1, tmp2;
  int amount;

  if (!present(owner)) {
    write("No one is here to help you.\n");
    return 1;
  }
  if (!str) {
    write(OWNER + " asks: What did you say?\n");
    return 1;
  }
  if (sscanf(Str, "%d %s", amount, tmp1)) {
    if (tmp1 == "gold") amount *= 1000;
    else if (tmp1 == "silver") amount *= 100;
  }
  if (amount > (int)this_player()->query_savings()) {
    write(OWNER + " says: You don't have that much in the vault!\n");
    return 1;
  }
  write(OWNER + " takes " + calc_value(amount) + " out of the vault.\n");
  write(OWNER + " takes " + calc_value(amount/10) + " as his fee.\n");
  this_player()->add_savings(-amount);
  amount -= amount/10;
  this_player()->add_money(amount);
  write(OWNER + " gives you " + calc_value(amount) + " coins.\n");
  say((string)this_player()->query_name() + " withdraws some money.\n");
  return 1;
}

status deposit(string str) {
  string tmp1, tmp2;
  int amount;

  if (!present(owner)) {
    write("There is no one here to help you.\n");
    return 1;
  }
  if (!str) {
    write(OWNER + " asks: What was that? What did you say?\n");
    return 1;
  }
  if (sscanf(str, "%d %s", amount, tmp1)) {
    if (tmp1 == "gold") amount *= 1000;
    if (tmp1 == "silver") amount *= 100;
  }
  if (amount > this_player()->query_money()) {
    write(OWNER + " exclaims: You don't have that much money to deposit!\n");
    return 1;
  }
  this_player()->add_money(-amount);
  if (!amount/10) {
    write(OWNER + " takes " + calc_value(1) + " as his fee.\n");
  }
  write(OWNER + " takes " + calc_value(amount/10) + " as his fee.\n");
  if (!amount/10) amount -= 1;
  else amount -= amount/10;
  this_player()->add_savings(amount);
  write(OWNER + " places " + calc_value(amount) + " in the vault.\n");
  return 1;
}

status balance() {
  if (!present(owner)) {
    write("There is no one here to help you.\n");
    return 1;
  }
  write(OWNER + " says: You have " +
        calc_value((int)this_player()->query_savings()) + " in the vault.\n");
  return 1;
}

/* Exchange rate for coins - do not alter
 * 1 gold = 10 silver, 1 silver = 100 copper
 */
mixed calc_value(int amount) {
  string tmp;

  tmp = (string)call_other(MONEY, "convert", amount);
  if (tmp == "") tmp = "nothing";
  return tmp;
}

void set_owner(string owner_name) {
  if (!stringp(owner_name)) owner_name = "keeper";
  if (!owner) owner = capitalize(owner_name);
  if (present(owner_name)) return;
  owner_ob = clone_object("inherit/monster");
  owner_ob->set_name(lower_case(owner));
  owner_ob->set_no_kill_flag(1);
  owner_ob->set_race("human");
  owner_ob->set_short(owner + ", the vault watcher");
  owner_ob->set_alias("watcher");
  owner_ob->set_long(owner + " has always kept this vault, and all \n" +
         "the money safe inside it.  He is vigilant in his efforts \n" +
         "of fair play, and monetary gain.\n");
  owner_ob->set_al(100);
  owner_ob->set_gender(1);
  owner_ob->set_level(15);
  owner_ob->set_wc(20);
  owner_ob->set_ac(18);
  owner_ob->set_hp(700050);
  owner_ob->load_chat(5, ({
        owner + " gives you a smile.\n",
        owner + " asks: Would you like to keep your money in my vault?\n",
        owner + " says: I store lots of money in my vault.\n",
        owner + " glances at your purse string.\n", }));
  owner_ob->load_a_chat(25, ({
        owner + " exclaims: You'll never steal from my vault!\n",
        owner + " gives you a wack over the head with his money bag.\n", }));
  owner_ob->add_money(1200 + random(800));
  move_object(owner_ob, this_object());
}

status long(string str) {
  ::long();
  write("There is a golden plaque on the wall to read.\n");
  return 1;
}

int query_no_kill() { return 1; }

