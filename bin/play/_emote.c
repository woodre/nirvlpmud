#include "/bin/ghost.c"
#include "/obj/security.h"

#pragma strict_types
#pragma save_types

int
cmd_emote(string str){
   string who, junk;
   object ob;
   int lvv, res;
   if(ghost())
      return 0;
   if(!str)
      return 0;
   if((res = sscanf(str, "%s<F1Q] %s %s", junk, who, str)) == 1 )
      {
      write("Emotef what?\n");
      return 1;
   }
   else if(res == 3)
      {
      if(this_player()->query_spell_point() <= 0) return (write("You don't even have the one spell point required to faremote.\n"), 0);
      if(ob = find_player(who)) {
         lvv = (int)this_player()->query_level();
         if (lvv < ob->query_level() && ob->query_invis() >= 39) {
            write("No player with that name.\n");
            return 1;
         }
         if (lvv < GOD && in_editor(ob)) {
            write("That person is editing. Please try again later.\n");
            return 1;
         }
         if (lvv < 21 && ob->query_tellblock()) {
            write("That person is blocking tells. Please try again later.\n");
            return 1;
         }
         if(this_player()->query_tellblock() && ob->query_level() < 21 && 
               lvv < 21) {
            write("You cannot use tell when tellblock is on.\n");
            return 1;
         }
         if(!ob->query_npc() && !interactive(ob)) 
            write(who+" is disconnected.\n");
         else if(query_idle(ob) > 120) write(who+" is idle at the moment.  You may not get a response right away.\n");
         if(this_player()->query_invis() > 0 && lvv < 199)
            {
            write( "Don't be annoying.  Become visible before you talk to someone!\n" );
            return 1;
         }
         ob->add_tellhistory( "<afar> "+this_player()->query_name() + " " + str);
         str = format(str, 60);
         if(ob->query_level() > lvv  && 
               (string)this_player()->query_name() == "Someone") 
         tell_object(ob,"< "+this_player()->query_real_name()+" > ");
         tell_object(ob, "<afar> "+this_player()->query_name() + " " + str + "\n");
         write("Ok.\n");
         write("You faremote to "+who+ ": " + str);
         if (lvv < EXPLORE)
            this_player()->add_spell_point(-1);
         return 1;
          }
      
      else return (write("No player with that name.\n"), 1);
   }
   write("You "+str+"\n");
   say(call_other(this_player(), "query_name", 0) + " "+ str +"\n");
   return 1;
}
