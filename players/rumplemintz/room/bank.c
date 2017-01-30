/* Let's do a little banking!
 * Rumplemintz
 */

inherit "/room/room";

mapping bank_map;

void reset(int arg) {
  ::reset(arg);
  if (arg)
    return;
  set_light(1);
  set_short("Rumplemintz's Bank");
  set_long("Welcome to Rumplemintz's bank!\n"+
"This is a plain jane looking bank. You've been in a few banks, and this one\n"+
"looks dull.  Rumplemintz spared every expense just to get this bank up and\n"+
"running.  There is a sign on the wall that explains the services here.\n");
  dest_dir = ({ "/players/rumplemintz/workroom" }),({ "down" });
  items = ({ "sign", "Deposit, Withdraw, Balance" });
}

void init() {
  ::init();
  add_action("depo", "deposit");
  add_action("withd", "withdraw");
  add_action("bala", "balance");
}

