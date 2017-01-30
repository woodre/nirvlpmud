/* *************************************************************************
  * /players/earwax/closed/shardak/new/gob/loader.c
 *
 * Guild Object Autoloader
 *
 * Earwax 7/29/03
 *
 * *************************************************************************
 *
 * Loads the guild object onto players.
 * News, changes, anything that needs to happen when the object is 
 * automatically loaded to someone would go here.
 *
 * *************************************************************************
*/

#include "../defs.h"

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
  /* Delaying this slightly, so that our news shows last :) */
  call_out("do_clone", 1, this_player());
}

void
do_clone(object ob)
{
  object gob;

  if (gob = clone_object(GOB))
    move_object(gob, ob);

  destruct(this_object());
}
