#define tpn this_player()->query_name()  /* player name  */
#include "/players/cosmo/closed/ansi.h"

id(str) { return str == "purse"; }
short() { return "A black leather purse"; }
query_save_flag() { return 1; }
query_value() { return (10); }
long() {
  write(short()+".\n"+
        "It looks like it contains some money.\n"+
        "Try to <snatch cash> to get the coins out.\n"); }

reset(arg) {
  if(arg) return;
}

init() {
  add_action("snatch","snatch"); }

snatch(str) {
int amt;
if(str == "cash") {
  amt = 400+random(100);
  this_player()->add_money(amt);
  write("You reach into the purse, grab the "+amt+" coins, and then toss the\n"+
        "purse in a nearby dumpster, hoping that nobody saw you.\n");
  destruct(this_object());
  return 1; }
else { write("You cannot snatch the "+str+".\n");
return 1; }
}

get() { return 1; }

query_weight() { return 1; }

