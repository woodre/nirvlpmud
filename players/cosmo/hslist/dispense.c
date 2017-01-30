/* VDS dispenser */
#include "/players/cosmo/closed/ansi.h"
#define TP this_player()
#define COST 5

int tally;

short() { return "A virtual display screen ["+BLU+"VDS"+NORM+"] dispenser"; }
long(str)  {
  if (str=="dispenser" || str=="box") {
    write("A small metal box with a coin slot on the\n");
    write("side and a sign engraved on top.\n");
    if(TP->query_level() > 21) 
      write(tally+" screens have been sold during this reboot.\n");
    return;
  }
  if (str=="coin slot" || str=="slot") {
    write("The slot is for inserting coins to buy a VDS.\n");
    return;
  }
  if (str=="sign") {
    write("The sign says: "+BOLD+"5 coins per VDS."+NORM+"\n");
    return;
  }
  return;
}

get()   { write("It's firmly attached.\n"); return 0; }
id(str) {
  if("dispenser"==str || "box"==str || "sign"==str || "slot"==str) return 1;
  else return 0;
}
init()  {
  add_action("read","read");
  add_action("insert","insert");
}

read(str) {
  if(!str) { write("Read what?\n"); return 1; }
  if(str=="sign") write(BOLD+"5 coins per VDS."+NORM+"\n");
  else write("The "+str+" cannot be read.\n");
  return 1;
}
  
insert(str) {
  object ob;
  if(!str) { write("Try <insert coins>.\n"); return 1; }
  if(str=="coins") {
    if(TP->query_money() < COST) {
      write("Show me the money!\n");
      return 1;
    }
    ob = clone_object("/players/cosmo/hslist/vds");
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
