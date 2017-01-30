#include <ansi.h>

/*
 * Coded by Vertebraker@Nirvana
 * Based on existing code
 * 7-16-2002
 */

#define TOP    "\n     Name          Guild        Location\n"
#define BOTTOM "<----------------------------------------------------------------------->\n"

#pragma strict_types
#pragma save_types

int count,count_vis;

string construct_info(object ob)
{
  object scratch;
  string gname, info_str, name;
  int i;
  if((int)ob->query_level() < 21)
  i = (int)ob->query_invis((int)this_player()->query_level(),
      (int)this_player()->query_extra_level());
  else
  i = (int)ob->query_invis();
  if(ob && (scratch = environment(ob)) &&
  /*   ((int)ob->query_invis() < 1) && */
     (i < 1) &&
     ((int)ob->query_level() < 100001))
  {
    info_str = " " + ((count < 10) ? " " : "") + count + ": ";
    if(!(gname=(string)ob->query_guild_name()))
      gname = "None";
    else gname = capitalize(gname);
    if(gname == "Knights Templar")
      gname = "Knights";
    name = colour_pad((((int)ob->query_pl_k() == 1) &&
                      ((int)ob->query_level() < 21) ?
                      HIR + "*" + NORM : "") +
                      (string)ob->query_name(), 14);
    if((int)ob->query_invis() < 1)
      info_str += (name + pad(gname, 13) +
                 colour_pad((string)scratch->short(), 42));
    else
      info_str += (name + pad(gname, 13) + pad("Unknown", 42));
    return (info_str + "\n");
  }
  return 0;
}

int cmd_who2(string arg)
{
  object *list, ob;
  int    i,     s;
  string info, *custom_who2;

  if(!arg)
    s=sizeof(list=users());
  count = 1;

  if(arg)
  {
    if(!(custom_who2=explode(arg, ",")) ||
       !(s=sizeof(custom_who2)))
    {
      if(info=construct_info(find_player(arg))) {
        if(info && info != "")
           return (write(TOP+BOTTOM+info+BOTTOM), 1);
        else
         return (write("None of the players you listed have logged on."),1);
      }
      else
        return (write(capitalize(arg) + " is not logged in.\n"), 1);
    }
    else
    {
      list=({});
      for(i=0;i<s;i++)
        if(ob=find_player(custom_who2[i]))
          list += ({ ob });
      i=0;
      s = sizeof(list);
    }
    
  }

  if(!s)
  {
    if(!arg)
      return (write("\nNo players logged in.\n\n"), 1);
    else
      return (write("\nNone of the players you listed have logged on.\n"), 1);
  }

  if(arg) {
    count_vis = 0;
    for (i=0; i < s; i++)
      if((ob=list[i]) && (info=construct_info(ob)))
      {
        if(info) count_vis += 1;
        count ++;
      }
  }
  if(!count_vis) 
    return (write("\nNone of the players you listed have logged on.\n"), 1);

  write(TOP+BOTTOM);

  for (i=0; i < s; i++)
    if((ob=list[i]) && (info=construct_info(ob)))
    {
      write(info);
      count ++;
    }

  write(BOTTOM);
  return 1;
}