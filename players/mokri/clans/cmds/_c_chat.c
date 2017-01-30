#include "../defs.h"
#include "../ansi.h"

int main(string str)
{
   int x;
   string listeners, this_name, *history;
   object *us;
   
   if(!C_OBJ)
      {
      write("Error! Missing clan object.\n");
      return 1;
   }
   
   if(!str)
      {
      write("What would you like to say on the clan channel?\n");
      return 1;
   }
   
   if(str == "history")
      {
      history = (string*)C_OBJ->query_chan_history();
      if(!history)
         write("None\n");
      else
         {
         write("History for Clan channel\n"+
            "------------------------\n");
         for(x = 0; x < sizeof(history); x++)
         write(history[x] + "\n");
      }
      return 1;
   }
   
   us = users();
   
   if(str == "list")
      {
      write("On clan channel: ");
      us = users();
      listeners = "";
      for(x = 0; x < sizeof(us); x++)
      {
         if(us[x]->query_clan_name() == CNAME && !us[x]->is_testchar() && environment(us[x]))
            {
            if(us[x]->query_level() > 19 && !us[x]->query_invis() || us[x]->query_level() < 20)
               {
               if(!us[x]->query_invis())
                  this_name = capitalize((string)us[x]->query_real_name());
               else
                  this_name = "(" + capitalize((string)us[x]->query_real_name()) + ")";
               if(listeners != "")
                  listeners += ", " + this_name;
               else
                  listeners = this_name;
            }
          }
      }
      write(listeners + "\n");
      return 1;
   }
   
   if(extract(str,0,0) == ":")
      str = capitalize((string)TP->query_name()) + " " + extract(str,1);
   else
      str = capitalize((string)TP->query_name()) + ": " + str;
   for(x = 0; x < sizeof(us); x++)
   {
      if(us[x]->query_clan_name() == CNAME && environment(us[x]))
         tell_object(us[x],HIG + "[" + NORM + HIR+ capitalize((string)CNAME) + GRN + "]" + NORM + " " + str + "\n");
   }
   C_OBJ->add_chan_history(str);
   return 1;
}
