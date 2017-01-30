/*
File: rush.c
Author: Feldegast
Date: 04/28/02
Description:
  The token for the rush spell.  Lasts for 6 hbs and provides a
6wc bonus to the target.
*/
#include "/players/feldegast/defines.h"

int count;

void reset(int arg)
{
  if(arg) return;
  count = 6;
  set_heart_beat(1);
}

int id(string str)
{
  return str == "generic_wc_bonus" || str == "rush";
}

int gen_wc_bonus()
{

  if(!environment() || !environment(environment())) /* Improbable, but can't hurt. */
    destruct(this_object());

  /* If this spell becomes an issue in pk, just uncomment this line.
  if(((object)environment()->query_attack())->is_player())
    return;
  */

  tell_object(environment(), RED+"You move with uncanny speed!\n"+NORM);
  tell_room(environment(environment()), RED+(string)environment()->query_name()+" moves with uncanny speed!\n"+NORM, ({ environment() }));
  return 6;
}

void heart_beat()
{

  if(!environment() || !living(environment()))
    destruct(this_object());

  if(count <= 0)
  {
    tell_object(environment(), BLU+"You begin to move at a normal rate again.\n"+NORM);
    destruct(this_object());
  }
  count--;
}
