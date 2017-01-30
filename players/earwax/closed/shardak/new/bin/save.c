#include "defs.h"

int *reqs() { return ({ 0, 0, 0, 0, 0 }); }

status
main(string arg)
{
/* Uncomment this once this is in a wizard directory.
  write("This won't work until it's in a wizard's directory instead of /open.\n");
*/
  present(GOB_ID, this_player())->save_info();
  write("Guild status saved.\n");
  return 0;
}
