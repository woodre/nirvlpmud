/*
  replace_fangs.h
*/

#include "/players/eurale/defs.h"

  /*  allow 'selected' vamps to replace fangs  */
veplace(str) {
  object target_obj, obj;

if(!str) {
  write("You must specify whose fangs you want to replace.\n");
  write("Use: veplace <who>\n");
  return 1; }

if(TPRN != "hottentot") {
  write("You lack the authority to use this ability.\n");
  return 1; }

target_obj = find_player(str);
if(!target_obj) {
  write("Can't find '"+str+"'\n");
  return 1; }

obj = present("vampire fangs", target_obj);
if(obj) destruct(obj);
move_object(clone_object(FANGS), target_obj);
tell_object(target_obj,
  "Your gums tingle and you feel new "+HIR+"FANGS"+NORM+" grow.\n");
write(capitalize(str)+" now has new "+HIR+"FANGS"+NORM+"\n");
return 1;
}
