/*
 *      File:                   player_access.c
 *      Function:               handles MUD read/write access
 *      Author(s):              Vertebraker@Nirvana
 *      Copyright:              Copyright (c) 2005 Vertebraker
 *                                      All Rights Reserved.
 *      Source:                 10/25/2005
 *      Notes:
 *      Change History:
 */

#include <ansi.h>
#include <security.h>
#include "/closed/handshake.h"

nomask string valid_read(string arg);
nomask varargs string valid_write(string arg, object c);

int is_restricted_dir(string str)
{
  return (str[0..3]=="room" ||
          str[0..2]=="obj" ||
          str[0..2]=="bin" ||
          str[0..7]=="post_dir" ||
          str[0..5]=="closed");
}

nomask string valid_read(string arg)
{
  string str, who, file;
  object c;
  string c_name;
  string play_name;
  int    play_level;
  
  if(!arg) return 0;
  
  play_name = (string)this_object()->query_real_name();
  play_level = (int)this_object()->query_level();

  if(c = caller())
  {
    c_name = basename(c);
  }
  
  if(c != this_object() && !in_editor(this_object()))
  {
    if(is_restricted_dir(c_name))
    {
      c=this_object();
    }
  }
    
  if(file = valid_write(arg,c))
  {
    return file;
  }

  str = resolve_path(arg);
 
  /* left in for solidarity */
  if(text_contains(str, "//") ||
     text_contains(str, "/."))
  {
    return 0;
  }
  
  if(sscanf(str, "/players/%s/%s", who, file) == 2)
  {
    if(file != "PLAN" && file != "access.c")
    {
      if(file[0..5]=="closed")
      {
        if(who != play_name && play_level < SENIOR)
        {
          return 0;
        }
      }
    }
    if(who == "guilds")
    {
      if(play_level < ITEM_OVER) /* replace with guilds role hook */
      {
        return 0;
      }
    }
  }
  
  /* i don't think the next line works for restore_object() */
  else if(sscanf(str,"/post_dir/%s.o",who))
  {
    if(who != play_name && play_level < ELDER)
    {
      return 0;
    }
  }
  
  else if(str[0..2]=="/pa")
  {
    if(play_level < ELDER &&  /* replace with role hook */
       !((int)"/pa/admin/pa-daemon"->query_name(play_name)))
    {
      return 0;
    }
  }
  
  else if(str[0..6]=="/closed")
  {
    if(play_level < ELDER)
    {
      return 0;
    }
  }
  
  return file;
}

nomask varargs string valid_write(string arg, object c)
{
  string str, who,tmpa,tmpb,tmpc, file, temp, dir;
  string tpa,tpb;
  int tempb;
  object prev_caller;
  string play_name;
  int    play_level;
  string c_name;
  
  if(!arg) return 0;
  
  play_name = (string)this_object()->query_real_name();
  play_level = (int)this_object()->query_level();
  
  prev_caller = caller();
  
  if(prev_caller)
    c_name = basename(prev_caller);
  
  if (caller() != this_object() || !c)
  {
    c = caller();
  }
  
  if (c != this_object() && !in_editor(this_object()))
  {
    if(is_restricted_dir(c_name))
    {
      c = this_object();
    }
  }
  
  if(in_editor(this_object()))
  {
    c = this_object();
  }
  
  str = resolve_path(arg);
 
  /* left in for solidarity */
  if(text_contains(str, "//") ||
     text_contains(str, "/."))
  {
    return 0;
  }
  
  if(this_object()->query_inact())
  {
    if((int)this_object()->get_handshake(handshake) !=
       (int)this_object()->query_inact())
    {
      return 0;
    }
    else if(sscanf(arg, "/pfiles/%s.o", who))
    {
      if(who != play_name[0..0]+"/"+play_name)
      {
        return 0;
      }
    }
    else if(sscanf(arg, "/players/%s.o", who) ||
            sscanf(arg, "/players/inactive_saved/%s.o", who))
    {
      if(who != play_name)
      {
        return 0;
      }
    }
  }
  
  if(sscanf(arg, "/bin/%s/%s", dir, file) == 2)
  {
    if(dir == "soul")
    {
      if(play_level < ELDER && c_name != "/bin/soul/editor")
      {
        return 0;
      }
    }
    
    if(play_level < ELDER)
      return 0;
  }
  
  else if(arg[0..4] == "/doc/")
  {
    if(sscanf(arg, "/doc/%s/%s", dir, file))
    {
      if(dir == "helpdir" || dir == "wizhelp")
      {
        /* help file role here */
        if(play_level < ELDER) return 0;
      }
    }
  }
  
  else if (sscanf(str, "/players/%s/%s", who, file) == 2)
  {
    if(play_level < ELDER && play_level > 20)
    {
      if(who != play_name)
      {
        string a, b, vvverb;
        
        if(play_level < SENIOR) /* add access.c hook */
          return 0;
          
        vvverb = query_verb();
        if(vvverb == "mv" || vvverb == "cp" || vvverb == "ed" || vvverb=="rm")
        {
          log_file("ED_OTHER",
            play_name+" ["+vvverb+"] "+str+" "+ctime()[4..15]+"\n");
        }
        return "players/"+who+"/"+file;
      }
      else /* my dir */
      {
        return "players/"+play_name+"/"+file;
      }
    }
  }
  
  else if(sscanf(str, "/players/%s.o", file))
  {
    if(c_name == "/obj/simul_efun")
      return "players/"+file+".o";
  }
  
  else if(str[0..6]=="/open/")
  {
    string vverb;
    vverb = query_verb();
    
    if(vverb == "mv" || vverb == "cp" || vverb == "ed" || vverb == "rm")
    {
      log_file("ED_OTHER",
        play_name+" ["+vverb+"] "+str+" "+ctime()[4..15]+"\n");
    }
    return str[1..strlen(str)-1];
  }
  
  else if(str[0..4]=="/log/")
  {
    if(str=="/log/"+play_name)
      return str[1..strlen(str)-1];
      
    else if(sscanf(str,"/log/WR/%s_%s", who, file) == 2)
    {
      if(who == play_name)
      {
        return str[1..strlen(str)-1];
      }  
    }
    else if(sscanf(str,"/log/user/%s",who))
    {
      if(c_name[0..8]=="/obj/user")
      {
        return "log/user/"+who;
      }
    }
    if(play_level >= ED_LOG || text_contains(str,"SQLDATA"))
    {
      return str[1..strlen(str)-1];
    }
  }
  
  if(sscanf(str, "/pa/%s/%s",dir,file))
  {
    if(dir == "log")
    {
      if(c_name=="/obj/soul" ||
         c_name=="/closed/wiz_soul")
      {
        return str[1..strlen(str)-1];
      }
    }
    else if(dir == "admin")
    {
      if(play_level < ELDER) return 0;
    }
    
    if("/pa/admin/pa-daemon"->query_name(play_name)) /* replace with role hook */
    {
      return str[1..strlen(str)-1];
    }
  }
  
  if(str[0..7] == "/pfiles/")
  {
    if(c_name == "/obj/simul_efun")
    {
      return str[1..strlen(str)-1];
    }
  }
  
  if(c != this_object())
  {
    return 0;
  }
  
  if(play_level < ELDER)
    return 0;
  else
    return str[1..strlen(str)-1];
}