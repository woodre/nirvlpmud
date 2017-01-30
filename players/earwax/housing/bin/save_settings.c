#include "../defs.h"

int *priv_cost() { return ({ 2, 5000 }); }

status 
main(string arg, object room, object master)
{
  room->save_info();
  write("Saving completed.\n");
  return 1;
}
