#include "/players/mokri/define.h"

inherit "/obj/treasure.c";
reset(int arg) {
   if(arg) return;
   set_id("teller");
   set_long("There is no this_teller here.\n");
}

init()
{
   ::init();
   add_action("tell","tell");
}

tell(string str) {
   int x;
   string name;
   object who;
   
   if(!str || sscanf(str,"%s %s",name,str) != 2)
   {
      write("Syntax: tell <player> <message>\n");
      return 1;
   }
   
   who = find_player(name);
   
   if(!who)
   {
      write("Nope.\n");
      return 1;
   }
   
   if(who->query_invis()) write("Warning: " + CAP(who->query_real_name()) + " is invisible.\n");
   if(in_editor(who)) write("Warning: " + CAP(who->query_real_name()) + " is editing.\n");
   
   write(HIM+"You tell "+CAP(who->query_real_name())+", \""+NORM+str+HIM+"\"\n"+NORM);
   
   /* added by mizan for invis to wizards */
   if(who->query_level() >=21 && this_player()->query_invis())
      name = HIM + "(invis) " + capitalize(this_player()->query_real_name()) + " tells you, \""+NORM+str+HIM+"\""+NORM;
   else
      name = HIM+TPN+" tells you, \""+NORM+str+HIM+"\""+NORM;
   /* end changes */

   tell_object(who,name + "\n");

   who->add_tellhistory(name);
   who->Replyer(this_player()->query_real_name());
   return 1; }

drop() { return 1; }
query_auto_load() { return "/players/katya/new_tell.c:"; }
