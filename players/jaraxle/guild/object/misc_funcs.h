#include "basename.h"

status drop() { return 1; }

status get() { return 1; }

mixed
remove_object()
{
    object Wep;

    Wep = first_inventory(this_object());

    if(Wep)
      if((status)Wep->query_save_flag() ||
         (status)Wep->generic_object() ||
         basename(Wep)[0..2] == "obj")
      {
        move_object(Wep, environment(environment()));
        Sheathed = 0;
      }

    save_it();
}
