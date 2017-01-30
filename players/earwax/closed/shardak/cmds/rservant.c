/* **********************************************************************
 * rservant.c
 *
 * remove a servant from the guild hierarchy/members lists manually.
 *
 * syntax: rservant <name>
 *
 * Earwax 7/23/03
*/

#include "../include/daemons.h"

status main(string arg) {

  arg = lower_case(arg);
  HIERARCHYD->remove_member(arg);
  write(capitalize(arg) + " has been removed from the Servants Rosters.\n");
  return 1;
}
