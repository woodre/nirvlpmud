/*
 *      File:                   _pa_unbug.c
 *      Function:               This command removes a bug
 *                               on players/wizards who are being
 *                               logged by Player Affairs Wizards.
 *      Author(s):              Vertebraker@Nirvana
 *      Copyright:              Copyright (c) 2005 Vertebraker
 *                               All Rights Reserved.
 *      Source:                 09/24/2005
 *      Notes:                  
 *      Change History:
 */

#include <ansi.h>
#include <security.h>

#define PA_DAEMON  "/pa/admin/pa-daemon"
#define LOG_DAEMON "/pa/tools/loggers"
#define ALTS       "/pa/log/ip_data/alts/"
#define NAMES      "/pa/log/ip_data/names/"
#define IPS        "/pa/log/ip_data/nums/"

int cmd_pa_unbug(string str)
{
  object obj;
  
  if((int)this_player()->query_level() < SENIOR &&
     !PA_DAEMON->query_name((string)this_player()->query_real_name()))
  {
    return 0;
  }
  
  if(!str)
  {
    write("Usage: 'pa_unbug <name>'\n");
    return 1;
  }
  
  if(file_size("/pa/log/ip_data/names/"+str) == -1)
  {
    write(str+" is NOT being bugged.\n");
    return 1;
  }
  
  else
  {
    string *alts;
    string *ips, *i, ip;
    int s, x;
    
    if(file_size(ALTS+str) > -1)
    {
      alts = explode(read_file(ALTS+str),"\n");
      s = sizeof(alts);
      ips = ({ });
    
      while(s--)
      {
        if(read_file(NAMES+alts[s]))
        {
          i = explode(read_file(NAMES+alts[s]),"\n");
          x = sizeof(i);
          while(x --)
          {
            if(member_array(i[x], ips) == -1)
            {
              ips += ({ i[x] });
            }
          }
        }
        rm(NAMES+alts[s]);
      }
    
      s = sizeof(ips);
    
      while(s --)
      {
        rm(IPS+ips[s]);
      }
    }
  }
  
  rm(NAMES+str);
  
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
    
  write("Stopped bugging "+str+".\n");
  return 1;
}
