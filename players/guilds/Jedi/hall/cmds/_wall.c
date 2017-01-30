#include "../defs.h"
#define PRICE 10000
#define SP_COST 100

main(string str)
{
   object new_wall;
   int valid_member;
   
   if(!C_OBJ)
      {
      write("Error! Missing clan object.\n");
      return 1;
   }
   
   return 0;
   if(C_OBJ->query_private_coffer() < PRICE)
      {
      write("Your clan is too poor to produce a wall.\n");
      return 1;
   }
   
   if(environment(TP)->query_no_fight())
      {
      write("You cannot do that here.\n");
      return 1;
   }
   
   if(this_player()->query_sp() < SP_COST)
      {
      write("You do not have the required " + SP_COST + " spell points to create a wall. Work on that, then get back to me.\n");
      return 1;
   }
   
   
   if(!str)
      {
      write("In which direction would you like to produce a wall?\n");
      return 1;
   }
   
   valid_member =  member(environment(this_player())->query_dest_dir(),str);
   if(valid_member && (valid_member == 1 || (sizeof(environment(this_player())->query_dest_dir()) % valid_member)))
      {
      if(present("clan_wall_blocker_obj",environment(this_player())))
         {
         write("There is already a wall in this room.\n");
         return 1;
      }
   }
   else
      {
      write("There is no such exit to block.\n");
      return 1;
   }
   
   C_OBJ->add_private_coffer(-PRICE);
   this_player()->add_sp(-SP_COST);
   write("You pull a wall out of your pocket and set it to block '" + str + "'.\n");
   say((string)this_player()->query_name() + " sets a wall to block '" + str + "'.\n");
   new_wall = clone_object(TOP_DIR + "obj/wall");
   new_wall->set_dir_blocked(str);
   move_object(new_wall,environment(this_player()));
   return 1;
}
