#include "../std.h"

inherit ITEM;
int worn;
string my_wear_msg, room_wear_msg, my_remove_msg, room_remove_msg,
old_title, old_al, costume_title;
string name_str;
reset(x)
{
   if(x) return;
   set_alias("costume");
   set_value(25);
}

init()
{
   ::init();
   add_action("cmd_wear","don");
   add_action("cmd_wear","wear");
   add_action("remove","remove");
   add_action("cmd_say","say");
#ifndef __LDMUD__
  add_action("cmd_say"); add_xverb("\"");
  add_action("cmd_emote"); add_xverb(":");
  add_action("cmd_say"); add_xverb("'");
#else
  add_action("cmd_say", "\"", 3);
  add_action("cmd_say", "'", 3);
  add_action("cmd_say", ":", 3);
#endif
   add_action("cmd_emote","emote");
   add_action("cmd_gossip", "gossip");
   add_action("cmd_gossip", "junk");
    add_action("cmd_gossip", "risque");
    add_action("cmd_gossip", "babble");
    add_action("cmd_gossip", "equip");
}

set_my_wear_msg(string str) { my_wear_msg = str; }
set_room_wear_msg(string str) { room_wear_msg = str; }
set_my_remove_msg(string str) { my_remove_msg = str; }
set_room_remove_msg(string str) { room_remove_msg = str; }
set_costume_title(string str) { costume_title = str; }

query_worn() { return worn; }

cmd_wear(str)
{
   int x; object *inv;
   if(USER != TP) return;
   if(worn) return 0;
   inv = all_inventory(USER);
   for(x=0;x<sizeof(inv);x++)
   if(inv[x]->query_worn() && inv[x]->id("costume"))
      {
      notify_fail("You are already wearing a costume.\n");
      return 0;
   }
   if(id(str))
      {
      if(worn)
         {
         notify_fail("You are already wearing that costume!\n");
         return 0;
      }
      write(my_wear_msg);
      TP->remote_say(TPN+" "+room_wear_msg);
      old_title = TP->query_title();
      old_al = TP->query_al_title();
      TP->set_title(costume_title);
      TP->set_al_title(BOLD+BLK+"Ha"+HIR+"llo"+BOLD+BLK+"we"+HIR+"en"+NORM);
      worn = 1;
      return 1;
   }
}

remove(str)
{
   if(USER != TP) return;
   if(id(str))
      {
      if(!worn)
         {
         notify_fail("You aren't wearing that costume!\n");
         return 0;
      }
      worn = 0;
      write(my_remove_msg);
      TP->remote_say(TPN+" "+room_remove_msg);
      TP->set_title(old_title);
      TP->set_al_title(old_al);
      return 1;
   }
}

short()
{
   return (worn ? short_desc+" (worn)" : short_desc);
}

drop()
{
   if(worn) command("remove "+name,TP);
}
cmd_say(str)
{
   string one, two;
   if(!worn) return;
   if(!str)
      {
      write("Say what?\n");
      return 1;
   }
   if(sscanf(str,"%strick or treat%s",one,two) || sscanf(str,"%strickortreat%s",one,two))
      {
      if(present("verte_halloween_pail",TP))
         {
         write("Type: 'trickortreat <name>'\n");
         return 1;
      }
   }
   write("Disguised as "+name_str+", you say: "+str+"\n");
   say(name_str+" says: "+str+"\n");
   return 1;
}

cmd_emote(str)
{
   if(!worn) return;
   if(!str)
      {
      write("Emote what?\n");
      return 1;
   }
   tell_room(ENV(TP),name_str+" "+str+"\n");
   return 1;
}

query_save_flag() { return 1; }

remove_object()
{
   if(USER && worn)
      {
      USER->set_title(old_title);
      USER->set_al_title(old_al);
   }
}

cmd_gossip(str)
{
    object *Us;  int s;  string bling, verb;
    if(!worn) return 0;
    if(!str || str == "history" || str == "list") return 0;
    verb = query_verb();
    if(str[0] == ':') bling = "(" + verb + ") " + name_str + " " + str[1..strlen(str)-1] + "\n";
    else bling = name_str + " " + verb + "s: " + str + "\n";
    Us = users();
     emit_channel("gossip", bling);
    return 1;
}

