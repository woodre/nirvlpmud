#include "../DEFS.h"
#define LEVEL  3
#define DRAIN  50

status main(string str) {
  object meat;
  if(!gotrank(TP, LEVEL)) return 0;
  if(!gotsp(TP,   DRAIN)) return 1;
  meat = (object)TP->query_attack();
  if(!meat) {
    write("You have nothing to retreat from as you are not in combat!\n");
    return 1; }
  TP->add_spell_point(-DRAIN);
  write("You retreat from your attack!\n");
  say(TPN+" retreats from "+TP->POS+" attack!\n");
  if((object)meat->query_attack() == TP) {
    meat->stop_fight();
    meat->stop_fight();
    meat->stop_hunter();
  }
  TP->stop_fight();
  TP->stop_fight();
  TP->stop_hunter();
  return 1;
}
