/* *************************************************************************
 * tkills
 *
 * - Earwax 9/14/03
 * 
 * Display a player's kills.
 *
 * *************************************************************************
*/

#include "../defs.h"

inherit WAXFUNS;

status main(string arg) {
  string filename;
  object ob;

  if (!arg) arg = (string)this_player()->query_real_name();

  filename = SAVEPATH+arg[0..0]+"/"+arg+".pks";
  if (file_size(filename) < 0)
  {
    notify_fail("PK Kill file for "+capitalize(arg)+" does not exist.\n");
    return 0;
  }
  ob = clone_object("/players/earwax/closed/TRACKER/obj/more_ob");
  ob->more(filename);
  return 1;
}
