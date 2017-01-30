/*
 *      File:                   orb-lib.c
 *      Function:               Main inherit for all Jaraxle orbs
 *      Author(s):              Vertebraker@Nirvana
 *      Copyright:              Copyright (c) 2005 Vertebraker
 *                                      All Rights Reserved.
 *      Source:                 10/21/2005
 *      Notes:                  
 *                              Structure based off Jar's version 1 orbs.
 *      Change History:
 */

#include <ansi.h>
#include <security.h>

inherit "obj/armor";

void
reset(int arg)
{
  ::reset(arg);
  if(arg) return;
  set_type("orb");
  set_weight(0);
  set_value(6000+random(2000)); /* i assume this is communal */
  worn_tag_short_flag=1; /* i added this to the lib, long overdue,
                            this removes the "(worn)" tag */
}

string short()
{
  return (::short() + (worn_by ? " (floating nearby)" : ""));
}

void long(string str)
{
  ::long(str);
  write("You may \"activate\" or \"deactivate\" the orb.\n");
}

int query_save_flag()
{
  return 0;
}

void init()
{
  ::init();
  add_action("wear_it","wear");
  add_action("wear_it","remove");
  add_action("de_or_activate","activate");
  add_action("de_or_activate","deactivate");
}

int wear_it(string str)
{
  if(id(str))
  {
    write("You can \"activate\" and \"deactivate\" the "+
          query_name()+" in order to toggle its power.\n");
    return 1;
  }
}

int de_or_activate(string str)
{
  if(!str)
  {
    notify_fail("What would you like to "+query_verb()+" ?\n");
    return 0;
  }
  if(!id(str))
  {
    notify_fail("You can only "+query_verb()+" \""+query_name()+"\".\n");
    return 0;
  }
  else
  {
    object room;
    room = environment(environment());
    if(environment()->is_kid())
    {
      tell_room(room,
        "The orb refuses the child's will.\n");
    }
    else
    {
      int current_worn;
      current_worn = worn;
    
      if(query_verb()=="activate")
      {
        if(!current_worn &&
          (::wear(str)) && worn)
        {
          write("The "+query_name()+" slowly floats to your side.\n");
          tell_room(room,
            "The "+query_name()+" slowly floats to "+
             (string)this_player()->query_name()+"'s side.\n",
            ({this_player()}));
        }
        else
        {
          write("The orb is already engaged.\n");
        }
      }
      else if(query_verb()=="deactivate")
      {
        if(current_worn &&
           (::remove(str)) && !worn)
        {
          write("The "+query_name()+" disengages from your side.\n");
          tell_room(room,
            "The "+query_name()+" disengages from "+
            (string)this_player()->query_name()+"'s side.\n",
          ({this_player()}));
        }
        else
        {
          write("The orb is already disengaged.\n");
        }
      }
    }
    return 1;
  }
}
