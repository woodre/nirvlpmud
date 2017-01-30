#include "../defs.h"

int main(string str)
{
   if(!C_OBJ)
      {
      write("Error! Missing clan object.\n");
      return 1;
   }
   
   if(!C_OBJ->query_leader(TP->query_real_name())) return 0;
   if(!str)
      {
      write("Recruit type currently set to: ");
      switch(C_OBJ->query_join_type())
      {
         case 0:
         write("ALL clan members may recruit.\n");
         break;
         case 1:
         write("only CLAN LEADERS may recruit.\n");
         break;
         case 2:
         write("only the CLAN OWNER may recruit.\n");
         break;
      }
      return 1;
   }
   
   switch(str)
   {
      case "all":
      write("Setting recruit type to: ALL clan members may recruit.\n");
      C_OBJ->set_join_type(0);
      break;
      case "leaders":
      write("Setting recruit type to: only CLAN LEADERS may recruit.\n");
      C_OBJ->set_join_type(1);
      break;
      case "owner":
      write("Setting recruit type to: only the CLAN OWNER may recruit.\n");
      C_OBJ->set_join_type(2);
      break;
      default:
      write("Syntax: recruit_type [type]\n'Type' may be 'all', 'leaders', or 'owner'.\n");
      break;
   }
   return 1;
}
