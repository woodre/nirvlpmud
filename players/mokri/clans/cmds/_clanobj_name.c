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
      write("What would you like to set the object name to?\n");
      return 1;
   }
   
   write("Setting object name to: " + str + ".\n");
   C_OBJ->set_object_name(str);
   return 1;
}
