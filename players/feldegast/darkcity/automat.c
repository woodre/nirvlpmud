#include "def.h"

inherit MYROOM;

reset(arg) {
  if(!present("policeman")) {
    move_object(clone_object(PATH+"Npc/police"),this_object());
    move_object(clone_object(PATH+"Npc/police"),this_object());
  }
  if (arg) return;
  set_light(1);
  short_desc=GRN+"The Automat"+NORM;
  long_desc=
"     This is a small, utilitarian restaurant with a row of booths\n\
along each wall and a wall of coin operated slots in back.  A glass\n\
window looks out on the street.\n";
  items=({
    "slots","From all the slots, the only good things you see are:\n"+
            "       Green Jello..............80 coins\n"+
            "       Donut...................140 coins\n"+
            "       Moldy sandwich..........240 coins\n"+
            "       Day old pie.............250 coins\n",
    "booths","Cozy booths with comfortable padded benches",
    "wall","You get the feeling employees don't get out here often"
  });
  dest_dir=({
    PATH+"street4","south"
  });
}   

init() {
  ::init();
  add_action("cmd_buy","buy");
}

cmd_buy(str) {
  int intox;
  int cost;
  int heal;
  switch(str) {
    case "jello": case "green jello":
      intox=8; cost=80; heal=5; break;
    case "donut":
      intox=10; cost=140; heal=10; break;
    case "sandwich": case "moldy sandwich":
      intox=12; cost=240; heal=20; break;
    case "pie": case "old pie": case "day old pie":
      intox=14; cost=250; heal=25; break;
    default: write("You don't see that anywhere.\n");
             return 1;
             break;
  }
  if(TP->query_money()<cost) {
    write("You don't have enough coins.\n");
    say(TPN+" brushes some lint out of "+TP->query_possessive()+" pockets.\n");
    return 1;
  }
  if(TP->eat_food(intox)) {
    write("You push "+cost+" coins into the machine and get a "+str+" which you\n"+
          "scarf down right away.\n");
    say(TPN+" eats a "+str+" from one of the slots.\n");
    TP->add_money(-cost);
    TP->heal_self(heal);
    return 1;
  }
}
