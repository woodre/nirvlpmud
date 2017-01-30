/*
 *      File:                   _pa_bug.c
 *      Function:               This command toggles a bug
 *                               on players/wizards who are being
 *                               logged by Player Affairs Wizards.
 *      Author(s):              Vertebraker@Nirvana
 *      Copyright:              Copyright (c) 2005 Vertebraker
 *                                      All Rights Reserved.
 *      Source:                 09/24/2005
 *      Notes:                  
 *      Change History:
 */

#include <ansi.h>
#include <security.h>

#define PA_DAEMON  "/pa/admin/pa-daemon"

int cmd_pa_bug(string str)
{
  object obj;
  
  if((int)this_player()->query_level() < SENIOR &&
     !PA_DAEMON->query_name((string)this_player()->query_real_name()))
  {
    return 0;
  }
  
  if(!str)
  {
    write("Usage: 'pa_bug <name>'\n");
    return 1;
  }
  
  if(file_size("/pa/log/ip_data/names/"+str) > -1)
  {
    write(str+" is already being bugged.\n");
    return 1;
  }
  
  if(!valid_player(str))
  {
    write("No such player named "+str+"\n");
    return 1;
  }
  
  write_file("/pa/log/ip_data/names/"+str, "");

  if(obj = find_player(str))
  {
    string clone_path;
    if(present("soul", obj))
    {
      destruct(present("soul",obj));
      if((int)obj->query_level() >= APPRENTICE)
      {
        clone_path = "/closed/wiz_soul";
      }
      else
      {
        clone_path = "/obj/soul";
      }
    }
  
    move_object(clone_object(clone_path), obj);
  }
  
  write("Started bugging "+str+".\n");
  return 1;
}
