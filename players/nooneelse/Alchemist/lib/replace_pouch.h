/*
  replace_pouch.h
*/

#include "/players/nooneelse/Alchemist/lib/defs.h"

/* ----- Allow upper level members to fix players who lose their pouch ------- */
replace_fangs(str) {
  string str2;
  object target_obj, obj;

  if (!str) {
    write(NORM+CYN+"You must specify who you want to repair.\n"+
          "use: replace <who>\n"+NORM);
    return 1;
  }
  if (this_player()->query_real_name()!=ALCHEMIST_GUILD_MASTER) {
    write(NORM+CYN+"You can't use that abilitiy.\n"+NORM);
    return 1;
  }
  sscanf(str, "pouch %s", str2);
  if (!str2) {
    write("use: areplace pouch <who>\n");
    return 1;
  }
  target_obj = find_player(str2);
  if (!target_obj) {
    write(NORM+CYN+"Can't find '"+str2+"'\n"+NORM);
    return 1;
  }
  obj = present("Alchemist Pouch", target_obj);
  if (obj) destruct(obj);
  move_object(clone_object(ALCHEMIST_POUCH), target_obj);
  write(NORM+CYN+capitalize(str2)+" now has the latest version of the Alchemist "+
        "Guild's pouch.\n"+NORM);
  return 1;
}
