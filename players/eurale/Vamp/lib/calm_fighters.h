/*
  calm_fighters.h
*/

#include "/players/eurale/defs.h"

/*  Calm the fighers in an area  */

calm_fighters(str) {
  object target_obj;

if(TPL < 12 || TPGEXP < 668 || TP->query_attrib("wil") < 16) {
  write("You lack the skills to use that ability.\n");
  return 1; }

if(TPSP < 20) {
  write("You don't have enough spell points.\n");
  return 1; }

TP->add_spell_point(- 20);
if(!str) {
  target_obj = first_inventory(ROOM);
  while (target_obj) {
    target_obj->stop_fight();
    target_obj->stop_fight();
    target_obj->stop_hunter();
    target_obj=next_inventory(target_obj);
  }
tell_room(environment(TP),
  BOLD+"An eeirie stillness comes over the room."+NORM+"\n\n");
  return 1;
}

target_obj = present(str, ROOM);
if(!target_obj) {
  write(capitalize(str)+" is not present.\n");
  return 1; }

target_obj->stop_fight();
target_obj->stop_fight();
target_obj->stop_hunter();
TP->stop_fight();
TP->stop_fight();
TP->stop_hunter();
EFANGS->tell_my_room(BOLD+
  capitalize(TPRN)+" points a finger and "+capitalize(str)+
    " is stilled."+NORM+"\n\n");
write(BOLD+"You point your finger at "+capitalize(str)+
  " and still them."+NORM+"\n\n");
return 1;
}
