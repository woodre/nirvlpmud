#include "/players/feldegast/defines.h"
#define MAX_CHARGES 16
#define STRENGTH1 3
#define STRENGTH2 5
#define STRENGTH3 10
#define HEAL1 10
#define HEAL2 20
#define HEAL3 40

int charges;

init() {
  if(!environment()->is_player()) return;

  add_action("sip","sip");
  add_action("drink", "drink");
  add_action("swig","swig");
  add_action("swig","chug");
}
reset(arg) {
  if(arg) return;
  charges=MAX_CHARGES;
}

id(str) {
  return str=="rum" || str=="bottle";
}

short(){
   return "Bottle of Spiced Rum *"+charges+"*";
}

long() {
  write("This is a bottle of good rum.  There are "+charges+" ounces left.\n");
  write("You can sip it, drink it, or swig it.\n");
}

get(){
  return 1;
}
sip(str) {

  if (!str || !id(str))
    return 0;

  if(charges < 1)
  {
    notify_fail("There isn't enough left for that.\n");
    return 0;
  }
  if(!TP->drink_alcohol(STRENGTH1)) return 1;
  

  charges--;
  TP->heal_self(HEAL1);
  write("You sip the good rum.  There are "+charges+" ounces left.\n");
  say(TPN+" sips some rum.\n");
  command("mon",TP);
  if(charges <= 0) {
    destruct(this_object());
    TP->add_weight(-1);
    write("You finish off the rum and toss the bottle aside.\n");
  }
  return 1;
}

drink(str) {

  if (!str || !id(str))
    return 0;

  if(charges < 2)
  {
    notify_fail("There isn't enough left for that.\n");
    return 0;
  }
  if(!TP->drink_alcohol(STRENGTH2)) return 1;
  

  charges-=2;
  TP->heal_self(HEAL2);
  write("You drink the good rum.  There are "+charges+" ounces left.\n");
  say(TPN+" drinks some rum.\n");
  command("mon",TP);
  if(charges <= 0) {
    destruct(this_object());
    TP->add_weight(-1);
    write("You finish off the rum and toss the bottle aside.\n");
  }
  return 1;
}
swig(str) {

  if (!str || !id(str))
    return 0;

  if(charges < 4)
  {
    notify_fail("There isn't enough left for that.\n");
    return 0;
  }
  if(!TP->drink_alcohol(STRENGTH3)) return 1;
  

  charges-=4;
  TP->heal_self(HEAL3);
  write("You swig the good rum.  There are "+charges+" ounces left.\n");
  say(TPN+" swigs some rum.\n");
  command("mon",TP);
  if(charges <= 0) {
    destruct(this_object());
    TP->add_weight(-1);
    write("You finish off the rum and toss the bottle aside.\n");
  }
  return 1;
}
query_value() {
   return 100*charges;
}

query_weight() {
   return 1;
}
query_save_flag() { return 1; }
