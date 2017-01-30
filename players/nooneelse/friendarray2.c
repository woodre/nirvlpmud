#include "/players/sado/guild/std.h"

inherit "/obj/treasure.c";

reset(arg)
{
   if(arg) return;
   set_id("pentagram");
   set_short("A Golden Pentagram");
   set_long("The Golden Pentagram is the sign of the Alchemist guild.\n");
   set_weight(0);
   set_value(0);
   if(query_verb()!="recruit") CENTRAL->f_emote(tp,"has logged on.");
   CENTRAL->refresh_soon();
   enable_commands();
}

init()
{
   ::init();
   add_action("alchemists","alchemists");
   add_action("brew","brew");
   add_action("lightning","lightning");
   add_action("illusion","illusion");
   add_action("update","newcent");
   add_action("sp_spark","spark");
   add_action("alchemists","a");
   add_action("invite","recruit");
   add_action("remove","revoke");
   add_action("f_emote","ate");
   add_action("f_talk","att");
   add_action("quit","quit");
}

drop() {return 1;}

alchemists()
{
   CENTRAL->f_who();
   return 1;
}

invite(str)
{
   return CENTRAL->recruit(str);
}

remove(str)
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

quit()
{
   CENTRAL->f_emote(tp,"has logged off.");
   CENTRAL->refresh_soon();
   
   return tp->do_quit();
}


query_auto_load() { return PENT+":"; }

update()
{
   if(find_object(CENTRAL)) destruct(find_object(CENTRAL));
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

lightning(str)
{
   return CENTRAL->lightning(str);
}

illusion(str)
{
   return CENTRAL->illusion(str);
}
