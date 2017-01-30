int rvis(string str){
   object ob;
   if(!str){
      notify_fail("Usage: rvis <who>\n");
      return 0;
   }
   ob = find_player(str);
   if(!ob){
      notify_fail("Cannot find player "+ob+"\n");
      return 0;
   }
   if(this_player()->query_level() < ob->query_level()){
      notify_fail("Not wise to force higher levels to do something.\n");
      return 0;
   }
   if((int)ob->query_invis() > 20)
      command("vis", ob);
   else
      write(ob+" is now visible.\n");
   ob->unset_invs_sp();
   tell_object(environment(ob), (string)ob->query_name()+" appears in a puff of smoke.\n");
   return 1;
}
