#include "../defs.h"

int main()
{
   object stuff;
   int critter;
   if(!C_OBJ)
      {
      write("Error! Missing clan object.\n");
      return 1;
   }
   
   if(!C_OBJ->query_hall_path())
      {
      write("No clan hall set.\n");
      return 1;
   }
   
   if("/" + file_name(environment(TP)) != C_OBJ->query_hall_path())
      {
      write("You may enter the clan hall from: " + C_OBJ->query_hall_path()->short()+"\n");
      return 1;
   }
   
#if 0
   stuff = first_inventory(environment(this_player()));
   critter = 0;
   
   while(stuff)
   {
      if(stuff->query_npc() && !stuff->is_pet() && !stuff->is_kid())
         critter = 1;
      stuff = next_inventory(stuff);
   }
   
   if(critter > 0)
      {
      write("You cannot enter your hall while creatures stand guard.\n"+
         "You wouldn't want them to know where you live, would you?\n");
      return 1;
   }
#endif
   
   stuff = (object)TP->query_attack();
   if(stuff && present(stuff,environment(TP)))
      {
      write("Stop fighting, first!\n");
      return 1;
   }
   
   move_object(TP,TOP_DIR + CNAME + "/hall/main");
   "/bin/play/_look"->cmd_look();
   if(!TP->query_invis())
      say(TP->query_name() + " is gone.\n");
   return 1;
}
