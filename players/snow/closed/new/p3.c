#include "../DEFS.h"
#define LEVEL 10
#define DRAIN 25

status main(string str) { return 0; }

/* this function should have no return type in its declaration */
static_main(string str) {
  object meat;
  int dmg;
  string name;
  if(!gotrank(TP, LEVEL)) return 0;
  if((string)IPTP->query_wepsync()) {
    write("You have synchronized your weapon.\n"+
          "Thus, this command cannot be used independently.\n");
    return 1;
  }
  if(!gotsp(TP,   DRAIN)) return 1;
  if(TP->query_level() < 19) {
    write("You must be player level 19 to use this.\n"); 
    return 1; 
  }
  if(str) {
    meat = present(str, environment(TP));
    name = capitalize(str);
    if(!meat) { 
      write("You cannot see [ "+str+" ] here.\n");
      return 1; 
    }
  }
  if(!str) {
    if(!TP->query_attack()) {
      write("What do you want to power?\n");
      return 1; 
    }
    meat = (object)TP->query_attack();
    name = MEAN;
  }
  if(!meat || !present(meat, environment(TP))) {
    write("Your opponent is not here to fight.\n");
    return 1; 
  }

  dmg = random(20) + 15;

  TP->spell_object(meat, "Power Wield", dmg, DRAIN,
    "Double laser disruption funnels thunder from your eyes and slam into "+
      name +".\n",
    "Double laser disruption funnels thunder from "+TPN+
      "'s eyes and slam into you!\n",
    "Double laser disruption funnels thunder from "+TPN+
      "'s eyes and slam into "+name +".\n");
  return 1;
}
