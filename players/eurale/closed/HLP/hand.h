#include "DEF.h"
 
hand(str) {
  object who;
  string what;

if(!sscanf(str,"%s %s",who,what) == 2) {
  write("Usage: hand <player> <item>\n");
  return 1; }

if(!find_living(who)) {
  write("Couldn't find "+capitalize(who)+".\n");
  return 1; }

  who = find_living(who);
  move_object(clone_object(what),who);
  tell_object(who,
    "Eurale's "+HIB+"pet blue demon"+NORM+" flies in and hands you "+
    "something...\n");
  write("Your "+HIB+"pet blue demon"+NORM+" takes something and flies off...\n");
  return 1;
}
