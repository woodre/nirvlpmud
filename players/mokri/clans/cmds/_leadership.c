#include "../defs.h"

int main(string str)
{
   int x;
   string who, *leaders;
   object them;
   
   if(!C_OBJ)
      {
      write("Error! Missing clan object.\n");
      return 1;
   }
   
   if(!str || !C_OBJ->query_leader(TP->query_real_name()))
      {
      write("Clan Leadership\n"+
         "===============\n\n"+
         "Owner\n=====\n" + capitalize((string)C_OBJ->query_owner())+ "\n\nLeaders\n=======\n");
      leaders = (string*)C_OBJ->query_leaders();
      if(!leaders || sizeof(leaders) == 0)
         {
         write("None.\n");
         return 1;
      }
      for(x = 0; x < sizeof(leaders); x++)
      write(capitalize(leaders[x]) + "\n");
      return 1;
   }
   
   if(sscanf(str,"%s %s",str,who) != 2)
      {
      write("Syntax: leadership [add || remove] [player].\n");
      return 1;
   }
   
   leaders = (string*)C_OBJ->query_leaders();
   who = lower_case(who);
   
   if(str == "add")
      {
      them = find_player(who);
      if(member(leaders,them->query_real_name()) != -1 || them->query_real_name() == C_OBJ->query_owner())
         {
         write("They are already a clan leader!\n");
         return 1;
      }
      
      if(!them || them->query_clan_name() != CNAME || (them->query_level() > 19 && them->query_invis()))
         {
         write("No such player logged on in this clan!\n");
         return 1;
      }
      
      C_OBJ->add_clan_leader(them->query_real_name());
      call_other(TOP_DIR + "cmds/_c_chat","main",":has promoted " + capitalize((string)them->query_real_name()) + " to a clan leader!");
      return 1;
   }
   
   if(C_OBJ->query_owner() != TP->query_real_name())
      {
      write("Only the clan owner may remove leaders.\n");
      return 1;
   }
   
   if(member(leaders,who) == -1)
      {
      write("No such leader to remove!\n");
      return 1;
   }
   
   C_OBJ->remove_clan_leader(who);
   call_other(TOP_DIR + "cmds/_c_chat","main",":has removed " + capitalize(who) + " as a clan leader!");
   return 1;
}
