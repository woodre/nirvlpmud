#include "include/people.h"
#include "include/def.h"
#include "include/ansi.h"
#include "include/tasks.h"
#include "include/macros.h"

/* R.I.P. ME! (vertebraker)
   Reopened by Earwax with Vertebraker's explicit permission.
*/

init_arg(ackughbleh)
{
 object x,y;
 int    comp;
 if((x = this_player()))
 {
  tell_object(x,"mark.c cloned to you\n");
  y = clone_object(GUILDOBJ);
  move_object(y,x);
  y->init_arg();
  command("save", x);
  cat(NEWS);
  destruct(this_object());
 }
}

drop()
{
 return 1;
}

reset(status arg) {
  return;
}
