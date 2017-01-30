#include "defs.h"

status main(string arg) {
  object ob;

  if (ob = present(MGOB_ID, this_player()))
    ob->save_info();

  return 0;
}
