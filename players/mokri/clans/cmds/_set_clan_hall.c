#include "../defs.h"

int main()
{
   int x, populated;
   object tmp_obj, *us;
   if(!C_OBJ)
      {
      write("Error! Missing clan object.\n");
      return 1;
   }

   if(!C_OBJ->query_leader(TP->query_real_name())) return 0;

   if("/" + file_name(environment(TP)) == C_OBJ->query_hall_path()) {
      write("The clan hall entrance room is already set to this room.\n");
      return 1;
   }

   if(environment(TP)->realm("NT"))
      {
      write("Unable to move clan hall to this area.\n");
      return 1;
   }

   x = 0;
   tmp_obj = first_inventory(environment(this_player()));
   while(tmp_obj)
   {
     if(tmp_obj->query_npc() && !tmp_obj->is_pet() && !tmp_obj->is_kid())
         x = 1;
      tmp_obj = next_inventory(tmp_obj);
   }

   if(x)
      {
      write("You cannot set the clan hall while creatures stand guard.\n"+
         "You wouldn't want them to know where you live, would you?\n");
      return 1;
   }
   us = users();
   tmp_obj = clone_object(TOP_DIR + "funcs");
   for(x = 0; x < sizeof(us); x++)
   {
      if(tmp_obj->in_clan_hall(us[x],CNAME)) populated = 1;
   }
   destruct(tmp_obj);

   if(populated)
      {
      write("Unable to move clan hall while people are inside.\n");
      return 1;
   }

   if(TP->query_sp() < 100) { write("You don't have enough energy.\n"); return 1;}
   TP->add_spell_point(-100);
   C_OBJ->set_hall_path("/" + file_name(environment(TP)));
   write("You spend 100 sps and set your clan hall's location.\n");
   return 1;
}
