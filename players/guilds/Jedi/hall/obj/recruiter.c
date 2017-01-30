#include "../defs.h"
string clan_name, recruiter;

inherit "/obj/treasure.c";
reset(int arg) {
   if(arg) return;
   set_id("clan_recruit_object");
   set_long("There is no clan_recruit_object here.\n");
}

init()
{
   add_action("start_clan_join_offer","start_clan_join_offer");
}

int join_choice(string str)
{
   object offerer, obj;
   offerer = find_player(recruiter);
   
   if(str != "y" && str != "Y" && str != "yes" && str != "Yes")
      {
      write("You decline the offer.\n");
      if(offerer)
         tell_object(offerer,capitalize((string)TP->query_real_name()) + " has DECLINED your offer to join the clan.\n");
      destruct(this_object());
      return 1;
   }
   
   write("You are now a member of the clan.\n");
   if(offerer)
      tell_object(offerer,capitalize((string)TP->query_real_name()) + " has ACCEPTED your offer to join the clan.\n");
   TP->set_clan_name(clan_name);
   obj = clone_object(TOP_DIR + "object");
   move_object(obj,TP);
   call_other(TOP_DIR + "cmds/_c_chat","main",":has joined the clan!");
   destruct(this_object());
   return 1;
}

int start_clan_join_offer()
{
   if(!clan_name || !recruiter)
      {
      destruct(this_object());
      return 1;
   }
   
   write(capitalize(recruiter) + " has sent you an offer to join clan " + clan_name + ".\n"+
      "Would you like to join (y/n)? > ");
   input_to("join_choice");
   return 1;
}
set_clan_name(string cn) { clan_name = cn; }
set_recruiter(string rec) { recruiter = rec; }
