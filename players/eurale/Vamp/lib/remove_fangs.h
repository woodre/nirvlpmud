/*
  remove_fangs.h
*/

#include "/players/eurale/defs.h"

/* ----- Allow upper level members to remove players fangs but not remove
         them from the guild                                     ------- */
remove_fangs(str) {
  object target_obj, obj;

if(!str) {
  write("You must specify who's fangs you want to remove.\n");
  write("Use: remove <who>\n");
  return 1; }

if(TPGEXP < 671) {
  write("You lack the authority to use that command.\n");
  return 1; }

target_obj = find_player(str);
if(!target_obj) {
  write("Can't find '"+str+"'\n");
  return 1; }

obj = present("vampire fangs", target_obj);
if(!obj) {
  write(capitalize(str)+" has no vampire fangs to remove.\n");
  return 1; }

if(obj) {
  write("You remove the "+HIR+"FANGS"+NORM+" of "+
        capitalize(str)+".\n");
  tell_object(target_obj,HIR+
    "Your vampire fangs have been removed pending review"+NORM+".\n");
  destruct(obj);
  return 1; }
}
