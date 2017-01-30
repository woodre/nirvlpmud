#include "/players/eurale/closed/ansi.h"
inherit "obj/treasure";
#define ETP environment(this_player())
#define TP this_player()

reset(arg) {
  if(arg) return;

set_id("tentacle");
set_alias("crawler tentacle");
set_short(HIG+"carrion crawler tentacle"+NORM);
set_long(
  "Once extending from the head of a carrion crawler, this tentacle\n"+
  "was used as a fighting weapon.  It is dried out and cracked but\n"+
  "can still be bartered to someone who makes magic potions.\n");

set_weight(1);
set_value(950 + random(200));
}

query_no_save() { return 1; }

init() {
  ::init();
  add_action("Barter","barter");
}

Barter(str) {
int money;
if(!present("madame rue",ETP)) return 0;
if(str == "tentacle" || str == "crawler tentacle" ||
   str == "carrion crawler tentacle") {
money = 4444 + random(1000);
write("Madame Rue claps her hands in delight.  She winks at you and\n"+
      "whispers, 'I've been waiting for some of this so I can brew up\n"+
      "another batch of antitoxin potion for the folks who brave the\n"+
      "labryinth.  You've done well, brave one.'  And with that she\n"+
      "tucks the tentacle away and gives you "+money+" coins.  She\n"+
      "whispers again, 'Tell all your friends I'll buy all the crawler\n"+
      "tentacles they can bring me' and she smiles.\n");
TP->add_money(money);
destruct(this_object());
return 1; }
}
