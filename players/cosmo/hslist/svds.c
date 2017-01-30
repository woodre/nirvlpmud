#include "/players/cosmo/closed/ansi.h"
#define VDS_MASTER "/players/cosmo/hslist/vds.c"

/*
#define COST 5

int tally;
*/

reset(arg) {
  if(arg) return;
  /*
  tally = 0;
  */
}

short() { return "A virtual display screen ["+BLU+"VDS"+NORM+"]"; }

long() {
  write("\n"+short()+"\n"+
    "A wall-size screen with a sign engraved on top.\n"+
    BOLD+"Read"+NORM+" the "+BOLD+"sign"+NORM+" for operating instructions.\n"+
/*
    "or "+BOLD+"insert"+NORM+" 25 "+BOLD+"coins"+NORM+" to purchase a mobile VDS."+
*/
    "\n");
}

id(str) { return str == "VDS" || str == "screen" ||
     str == "display" || str == "vds" || str == "display screen"; }

query_weight() { return 1000; }
query_value() { return 0; }
get() { return 0; }

init() {
  add_action("view","view");
  add_action("read","read");
  /*
  add_action("insert"); add_verb("insert");
  */
}

view(str) { VDS_MASTER->view(str); return 1; }

read(str) {
  if(str=="sign") {
    write("This wall-size screen tracks the players that have earned the\n"+
      "most experience since the last reboot. You may "+BOLD+"view"+NORM+
      " the "+BOLD+"current"+NORM+"\nscores for this reboot period, or the "+
      BOLD+"alltime"+NORM+" scores achieved\nduring one reboot period.\n"+
      "NOTES:\n"+
      "  1. All-time score statistics began on 4/29/99.\n"+
      "  2. The all-time scores are updated right before reboot.  Any\n"+
      "     experience earned after Armageddon appears is not counted.\n"+
      "  3. Mail any comments to Cosmo.\n");
    return 1;
  }
  else {
    write("You may look at the note, or read the sign.\n");
    return 1;
  }
}

/*
insert(str) {
  object ob;
  if(!str) { write("Try <insert coins>.\n"); return 1; }
  if(str=="coins") {
    if(tally > 9) {
      write("Sorry, we are currently sold out of the mobile units.\n");
      return 1;
    }
    if(TP->query_money() < COST) {
      write("Show me the money!\n");
      return 1;
    }
    ob = clone_object("/players/cosmo/hslist/mvds");
    if(!TP->add_weight(ob->query_weight())) {
      write("You cannot carry that much.\n");
      return 1;
    }
    write("You purchase "+ob->short()+".\n");
    say(TP->query_name()+" buys "+ob->short()+".\n", TP);
    TP->add_money(-COST);
    if(!ob->get()) move_object(ob, environment(TP));
    else move_object(ob, TP);
    tally++;
  }
  else write("You cannot insert "+str+" into the slot.\n");
  return 1;
}
*/
