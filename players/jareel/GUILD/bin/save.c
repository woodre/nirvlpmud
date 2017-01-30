#include "../defs.h"

status
main(string arg)
{

  present(GOB_ID, this_player())->save_info();

  write("This won't work until it's in a wizard's directory instead of /open.\n");
  return 0;
}
