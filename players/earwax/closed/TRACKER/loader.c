/* *************************************************************************
 * /players/earwax/closed/TRACKER/loader
 *
 * Tracker Autoloader
 *
 * Earwax 7/29/03
 *
 * *************************************************************************
 *
 * Loads the tracker object onto players.
 * News, changes, anything that needs to happen when the object is 
 * automatically loaded to someone would go here.
 *
 * *************************************************************************
*/

#include "defs.h"

void
reset(status arg)
{
  return;
}

/* *************************************************************************
 * init_arg
 *
 * this function is called when the object is autoloaded to a player
 *
*/

void
init_arg(string x)
{
  object ob;

  if (ob = clone_object(TRACKER_OBJECT))
    move_object(ob,this_player());

  destruct(this_object());
}
