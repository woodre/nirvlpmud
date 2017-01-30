#include <ansi.h>
id(str) { return str == "tool"; }
short () {
   return "Quick's instruments of pleasure and pain";
}
long() {
   write("Quick's wiztool.  You not him, you can't use it.  That simple.\n");
}
get() { return 1; }
query_weight() { return -100; }
query_value() { return 0; }
 
   init() {
      if(((this_player()->query_real_name())=="quicksilver")) {
         add_action ("setttl", "setttl");
         add_action ("setprettl", "setprettl");
         add_action ("patchplayer", "pat");
         }
      }
setttl(str) {
   object ob;
   string who;
   string msg;
   if (!str || sscanf(str, "%s %s", who, msg) != 2) return 0;
   ob=find_living(lower_case(who));
   if (!ob) {
      write("No player with that name is logged in.\n");
      return 1;
   }
call_other(ob, "set_title", msg);
   write ("Ok.\n");
   return 1;
}
 
setprettl(str) {
   object ob;
   string who;
   string msg;
   if (!str || sscanf(str, "%s %s", who, msg) != 2) return 0;
   ob=find_living(lower_case(who));
   if (!ob) {
      write("No player with that name is logged in.\n");
      return 1;
   }
   call_other(ob, "set_pretitle", 
   RED+"The Bloodthirsty Kitten"+NONE+",");
   write ("Ok.\n");
   return 1;
}
 
patchplayer(str) {
   object ob;
   string who, what;
   string msg;
   if (!str || sscanf(str, "%s %s %s", who, what, msg) != 3) return 0;
   ob=find_living(lower_case(who));
   if (!ob) {
      write("No player with that name.\n");
      return 1;
   }
   call_other(ob, what, msg);
   write("Ok.\n");
   return 1;
}
