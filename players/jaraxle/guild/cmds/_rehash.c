#include "../def.h"

status
main()
{
    int x;
    object d, Ob, p;

    write("Rehashing guild object...\n");

    Ob = clone_object(AUTOLOAD);
    p = previous_object();

    if((status)p->query_sheathed())
    {
      d = first_inventory(p);
      if(d)
      {
        move_object(d, Ob);
        Ob->toggle_sheathed();
      }
    }
    
    destruct(p);
    move_object(Ob, this_player());

    write("Rehash complete.\n");
    return 1;
}
