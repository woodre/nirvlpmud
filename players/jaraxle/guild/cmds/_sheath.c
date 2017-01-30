#include "../def.h"
#include "../object/basename.h"

status
main()
{
    object *d, Wep, Ob;
    int c;
    string sh;

    Ob = previous_object();
/*
    if(!Ob->query_solved(SWORD_TASK))
    {
      notify_fail("\
You don't have a weapon approved for the Tournament;\n\
Therefore sheathing would be unnecessary.\n");
      return 0;
    }
*/


    if((mixed)Ob->query_sheathed())
    {
      notify_fail("\
Your sword is already safely sheathed.\n");
      return 0;
    }

    d = deep_inventory(this_player());

    for(c = 0; c < sizeof(d); c ++)
    {
      Wep = d[c];
      if(basename(Wep) == (string)Ob->query_weapon())
      {
        if((status)Wep->query_wielded())
          command("unwield", this_player());
        sh = (string)Wep->short();
        write("\
 You tuck " + sh + " securely within your sheath,\n\
 the blade sliding gently within the confines.\n");
        say((string)this_player()->query_name() + " \
tucks " + sh + " securely within " + possessive(this_player()) 
+ "\nsheath.\n");
        move_object(Wep, Ob);
        Ob->set_sheath(basename(Wep));
        Ob->save_it();
        return 1;
      }
    }

    notify_fail("\
You don't have your selected weapon for the Immortal\n\
tournament on hand.\n");
    return 0;
}
