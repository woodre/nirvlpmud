/*
* An object for allies of the Servants of Shardak
* Makes the ally join in on the guild channel
*/

#include "../def.h"
#include "../daemons.h"
static mapping  cmds;
static int      muffled;

id(str) { return str == "mark" || str == "allymark";}
drop()  { return 1;}
get()   { return 1;}
query_auto_load() { return ("/players/vertebraker/closed/shardak/obj/allymark.c:"); }
extra_look() { return environment()->query_name() + " is an ally of the Servants of Shardak";}
short() { if (this_player() == environment()) return "The mark of an ally";}

reset(a)
{
   if(!a && !root()) {
      CHANNELD->register(this_object(), "Servants");
      cmds = ACTIOND->query_cmds();
   }
}

long()
{
   write("\
With this mark you can easily communicate with your allies, the\n\
Servants of Shardak. Available are the commands at, ae, ats, aw\n\
aupdate [to update the mark in case of bugs], and leave alliance.\n");
}

init()
{
   if(this_player())
   if(this_player()->query_real_name() == "yorick") return destruct(this_object());
/* Added by Maledicta - Enough of the snoopy wizards interfering */
   if(this_player())
   if(this_player()->query_level() < 100 && this_player()->query_level() > 19 &&  
      this_player()->query_real_name() != "wren" &&
      this_player()->query_real_name() != "vital" &&
      this_player()->query_real_name() != "laera") return destruct(this_object());
      
   ACTIOND->GetMap();
   if(!cmds) cmds = ACTIOND->query_cmds();
   if (environment() == this_player()) {
      CHANNELD->register(this_player(), "[Servants]");
      add_attribute("ansi", this_player());
      add_action("cmd_leave", "leave");
      add_action("cmd_hook", "ats");
      add_action("cmd_hook", "aw");
      add_action("cmd_hook", "af");
      add_action("cmd_hook", "ae");
      add_action("cmd_hook", "at");
      add_action("cmd_update", "aupdate");
      if(!cmds) cmds = ACTIOND->query_cmds();
   }
}

void
remove_object(object caller)
{
   CHANNELD->deregister(this_object(), "Servants");
   CHANNELD->deregister(environment(), "[Servants]");
   destruct(this_object());
}

cmd_leave(string str)
{
   if (str != "alliance") return 0;
   write("You are no longer an ally of the Servants of Shardak.\n");
   remove_object();
   return 1;
}

cmd_hook(string str)
{
   string cmd;
   if(!cmds) cmds = ACTIOND->query_cmds();
   switch (cmd = query_verb()) {
      case "at": cmd = "gt"; break;
      case "ae": cmd = "ge"; break;
      case "af": cmd = "gf"; break;
      case "aw": cmd = "gw"; break;
      case "ats": cmd = "gts"; break;
   }
   if (cmd = cmds[cmd])
      return (status) cmd->main(str);
}

GuildClass(x) { return -1;}
Muffled(mf)   { return (muffled ^= mf);}

receive_message(int p, string msg, string cmsg)
{
   if (!muffled && !p && environment())
      tell_object(environment(), cmsg);
}

ClassName() { return "Ally"; }

cmd_update() { move_object(clone_object("/players/vertebraker/closed/shardak/obj/allymark"), this_player()); write("Ok.\n"); destruct(this_object()); return 1; }

init_arg() { command("aupdate", this_player()); return 1; }
