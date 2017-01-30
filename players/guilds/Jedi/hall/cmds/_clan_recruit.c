#include "../defs.h"

int main(string str)
{
   object player, obj;
   if(!C_OBJ)
      {
      write("Error! Missing clan object.\n");
      return 1;
   }
   
   switch(C_OBJ->query_join_type())
   {
     case 1:
       if(!C_OBJ->query_leader(TP->query_real_name()))
       {
         write("Only clan leaders may recruit new clan members.\n");
         return 1;
       }
       break;
     case 2:
       if(C_OBJ->query_owner() != TP->query_real_name())
       {
         write("Only the clan owner may recruit new clan members.\n");
         return 1;
       }
       break;
   }
   
   if(!str)
   {
     write("Whom would you like to recruit?\n");
     return 1;
   }
   
   str = lower_case(str);
   player = find_player(str);
   if(!player || !present(player,environment(TP)) || player->query_invis())
   {
     write("No such player present to recruit.\n");
     return 1;
   }
   
   if(player->query_clan_name())
   {
     write(capitalize(str) + " is already in a clan!\n");
     return 1;
   }
   
   write("You give a recruitment offer to " + capitalize(str) + ".\n");
   obj = clone_object(TOP_DIR + "obj/recruiter");
   obj->set_clan_name(CNAME);
   obj->set_recruiter(TP->query_real_name());
   move_object(obj,player);
   command("start_clan_join_offer",player);
   return 1;
}
