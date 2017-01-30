#include "../defs.h"

int main(string str)
{
   object them, tmp_obj;
   string *leaders;
   if(!C_OBJ)
      {
      write("Error! Missing clan object.\n");
      return 1;
   }
   
   if(!C_OBJ->query_leader(TP->query_real_name())) return 0;
   if(!str)
      {
      write("Whom would you like to remove from the clan?\n");
      return 1;
   }
   
   them = find_player(str);
   if(!them || them->query_clan_name() != CNAME || (them->query_level() > 19 && them->query_invis()))
      {
      write("No such player logged on in this clan!\n");
      return 1;
   }
   
   str = (string)them->query_real_name();
   
   if(C_OBJ->query_owner() != TP->query_real_name())
      {
      leaders = (string*)C_OBJ->query_leaders();
      if((leaders && member(leaders,str) != -1) || (string)C_OBJ->query_owner() == str)
         {
         write("Only the clan owner can remove leaders or the owner!\n");
         return 1;
      }
   }
   
   if((string)C_OBJ->query_owner() == str)
      {
      write("If you wish to leave, use the 'clan_leave' command.\n");
      return 1;
   }
   
   call_other(TOP_DIR + "cmds/_c_chat","main",":has removed " + capitalize(str) + " from the clan!");
   
   tmp_obj = clone_object(TOP_DIR + "funcs");
   if(tmp_obj->in_clan_hall(them,CNAME))
      {
      tell_object(them,"Moving from clan hall to green.\n");
      move_object(them,"/room/vill_green");
   }
   destruct(tmp_obj);
   
   them->set_clan_name(0);
   destruct(present("clan_object",them));
   return 1;
}
