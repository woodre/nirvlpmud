#pragma strict_types
#include "../std.h"
inherit CMD;

#define query_tag(ob) query_attribute("*", ob)

inherit "/players/vertebraker/closed/std/m_efuns";

status
main(string arg)
{
    int i, s, c, hit, bling;
    string sh, *z;
    object item, oitem, x;
    mapping things;

    if(arg) return 0;


    if((int)this_player()->test_dark())
      return (write("It is too dark.\n"), 1);
    item = first_inventory(x = this_player());

    if(!item) /* this should never happen */
    {
      write("You aren't carrying anything.\n");
      return 1;
    }
 
    things = ([ ]);


    while(item)
    {
      oitem = next_inventory(item);

      if(sh = (string) item->extra_look()) 
      {
        hit = 1;
        write(sh + ".\n");
      }

      if(sh = (string)item->short())
      {
        sh = capitalize(sh);
        if (query_tag(item)) sh = "*" + sh; else sh = " " + sh;
        things[sh] ++;
        bling ++;
      }

      item = oitem;
    }

    if(hit) 
    {
      write("\n");
      hit = 0;
    }

    s = sizeof(z = m_indices(things));
    for(i = 0; i < s; i++)
    {
      if((c = things[z[i]]) > 1)
        write(c + "x " + z[i] + ".\n");
      else
        write("   " + z[i] + ".\n");
    }

    if(!bling) write("You aren't carrying anything.\n");
    return 1;
}
