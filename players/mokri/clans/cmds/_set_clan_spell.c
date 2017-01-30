#include "../defs.h"

int main(string str)
{
   object spell_builder;
   if(!C_OBJ)
      {
      write("Error! Missing clan object.\n");
      return 1;
   }

   if(!C_OBJ->query_leader(TP->query_real_name())) return 0;
   
  if(C_OBJ->spell_is_delayed())
      {
      write("Spell in use. Please try again later.\n");
      return 1;
   }
   
   spell_builder = clone_object(TOP_DIR + "obj/spell_builder");
   spell_builder->start_spell();
   return 1;
}
