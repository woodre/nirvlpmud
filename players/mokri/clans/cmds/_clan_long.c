#include "../defs.h"

int main(string str)
{
   object long_builder;
   if(!C_OBJ)
      {
      write("Error! Missing clan object.\n");
      return 1;
   }
   
   if(!C_OBJ->query_leader(TP->query_real_name())) return 0;
   long_builder = clone_object(TOP_DIR + "obj/long_builder");
   long_builder->start_long();
   return 1;
}
