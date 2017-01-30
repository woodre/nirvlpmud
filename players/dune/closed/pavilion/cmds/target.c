#include "../DEFS.h"

status main(string str) {
  /* targeting system                    */
  /* allows pilot to target another mech */
  if(!str) {
    write("Usage: target <mech>\n");
    write(
      "Note: Be sure to target the mech, and not the pilot.\n"+
      "      If you don't know who to target, type 'target any'\n");
    return 1;
  }
  str = lower_case(str);
  ETP->set_target(str);
  tell_object(this_player(), "You target "+capitalize(str)+".\n");
  return 1;
}
