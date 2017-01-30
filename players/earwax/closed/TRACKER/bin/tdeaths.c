/* *************************************************************************
 * tdeaths
 *
 * - Earwax 9/14/03
 * 
 * Display a player's deaths.
 *
 * *************************************************************************
*/

#include "../defs.h"

inherit WAXFUNS;

string *Death_list;
string Pks, Deaths, Points;
status Muffled;

status main(string arg) {
  string filename;
  int i, siz;

  if (!arg) arg = (string)this_player()->query_real_name();

  filename = STATSPATH+arg[0..0]+"/"+arg;
  if (file_size("/"+filename+".o") < 0)
  {
    notify_fail(capitalize(arg)+" does not have death stats.\n");
    return 0;
  }

  restore_object(filename);
/* verte added next ln */
  if(!Death_list) Death_list = ({ });
  siz = sizeof(Death_list);  
  for (i = 0; i < siz; i++)
    write(ralign(i+"",3) + " " + Death_list[i]);
  return 1;
}

