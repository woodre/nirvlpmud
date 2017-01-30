#include "../def.h"

status
main()
{
    string sh, s;
    object Ob, Wep;

    Ob = previous_object();
    Wep = first_inventory(Ob);

    s = (string)Ob->query_sheathed();
    if(!s)
    {
      notify_fail("\
You don't have a weapon currently sheathed, rendering\n\
an unsheath impossible.\n");
      return 0;
    }
    Wep = clone_object(s);
    sh = (string)Wep->short();
    
    write("\
You withdraw " + sh + " from your sheath in a\n\
smooth, effortless motion.\n");
    say((string)this_player()->query_name() + " \
withdraws " + sh + " from " + possessive(this_player()) + "\n\
sheath in a smooth, effortless motion.\n");
    
    Ob->set_sheath(0);
    Ob->save_it();
    move_object(Wep, this_player());
    if(!this_player()->query_weapon())
      command("wield " + (string)Wep->query_name(), this_player());

    return 1;
} 
