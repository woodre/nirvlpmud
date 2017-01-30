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
      write("What would you like to set the short description to?\n");
      return 1;
   }
   
   write("Setting short description to: " + (string)call_other(TOP_DIR + "funcs","modify_spell_message",str, this_player()) + ".\n");
   C_OBJ->set_clan_short(str);
   return 1;
}
