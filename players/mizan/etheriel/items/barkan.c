#define PLAYERNAME "reflex"

reset()
{
   do_lockdown();
}

do_lockdown()
{
   object ob;
   ob = find_player(PLAYERNAME);
   
   if(ob)
      {
      object oc;
      
      oc = present("ri8co3304", ob);
      if(!oc)
         {
         move_object(clone_object("/players/mizan/closed/emmerdale2"), ob);
         ob->set_home("/obj/master");
        ob->set_pretitle("Anyone here know LPC?");
        ob->set_title("needs to code something all by himself.");
         ob->set_al_title("[Code Leecher!]");
      }
      
   }
   
   remove_call_out("do_lockdown");
   call_out("do_lockdown", 1);
}
