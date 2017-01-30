/*
 * ATM card for use with the bank functions.
 * Rumplemintz
 */

#include <ansi.h>

string short() {
  return capitalize((string)environment(this_object())->query_name()) +
         "'s " + HIR + "ATM " + NORM + "card";
}

void long() {
  write("This is an ATM card that is usable for Nirvana's bank.\n" +
        "You can use the the commands as follows:\n" +
        "_____________________________________________________________\n" +
        "ATM                   ............... Show current balance\n" +
        "ATM withdraw <amount> ............... Withdraw <amount> coins\n" +
        "ATM deposit  <amount> ............... Deposit <amount> coins\n" +
        "_____________________________________________________________\n");
}

void reset(int arg){ if(arg) return; }

void init() {
  if (!environment() || environment(this_object()) != this_player()) return;
#if 0 /* Change to 1 to disallow players */
  if (((int)this_player()->query_level()<20) && !this_player()->is_testchar())
    return;
#endif
  add_action("atm_funcs", "ATM");
}

int atm_funcs(string str) {
  string type;
  int amount;

  if (!str) {
    write("Your current bank balance is: " +
          this_player()->query_bank_balance() + "\n");
    return 1;
  }
  if (str && sscanf(str, "%s %d", type, amount) != 2) return 0;
  if (amount <= 0) return 0;

  if (type == "deposit") {
    if ((int)this_player()->query_money() < amount) {
      write("You do not have that much money.\n");
      return 1;
    }
    this_player()->add_money(-amount);
    this_player()->add_bank_balance(amount);
  } else if (type == "withdraw") {
    if ((int)this_player()->query_bank_balance() < amount) {
      write("You do not have that much money in your account.\n");
      return 1;
    }
    if (((int)this_player()->query_money() + amount) > 80000) {
      write("You cannot withdraw more than " +
            (80000 - (int)this_player()->query_money()) + ".\n");
      return 1;
    }
    this_player()->add_money(amount);
    this_player()->add_bank_balance(-amount);
  } else {
    return 0;
  }
  write("You " + type + " " + amount + " coins " +
        (type == "deposit" ? "to" : "from") + " your account.\n");
  say(this_player()->query_name() + " " + type + "s " + amount + " coins " +
      (type == "deposit" ? "into" : "from") + " " +
      this_player()->query_possessive() + " bank account.\n");
  write("Your account balance is " + this_player()->query_bank_balance() +
        " gold coins.\n");
  return 1;
}

int get() { return 1; }
int drop() { return 1; }

int id(string str) { return str=="atm" || str=="atm card" || str=="card"; }
string query_auto_load(){ return "players/rumplemintz/closed/atm.c:";}

