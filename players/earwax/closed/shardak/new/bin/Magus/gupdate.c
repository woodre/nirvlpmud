#include "../defs.h"

status
main(string arg)
{
  object ob;

  ob = present(GOB_ID, this_player());
  COMMANDSD->rehash();
  destruct(ob);
  move_object(clone_object(GOB), this_player());
  write("Guild object has been updated.\n");
  return 1;
}
