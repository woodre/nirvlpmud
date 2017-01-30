#include "/players/sado/guild/std.h"

id(str) { return "pentagram" == str; }
short() { return "A Golden Pentagram"; }
long() { write("The Golden Pentagram is the sign of the Alchemist guild.\n"); }
query_weight() { return 0; }
query_value() { return 0; }

reset(arg)
{
   if(arg) return;
   if(query_verb()!="recruit") CENTRAL->f_emote(tp,"has logged on.");
   CENTRAL->refresh_soon();
}

init()
{
   add_action("alchemists","alchemists");
   add_action("brew","brew");
   add_action("sp_spark","spark");
   add_action("sp_lightning","lightning");
   add_action("sp_illusion","illusion");
   add_action("alchemists","a");
   add_action("f_emote","ate");
   add_action("f_talk","att");
   add_action("help","help");
   add_action("quit","quit");

   if(CENTRAL->is_master(env(this_object())))
   {
     add_action("recruit","recruit");
     add_action("revoke","revoke");
     add_action("newcent","newcent");
   }
}

drop() {return 1;}
get() {return 1;}

help(str)
{
  return CENTRAL->help(str);
}

alchemists()
{
   CENTRAL->f_who();
   return 1;
}

recruit(str)
{
   return CENTRAL->recruit(str);
}

revoke(str)
{
   if(!CENTRAL->is_friend(find_player(str))) return 0;
   CENTRAL->remove_friend(find_player(str));
   return 1;
}

f_talk(str)
{
   CENTRAL->f_talk(tp,str);
   return 1;
}

f_emote(str)
{
   CENTRAL->f_emote(tp,str);
   return 1;
}

sp_spark(str)
{
   return CENTRAL->spark(str);
}

sp_lightning(str)
{
   return CENTRAL->lightning(str);
}

sp_illusion(str)
{
   return CENTRAL->illusion(str);
}

quit()
{
   CENTRAL->f_emote(tp,"has logged off.");
   CENTRAL->refresh_soon();

   return tp->do_quit();
}

query_auto_load() { return PENT+":"; }

newcent()
{
   object c;
   if(c = find_object(CENTRAL)) destruct(c);
   CENTRAL->update();
   return 1;
}

catch_tell(str)
{
   object who;
   string name,what;
   
   who=env(this_object());
   if(sscanf(str,"%s %s\n",name,what)!=2) return;
   if(name!=who->query_name()) return;
   if(what!=" just disconnected.") return;
   command(who,"quit");
}

brew(str)
{
   return CENTRAL->brew(str);
}
