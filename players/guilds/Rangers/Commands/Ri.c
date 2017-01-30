#pragma strict_types
#include <ansi.h>
#include "../RangerDefs.h"

status
RangerPower(string str, string Align)
{
  object ob;
  string shrt;
  int i;
  object *items;
  if(str == "pack")
  {
    items =
      (mixed *) "/players/guilds/Rangers/Commands/Pack.c"->ListItem(
      (string) this_player()->query_real_name() );
    write(RED+"Pack Inventory."+OFF+"\n");
    write("_______________________\n");

    if(items != 0)
    {
      for(i=0;i<sizeof(items); i++)
      {
        if(items[i])
        {
          shrt = (string) items[i]->short();
          if(shrt) write(shrt+"\n");
        }
      }
    }

  }
  else
  {
    write("Power Ranger Inventory.\n");
    write("_______________________\n");
    for(ob = first_inventory(this_player()); ob; ob = next_inventory(ob))
    {
      if(ob->short() &&  /* uh.. short() check 6.6.01 by verte */
        !ob->query_auto_load() &&
        !ob->id("GI")) write(ob->short() + "\n");
    }
  }
  write("_______________________\n");
  return 1;
}

int
QMax() { return 1; }

status
RangerInfo(string str)
{
  write(format("\
  The \'ri\' command lists your current inventory without any of your Power \
Ranger gear getting in the way. It is a quick way to access what you are \
carrying without having to fish through several other things.\n"));
  return 1;
}

status
QRangerInfo(){ return 1; }
