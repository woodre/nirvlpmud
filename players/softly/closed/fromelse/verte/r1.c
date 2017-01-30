#include "define.h"
inherit "room/room";

void reset(int arg)
{
    if(arg) return;
    set_light(1);
    short_desc = "A lake [test]";
    long_desc = "test test\n";
    dest_dir = ({ "/players/vertebraker/r2", "north" });
}
status query_skates(object ob)
{
    int x, z;
    object *all;
    
    all = all_inventory(ob);
    for(x = 0; x < sizeof(all); x ++)
    {
      if((int)all[x]->is_softly() && (mixed)all[x]->id("ice skates") && (int)all[x]->query_worn())
      z = 1;
    }
    return z;  
}   

status move(string str)
{
    int chance;
    string where;

    chance = random(20);
    if(query_skates(this_player()) || !chance)
    {
      write("\tYou glide across the ice...\n");
      say((string)this_player()->query_name() + "\
 glides across the ice.\n");
      ::move(str);
      return 1;
    }
    else
    {
      switch(random(4))
      {
        case 0: where = "bum"; break;
        case 1: where = "side"; break;
        case 2: where = "face"; break;
        case 3: where = "belly"; break;
      }
      write("\tYou fall and land on your " + where + "!\n");
      say((string)this_player()->query_name() + "\
 falls and lands on " + possessive(this_player()) + "\
 " + where + ".\n");
      return 1;
    }
}
