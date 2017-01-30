/* *************************************************************************
 * Guild channel daemon
 *
 * Coded by Earwax 7/26/03
 *
 * Channel functions and other members related functions
 *
*/

#include "../defs.h"

#define HISTSIZE 15

inherit WAXFUNS;                 /* Various ansi formatting functions */

/* Global Variables */
string       *History;           /* Channel History                   */
object       *Mchannel;          /* Members of the channel            */

/* Prototype Declarations */
object *manual_register();       /* I prefer having reset() first     */
void tell_wax(string arg) { object ob; if (ob = find_player("jareel")) tell_object(ob,arg); }

/* *************************************************************************
 * reset
 *
*/

void
reset(status arg)
{
  if (arg)
    return;

  Mchannel = manual_register();
  History = ({ });
}

/* *************************************************************************
 * Channel Functions
 *
 * Register/unregister, send message, add message to history, show history
*/

/* bah, not going to do it this way....less efficient, but more workable
void register(object ob) { Mchannel += ({ ob }); }
void unregister(object ob) { Mchannel -= ({ ob }); }
*/

void
add_history(string msg)
{
  int i, siz;

  siz = sizeof(History);

  if (siz < HISTSIZE)
  {
    History += ({ msg });
    return;
  }

  for (i = 0; i < siz; i++) 
    if ((i + 1) < siz)
      History[i] = History[i + 1];
    else
      History[i] = msg;
}

void
channel_msg(string msg)
{
  int i;

  i = sizeof(Mchannel = manual_register());
  add_history(msg);
  while (i--) if (Mchannel[i]) tell_object(Mchannel[i],msg);
}

string
*dump_history()
{
  int i;
  string *output;

  output = ({ }); i = sizeof(History);
  while (i--) output += ({ History[i] });
  return output;
}

/* *************************************************************************
 * return_all_members, return_members, manual_register
 * 
 * return_members filters those who have channel muffled.
 *
*/

object 
*manual_register()
{
  object *obs, *temp, ob;
  int i;

  temp = ({ });
  i = sizeof(obs = users());
  while (i--) 
    if ((status)obs[i]->is_player())
    {
      ob = present(GOB_ID,obs[i]);
      if (ob && (status)ob->query_muffle() == 0)
        temp += ({ obs[i] });
    }
 
  obs = ({ });
  return temp;
}

object *get_users() { return manual_register(); }

object
*return_members()
{
  return Mchannel;
}

object
*return_all_members()
{
  object *obs, *temp; int i;

  temp = ({ }); i = sizeof(obs = users());
  while (i--) if (present(GOB_ID,obs[i])) temp += ({ obs[i] });
  obs = ({ });
  return temp;
}

/* *************************************************************************
 * filter_invis
 *
 * Filter out who they can't see.  If their level is 19, check for who has
 * more xlevels.  This goes purely off level, not off invisibility level,
 * since the invisibility level thing works a lot differently here than I'm
 * used to, and I don't have a copy of player.c or anything I can look at
 * while I'm coding this, and I'm too drunk to think right now anyway.
 *
 * When sober - set this up to use filter_array() instead, this sucks.
*/

object
*filter_invis(object *t)
{
  object *temp;
  int i, lvl, l, xlvl;

  temp = ({ });
  i = sizeof(t);
  lvl = (int)this_player()->query_level();
  if (lvl == 19) xlvl  = (int)this_player()->query_extra_level();

  while (i--) 
  {
    if ((int)t[i]->query_invis())
    {
      l = (int) t[i]->query_level();
      if (lvl > l)
        temp += ({ t[i] });
      else
      if (lvl == l)
      {
        if (lvl != 19)
          temp += ({ t[i] });
        else
        if (xlvl >= (int) t[i]->query_xlevel())
          temp += ({ t[i] });
      }
    }
    else
      temp += ({ t[i] });
  }
  return temp;
}

