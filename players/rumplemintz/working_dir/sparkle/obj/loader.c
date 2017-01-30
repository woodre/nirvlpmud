#include "../defs.h"

reset(arg) { return; }

init_arg(x) {
  object ob;

  /* Put anything in here you want to happen when it's actually autoloaded
   * onto someone.  (Ie, display news, whatever).
  */

  ob = clone_object(GARTER);
  move_object(ob, this_player());
  tell_object(this_player(), "Garter has been cloned to you.\n");

  destruct(this_object());
}
