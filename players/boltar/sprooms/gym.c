#include "std.h"
int lght,unlocked;

init() {
if(set_light(0)==0)
   set_light(1);
   add_action("join","deposit");
   add_action("use","use");
   add_action("west","west");
 }

short() { return "Groc's Gym"; }
id(str) {
  return str=="doorway" || str=="equipment" || str=="gym equipment" ||
         str=="machine" || str=="sign";
}
long(str) {
  if(str=="doorway") 
    write("A battered, weathered door, pinned open. Faded lettering\n"+
     "reads 'Groc's Gym'\n");
  if(str=="equipment" || str=="gym equipment")
    write("Various universal and popular workout machines. Some \n"+
     "appear familiar from wide spread advertisements.\n");
  if(str=="sign")
    write("The finer print on sign says deposit 100 coins into the \n"+
     "machine to use the equipment.\n");
  if(str=="machine")
    write("A vending machine with a message read out. There is a \n"+
     "place to deposit coins. A small, well-worn plaque says '100 coins'\n"+
     "The machine itself is beat up and has been broken into more than\n"+
     "once. Various bars and locks have been added to thwart future\n"+
     "attempts.\n");
  if(str) return 0;

  write("You have entered a run-down looking brick building. As you pass\n"+
   "through the doorway you notice faded and chipped lettering reading\n"+
   "'Groc's Gym'. Before is a large open area with all sorts of equipment.\n"+ 
   "However there are no free weights about, likely all stolen in the\n"+
   "past. On the wall you notice a sign that reads 'Groc's physical\n"+
   "training gym, Turn yourself into a lean, mean fighting machine for\n"+
   "only 100 coins a workout'. Groc should be around someplace, but is\n"+
   "often gone. There's a small machine in the corner to deposit coins\n"+
   "into that appears to be wired to unlock the equipment.\n");
   write("The only exit is west back towards Southroad.\n");
   }

west() {
    call_other(this_player(), "move_player", "west#room/southroad2.c");
    return 1;
}

join(str) {
 object ob;
 int a;
 string b;
   if(str=="coins" || str == "coin") write("You must deposit 100 coins.\n");
   if(sscanf(str,"%d %s",a,b)!=2) return 0;
   if(b != "coins") { 
     write("The machine only accepts coins.\n");
     return 1;
   }
   if(a < 100) { 
     write("You must deposit 100 coins.\n");
     return 1;
   }
   if(a > 100) 
     write("The machine takes 100 coins, the rest fall through to your hand.\n");
   if (this_player()->query_money() < 100) {
     write("You do not have enough money.\n");
     return 1;
   }
   if(this_player()->query_pregnancy()) {
   if(this_player()->query_age()-this_player()->query_pregnancy() >3000) {
      write("You deposit your coins in the machine. The display on\n");
      write("the machine cautions you to not strain yourself.\n");
      write("The following message indicates the equipment is ready.\n");
      lght = 1;
      unlocked = 1;
      this_player()->add_money(-100);
      return 1;
    }}
    unlocked = 1;
    this_player()->add_money(-100);
    write("You deposit your coins in the machine. The display on\n");
    write("the machine states the equipment is ready to use.\n");
    return 1;
}

use(str) {
  int kc,x;
  if(!str) return 0;
  if(str != "equipment" && str!="machine" && str!="machines" &&
     str!="gym equipment") return 0;
  if(!unlocked) { 
    write("You find the vending machine has the equipment locked.\n");
    return 1;
  }
  unlocked = 0;
  write("You workout using the equipment, feeling stronger and better\n"+
     "as a result.\n");
  kc = random(11);
  if(lght) kc = random(1);
  lght = 0;
  if (kc < 0) kc = random(1);
  if (this_player()->query_phys_at(3)<18*this_player()->query_phys_at(1))
     kc = 0;
  if(!this_player()->query_pregnancy() ||this_player()->query_pregnancy()< 4000)
    this_player()->add_phys_at(3, -kc);
  return 1;
}
