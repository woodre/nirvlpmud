#include "../DEFS.h"

status main(string str) {
  /* allows pilot to repair damage and cool the  */
  /* mech down.  makes mech vulnerable to attack */
  int time;
  object ob;
  if(!str) {
    write("Usage: repair [minor/average/major]\n");
    return 1;
  }
  switch(str) {
    case "minor":   time = 5; break;
    case "average": time = 10; break;
    case "major":   time = 15; break;
  }
  if(!time) {
    write("Wrong repair type, your choices are:\n"+
          "'minor, average, or major'\n");
    return 1;
  }
  ob = clone_object(
       "/players/dune/closed/pavilion/repair.c");
  move_object(ob, ETP);
  ob->set_repairs(time, str);
  return 1;
}
