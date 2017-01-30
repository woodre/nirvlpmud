#include "../defs.h"

int leave_confirm(string str)
{
   int x;
   object tmp_obj, *us;
   if(str) str = lower_case(str);
   if(str != "y" && str != "yes")
      {
      write("Aborting clan_leave.\n");
      return 1;
   }
   
   if(C_OBJ->query_owner() == TP->query_real_name())
      {
      us = users();
      tmp_obj = clone_object(TOP_DIR + "funcs");
      for(x = 0; x < sizeof(us); x++)
      {
         if(tmp_obj->in_clan_hall(us[x],CNAME))
            {
            tell_object(us[x],"Clan room destructing. Moving to green.\n");
            move_object(us[x],"/room/vill_green");
          }
         
         if(us[x]->query_clan_name() == CNAME && us[x] != TP)
            {
            tell_object(us[x],"Your clan leader has disbanded the clan.\n");
            us[x]->set_clan_name(0);
            destruct(present("clan_object",us[x]));
          }
      }
      destruct(tmp_obj);
      call_other(TOP_DIR + "funcs","remove_clan",CNAME);
      write("You disband the clan.\n");
   }
   
   write("You leave the clan.\n");
   TP->set_clan_name(0);
   destruct(C_OBJ);
   return 1;  
}

int main()
{
   object tmp_obj;
   return 0;
   if(!C_OBJ)
      {
      write("Error! Missing clan object.\n");
      return 1;
   }
   
   tmp_obj = clone_object(TOP_DIR + "funcs");
   if(tmp_obj->in_clan_hall(TP,CNAME))
      {
      write("You must exit the clan hall before leaving the clan.\n");
      destruct(tmp_obj);
      return 1;
   }
   
   destruct(tmp_obj);  
   if(C_OBJ->query_owner() == TP->query_real_name())
      write("NOTE: As the clan owner, if you leave, the entire clan will be disbanded.\n");
   write("Are you sure you would like to leave the clan (y/n)? > ");
   input_to("leave_confirm");
   return 1;
}
